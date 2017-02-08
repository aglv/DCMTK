//
//  dcmqrdbq.m
//  OsiriX
//
//  Created by Lance Pysher on 3/19/06.

/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - GPL
  
  See http://homepage.mac.com/rossetantoine/osirix/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/
#import "browserController.h"
#import "DICOMToNSString.h"
#import "LogManager.h"

#undef verify

#include "osconfig.h"    /* make sure OS specific configuration is included first */

BEGIN_EXTERN_C
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
END_EXTERN_C

#define INCLUDE_CCTYPE
#define INCLUDE_CSTDARG
#include "ofstdinc.h"

#include "dcmqrdbs.h"
// #include "dcmqrdbi.h"
#include "dcmqrcnf.h"

#include "dcmqridx.h"
#include "diutil.h"
#include "dcfilefo.h"
#include "ofstd.h"


#import "dcmqrdbq.h"

#include "ofstring.h"
#include "dimse.h"
#include "diutil.h"
#include "dcdatset.h"
#include "dcmetinf.h"
#include "dcfilefo.h"
#include "dcdebug.h"
#include "dcuid.h"
#include "dcdict.h"
#include "dcdeftag.h"

#include "ofconapp.h"
#include "dcuid.h"     /* for dcmtk version name */
#include "dicom.h"     /* for DICOM_APPLICATION_REQUESTOR */
#include "dcostrmz.h"  /* for dcmZlibCompressionLevel */
#include "dcasccfg.h"  /* for class DcmAssociationConfiguration */
#include "dcasccff.h"  /* for class DcmAssociationConfigurationFile */

#include "djdecode.h"  /* for dcmjpeg decoders */
#include "djencode.h"  /* for dcmjpeg encoders */
#include "dcrledrg.h"  /* for DcmRLEDecoderRegistration */
#include "dcrleerg.h"  /* for DcmRLEEncoderRegistration */
#include "djrploss.h"
#include "djrplol.h"
#include "dcpixel.h"
#include "dcrlerp.h"

OFCondition decompressFileFormat(DcmFileFormat fileformat, const char *fname){
	OFBool status = YES;
	//DcmFileFormat fileformat;
	OFCondition cond;
	DcmXfer filexfer(fileformat.getDataset()->getOriginalXfer());
	//hopefully dcmtk willsupport jpeg2000 compression and decompression in the future
	if (filexfer.getXferID() == EXS_JPEG2000LosslessOnly || filexfer.getXferID() == EXS_JPEG2000) {
		NSString *path = [NSString stringWithCString:fname encoding:[NSString defaultCStringEncoding]];
		DCMObject *dcmObject = [[DCMObject alloc] initWithContentsOfFile:path decodingPixelData:YES];
		[[NSFileManager defaultManager] removeFileAtPath:path handler:nil];
		[dcmObject writeToFile:path withTransferSyntax:[DCMTransferSyntax ExplicitVRLittleEndianTransferSyntax] quality:1 AET:@"OsiriX" atomically:YES];
		[dcmObject release];
	}
	else {
		  DcmDataset *dataset = fileformat.getDataset();

		  // decompress data set if compressed
		  dataset->chooseRepresentation(EXS_LittleEndianExplicit, NULL);

		  // check if everything went well
		  if (dataset->canWriteXfer(EXS_LittleEndianExplicit))
		  {
			fileformat.loadAllDataIntoMemory();
			[[NSFileManager defaultManager] removeFileAtPath:[NSString stringWithCString:fname] handler:nil];
			cond = fileformat.saveFile(fname, EXS_LittleEndianExplicit);
			status =  (cond.good()) ? YES : NO;
			
		  }
		  else
			status = NO;

	}

	return cond;
}

static OFBool compressFileFormat(DcmFileFormat fileformat, const char *fname, E_TransferSyntax newXfer){
	
	int opt_Quality;
	OFCondition cond;
	OFBool status = YES;
	DcmXfer filexfer(fileformat.getDataset()->getOriginalXfer());
	//hopefully dcmtk willsupport jpeg2000 compressio and compression in the future
	
	if (newXfer == EXS_JPEG2000) {
		NSLog(@"Compress JPEG 2000 Lossy");
		NSString *path = [NSString stringWithCString:fname encoding:[NSString defaultCStringEncoding]];
		DCMObject *dcmObject = [[DCMObject alloc] initWithContentsOfFile:path decodingPixelData:YES];
		[[NSFileManager defaultManager] removeFileAtPath:path handler:nil];
		[dcmObject writeToFile:path withTransferSyntax:[DCMTransferSyntax JPEG2000LossyTransferSyntax] quality:opt_Quality AET:@"OsiriX" atomically:YES];
		[dcmObject release];
	}
	else if  (newXfer == EXS_JPEG2000LosslessOnly) {
		NSString *path = [NSString stringWithCString:fname encoding:[NSString defaultCStringEncoding]];
		DCMObject *dcmObject = [[DCMObject alloc] initWithContentsOfFile:path decodingPixelData:YES];
		[[NSFileManager defaultManager] removeFileAtPath:path handler:nil];
		[dcmObject writeToFile:path withTransferSyntax:[DCMTransferSyntax JPEG2000LosslessTransferSyntax] quality:0 AET:@"OsiriX" atomically:YES];
		[dcmObject release];
	}
	else {
		
		DcmDataset *dataset = fileformat.getDataset();
		DcmItem *metaInfo = fileformat.getMetaInfo();
		DcmRepresentationParameter *params;
		DJ_RPLossy lossyParams(opt_Quality);
		DcmRLERepresentationParameter rleParams;
		DJ_RPLossless losslessParams; // codec parameters, we use the defaults
		if (newXfer == EXS_JPEGProcess14SV1TransferSyntax)
		params = &losslessParams;
		else if (newXfer == EXS_JPEGProcess2_4TransferSyntax)
		params = &lossyParams; 
		else if (newXfer == EXS_RLELossless)
		params = &rleParams; 

	
		// this causes the lossless JPEG version of the dataset to be created
		dataset->chooseRepresentation(newXfer, params);

		// check if everything went well
		if (dataset->canWriteXfer(newXfer))
		{
		// force the meta-header UIDs to be re-generated when storing the file 
		// since the UIDs in the data set may have changed 
		delete metaInfo->remove(DCM_MediaStorageSOPClassUID);
		delete metaInfo->remove(DCM_MediaStorageSOPInstanceUID);

			// store in lossless JPEG format
			
			fileformat.loadAllDataIntoMemory();
			[[NSFileManager defaultManager] removeFileAtPath:[NSString stringWithCString:fname] handler:nil];
			cond = fileformat.saveFile(fname, newXfer);
			status =  (cond.good()) ? YES : NO;
		}
		else
			status = NO;
	}
	
	return status;
}


const OFConditionConst DcmQROsiriXDatabaseErrorC(OFM_imagectn, 0x001, OF_error, "DcmQR Index Database Error");
const OFCondition DcmQROsiriXDatabaseError(DcmQROsiriXDatabaseErrorC);

/* ========================= static data ========================= */

/**** The TbFindAttr table contains the description of tags (keys) supported
 **** by the DB Module.
 **** Tags described here have to be present in the Index Record file.
 **** The order is unsignificant.
 ****
 **** Each element of this table is described by
 ****           The tag value
 ****           The level of this tag (from patient to image)
 ****           The Key Type (only UNIQUE_KEY values is used)
 ****           The key matching type, specifiing which type of
 ****                   matching should be performed. The OTHER_CLASS
 ****                   value specifies that only strict comparison is applied.
 ****
 **** This table and the IndexRecord structure should contain at least
 **** all Unique and Required keys.
 ***/

static const DB_FindAttr TbFindAttr [] = {
        DB_FindAttr( DCM_PatientsBirthDate ,                    PATIENT_LEVEL,  OPTIONAL_KEY,   DATE_CLASS      ),
        DB_FindAttr( DCM_PatientsSex,                           PATIENT_LEVEL,  OPTIONAL_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_PatientsName,                          PATIENT_LEVEL,  REQUIRED_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_PatientID,                             PATIENT_LEVEL,  UNIQUE_KEY,     STRING_CLASS    ),
        DB_FindAttr( DCM_PatientsBirthTime,                     PATIENT_LEVEL,  OPTIONAL_KEY,   TIME_CLASS      ),
       // DB_FindAttr( DCM_OtherPatientIDs,                       PATIENT_LEVEL,  OPTIONAL_KEY,   STRING_CLASS    ),
       // DB_FindAttr( DCM_OtherPatientNames,                     PATIENT_LEVEL,  OPTIONAL_KEY,   STRING_CLASS    ),
       // DB_FindAttr( DCM_EthnicGroup,                           PATIENT_LEVEL,  OPTIONAL_KEY,   STRING_CLASS    ),
       // DB_FindAttr( DCM_PatientComments,                       PATIENT_LEVEL,  OPTIONAL_KEY,   STRING_CLASS    ),
       // DB_FindAttr( DCM_NumberOfPatientRelatedStudies,         PATIENT_LEVEL,  OPTIONAL_KEY,   STRING_CLASS    ),
      //  DB_FindAttr( DCM_NumberOfPatientRelatedSeries,          PATIENT_LEVEL,  OPTIONAL_KEY,   STRING_CLASS    ),
     //   DB_FindAttr( DCM_NumberOfPatientRelatedInstances,       PATIENT_LEVEL,  OPTIONAL_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_StudyDate,                             STUDY_LEVEL,    REQUIRED_KEY,   DATE_CLASS      ),
        DB_FindAttr( DCM_StudyTime,                             STUDY_LEVEL,    REQUIRED_KEY,   TIME_CLASS      ),
        DB_FindAttr( DCM_StudyID,                               STUDY_LEVEL,    REQUIRED_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_AccessionNumber,                       STUDY_LEVEL,    REQUIRED_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_ReferringPhysiciansName,               STUDY_LEVEL,    OPTIONAL_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_StudyDescription,                      STUDY_LEVEL,    OPTIONAL_KEY,   STRING_CLASS    ),
   //     DB_FindAttr( DCM_NameOfPhysiciansReadingStudy,          STUDY_LEVEL,    OPTIONAL_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_StudyInstanceUID,                      STUDY_LEVEL,    UNIQUE_KEY,     UID_CLASS       ),
   //     DB_FindAttr( DCM_OtherStudyNumbers,                     STUDY_LEVEL,    OPTIONAL_KEY,   OTHER_CLASS     ),
   //     DB_FindAttr( DCM_AdmittingDiagnosesDescription,         STUDY_LEVEL,    OPTIONAL_KEY,   STRING_CLASS    ),
   //     DB_FindAttr( DCM_PatientsAge,                           STUDY_LEVEL,    OPTIONAL_KEY,   STRING_CLASS    ),
   //     DB_FindAttr( DCM_PatientsSize,                          STUDY_LEVEL,    OPTIONAL_KEY,   OTHER_CLASS     ),
  //      DB_FindAttr( DCM_PatientsWeight,                        STUDY_LEVEL,    OPTIONAL_KEY,   OTHER_CLASS     ),
  //      DB_FindAttr( DCM_Occupation,                            STUDY_LEVEL,    OPTIONAL_KEY,   STRING_CLASS    ),
  //      DB_FindAttr( DCM_AdditionalPatientHistory,              STUDY_LEVEL,    OPTIONAL_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_NumberOfStudyRelatedSeries,            STUDY_LEVEL,    OPTIONAL_KEY,   OTHER_CLASS     ),
        DB_FindAttr( DCM_NumberOfStudyRelatedInstances,         STUDY_LEVEL,    OPTIONAL_KEY,   OTHER_CLASS     ),
        DB_FindAttr( DCM_SeriesNumber,                          SERIE_LEVEL,    REQUIRED_KEY,   OTHER_CLASS     ),
        DB_FindAttr( DCM_SeriesInstanceUID,                     SERIE_LEVEL,    UNIQUE_KEY,     UID_CLASS       ),
        DB_FindAttr( DCM_Modality,                              SERIE_LEVEL,    OPTIONAL_KEY,   STRING_CLASS    ),
        DB_FindAttr( DCM_InstanceNumber,                        IMAGE_LEVEL,    REQUIRED_KEY,   OTHER_CLASS     ),
        DB_FindAttr( DCM_SOPInstanceUID,                        IMAGE_LEVEL,    UNIQUE_KEY,     UID_CLASS       )
  };

/**** The NbFindAttr variable contains the length of the TbFindAttr table
 ***/

static int NbFindAttr = ((sizeof (TbFindAttr)) / (sizeof (TbFindAttr [0])));


OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::pruneInvalidRecords()
{
    return (EC_Normal) ;
}

/*******************
 *    Is the specified tag supported
 */

static int DB_TagSupported (DcmTagKey tag)
{
    int i;

    for (i = 0; i < NbFindAttr; i++)
    if (TbFindAttr[i]. tag == tag)
        return (OFTrue);

    return (OFFalse);

}


/*******************
 *    Get UID tag of a specified level
 */

static OFCondition DB_GetUIDTag (DB_LEVEL level, DcmTagKey *tag)
{
    int i;

    for (i = 0; i < NbFindAttr; i++)
    if ((TbFindAttr[i]. level == level) && (TbFindAttr[i]. keyAttr == UNIQUE_KEY))
        break;

    if (i < NbFindAttr) {
    *tag = TbFindAttr[i].tag;
    return (EC_Normal);
    }
    else
    return (DcmQROsiriXDatabaseError);

}

/*******************
 *    Get tag level of a specified tag
 */

static OFCondition DB_GetTagLevel (DcmTagKey tag, DB_LEVEL *level)
{
    int i;

    for (i = 0; i < NbFindAttr; i++)
    if (TbFindAttr[i]. tag == tag)
        break;

    if (i < NbFindAttr) {
    *level = TbFindAttr[i]. level;
    return (EC_Normal);
    }
    else
    return (DcmQROsiriXDatabaseError);
}

/*******************
 *    Get tag key attribute of a specified tag
 */

static OFCondition DB_GetTagKeyAttr (DcmTagKey tag, DB_KEY_TYPE *keyAttr)
{
    int i;

    for (i = 0; i < NbFindAttr; i++)
    if (TbFindAttr[i]. tag == tag)
        break;

    if (i < NbFindAttr) {
    *keyAttr = TbFindAttr[i]. keyAttr;
    return (EC_Normal);
    }
    else
    return (DcmQROsiriXDatabaseError);
}

/*******************
 *    Get tag key attribute of a specified tag
 */

static OFCondition DB_GetTagKeyClass (DcmTagKey tag, DB_KEY_CLASS *keyAttr)
{
    int i;

    for (i = 0; i < NbFindAttr; i++)
    if (TbFindAttr[i]. tag == tag)
        break;

    if (i < NbFindAttr) {
    *keyAttr = TbFindAttr[i]. keyClass;
    return (EC_Normal);
    }
    else
    return (DcmQROsiriXDatabaseError);
}

/***********************
 *    Duplicate a dicom element
 *    dst space is supposed provided by the caller
 */

static void DB_DuplicateElement (DB_SmallDcmElmt *src, DB_SmallDcmElmt *dst)
{
    bzero( (char*)dst, sizeof (DB_SmallDcmElmt));
    dst -> XTag = src -> XTag;
    dst -> ValueLength = src -> ValueLength;

    if (src -> ValueLength == 0)
    dst -> PValueField = NULL;
    else {
    dst -> PValueField = (char *)malloc ((int) src -> ValueLength+1);
    bzero(dst->PValueField, (size_t)(src->ValueLength+1));
    if (dst->PValueField != NULL) {
        memcpy (dst -> PValueField,  src -> PValueField,
            (size_t) src -> ValueLength);
    } else {
        CERR << "DB_DuplicateElement: out of memory" << endl;
    }
    }
}

/*******************
 *    Free an element List
 */

static OFCondition DB_FreeUidList (DB_UidList *lst)
{
    if (lst == NULL) return EC_Normal;

    OFCondition cond = DB_FreeUidList (lst -> next);
    if (lst -> patient)
    free (lst -> patient);
    if (lst -> study)
    free (lst -> study);
    if (lst -> serie)
    free (lst -> serie);
    if (lst -> image)
    free (lst -> image);
    free (lst);
    return (cond);
}


/*******************
 *    Free a UID List
 */

static OFCondition DB_FreeElementList (DB_ElementList *lst)
{
    if (lst == NULL) return EC_Normal;

    OFCondition cond = DB_FreeElementList (lst -> next);
    if (lst->elem.PValueField != NULL) {
    free ((char *) lst -> elem. PValueField);
    }
    free (lst);
    return (cond);
}

/*************
Log Entry
*************/
OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::updateLogEntry(DcmDataset *dataset) {
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
			
	const char *scs = 0L;
	NSString *specificCharacterSet;
	const char *pn = 0L;
	NSString *patientName;
	const char *sd = 0L;
	NSString *studyDescription;
	
	if (dataset->findAndGetString (DCM_SpecificCharacterSet, scs, OFFalse).good() && scs != NULL) {
		specificCharacterSet = [NSString stringWithCString:scs];
	}
	else {
		specificCharacterSet = [NSString stringWithString:@"ISO_IR 100"];
	}
	
	if (dataset->findAndGetString (DCM_PatientsName, pn, OFFalse).good() && pn != NULL) {
		patientName = [NSString stringWithCString:pn  DICOMEncoding:specificCharacterSet];
	}
	else {
		patientName = [NSString stringWithString:@""];
	}
	
	if (dataset->findAndGetString (DCM_StudyDescription, sd, OFFalse).good() && sd != NULL) {
		studyDescription = [NSString stringWithCString:sd  DICOMEncoding:specificCharacterSet];
	}
	else {
		studyDescription = [NSString stringWithString:@""];
	}
	if (handle->logEntry == NULL) {
		handle->logEntry = [[NSMutableDictionary alloc] init];
		NSMutableDictionary *userInfo = handle->logEntry;
		[userInfo setObject:patientName forKey:@"PatientName"];		
		[userInfo setObject:studyDescription forKey:@"StudyDescription"];
		[userInfo setObject:[NSString stringWithCString:handle->callingAET] forKey:@"CallingAET"];
		[userInfo setObject:[NSDate date] forKey:@"startTime"];
		[userInfo  setObject:@"In Progress" forKey:@"message"];
		[userInfo  setObject:[NSString stringWithFormat:@"%d", random()] forKey:@"uid"];
	}
	
	NSMutableDictionary *userInfo = handle->logEntry;	
	[userInfo setObject:[NSNumber numberWithInt:++(handle->imageCount)]  forKey:@"numberReceived"];
	[userInfo setObject:[NSDate date] forKey:@"endTime"];
	NSString *path = [[[LogManager currentLogManager] logFolder]
				stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.plist",[userInfo objectForKey:@"uid"]]];
	[userInfo writeToFile:path atomically:YES];
	
	[pool release];
	return EC_Normal;
}






/************************************
				FIND
**************************************/

/********************
**      Start find in Database
**/

OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::startFindRequest(
                const char      *SOPClassUID,
                DcmDataset      *findRequestIdentifiers,
                DcmQueryRetrieveDatabaseStatus  *status)
{
    DB_SmallDcmElmt     elem ;
    DB_ElementList      *plist = NULL;
    DB_ElementList      *last = NULL;
    int                 MatchFound ;
    IdxRecord           idxRec ;
    DB_LEVEL            qLevel = PATIENT_LEVEL; // highest legal level for a query in the current model
    DB_LEVEL            lLevel = IMAGE_LEVEL;   // lowest legal level for a query in the current model

    OFCondition         cond = EC_Normal;
    OFBool qrLevelFound = OFFalse;

    /**** Is SOPClassUID supported ?
    ***/
//we only support study root currently
//    if (strcmp( SOPClassUID, UID_FINDPatientRootQueryRetrieveInformationModel) == 0)
//        handle->rootLevel = PATIENT_ROOT ;

 if (strcmp( SOPClassUID, UID_FINDStudyRootQueryRetrieveInformationModel) == 0)
        handle->rootLevel = STUDY_ROOT ;
		
//#ifndef NO_PATIENTSTUDYONLY_SUPPORT
//    else if (strcmp( SOPClassUID, UID_FINDPatientStudyOnlyQueryRetrieveInformationModel) == 0)
//        handle->rootLevel = PATIENT_STUDY ;
//#endif
    else {
        status->setStatus(STATUS_FIND_Refused_SOPClassNotSupported);
        return (DcmQROsiriXDatabaseError) ;
    }
	
	    /**** Parse Identifiers in the Dicom Object
    **** Find Query Level and contruct a list
    **** of query identifiers
    ***/

    int elemCount = (int)(findRequestIdentifiers->card());
    for (int elemIndex=0; elemIndex<elemCount; elemIndex++) {

        DcmElement* dcelem = findRequestIdentifiers->getElement(elemIndex);

        elem.XTag = dcelem->getTag().getXTag();
        if (elem.XTag == DCM_QueryRetrieveLevel || DB_TagSupported(elem.XTag)) {
            elem.ValueLength = dcelem->getLength();
            if (elem.ValueLength == 0) {
                elem.PValueField = NULL ;
            } else if ((elem.PValueField = (char*)malloc((size_t)(elem.ValueLength+1))) == NULL) {
                status->setStatus(STATUS_FIND_Refused_OutOfResources);
                return (DcmQROsiriXDatabaseError) ;
            } else {
                /* only char string type tags are supported at the moment */
                char *s = NULL;
                dcelem->getString(s);
                strcpy(elem.PValueField, s);
            }
            /** If element is the Query Level, store it in handle
             */

            if (elem. XTag == DCM_QueryRetrieveLevel) {
                char *pc ;
                char level [50] ;

                strncpy(level, (char*)elem.PValueField,
                        (elem.ValueLength<50)? (size_t)(elem.ValueLength) : 49) ;

                /*** Skip this two lines if you want strict comparison
                **/

                for (pc = level ; *pc ; pc++)
                    *pc = ((*pc >= 'a') && (*pc <= 'z')) ? 'A' - 'a' + *pc : *pc ;

                if (strncmp (level, PATIENT_LEVEL_STRING,
                             strlen (PATIENT_LEVEL_STRING)) == 0)
                    handle->queryLevel = PATIENT_LEVEL ;
                else if (strncmp (level, STUDY_LEVEL_STRING,
                                  strlen (STUDY_LEVEL_STRING)) == 0)
                    handle->queryLevel = STUDY_LEVEL ;
                else if (strncmp (level, SERIE_LEVEL_STRING,
                                  strlen (SERIE_LEVEL_STRING)) == 0)
                    handle->queryLevel = SERIE_LEVEL ;
                else if (strncmp (level, IMAGE_LEVEL_STRING,
                                  strlen (IMAGE_LEVEL_STRING)) == 0)
                    handle->queryLevel = IMAGE_LEVEL ;
                else {
                    if (elem. PValueField)
                        free (elem. PValueField) ;
#ifdef DEBUG
                    dbdebug(1, "DB_startFindRequest () : Illegal query level (%s)\n", level) ;
#endif
                    status->setStatus(STATUS_FIND_Failed_UnableToProcess);
                    return (DcmQROsiriXDatabaseError) ;
                }
                qrLevelFound = OFTrue;
				
            } 
			/*
			else {
                // Else it is a query identifier.
                // Append it to our RequestList if it is supported
                // Not sure we need this either
                if (DB_TagSupported (elem. XTag)) {

                    plist = (DB_ElementList *) malloc (sizeof (DB_ElementList)) ;
                    if (plist == NULL) {
                        status->setStatus(STATUS_FIND_Refused_OutOfResources);
                        return (DcmQROsiriXDatabaseError) ;
                    }
                    plist->next = NULL ;
                    DB_DuplicateElement (&elem, &(plist->elem)) ;
                    if (handle->findRequestList == NULL) {
                        handle->findRequestList = last = plist ;
                    } else {
                        last->next = plist ;
                        last = plist ;
                    }
                }
            }
			*/	
            if ( elem. PValueField ) {
                free (elem. PValueField) ;
            }
        }
    }

    if (!qrLevelFound) {
        /* The Query/Retrieve Level is missing */
        status->setStatus(STATUS_FIND_Failed_IdentifierDoesNotMatchSOPClass);
        CERR << "DB_startFindRequest(): missing Query/Retrieve Level" << endl;
        //handle->idxCounter = -1 ;
        DB_FreeElementList (handle->findRequestList) ;
        handle->findRequestList = NULL ;
        return (DcmQROsiriXDatabaseError) ;
    }
	
	    switch (handle->rootLevel)
    {
      case PATIENT_ROOT :
        qLevel = PATIENT_LEVEL ;
        lLevel = IMAGE_LEVEL ;
        break ;
      case STUDY_ROOT :
        qLevel = STUDY_LEVEL ;
        lLevel = IMAGE_LEVEL ;
        break ;
      case PATIENT_STUDY:
        qLevel = PATIENT_LEVEL ;
        lLevel = STUDY_LEVEL ;
        break ;
    }
	
	    /**** Test the consistency of the request list
    ***/
	// I'm not sure this is necessary 
	/*
    if (doCheckFindIdentifier) {
        cond = testFindRequestList (handle->findRequestList, handle->queryLevel, qLevel, lLevel) ;
        if (cond != EC_Normal) {
            //handle->idxCounter = -1 ;
            DB_FreeElementList (handle->findRequestList) ;
            handle->findRequestList = NULL ;
#ifdef DEBUG
            dbdebug(1, "DB_startFindRequest () : STATUS_FIND_Failed_IdentifierDoesNotMatchSOPClass - Invalid RequestList\n") ;
#endif
            status->setStatus(STATUS_FIND_Failed_IdentifierDoesNotMatchSOPClass);
            return (cond) ;
        }
    }
	*/
	
	/**** Then find the first matching image
    ***/
	
	// Search Core Data here
	
	cond = [handle->dataHandler prepareFindForDataSet:findRequestIdentifiers];
	MatchFound = [handle->dataHandler findMatchFound];
	 /**** If an error occured in Matching function
    ****    return a failed status
    ***/

    if (cond != EC_Normal) {
       DB_FreeElementList (handle->findRequestList) ;
        handle->findRequestList = NULL ;
#ifdef DEBUG
        dbdebug(1, "DB_startFindRequest () : STATUS_FIND_Failed_UnableToProcess\n") ;
#endif
        status->setStatus(STATUS_FIND_Failed_UnableToProcess);
        return (cond) ;
    }
	
	 /**** If a matching image has been found,
    ****         add index record to UID found list
    ****    prepare Response List in handle
    ****    return status is pending
    ***/

    if (MatchFound) {
//        DB_UIDAddFound (handle, &idxRec) ;
//        makeResponseList (handle, &idxRec) ;
#ifdef DEBUG
        dbdebug(1, "DB_startFindRequest () : STATUS_Pending\n") ;
#endif
        status->setStatus(STATUS_Pending);
        return (EC_Normal) ;
    }

    /**** else no matching image has been found,
    ****    free query identifiers list
    ****    status is success
    ***/

    else {
  //      handle->idxCounter = -1 ;
        DB_FreeElementList (handle->findRequestList) ;
        handle->findRequestList = NULL ;
#ifdef DEBUG
        dbdebug(1, "DB_startFindRequest () : STATUS_Success\n") ;
#endif
        status->setStatus(STATUS_Success);

        return (EC_Normal) ;
    }

}


/************
**      Test a Find Request List
**      Returns EC_Normal if ok, else returns DcmQROsiriXDatabaseError
 */

OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::testFindRequestList (
                DB_ElementList  *findRequestList,
                DB_LEVEL        queryLevel,
                DB_LEVEL        infLevel,
                DB_LEVEL        lowestLevel
                )
{
    DB_ElementList *plist ;
    DB_LEVEL    XTagLevel ;
    DB_KEY_TYPE         XTagType ;
    int level ;

    /**** Query level must be at least the infLevel
    ***/

    if (queryLevel < infLevel) {
        dbdebug(1,"Level incompatible with Information Model (level %d)\n", queryLevel) ;
        return DcmQROsiriXDatabaseError ;
    }

    if (queryLevel > lowestLevel) {
        dbdebug(1,"Level incompatible with Information Model (level %d)\n", queryLevel) ;
        return DcmQROsiriXDatabaseError ;
    }

    for (level = PATIENT_LEVEL ; level <= IMAGE_LEVEL ; level++) {

        /**** Manage exception due to StudyRoot Information Model :
        **** In this information model, queries may include Patient attributes
        **** but only if they are made at the study level
        ***/

        if ((level == PATIENT_LEVEL) && (infLevel == STUDY_LEVEL)) {
            /** In Study Root Information Model, accept only Patient Tags
            ** if the Query Level is the Study level
            */

            int atLeastOneKeyFound = OFFalse ;
            for (plist = findRequestList ; plist ; plist = plist->next) {
                DB_GetTagLevel (plist->elem. XTag, &XTagLevel) ;
                if (XTagLevel != level)
                    continue ;
                atLeastOneKeyFound = OFTrue ;
            }
            if (atLeastOneKeyFound && (queryLevel != STUDY_LEVEL)) {
                dbdebug(1,"Key found in Study Root Information Model (level %d)\n", level) ;
                return DcmQROsiriXDatabaseError ;
            }
        }

        /**** If current level is above the QueryLevel
        ***/

        else if (level < queryLevel) {

            /** For this level, only unique keys are allowed
            ** Parse the request list elements reffering to
            ** this level.
            ** Check that only unique key attr are provided
            */

            int uniqueKeyFound = OFFalse ;
            for (plist = findRequestList ; plist ; plist = plist->next) {
                DB_GetTagLevel (plist->elem. XTag, &XTagLevel) ;
                if (XTagLevel != level)
                    continue ;
                DB_GetTagKeyAttr (plist->elem. XTag, &XTagType) ;
                if (XTagType != UNIQUE_KEY) {
                    dbdebug(1,"Non Unique Key found (level %d)\n", level) ;
                    return DcmQROsiriXDatabaseError ;
                }
                else if (uniqueKeyFound) {
                    dbdebug(1,"More than one Unique Key found (level %d)\n", level) ;
                    return DcmQROsiriXDatabaseError ;
                }
                else
                    uniqueKeyFound = OFTrue ;
            }
        }

        /**** If current level is the QueryLevel
        ***/

        else if (level == queryLevel) {

            /** For this level, all keys are allowed
            ** Parse the request list elements reffering to
            ** this level.
            ** Check that at least one key is provided
            */

            int atLeastOneKeyFound = OFFalse ;
            for (plist = findRequestList ; plist ; plist = plist->next) {
                DB_GetTagLevel (plist->elem. XTag, &XTagLevel) ;
                if (XTagLevel != level)
                    continue ;
                atLeastOneKeyFound = OFTrue ;
            }
            if (! atLeastOneKeyFound) {
                dbdebug(1,"No Key found at query level (level %d)\n", level) ;
                return DcmQROsiriXDatabaseError ;
            }
        }

        /**** If current level beyond the QueryLevel
        ***/

        else if (level > queryLevel) {

            /** For this level, no key is allowed
            ** Parse the request list elements reffering to
            ** this level.
            ** Check that no key is provided
            */

            int atLeastOneKeyFound = OFFalse ;
            for (plist = findRequestList ; plist ; plist = plist->next) {
                DB_GetTagLevel (plist->elem. XTag, &XTagLevel) ;
                if (XTagLevel != level)
                    continue ;
                atLeastOneKeyFound = OFTrue ;
            }
            if (atLeastOneKeyFound) {
                dbdebug(1,"Key found beyond query level (level %d)\n", level) ;
                return DcmQROsiriXDatabaseError ;
            }
        }

    }
    return EC_Normal ;
}

/********************
**      Get next find response in Database
 */

OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::nextFindResponse (
                DcmDataset      **findResponseIdentifiers,
                DcmQueryRetrieveDatabaseStatus  *status)
		
{
	dbdebug(1, "nextFindResponse () : start\n") ;
	OFCondition         cond = EC_Normal;
	BOOL isComplete;
	*findResponseIdentifiers = new DcmDataset ;
	dbdebug(1, "nextFindResponse () : new dataset\n") ;
	cond = [handle ->dataHandler nextFindObject:*findResponseIdentifiers  isComplete:&isComplete];
	dbdebug(1, "nextFindResponse () : next response\n") ;
	if (isComplete) {
		*findResponseIdentifiers = NULL ;
        status->setStatus(STATUS_Success);
		dbdebug(1, "nextFindResponse () : STATUS_Success\n") ;
		 return (EC_Normal) ;
	}
	if ( *findResponseIdentifiers != NULL ) {
		status->setStatus(STATUS_Pending);
		dbdebug(1, "nextFindResponse () : STATUS_Pending\n") ;
		return (EC_Normal) ;
	}
	
	
	return DcmQROsiriXDatabaseError;
}



OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::cancelFindRequest (DcmQueryRetrieveDatabaseStatus *status)
{
	return DcmQROsiriXDatabaseError;
}

/************************************
			MOVE
**************************************/

OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::nextMoveResponse(
                char            *SOPClassUID,
                char            *SOPInstanceUID,
                char            *imageFileName,
                unsigned short  *numberOfRemainingSubOperations,
                DcmQueryRetrieveDatabaseStatus  *status)
{
	if ( handle->NumberRemainOperations <= 0 ) {
        status->setStatus(STATUS_Success);
        return (EC_Normal) ;
    }
	
	*numberOfRemainingSubOperations = --handle->NumberRemainOperations ;
	NSLog(@"next Move response: %d", *numberOfRemainingSubOperations);
	 status->setStatus(STATUS_Pending);
	 /**** Goto the next matching image number  *****/
	OFCondition cond = [handle->dataHandler nextMoveObject:imageFileName];
	NSLog(@"Next file: %s", imageFileName);
	DcmFileFormat fileformat;
	cond = fileformat.loadFile(imageFileName);
	
	if (cond.good()) {
		const char *sopclass;
		const char *sopinstance;
		cond = fileformat.getDataset()->findAndGetString(DCM_SOPClassUID, sopclass, OFFalse);
		cond = fileformat.getDataset()->findAndGetString(DCM_SOPInstanceUID, sopinstance, OFFalse);
		strcpy (SOPClassUID, (char *) sopclass) ;
		strcpy (SOPInstanceUID, (char *) sopinstance) ;
		/* figure out which of the accepted presentation contexts should be used */
		DcmXfer filexfer(fileformat.getDataset()->getOriginalXfer());
		//on the fly conversion:
		//currently we will convert everything to EXS_LittleEndianExplicit. Eventually this should be the preferred sntacx for the destination
		E_TransferSyntax moveTransferSyntax = EXS_LittleEndianExplicit;
		T_ASC_PresentationContextID presId;
		DcmXfer preferredXfer(moveTransferSyntax);
		OFBool status = YES;
		//presId = ASC_findAcceptedPresentationContextID(assoc, sopClass, preferredXfer.getXferID());
		//T_ASC_PresentationContext pc;
		//ASC_findAcceptedPresentationContext(assoc->params, presId, &pc);
		//DcmXfer propoesdTransfer(pc.acceptedTransferSyntax);
		// if (presId != 0) {
			
			if (filexfer.isNotEncapsulated() && preferredXfer.isNotEncapsulated()) {
				// do nothing
			}
			else if (filexfer.isEncapsulated() && preferredXfer.isNotEncapsulated()) {
				cond = decompressFileFormat(fileformat, imageFileName);
			}
			//else if (filexfer.isNotEncapsulated() && preferredXfer.isEncapsulated()) {
			//	status = compressFile(fileformat, fname);
			//}
			//else if (filexfer.getXfer() != opt_networkTransferSyntax){
			// may need to convert encapsulated syntax
			//	status = compressFileFormat(fileformat, fname,moveTransferSyntax );
			//}
		// }
		
		
		
	}

	//read file to get SOPClass and SOPInstanceUIDs
	
	
	
	
	 
	 return cond;
	//return DcmQROsiriXDatabaseError;
}

OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::startMoveRequest(
        const char      *SOPClassUID,
        DcmDataset      *moveRequestIdentifiers,
        DcmQueryRetrieveDatabaseStatus  *status)
{
	DB_SmallDcmElmt     elem ;
    DB_ElementList      *plist = NULL;
    DB_ElementList      *last = NULL;
    int                 MatchFound ;
    IdxRecord           idxRec ;
    DB_LEVEL            qLevel = PATIENT_LEVEL; // highest legal level for a query in the current model
    DB_LEVEL            lLevel = IMAGE_LEVEL;   // lowest legal level for a query in the current model

    OFCondition         cond = EC_Normal;
    OFBool qrLevelFound = OFFalse;


	NSLog(@"start move request");
    /**** Is SOPClassUID supported ?
    ***/
//we only support study root currently
    // handle->rootLevel = PATIENT_ROOT ;
	if (strcmp(SOPClassUID, UID_MOVEStudyRootQueryRetrieveInformationModel) == 0)
        handle->rootLevel = STUDY_ROOT ;

	#ifndef NO_GET_SUPPORT
	//    else if (strcmp( SOPClassUID, UID_GETStudyRootQueryRetrieveInformationModel) == 0)
    //    handle->rootLevel = STUDY_ROOT ;
	#endif
	    else {
        status->setStatus(STATUS_MOVE_Failed_SOPClassNotSupported);
        return (DcmQROsiriXDatabaseError) ;
    }
	
	    /**** Parse Identifiers in the Dicom Object
    **** Find Query Level and contruct a list
    **** of query identifiers
    ***/

    int elemCount = (int)(moveRequestIdentifiers->card());
    for (int elemIndex=0; elemIndex<elemCount; elemIndex++) {

        DcmElement* dcelem = moveRequestIdentifiers->getElement(elemIndex);

        elem.XTag = dcelem->getTag().getXTag();
        if (elem.XTag == DCM_QueryRetrieveLevel || DB_TagSupported(elem.XTag)) {
            elem.ValueLength = dcelem->getLength();
            if (elem.ValueLength == 0) {
                elem.PValueField = NULL ;
            } else if ((elem.PValueField = (char*)malloc((size_t)(elem.ValueLength+1))) == NULL) {
                status->setStatus(STATUS_FIND_Refused_OutOfResources);
                return (DcmQROsiriXDatabaseError) ;
            } else {
                /* only char string type tags are supported at the moment */
                char *s = NULL;
                dcelem->getString(s);
                strcpy(elem.PValueField, s);
            }
            /** If element is the Query Level, store it in handle
             */

            if (elem. XTag == DCM_QueryRetrieveLevel) {
                char *pc ;
                char level [50] ;

                strncpy(level, (char*)elem.PValueField,
                        (elem.ValueLength<50)? (size_t)(elem.ValueLength) : 49) ;

                /*** Skip this two lines if you want strict comparison
                **/

                for (pc = level ; *pc ; pc++)
                    *pc = ((*pc >= 'a') && (*pc <= 'z')) ? 'A' - 'a' + *pc : *pc ;

                if (strncmp (level, PATIENT_LEVEL_STRING,
                             strlen (PATIENT_LEVEL_STRING)) == 0)
                    handle->queryLevel = PATIENT_LEVEL ;
                else if (strncmp (level, STUDY_LEVEL_STRING,
                                  strlen (STUDY_LEVEL_STRING)) == 0)
                    handle->queryLevel = STUDY_LEVEL ;
                else if (strncmp (level, SERIE_LEVEL_STRING,
                                  strlen (SERIE_LEVEL_STRING)) == 0)
                    handle->queryLevel = SERIE_LEVEL ;
                else if (strncmp (level, IMAGE_LEVEL_STRING,
                                  strlen (IMAGE_LEVEL_STRING)) == 0)
                    handle->queryLevel = IMAGE_LEVEL ;
                else {
                    if (elem. PValueField)
                        free (elem. PValueField) ;
#ifdef DEBUG
                    dbdebug(1, "DB_startFindRequest () : Illegal query level (%s)\n", level) ;
#endif
                    status->setStatus(STATUS_FIND_Failed_UnableToProcess);
                    return (DcmQROsiriXDatabaseError) ;
                }
                qrLevelFound = OFTrue;
				
            } 
			/*
			else {
                // Else it is a query identifier.
                // Append it to our RequestList if it is supported
                // Not sure we need this either
                if (DB_TagSupported (elem. XTag)) {

                    plist = (DB_ElementList *) malloc (sizeof (DB_ElementList)) ;
                    if (plist == NULL) {
                        status->setStatus(STATUS_FIND_Refused_OutOfResources);
                        return (DcmQROsiriXDatabaseError) ;
                    }
                    plist->next = NULL ;
                    DB_DuplicateElement (&elem, &(plist->elem)) ;
                    if (handle->findRequestList == NULL) {
                        handle->findRequestList = last = plist ;
                    } else {
                        last->next = plist ;
                        last = plist ;
                    }
                }
            }
			*/	
            if ( elem. PValueField ) {
                free (elem. PValueField) ;
            }
        }
    }

    if (!qrLevelFound) {
        /* The Query/Retrieve Level is missing */
        status->setStatus(STATUS_FIND_Failed_IdentifierDoesNotMatchSOPClass);
        CERR << "DB_startFindRequest(): missing Query/Retrieve Level" << endl;
        //handle->idxCounter = -1 ;
        DB_FreeElementList (handle->findRequestList) ;
        handle->findRequestList = NULL ;
        return (DcmQROsiriXDatabaseError) ;
    }
	
	    switch (handle->rootLevel)
    {
      case PATIENT_ROOT :
        qLevel = PATIENT_LEVEL ;
        lLevel = IMAGE_LEVEL ;
        break ;
      case STUDY_ROOT :
        qLevel = STUDY_LEVEL ;
        lLevel = IMAGE_LEVEL ;
        break ;
      case PATIENT_STUDY:
        qLevel = PATIENT_LEVEL ;
        lLevel = STUDY_LEVEL ;
        break ;
    }
	
		/**** Then find the first matching image
    ***/
	
	// Search Core Data here
	NSLog(@"search core data for move");
	cond = [handle->dataHandler prepareMoveForDataSet:moveRequestIdentifiers];
	handle->NumberRemainOperations = [handle->dataHandler moveMatchFound];
	NSLog(@"NumberRemainOperations: %d", [handle->dataHandler moveMatchFound]);
	
	 /**** If an error occured in Matching function
    ****    return a failed status
    ***/
	
	    if ( handle->NumberRemainOperations > 0 ) {
#ifdef DEBUG
        dbdebug(1,"DB_startMoveRequest : STATUS_Pending\n") ;
#endif
        status->setStatus(STATUS_Pending);
        return (EC_Normal) ;
    }

    /**** else no matching image has been found,
    ****    free query identifiers list
    ****    status is success
    ***/

    else {
        //handle->idxCounter = -1 ;
#ifdef DEBUG
        dbdebug(1,"DB_startMoveRequest : STATUS_Success\n") ;
#endif
        status->setStatus(STATUS_Success);

        return (EC_Normal) ;
    }


}

OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::cancelMoveRequest (DcmQueryRetrieveDatabaseStatus *status)
{
	return DcmQROsiriXDatabaseError;
}



/***********************
 *      Creates a handle
 */

DcmQueryRetrieveOsiriXDatabaseHandle::DcmQueryRetrieveOsiriXDatabaseHandle(
    const char *callingAET,
    OFCondition& result)
:handle(NULL)
, quotaSystemEnabled(OFFalse)
, doCheckFindIdentifier(OFFalse)
, doCheckMoveIdentifier(OFFalse)
, fnamecreator()
, debugLevel(0)
{
	
    handle = (DB_OsiriX_Handle *) malloc ( sizeof(DB_OsiriX_Handle) );

#ifdef DEBUG
   // dbdebug(1, "DB_createHandle () : Handle created for %s\n",storageArea);
   // dbdebug(1, "                     maxStudiesPerStorageArea: %ld maxBytesPerStudy: %ld\n",
  //          maxStudiesPerStorageArea, maxBytesPerStudy);
#endif

    if (handle) {
		strcpy((char *)(handle -> callingAET), callingAET);
		handle -> findRequestList = NULL;
		handle -> findResponseList = NULL;
		handle -> uidList = NULL;
		result = EC_Normal;
		handle -> dataHandler = [[OsiriXSCPDataHandler requestDataHandlerWithDestinationFolder:nil debugLevel:0] retain];
		handle -> logEntry = NULL;
		handle -> imageCount = 0;
	}
	else
		result = DcmQROsiriXDatabaseError;

	return;
}

/***********************
 *      Destroys a handle
 */

DcmQueryRetrieveOsiriXDatabaseHandle::~DcmQueryRetrieveOsiriXDatabaseHandle()
{
    int closeresult;

    if (handle)
    {
		// set logEntry to complete
		NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	   if (handle->logEntry != NULL) {
			NSMutableDictionary *logEntry = handle->logEntry;
		   [logEntry  setObject:@"Complete" forKey:@"message"];
		   [logEntry  setObject:[NSDate date] forKey:@"endTime"];
			NSString *path = [[[LogManager currentLogManager] logFolder]
				stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.plist",[logEntry objectForKey:@"uid"]]];
			[logEntry writeToFile:path atomically:YES];
		   [logEntry release];
		}

      /* Free lists */
      DB_FreeElementList (handle -> findRequestList);
      DB_FreeElementList (handle -> findResponseList);
      DB_FreeUidList (handle -> uidList);
	  [handle -> dataHandler release];
      free ( (char *)(handle) );
	  [pool release];
    }
}

/**********************************
 *      Provides a storage filename
 *********************************/

OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::makeNewStoreFileName(
                const char      *SOPClassUID,
                const char      * /* SOPInstanceUID */ ,
                char            *newImageFileName)
{	
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	NSString *dstFolder = [[[BrowserController currentBrowser] documentsDirectory] stringByAppendingPathComponent:@"INCOMING"];
    OFString filename;
    char prefix[12];

    const char *m = dcmSOPClassUIDToModality(SOPClassUID);
    if (m==NULL) m = "XX";
    sprintf(prefix, "%s_", m);
    // unsigned int seed = fnamecreator.hashString(SOPInstanceUID);
    unsigned int seed = (unsigned int)time(NULL);
    newImageFileName[0]=0; // return empty string in case of error
//   if (! fnamecreator.makeFilename(seed, handle->storageArea, prefix, ".dcm", filename)) return DcmQROsiriXDatabaseError;
	if (! fnamecreator.makeFilename(seed, [dstFolder UTF8String], prefix, ".dcm", filename)) return DcmQROsiriXDatabaseError;
	printf("newFileName: %s", filename.c_str());
    strcpy(newImageFileName, filename.c_str());
	[pool release];
    return EC_Normal;
}

OFCondition DcmQueryRetrieveOsiriXDatabaseHandle::storeRequest(
      const char *SOPClassUID,
      const char *SOPInstanceUID,
      const char *imageFileName,
      DcmQueryRetrieveDatabaseStatus  *status,
      OFBool     isNew){
	  
 return EC_Normal;
}

/* ========================= UTILS ========================= */


const char *DcmQueryRetrieveOsiriXDatabaseHandle::getStorageArea() const
{
  return handle->storageArea;
}
/*
const char *DcmQueryRetrieveOsiriXDatabaseHandle::getIndexFilename() const
{
  return handle->indexFilename;
}
*/

void DcmQueryRetrieveOsiriXDatabaseHandle::setDebugLevel(int dLevel)
{
    debugLevel = dLevel;
}

int DcmQueryRetrieveOsiriXDatabaseHandle::getDebugLevel() const
{
    return debugLevel;
}

void DcmQueryRetrieveOsiriXDatabaseHandle::dbdebug(int level, const char* format, ...) const
{
    va_list ap;
    char buf[4096]; /* we hope a message never gets larger */

    if (level <= debugLevel) {
        CERR << "DB:";
        va_start(ap, format);
        vsprintf(buf, format, ap);
        va_end(ap);
        CERR << buf << endl;
    }
}


void DcmQueryRetrieveOsiriXDatabaseHandle::setIdentifierChecking(OFBool checkFind, OFBool checkMove)
{
    doCheckFindIdentifier = checkFind;
    doCheckMoveIdentifier = checkMove;
}





/**************************************
	Handle Factory
***************************************/

DcmQueryRetrieveOsiriXDatabaseHandleFactory::DcmQueryRetrieveOsiriXDatabaseHandleFactory()
: DcmQueryRetrieveDatabaseHandleFactory()

{
}

DcmQueryRetrieveOsiriXDatabaseHandleFactory::~DcmQueryRetrieveOsiriXDatabaseHandleFactory()
{
}

DcmQueryRetrieveDatabaseHandle *DcmQueryRetrieveOsiriXDatabaseHandleFactory::createDBHandle(
    const char * callingAETitle,
    const char *calledAETitle,
    OFCondition& result) const
{
  return new DcmQueryRetrieveOsiriXDatabaseHandle(
    callingAETitle, result);
}





