Here follows the git log of the commits done to the DCMTK source in the OsiriX repository. Commits that have already been merged are ~~deleted~~. Also refer to the [original history](https://github.com/aglv/Horos/commits/83026738b2e18b106441597ecc06907293288d7f/Binaries/dcmtk-source) and [merged history](https://github.com/aglv/DCMTK/commits/66911c1d3f25b21b0a694c7a7656c7f8126d6266). Notice that original SVN commit IDs and author information were removed here.

The final purpose is to have a standalone version of a more recent DCMTK, that includes all the features that were introduced in the OsiriX fork.

##### ~~commit [02ad09228e81b0a3bda62755c24711cbbe8e0590](https://github.com/aglv/Horos/commit/02ad09228e81b0a3bda62755c24711cbbe8e0590)~~
Date:   Thu Mar 2 09:04:46 2006 +0000

First Import

> Comments, includes. Skipped.

##### ~~commit [251578f1cfb238c6f812367ba54bd1427658b9a6](https://github.com/aglv/Horos/commit/251578f1cfb238c6f812367ba54bd1427658b9a6)~~
Date:   Sat Mar 18 00:02:08 2006 +0000

Added dcmqrcnf.mm

> Comments, initConfigStruct() applicationTitle_ change from "CTN" to "OSIRIX". skipped.

##### commit [9034e45d2aa8910b6be8be3fca42fae051abf211](https://github.com/aglv/Horos/commit/9034e45d2aa8910b6be8be3fca42fae051abf211)
Date:   Sat Mar 18 00:11:31 2006 +0000

Prelim dcmtk Q?R work


##### commit [e9d03358049969f2dc84da99500043fc9d5c232c](https://github.com/aglv/Horos/commit/e9d03358049969f2dc84da99500043fc9d5c232c)
Date:   Sat Mar 18 20:12:38 2006 +0000

Added more transfer Syntaxes for Q/R


##### commit [f6fb8c5a0433a3b142e5cbfcf8859bc6dde04562](https://github.com/aglv/Horos/commit/f6fb8c5a0433a3b142e5cbfcf8859bc6dde04562)
Date:   Sat Mar 18 23:31:27 2006 +0000

Removed some dcmtk specific Q/R  restrictions



##### commit [f84dbb8e2fdc0308f6e45e4880e7474a2c214ac4](https://github.com/aglv/Horos/commit/f84dbb8e2fdc0308f6e45e4880e7474a2c214ac4)
Date:   Sun Mar 19 17:30:19 2006 +0000

Added dcmqrdbq -- DB Handle between core data and dcmtk Q/R scp


##### commit [586ef58f76bea69299107af9edc5df7532e0f06f](https://github.com/aglv/Horos/commit/586ef58f76bea69299107af9edc5df7532e0f06f)
Date:   Tue Mar 21 23:49:25 2006 +0000

Q/R work


##### commit [c3eb4c8bfb7560d343069cd9342079b8a3646385](https://github.com/aglv/Horos/commit/c3eb4c8bfb7560d343069cd9342079b8a3646385)
Date:   Wed Mar 22 23:45:58 2006 +0000

Fixed JPEG warnings.  Testing built in dcmtk server without Q/R -- very alpha


##### commit [16d34c3bd3bfc49459ee2e9dc00752c79f7af7ee](https://github.com/aglv/Horos/commit/16d34c3bd3bfc49459ee2e9dc00752c79f7af7ee)
Date:   Thu Mar 23 23:34:54 2006 +0000

Built in DCMTK Q/R server working for echo and storeSCP.  Working on FindSCP and MoveSCP


##### commit [e9321db36b3e0656b9d71b1ab2f0441bcf7bbebe](https://github.com/aglv/Horos/commit/e9321db36b3e0656b9d71b1ab2f0441bcf7bbebe)
Date:   Fri Mar 24 14:54:13 2006 +0000

Added storescp.mm


##### commit [30f93de5c1ad7e911dcc0bed7e823199b36edb0e](https://github.com/aglv/Horos/commit/30f93de5c1ad7e911dcc0bed7e823199b36edb0e)
Date:   Wed Mar 29 04:43:23 2006 +0000

dcmtk - core data q/r interface work


##### commit [c8587b577775f20c71540257f3c6ff476fb3a844](https://github.com/aglv/Horos/commit/c8587b577775f20c71540257f3c6ff476fb3a844)
Date:   Thu Mar 30 04:12:08 2006 +0000

More Q/R Work


##### commit [037fbc2d6fc265799fc72b089436b5631c9f21bb](https://github.com/aglv/Horos/commit/037fbc2d6fc265799fc72b089436b5631c9f21bb)
Date:   Sun Apr 2 04:37:23 2006 +0000

Query working.  Testing Move


##### commit [1a984e667ec41250e22288822b9ccbe858aed3ad](https://github.com/aglv/Horos/commit/1a984e667ec41250e22288822b9ccbe858aed3ad)
Date:   Sun Apr 2 21:48:04 2006 +0000

debugging dcmtk move


##### commit [85b217b8fe22a718fcc4043f157947ad0a42d7da](https://github.com/aglv/Horos/commit/85b217b8fe22a718fcc4043f157947ad0a42d7da)
Date:   Mon Apr 3 03:42:33 2006 +0000

More dcmtk move debugging. appears to work if there is no transferSyntax conversion to be done


##### commit [c2c41843b9004e5610f4861ce41a9cbd2cc464f4](https://github.com/aglv/Horos/commit/c2c41843b9004e5610f4861ce41a9cbd2cc464f4)
Date:   Mon Apr 3 22:36:52 2006 +0000

dcmtk movescp working


##### commit [560af75e2b17174f24a999ab35518bee205b431d](https://github.com/aglv/Horos/commit/560af75e2b17174f24a999ab35518bee205b431d)
Date:   Fri Apr 14 03:25:04 2006 +0000

Added to logEntry to dataHander structure


##### commit [ef047499b5488c7820a998ebb67cc5ca4707d65b](https://github.com/aglv/Horos/commit/ef047499b5488c7820a998ebb67cc5ca4707d65b)
Date:   Mon Apr 17 22:44:22 2006 +0000

Fixed bug in qr scp with retrieving using bonjour. Fixed Send bug,


##### commit [7101270fe3abec3dc9eb892558dc7bd9a20c13c0](https://github.com/aglv/Horos/commit/7101270fe3abec3dc9eb892558dc7bd9a20c13c0)
Date:   Tue Apr 18 02:56:02 2006 +0000

Adding logging to storescp portion of qrscp


##### commit [409b2a19da6cd2340e7bd2d104522d89594cdb51](https://github.com/aglv/Horos/commit/409b2a19da6cd2340e7bd2d104522d89594cdb51)
Date:   Tue Apr 18 08:22:41 2006 +0000

listener bug


##### commit [cd7fac9a69c2e92dc07b37d85b9012ae5abfc36e](https://github.com/aglv/Horos/commit/cd7fac9a69c2e92dc07b37d85b9012ae5abfc36e)
Date:   Tue Apr 18 08:25:27 2006 +0000

listener bug


##### commit [c6f190e8d39025c17225e6c510ffeda21ddb3229](https://github.com/aglv/Horos/commit/c6f190e8d39025c17225e6c510ffeda21ddb3229)
Date:   Wed Apr 19 21:59:37 2006 +0000

Removing store SCP logging for now


##### commit [7dbd993e2077a0689c332f714a5201022bd1c3ef](https://github.com/aglv/Horos/commit/7dbd993e2077a0689c332f714a5201022bd1c3ef)
Date:   Thu Apr 20 02:37:51 2006 +0000

imageCount removed


##### commit [35a1864e3480da17bee4ff2fe2594ece121f6298](https://github.com/aglv/Horos/commit/35a1864e3480da17bee4ff2fe2594ece121f6298)
Date:   Thu Apr 20 22:26:41 2006 +0000

Stubs for logEntryies


##### commit [a805016d9d4d8d7b2f009d0bf545cfa23fda6b9b](https://github.com/aglv/Horos/commit/a805016d9d4d8d7b2f009d0bf545cfa23fda6b9b)
Date:   Fri Apr 21 22:36:03 2006 +0000

Move logging working. Still problems with storeSCP logging.


##### commit [686a8ce64e017382e66391ea936b3719faf3a670](https://github.com/aglv/Horos/commit/686a8ce64e017382e66391ea936b3719faf3a670)
Date:   Fri Apr 21 22:55:28 2006 +0000

MOve log fix


##### commit [d951f036b043e170afce3c2e0c1555d03782a2c8](https://github.com/aglv/Horos/commit/d951f036b043e170afce3c2e0c1555d03782a2c8)
Date:   Sat Apr 22 04:15:27 2006 +0000

storeSCP logging working


##### commit [cac9fde9662d726725575162357dbd724afe53cc](https://github.com/aglv/Horos/commit/cac9fde9662d726725575162357dbd724afe53cc)
Date:   Sun Apr 23 17:52:52 2006 +0000

SUV units


##### commit [e5e65eb8748995f301782e7f0b7d1ebfbda3b3d1](https://github.com/aglv/Horos/commit/e5e65eb8748995f301782e7f0b7d1ebfbda3b3d1)
Date:   Mon Apr 24 07:33:38 2006 +0000

tests


##### commit [30160dd9cec9939bb9eb5a688ca8d90cc999a621](https://github.com/aglv/Horos/commit/30160dd9cec9939bb9eb5a688ca8d90cc999a621)
Date:   Mon Apr 24 07:51:26 2006 +0000

logs tests & bugs


##### commit [09aee360a00d09f3b6fe4b20d0876310e7f90c80](https://github.com/aglv/Horos/commit/09aee360a00d09f3b6fe4b20d0876310e7f90c80)
Date:   Mon Apr 24 08:36:06 2006 +0000

Network logs option


##### commit [2761faa991dc37893088f0f95d89128e5c8b66ac](https://github.com/aglv/Horos/commit/2761faa991dc37893088f0f95d89128e5c8b66ac)
Date:   Tue May 2 17:07:03 2006 +0000

OFGlobal<OFBool> dcmEnableUnknownVRConversion(OFTrue);


##### commit [70974551c7b5acf702c249e3f97ee6d5e6edb136](https://github.com/aglv/Horos/commit/70974551c7b5acf702c249e3f97ee6d5e6edb136)
Date:   Fri May 5 20:30:07 2006 +0000

tests on storescp


##### commit [1baebe5a88b519523ccbd3f4f47c6c197b37d292](https://github.com/aglv/Horos/commit/1baebe5a88b519523ccbd3f4f47c6c197b37d292)
Date:   Fri May 5 20:42:24 2006 +0000

tests on storescp


##### commit [9a0ce93f5ef51508273be714b32165852b18b6c2](https://github.com/aglv/Horos/commit/9a0ce93f5ef51508273be714b32165852b18b6c2)
Date:   Sat May 6 22:15:11 2006 +0000

Removed some debug logging for moveSCU


##### commit [29ef889a53533821e287f843f515ac145bca4a25](https://github.com/aglv/Horos/commit/29ef889a53533821e287f843f515ac145bca4a25)
Date:   Sun May 7 16:40:03 2006 +0000

misc


##### commit [ddce1ca0483acdcc4eeb583f273c74815da4a8a3](https://github.com/aglv/Horos/commit/ddce1ca0483acdcc4eeb583f273c74815da4a8a3)
Date:   Mon May 8 13:21:31 2006 +0000

lock in listener


##### commit [65268f38ec09da5241dd844ba36c4d98e2c86187](https://github.com/aglv/Horos/commit/65268f38ec09da5241dd844ba36c4d98e2c86187)
Date:   Tue May 9 05:13:57 2006 +0000

more bugs correction


##### commit [7063f290b04d4e5936b4184567b6e06102760288](https://github.com/aglv/Horos/commit/7063f290b04d4e5936b4184567b6e06102760288)
Date:   Thu May 11 08:54:40 2006 +0000

fixed documentdirectory for dicom listener to avoid dead spinLock


##### commit [9e8ef2327591f1fa178ffb5fc66eab986aa28492](https://github.com/aglv/Horos/commit/9e8ef2327591f1fa178ffb5fc66eab986aa28492)
Date:   Thu May 11 09:11:33 2006 +0000

fixed documentdirectory for dicom listener to avoid dead spinLock


##### commit [499603ee120c9e9c55929db8436ac1e9628b0875](https://github.com/aglv/Horos/commit/499603ee120c9e9c55929db8436ac1e9628b0875)
Date:   Fri May 12 13:02:38 2006 +0000

fixed networklogs for dicom listener to avoid dead spinLock


##### commit [9884d140d84b113b05da1b3b9664921ca3a2bbd5](https://github.com/aglv/Horos/commit/9884d140d84b113b05da1b3b9664921ca3a2bbd5)
Date:   Tue May 16 14:51:25 2006 +0000

more work on spinLock & listener


##### commit [6337cc62f0c776c5b4948cc433540426a020f4e4](https://github.com/aglv/Horos/commit/6337cc62f0c776c5b4948cc433540426a020f4e4)
Date:   Tue May 16 20:04:11 2006 +0000

lock prefs


##### commit [41a9fd8168bde6deb1abaf46fb34ead2b49a2810](https://github.com/aglv/Horos/commit/41a9fd8168bde6deb1abaf46fb34ead2b49a2810)
Date:   Wed May 17 05:53:33 2006 +0000

spinlock listener


##### commit [05e6ccb82a10d0ee51fdea9a5767c40e2be84fd6](https://github.com/aglv/Horos/commit/05e6ccb82a10d0ee51fdea9a5767c40e2be84fd6)
Date:   Thu May 18 13:58:31 2006 +0000

more work on spinLock cf. fork()


##### commit [4ccd61239c3ba767208d05a39b5a2dc9e45a89ce](https://github.com/aglv/Horos/commit/4ccd61239c3ba767208d05a39b5a2dc9e45a89ce)
Date:   Thu May 18 15:25:31 2006 +0000

more work on spinLock cf. fork()


##### commit [f5bdcf60acc9388a1b15c71a12ded29041abe1d1](https://github.com/aglv/Horos/commit/f5bdcf60acc9388a1b15c71a12ded29041abe1d1)
Date:   Fri May 19 07:35:53 2006 +0000

2.4a3


##### commit [499fceead7f56ddb8ff59e4913e13fd215f7fdea](https://github.com/aglv/Horos/commit/499fceead7f56ddb8ff59e4913e13fd215f7fdea)
Date:   Tue May 23 09:55:18 2006 +0000

safe process DicomFile check


##### commit [da335df9a000fa09640ba0bfc12206e9bab08261](https://github.com/aglv/Horos/commit/da335df9a000fa09640ba0bfc12206e9bab08261)
Date:   Tue May 23 11:24:46 2006 +0000

spin lock


##### commit [f3ed66c5ab6c25ab46d0bc2aac578fefb4384d84](https://github.com/aglv/Horos/commit/f3ed66c5ab6c25ab46d0bc2aac578fefb4384d84)
Date:   Sat May 27 09:25:26 2006 +0000

font


##### commit [559348167e058c03c40a30d0caa2e836d4266bf8](https://github.com/aglv/Horos/commit/559348167e058c03c40a30d0caa2e836d4266bf8)
Date:   Mon Jul 3 21:20:26 2006 +0000

Receives compressed syntax correctly now


##### commit [cb82401c1ca62cd5d3d1362d5b261bc948951ce0](https://github.com/aglv/Horos/commit/cb82401c1ca62cd5d3d1362d5b261bc948951ce0)
Date:   Thu Jul 13 20:45:06 2006 +0000

SR key images display now.  Removed hyperlinks form html rendering for now


##### commit [1085e3bedf1a0e5c4234c5876c51074d9d1eae01](https://github.com/aglv/Horos/commit/1085e3bedf1a0e5c4234c5876c51074d9d1eae01)
Date:   Mon Jul 17 10:10:56 2006 +0000

listener bug


##### commit [83f8acb9012abab2c19302778ee494ba34e92b6c](https://github.com/aglv/Horos/commit/83f8acb9012abab2c19302778ee494ba34e92b6c)
Date:   Mon Jul 17 22:59:41 2006 +0000

Initial work for support encapsulated Syntaxes during moves


##### commit [d62ae65c3de1404ee107106e6471810321c54531](https://github.com/aglv/Horos/commit/d62ae65c3de1404ee107106e6471810321c54531)
Date:   Tue Jul 18 22:44:13 2006 +0000

More work to support encapsulated Syntaxes during moves


##### commit [aebc5903c41d727c7ddcfae7d0a7313c77df88d7](https://github.com/aglv/Horos/commit/aebc5903c41d727c7ddcfae7d0a7313c77df88d7)
Date:   Tue Jul 25 13:38:53 2006 +0000

Papy jpeg (doesnt support multi-fragments)


##### commit [a68659c169b1cc000c9ad20241d2de015a8da655](https://github.com/aglv/Horos/commit/a68659c169b1cc000c9ad20241d2de015a8da655)
Date:   Mon Aug 21 22:29:32 2006 +0000

SR Drag and drop working. Better printing


##### commit [e2c50062a0661b757455bf47c2e617b3012b6d6c](https://github.com/aglv/Horos/commit/e2c50062a0661b757455bf47c2e617b3012b6d6c)
Date:   Sat Aug 26 21:31:16 2006 +0000

64-bit - Work in progress


##### commit [65b83e837f02f52bcdc79b838b299685409804be](https://github.com/aglv/Horos/commit/65b83e837f02f52bcdc79b838b299685409804be)
Date:   Wed Aug 30 20:20:43 2006 +0000

Add private OsiriX elements to dcmtk built in dicomdict to allow storing ROIs as DICOM presentation States


##### commit [c90fa0c413510edae0477c53e4e4f4941bdf606c](https://github.com/aglv/Horos/commit/c90fa0c413510edae0477c53e4e4f4941bdf606c)
Date:   Wed Aug 30 20:33:40 2006 +0000

Add private OsiriX elements to dcmtk built in dicomdict to allow storing ROIs as DICOM presentation States


##### commit [513a805522bf4950c702cf6e398cb4538fe3bbfa](https://github.com/aglv/Horos/commit/513a805522bf4950c702cf6e398cb4538fe3bbfa)
Date:   Sun Sep 3 22:02:32 2006 +0000

64-bit


##### commit [bdde3759baafdf1e9cefe85e931992705c02cb0b](https://github.com/aglv/Horos/commit/bdde3759baafdf1e9cefe85e931992705c02cb0b)
Date:   Tue Sep 5 03:16:36 2006 +0000

Add definition for OsiriX ROI tag


##### commit [a56415bdc10bbb7cacaef1e5d5ea3d1246ff62cb](https://github.com/aglv/Horos/commit/a56415bdc10bbb7cacaef1e5d5ea3d1246ff62cb)
Date:   Tue Oct 10 12:25:47 2006 +0000

misc bugs


##### commit [95f4b8be6563380aa9acc51361d0f2d8ebd84eb9](https://github.com/aglv/Horos/commit/95f4b8be6563380aa9acc51361d0f2d8ebd84eb9)
Date:   Wed Oct 18 22:53:28 2006 +0000

Added dcmtk category for ViewerController.  Will allow ROIs to be unarchived from DICOM.  Added private ROI data to SR annotation


##### commit [a77e7c54030203cb68fa2dcfa47df0597718f9e7](https://github.com/aglv/Horos/commit/a77e7c54030203cb68fa2dcfa47df0597718f9e7)
Date:   Thu Nov 9 22:12:10 2006 +0000

jpeg bug


##### commit [cdf989065d6433c48a45d4f5ff71d535869174d2](https://github.com/aglv/Horos/commit/cdf989065d6433c48a45d4f5ff71d535869174d2)
Date:   Sat Dec 16 21:14:24 2006 +0000

ping and c-echo


##### commit [4c273015558c838116d0f9d908d706a039a7cdd3](https://github.com/aglv/Horos/commit/4c273015558c838116d0f9d908d706a039a7cdd3)
Date:   Wed Dec 20 21:21:22 2006 +0000

Bonjour DICOM nodes


##### commit [3ccd29828f17aa11f141e091b804c484d7bd5dc4](https://github.com/aglv/Horos/commit/3ccd29828f17aa11f141e091b804c484d7bd5dc4)
Date:   Fri Jan 5 18:03:29 2007 +0000

misc network


##### commit [7a31f5c76295dd42310240656e53c21deaee20e5](https://github.com/aglv/Horos/commit/7a31f5c76295dd42310240656e53c21deaee20e5)
Date:   Sun Jan 28 09:54:15 2007 +0000

post processed exception


##### commit [d49832ce49456d4cb95730a361aa480dc28200c4](https://github.com/aglv/Horos/commit/d49832ce49456d4cb95730a361aa480dc28200c4)
Date:   Tue Feb 6 17:04:49 2007 +0000

test transfer syntax


##### commit [e4268c64ca6cdb4e2a5914d740f99214b5b7101c](https://github.com/aglv/Horos/commit/e4268c64ca6cdb4e2a5914d740f99214b5b7101c)
Date:   Thu Feb 8 14:26:44 2007 +0000

tests


##### commit [318a9edd7e5753890e8080fe776b4580bcef7147](https://github.com/aglv/Horos/commit/318a9edd7e5753890e8080fe776b4580bcef7147)
Date:   Thu Feb 8 14:45:14 2007 +0000

transfer tests


##### commit [ab06f547e6915d181c15a0e469a0461f9bf1f3af](https://github.com/aglv/Horos/commit/ab06f547e6915d181c15a0e469a0461f9bf1f3af)
Date:   Thu Feb 8 16:15:57 2007 +0000

encode decode sopInstanceUID


##### commit [f2391d38426490de654e209034ba5e6ed9a88de0](https://github.com/aglv/Horos/commit/f2391d38426490de654e209034ba5e6ed9a88de0)
Date:   Fri Feb 9 21:57:10 2007 +0000

destination tests


##### commit [447a3ff08aaa28c14df22834943497a7c143d00e](https://github.com/aglv/Horos/commit/447a3ff08aaa28c14df22834943497a7c143d00e)
Date:   Thu Apr 19 12:21:39 2007 +0000

compatibilty with 9A410


##### commit [a94ac1c4b2ddef63cc21489e019be01d7c0ca2b7](https://github.com/aglv/Horos/commit/a94ac1c4b2ddef63cc21489e019be01d7c0ca2b7)
Date:   Sun May 6 20:40:17 2007 +0000

xml editor


##### commit [e56b8d988106df195a1043000fbf78eafdbb9539](https://github.com/aglv/Horos/commit/e56b8d988106df195a1043000fbf78eafdbb9539)
Date:   Tue May 8 12:09:50 2007 +0000

dcmodify


##### commit [196d1f2b2d2b3e226513e86c9576ef83f6bf201e](https://github.com/aglv/Horos/commit/196d1f2b2d2b3e226513e86c9576ef83f6bf201e)
Date:   Thu Jun 21 21:08:28 2007 +0000

pet ct auto fuse


##### commit [e85e2467dcf304c1c6f4e22e6cd02bcf02de2a58](https://github.com/aglv/Horos/commit/e85e2467dcf304c1c6f4e22e6cd02bcf02de2a58)
Date:   Sun Jun 24 14:07:02 2007 +0000

quicklook


##### commit [e91ed077a9c6abde935bca4c14ae385deca6b4c8](https://github.com/aglv/Horos/commit/e91ed077a9c6abde935bca4c14ae385deca6b4c8)
Date:   Mon Jul 30 15:22:05 2007 +0000

new web site address


##### commit [5bf0a6e78efecde1cdf5c0e66fe9ce7006de6ca5](https://github.com/aglv/Horos/commit/5bf0a6e78efecde1cdf5c0e66fe9ce7006de6ca5)
Date:   Tue Jul 31 07:24:22 2007 +0000

pref pane for custom image annotations


##### commit [378754c77ee010ff28e682d6731d76d0e92e382a](https://github.com/aglv/Horos/commit/378754c77ee010ff28e682d6731d76d0e92e382a)
Date:   Sat Aug 4 18:01:31 2007 +0000

listener active session


##### commit [fd1caa1c0580cb27b2ebc792d1748ac070b43aa5](https://github.com/aglv/Horos/commit/fd1caa1c0580cb27b2ebc792d1748ac070b43aa5)
Date:   Sat Aug 4 18:22:38 2007 +0000

listener active session


##### commit [1fd0e5175f3221aaa6904ffa72be0fad732ce4be](https://github.com/aglv/Horos/commit/1fd0e5175f3221aaa6904ffa72be0fad732ce4be)
Date:   Thu Aug 30 21:10:07 2007 +0000

misc


##### commit [fda0b7586dc86de221991ee1a1dc4e354e5d4ca1](https://github.com/aglv/Horos/commit/fda0b7586dc86de221991ee1a1dc4e354e5d4ca1)
Date:   Wed Sep 19 16:13:55 2007 +0000

more associations


##### commit [ad53bf7805c3230d321c672d2179114d24de72e2](https://github.com/aglv/Horos/commit/ad53bf7805c3230d321c672d2179114d24de72e2)
Date:   Fri Sep 21 08:37:41 2007 +0000

MPEG2 transfersyntax


##### commit [68de3ae45b2a6f73e3e524a5b0c6706f71ebce99](https://github.com/aglv/Horos/commit/68de3ae45b2a6f73e3e524a5b0c6706f71ebce99)
Date:   Tue Oct 9 19:21:30 2007 +0000

cmove xml-rpc


##### commit [3143ac94a72682644c14d285b27e2f56c04cc5e1](https://github.com/aglv/Horos/commit/3143ac94a72682644c14d285b27e2f56c04cc5e1)
Date:   Wed Oct 10 20:36:13 2007 +0000

logs : move


##### commit [8279d08a90c20e939cb44f2b41f3f4554b9d7dbb](https://github.com/aglv/Horos/commit/8279d08a90c20e939cb44f2b41f3f4554b9d7dbb)
Date:   Thu Nov 8 06:49:15 2007 +0000

listener test


##### commit [42260878328aa105c50d1356336a4411ae11ad32](https://github.com/aglv/Horos/commit/42260878328aa105c50d1356336a4411ae11ad32)
Date:   Thu Nov 8 10:21:09 2007 +0000

dicom store-scu scp


##### commit [4cbfd92364362445a59855a8c4e66d38a1781b60](https://github.com/aglv/Horos/commit/4cbfd92364362445a59855a8c4e66d38a1781b60)
Date:   Thu Nov 8 20:02:23 2007 +0000

send/receive


##### commit [ae6e1bbc06950d6b433063a06db0ba74f56791d6](https://github.com/aglv/Horos/commit/ae6e1bbc06950d6b433063a06db0ba74f56791d6)
Date:   Thu Nov 15 21:32:43 2007 +0000

US Retired


##### commit [5b900559a8542a9a237782f39191b7e4baf93ca2](https://github.com/aglv/Horos/commit/5b900559a8542a9a237782f39191b7e4baf93ca2)
Date:   Sat Nov 17 06:57:11 2007 +0000

misc network


##### commit [d3f863726e37cfc4630d219cda81ce60967034e9](https://github.com/aglv/Horos/commit/d3f863726e37cfc4630d219cda81ce60967034e9)
Date:   Sun Nov 18 20:45:08 2007 +0000

tests, T1 T2


##### commit [fefba8877a3c3c0614bd6a25968de784832b58a5](https://github.com/aglv/Horos/commit/fefba8877a3c3c0614bd6a25968de784832b58a5)
Date:   Sun Nov 18 20:45:58 2007 +0000

tests, T1 T2


##### commit [456060b8f06f619f228cbc420f8c54e3806df40a](https://github.com/aglv/Horos/commit/456060b8f06f619f228cbc420f8c54e3806df40a)
Date:   Mon Dec 10 09:51:28 2007 +0000

unsigned long -> unsigned int


##### commit [132a0e22390d539ca0ecf949790983e5092ede79](https://github.com/aglv/Horos/commit/132a0e22390d539ca0ecf949790983e5092ede79)
Date:   Mon Dec 10 10:25:47 2007 +0000

signed long -> signed int


##### commit [f7e95e37665874377aa95d66f196da4ff6934367](https://github.com/aglv/Horos/commit/f7e95e37665874377aa95d66f196da4ff6934367)
Date:   Wed Dec 12 06:17:20 2007 +0000

fork tests


##### commit [9780e16722948b92302cd5641dd18c5c27f141c0](https://github.com/aglv/Horos/commit/9780e16722948b92302cd5641dd18c5c27f141c0)
Date:   Wed Dec 12 06:18:05 2007 +0000

fork tests


##### commit [abbc8ea33affea5bdf7114a7421e10b36c4f645f](https://github.com/aglv/Horos/commit/abbc8ea33affea5bdf7114a7421e10b36c4f645f)
Date:   Wed Dec 12 09:21:16 2007 +0000

fork find


##### commit [ea801b50e9088a6dfd33e17f8b97ee5046757ef1](https://github.com/aglv/Horos/commit/ea801b50e9088a6dfd33e17f8b97ee5046757ef1)
Date:   Wed Dec 12 15:21:58 2007 +0000

more protections against deadlock - fork()


##### commit [8fc22863b8bd04fec0d818fe25fd223ae6f7d6b8](https://github.com/aglv/Horos/commit/8fc22863b8bd04fec0d818fe25fd223ae6f7d6b8)
Date:   Thu Dec 13 08:39:08 2007 +0000

misc options


##### commit [abfba354528c85e61f88bfe664622d18aef37597](https://github.com/aglv/Horos/commit/abfba354528c85e61f88bfe664622d18aef37597)
Date:   Tue Dec 18 08:15:49 2007 +0000

messages


##### commit [4f51f350be97b1fb968e705ddd749539687d666f](https://github.com/aglv/Horos/commit/4f51f350be97b1fb968e705ddd749539687d666f)
Date:   Mon Jan 28 08:27:51 2008 +0000

log bug fixed


##### commit [b25a279485503d7c9c5e1bfce5dc5adb928c5a22](https://github.com/aglv/Horos/commit/b25a279485503d7c9c5e1bfce5dc5adb928c5a22)
Date:   Mon Jan 28 08:39:36 2008 +0000

log bug fixed


##### commit [7f2ccfca41b78140913bad1a69a9c6e482b67655](https://github.com/aglv/Horos/commit/7f2ccfca41b78140913bad1a69a9c6e482b67655)
Date:   Mon Jan 28 08:46:24 2008 +0000

log bug fixed


##### commit [5438ef936e0e753bd65ec632574a26044ab8951e](https://github.com/aglv/Horos/commit/5438ef936e0e753bd65ec632574a26044ab8951e)
Date:   Mon Jan 28 10:16:34 2008 +0000

log bug fixed: encoding


##### commit [e4b6dd067a96b3d07dd644e2314fb7acd47f7928](https://github.com/aglv/Horos/commit/e4b6dd067a96b3d07dd644e2314fb7acd47f7928)
Date:   Mon Feb 18 16:09:36 2008 +0000

misc


##### commit [6a839b399a50122b1365e7bf81401b0b6d8b6774](https://github.com/aglv/Horos/commit/6a839b399a50122b1365e7bf81401b0b6d8b6774)
Date:   Tue Feb 19 18:10:56 2008 +0000

no syncDICOMNodes if forked


##### commit [bd49425f7aa12fc7758c05f646becf72f7df870b](https://github.com/aglv/Horos/commit/bd49425f7aa12fc7758c05f646becf72f7df870b)
Date:   Wed Feb 20 06:39:27 2008 +0000

cached servers


##### commit [a3aa64d2a9bd9043c51c542fccead92e93649e02](https://github.com/aglv/Horos/commit/a3aa64d2a9bd9043c51c542fccead92e93649e02)
Date:   Thu Mar 27 08:59:43 2008 +0000

log window


##### commit [52a9288cbd83062b948959b60b039b06cdb7d177](https://github.com/aglv/Horos/commit/52a9288cbd83062b948959b60b039b06cdb7d177)
Date:   Thu Mar 27 10:29:37 2008 +0000

better random


##### commit [0e7a17af1b308fd8a7f21f8ab7f8ef6c671fb083](https://github.com/aglv/Horos/commit/0e7a17af1b308fd8a7f21f8ab7f8ef6c671fb083)
Date:   Sat Mar 29 17:54:25 2008 +0000

memory leaks...


##### commit [9035a94362724482f9c0096dcdf15a48e3a93048](https://github.com/aglv/Horos/commit/9035a94362724482f9c0096dcdf15a48e3a93048)
Date:   Sun Apr 27 20:26:41 2008 +0000

TS QR


##### commit [558c3c6ca1af1229e8a34386daa322fc1815ce3b](https://github.com/aglv/Horos/commit/558c3c6ca1af1229e8a34386daa322fc1815ce3b)
Date:   Mon Apr 28 09:37:58 2008 +0000

preferred syntax for retrieve


##### commit [49c3ae11fbc7331478d9d676803aba50966b9d56](https://github.com/aglv/Horos/commit/49c3ae11fbc7331478d9d676803aba50966b9d56)
Date:   Mon Apr 28 14:56:38 2008 +0000

compression tests


##### commit [712873550250bfc325c4eb9a28e3a1d208c1940f](https://github.com/aglv/Horos/commit/712873550250bfc325c4eb9a28e3a1d208c1940f)
Date:   Mon Apr 28 14:57:17 2008 +0000

compression tests


##### commit [7759002ef2ef87c2367727030ae2c4cfc83ae143](https://github.com/aglv/Horos/commit/7759002ef2ef87c2367727030ae2c4cfc83ae143)
Date:   Mon Apr 28 19:13:21 2008 +0000

update dicom node


##### commit [e33294b7257de88643e98d807789e69862654623](https://github.com/aglv/Horos/commit/e33294b7257de88643e98d807789e69862654623)
Date:   Thu May 1 16:13:01 2008 +0000

misc DICOM SR


##### commit [cd27619c88c16ed414f698e70a6d1612b0fcbb5e](https://github.com/aglv/Horos/commit/cd27619c88c16ed414f698e70a6d1612b0fcbb5e)
Date:   Thu Jun 12 08:30:59 2008 +0000

mark ROIs - NONBLOCKING


##### commit [cdd6595a5abc78c2e50c00157365b0ac04e311b1](https://github.com/aglv/Horos/commit/cdd6595a5abc78c2e50c00157365b0ac04e311b1)
Date:   Thu Jun 12 10:10:44 2008 +0000

DIMSE BLOCKING


##### commit [2035d148f1931a22680b6bde6ab904ca17e8a625](https://github.com/aglv/Horos/commit/2035d148f1931a22680b6bde6ab904ca17e8a625)
Date:   Thu Jun 12 15:19:31 2008 +0000

blocking mode for C-Find C-Retrieve


##### commit [545ee886a9018ae515534fcd015134b2c0fc0b03](https://github.com/aglv/Horos/commit/545ee886a9018ae515534fcd015134b2c0fc0b03)
Date:   Thu Jun 12 20:05:15 2008 +0000

DIMSE tests


##### commit [088bda029adf9f462bf568a509f9017b279235fb](https://github.com/aglv/Horos/commit/088bda029adf9f462bf568a509f9017b279235fb)
Date:   Fri Jul 11 22:26:21 2008 +0000

log move


##### commit [c5c2e1d98a4ff2a5b501c7c69dc47533a77b7119](https://github.com/aglv/Horos/commit/c5c2e1d98a4ff2a5b501c7c69dc47533a77b7119)
Date:   Tue Aug 12 21:32:31 2008 +0000

Q&R


##### commit [be28bdba5427fa97635f9c52aa8acb7d2fe5e05e](https://github.com/aglv/Horos/commit/be28bdba5427fa97635f9c52aa8acb7d2fe5e05e)
Date:   Tue Aug 12 21:37:46 2008 +0000

Q&R


##### commit [5566710956e25e9a11b34d25ee1288bea9f4d34c](https://github.com/aglv/Horos/commit/5566710956e25e9a11b34d25ee1288bea9f4d34c)
Date:   Wed Aug 13 06:59:39 2008 +0000

Q&R


##### commit [30e57b671327de48a81c4fc6e84b6e29ed458599](https://github.com/aglv/Horos/commit/30e57b671327de48a81c4fc6e84b6e29ed458599)
Date:   Wed Aug 13 07:05:26 2008 +0000

Q&R


##### commit [91b8b4564d550d6b20dfe2ff47d4ab693cda5152](https://github.com/aglv/Horos/commit/91b8b4564d550d6b20dfe2ff47d4ab693cda5152)
Date:   Wed Aug 13 10:31:38 2008 +0000

Q&R


##### commit [d3030d63f217c283d0a6dda1d5c0b9d9e1dddfa1](https://github.com/aglv/Horos/commit/d3030d63f217c283d0a6dda1d5c0b9d9e1dddfa1)
Date:   Wed Aug 13 11:23:38 2008 +0000

Q&R


##### commit [c2df2291a1832182e44424581321fade69466199](https://github.com/aglv/Horos/commit/c2df2291a1832182e44424581321fade69466199)
Date:   Wed Aug 13 15:30:55 2008 +0000

Q&R


##### commit [7affa762493f973e0f57d6354350262dad151c6a](https://github.com/aglv/Horos/commit/7affa762493f973e0f57d6354350262dad151c6a)
Date:   Wed Aug 13 15:40:47 2008 +0000

Q/R


##### commit [96bba4656fd4c9e498bcc0e597f0dc9449923502](https://github.com/aglv/Horos/commit/96bba4656fd4c9e498bcc0e597f0dc9449923502)
Date:   Wed Aug 13 15:56:42 2008 +0000

Q&R


##### commit [3af6c1e1f5f8271d7c428f62d1fa1f44130f4c31](https://github.com/aglv/Horos/commit/3af6c1e1f5f8271d7c428f62d1fa1f44130f4c31)
Date:   Sun Aug 17 19:42:55 2008 +0000

qr log


##### commit [a0e968cc2dc1f382e00ebd05e0fd3a54b07eb9c1](https://github.com/aglv/Horos/commit/a0e968cc2dc1f382e00ebd05e0fd3a54b07eb9c1)
Date:   Wed Sep 10 05:34:12 2008 +0000

no index spotlight


##### commit [ae821de4056b73efe4ea640fd0595dc10e84beaa](https://github.com/aglv/Horos/commit/ae821de4056b73efe4ea640fd0595dc10e84beaa)
Date:   Sun Sep 21 22:03:18 2008 +0000

dicom offis 3.5.4 UN VR to SEQ Conv


##### commit [cfa5442fa06b30bd8ce93786e092d9b0da8ff004](https://github.com/aglv/Horos/commit/cfa5442fa06b30bd8ce93786e092d9b0da8ff004)
Date:   Sun Sep 21 22:08:27 2008 +0000

UN SQ


##### commit [575ac1de51caa9f3a6f415c2633ce22e93b5784c](https://github.com/aglv/Horos/commit/575ac1de51caa9f3a6f415c2633ce22e93b5784c)
Date:   Sun Sep 21 22:12:45 2008 +0000

UN SQ


##### commit [0cf09e50ad231c3121dcb193ab6701d6ab249939](https://github.com/aglv/Horos/commit/0cf09e50ad231c3121dcb193ab6701d6ab249939)
Date:   Thu Sep 25 07:01:40 2008 +0000

compression bug


##### commit [4f6b7f1ddb85be38c565c5e4563cf39df8eafa93](https://github.com/aglv/Horos/commit/4f6b7f1ddb85be38c565c5e4563cf39df8eafa93)
Date:   Mon Oct 20 09:24:51 2008 +0000

more xml rpc functions


##### commit [cc68d454adcdf1ba7d2acd6d9e9f9e4845201c05](https://github.com/aglv/Horos/commit/cc68d454adcdf1ba7d2acd6d9e9f9e4845201c05)
Date:   Thu Nov 6 21:43:56 2008 +0000

lu li ld


##### commit [02814aafc27abd8578f8537980084329a3f75051](https://github.com/aglv/Horos/commit/02814aafc27abd8578f8537980084329a3f75051)
Date:   Fri Nov 7 10:52:16 2008 +0000

warnings


##### commit [1f7344f5ff8095264c4eaa13547330fc37bb8f6c](https://github.com/aglv/Horos/commit/1f7344f5ff8095264c4eaa13547330fc37bb8f6c)
Date:   Sat Nov 8 15:52:13 2008 +0000

warnings


##### commit [78c868c33c50d7283b4f640c83cf843222217f08](https://github.com/aglv/Horos/commit/78c868c33c50d7283b4f640c83cf843222217f08)
Date:   Thu Jan 29 16:59:17 2009 +0000

todo


##### commit [e94ade1ce9c5afcc6211b84efe601fe61d24db19](https://github.com/aglv/Horos/commit/e94ade1ce9c5afcc6211b84efe601fe61d24db19)
Date:   Fri Jan 30 08:43:12 2009 +0000

lock unlock file


##### commit [a725f3cbb68c0668252095bcbc9a37e8197291ed](https://github.com/aglv/Horos/commit/a725f3cbb68c0668252095bcbc9a37e8197291ed)
Date:   Fri Jan 30 13:58:00 2009 +0000

lock file


##### commit [4b0afc099c570485c008ff92d0668293dd607355](https://github.com/aglv/Horos/commit/4b0afc099c570485c008ff92d0668293dd607355)
Date:   Fri Jan 30 13:58:27 2009 +0000

lock file


##### commit [cfeb9362e096e0133ce2086c0faf66ea7258f99f](https://github.com/aglv/Horos/commit/cfeb9362e096e0133ce2086c0faf66ea7258f99f)
Date:   Sun Feb 1 17:19:17 2009 +0000

lock



##### commit [581d33e00f4f74ad6ec8b779928f4c1e20b3749d](https://github.com/aglv/Horos/commit/581d33e00f4f74ad6ec8b779928f4c1e20b3749d)
Date:   Mon Feb 2 10:22:10 2009 +0000

Q&R


##### commit [c040c6743bcd3b022dc4bae1e0de29af06d6603e](https://github.com/aglv/Horos/commit/c040c6743bcd3b022dc4bae1e0de29af06d6603e)
Date:   Mon Feb 16 07:43:17 2009 +0000

decompress: DETERMINE_OUTPUT_COLOR_SPACE_FROM_IJG_GUESS


##### commit [0e9c609095f7de8c71c09ca0ab9d3aa96be1b45e](https://github.com/aglv/Horos/commit/0e9c609095f7de8c71c09ca0ab9d3aa96be1b45e)
Date:   Mon Feb 16 15:41:33 2009 +0000

more work on c-get


##### commit [606d720e54cddcf87fd9fd3f140900d4bc087f94](https://github.com/aglv/Horos/commit/606d720e54cddcf87fd9fd3f140900d4bc087f94)
Date:   Mon Feb 16 20:39:36 2009 +0000

pid survivor


##### commit [ffdcc32ccdbf7a5a27ad1628cdcde28859827d9e](https://github.com/aglv/Horos/commit/ffdcc32ccdbf7a5a27ad1628cdcde28859827d9e)
Date:   Tue Feb 17 17:27:52 2009 +0000

error feedback mechanism for child processes


##### commit [ec00faaf36b1289b532a8a168e8f88872608ba10](https://github.com/aglv/Horos/commit/ec00faaf36b1289b532a8a168e8f88872608ba10)
Date:   Tue Feb 17 17:43:52 2009 +0000

deleting


##### commit [a83904c93c9eb60a0bfeb72652d2cecad4f0753d](https://github.com/aglv/Horos/commit/a83904c93c9eb60a0bfeb72652d2cecad4f0753d)
Date:   Mon Apr 6 15:55:32 2009 +0000

waitforassociation message in main thread


##### commit [823eda1c90f9ba78fe41cd8b491b6c629d08d4e5](https://github.com/aglv/Horos/commit/823eda1c90f9ba78fe41cd8b491b6c629d08d4e5)
Date:   Mon Apr 6 15:56:57 2009 +0000

waitforassociation message in main thread


##### commit [8b59dffba47f4e0fa1d76827cca3e7bca20d5fcd](https://github.com/aglv/Horos/commit/8b59dffba47f4e0fa1d76827cca3e7bca20d5fcd)
Date:   Sun Apr 12 15:21:44 2009 +0000

jp2000


##### commit [cfc3d618481a56b0e1ebd3ce4c996d9836e6a95d](https://github.com/aglv/Horos/commit/cfc3d618481a56b0e1ebd3ce4c996d9836e6a95d)
Date:   Thu Apr 16 08:56:12 2009 +0000

enhanced pet image storage


##### commit [bb328646850e88d4d2eba53bffa8753e30002d87](https://github.com/aglv/Horos/commit/bb328646850e88d4d2eba53bffa8753e30002d87)
Date:   Fri Apr 24 11:22:42 2009 +0000

noindex, umlaut


##### commit [1c785ace6c44b49e230d7e301b03e24096a95d48](https://github.com/aglv/Horos/commit/1c785ace6c44b49e230d7e301b03e24096a95d48)
Date:   Fri Apr 24 13:11:23 2009 +0000

umlaut log file


##### commit [a736ad38fc4274bf8bbb3f8a74b785cc2425cdf5](https://github.com/aglv/Horos/commit/a736ad38fc4274bf8bbb3f8a74b785cc2425cdf5)
Date:   Wed May 27 11:00:35 2009 +0000

exception protection for ChangeImageData (ViewerController), parameters for number of files (checkincoming, sub folder in DB), todo list update


##### commit [e3bcf807e8d8cceb2fd9fc5725865404cf46eda2](https://github.com/aglv/Horos/commit/e3bcf807e8d8cceb2fd9fc5725865404cf46eda2)
Date:   Thu May 28 09:17:57 2009 +0000

C-FIND SQL Query optimizations for multiple modalities


##### commit [0e5d5610aee13ce9e6d9e6b067dce0a224b0c947](https://github.com/aglv/Horos/commit/0e5d5610aee13ce9e6d9e6b067dce0a224b0c947)
Date:   Sun May 31 08:04:26 2009 +0000

New Feature: Support for C-GET SCU


##### commit [1fac8fecf1c5c6f17f19ac58c787b861d4de2e50](https://github.com/aglv/Horos/commit/1fac8fecf1c5c6f17f19ac58c787b861d4de2e50)
Date:   Sun May 31 09:28:46 2009 +0000

Better support for C-GET


##### commit [71265820178ac15a6231fd04e28a7f1f0445df62](https://github.com/aglv/Horos/commit/71265820178ac15a6231fd04e28a7f1f0445df62)
Date:   Sun May 31 09:46:53 2009 +0000

Objective-C++ for dimget.cc -> dimget.mm


##### commit [37b1ed644395f7b6b9baa0653ab10ee7d080acc8](https://github.com/aglv/Horos/commit/37b1ed644395f7b6b9baa0653ab10ee7d080acc8)
Date:   Sun May 31 10:02:08 2009 +0000

better random generator for logUID file system


##### commit [ba21d334a3a717d2053956477d1bb394c0557c2c](https://github.com/aglv/Horos/commit/ba21d334a3a717d2053956477d1bb394c0557c2c)
Date:   Sun May 31 16:36:23 2009 +0000

New Feature: C-GET SCP


##### commit [7e29f2613238d9a929397ce37da0d0c2144e08e4](https://github.com/aglv/Horos/commit/7e29f2613238d9a929397ce37da0d0c2144e08e4)
Date:   Mon Jun 1 13:32:09 2009 +0000

New Feature : activateCGETSCP preference to activate/inactivate the C-GET SCP support


##### commit [e602a70ac734a3a8cd1aad128b3f04d2cea78d06](https://github.com/aglv/Horos/commit/e602a70ac734a3a8cd1aad128b3f04d2cea78d06)
Date:   Thu Jun 4 18:33:27 2009 +0000

cleaning dcmframework network code: unused code removed


##### commit [0860cf3b705ec1df926fbeacdd56bf8628143f20](https://github.com/aglv/Horos/commit/0860cf3b705ec1df926fbeacdd56bf8628143f20)
Date:   Sat Jun 6 15:47:31 2009 +0000

New Feature: better compression transfer syntax selection during network communications


##### commit [d9075e51479d7f72e1556e6751b2ffd1fa781ce5](https://github.com/aglv/Horos/commit/d9075e51479d7f72e1556e6751b2ffd1fa781ce5)
Date:   Sun Jun 7 09:35:12 2009 +0000

New Feature: C-GET compression transfer syntaxes supported


##### commit [6ae175e733962292f9a4f15374c92cdd4d8fd20b](https://github.com/aglv/Horos/commit/6ae175e733962292f9a4f15374c92cdd4d8fd20b)
Date:   Sun Jun 7 09:44:35 2009 +0000

New Feature: compression settings per modality


##### commit [7c36203a44eac7cbe38a883f6f6a02e14db58789](https://github.com/aglv/Horos/commit/7c36203a44eac7cbe38a883f6f6a02e14db58789)
Date:   Sun Jun 7 09:59:15 2009 +0000

cleaning


##### commit [b7a776674ab7869dae5c51aeece998ef1f0916ef](https://github.com/aglv/Horos/commit/b7a776674ab7869dae5c51aeece998ef1f0916ef)
Date:   Tue Jun 9 12:21:18 2009 +0000

Bug Corrected: DCM Framework failed to write compressed DICOM images, if PixelData are present in Private Group -> Solution, DCM Framework will not write private group when compressing


##### commit [3d24b7ffc420665fceb5fdcad056503ab3b307e8](https://github.com/aglv/Horos/commit/3d24b7ffc420665fceb5fdcad056503ab3b307e8)
Date:   Tue Jun 16 16:29:58 2009 +0000

New Feature: JPEG2000 management


##### commit [65884c628d00d0fcab2f5eb094c594091d81a4b8](https://github.com/aglv/Horos/commit/65884c628d00d0fcab2f5eb094c594091d81a4b8)
Date:   Tue Jun 16 19:02:13 2009 +0000

more JPEG2000 tests


##### commit [d743331a803164c157c099d2a5964ed5a728da98](https://github.com/aglv/Horos/commit/d743331a803164c157c099d2a5964ed5a728da98)
Date:   Tue Jun 16 20:32:54 2009 +0000

JPEG2000 tests


##### commit [a78d170062412bbaf72977aad9e21229722a93f0](https://github.com/aglv/Horos/commit/a78d170062412bbaf72977aad9e21229722a93f0)
Date:   Tue Jun 16 21:03:12 2009 +0000

JPEG2000 cleaning


##### commit [becec16b04a90754f62520b1dd80d5d44735de01](https://github.com/aglv/Horos/commit/becec16b04a90754f62520b1dd80d5d44735de01)
Date:   Wed Jun 17 06:45:24 2009 +0000

fast switch from JPEG2000 to JPEG2000Lossless


##### commit [5fdd334259ced5004674bbc7fd222a592d0b52f2](https://github.com/aglv/Horos/commit/5fdd334259ced5004674bbc7fd222a592d0b52f2)
Date:   Thu Jun 18 06:49:52 2009 +0000

misc


##### commit [3210006fd24fa8c9a78cde54b9782b2a00b0a477](https://github.com/aglv/Horos/commit/3210006fd24fa8c9a78cde54b9782b2a00b0a477)
Date:   Sun Jun 21 11:02:21 2009 +0000

jpeg2000 ts tests


##### commit [fa6dcbb3091227326be88db9843089e5f41bb27a](https://github.com/aglv/Horos/commit/fa6dcbb3091227326be88db9843089e5f41bb27a)
Date:   Mon Jun 22 06:06:25 2009 +0000

more tests on ts


##### commit [72af694acd6196f10710b70fa08870f5caf54515](https://github.com/aglv/Horos/commit/72af694acd6196f10710b70fa08870f5caf54515)
Date:   Sun Jul 26 13:03:28 2009 +0000

code cleaning


##### commit [407825320b18c7e96f49284a2426b50a929fb1c1](https://github.com/aglv/Horos/commit/407825320b18c7e96f49284a2426b50a929fb1c1)
Date:   Sun Jul 26 13:39:06 2009 +0000

local db, when bonjour db sharing


##### commit [1c797ab3313245f47d3c2d27c01a234f7d36f1fb](https://github.com/aglv/Horos/commit/1c797ab3313245f47d3c2d27c01a234f7d36f1fb)
Date:   Mon Jul 27 11:12:22 2009 +0000

cleaning code


##### commit [4ae59420e86e45017e9fd17e5f5ac1f287fb40fc](https://github.com/aglv/Horos/commit/4ae59420e86e45017e9fd17e5f5ac1f287fb40fc)
Date:   Thu Jul 30 13:14:40 2009 +0000

QuickLook plugin 1.2


##### commit [90d51cb3b63708f1aff7c4a7cc8d4e572f3771a2](https://github.com/aglv/Horos/commit/90d51cb3b63708f1aff7c4a7cc8d4e572f3771a2)
Date:   Mon Aug 3 09:36:57 2009 +0000

PETEnhanced and MREnhanced storage syntax bug corrected, Protection against purge cache system based on ConditionLock


##### commit [72f24f5794428e793ade19a5dabc5a88bb2fe49e](https://github.com/aglv/Horos/commit/72f24f5794428e793ade19a5dabc5a88bb2fe49e)
Date:   Wed Aug 5 08:03:09 2009 +0000

performretrieve exception protection


##### commit [5b5ece16b1755e07f75647f869e70cd2984922a6](https://github.com/aglv/Horos/commit/5b5ece16b1755e07f75647f869e70cd2984922a6)
Date:   Thu Aug 6 16:49:39 2009 +0000

Protection against full hard disk


##### commit [3298c4adbcbc16b3371baa5fb580f8ad84bf6d9f](https://github.com/aglv/Horos/commit/3298c4adbcbc16b3371baa5fb580f8ad84bf6d9f)
Date:   Sun Aug 16 13:46:32 2009 +0000

Stop support for UID_DeflatedExplicitVRLittleEndianTransferSyntax


##### commit [8feeb308fb272fc7f323857757ead011a629190c](https://github.com/aglv/Horos/commit/8feeb308fb272fc7f323857757ead011a629190c)
Date:   Sun Aug 16 13:46:55 2009 +0000

Stop support for UID_DeflatedExplicitVRLittleEndianTransferSyntax


##### commit [dbd83dfaf544e4962dab58965bd252109257183f](https://github.com/aglv/Horos/commit/dbd83dfaf544e4962dab58965bd252109257183f)
Date:   Fri Aug 21 20:32:53 2009 +0000

Snow OsiriX


##### commit [d547b567853c31f1430afcb059f606ad969c5dc2](https://github.com/aglv/Horos/commit/d547b567853c31f1430afcb059f606ad969c5dc2)
Date:   Wed Sep 2 14:43:17 2009 +0000

log tests + QR 10.6 corrected <- For your problem, JoriX


##### commit [98acf78660ed8fe0538b930cf9b9a020d91c70bc](https://github.com/aglv/Horos/commit/98acf78660ed8fe0538b930cf9b9a020d91c70bc)
Date:   Thu Sep 3 09:51:45 2009 +0000

better exceptions handling


##### commit [3afbff742db16344293858a0bd3ed354ce0b6e8c](https://github.com/aglv/Horos/commit/3afbff742db16344293858a0bd3ed354ce0b6e8c)
Date:   Sat Sep 19 06:29:02 2009 +0000

corrupted files, tests


##### commit [3e02e8d6efcea2a48bb3b342b2d88f3efb94d837](https://github.com/aglv/Horos/commit/3e02e8d6efcea2a48bb3b342b2d88f3efb94d837)
Date:   Sat Sep 19 15:16:15 2009 +0000

better resistance against corrupted files


##### commit [c8145f49760362e5ab48de41eb58eddc16e7e589](https://github.com/aglv/Horos/commit/c8145f49760362e5ab48de41eb58eddc16e7e589)
Date:   Sat Sep 19 15:53:18 2009 +0000

better resistance against corrupted files


##### commit [d57e0f04daf477f1c108974fb23a64c9721cc66e](https://github.com/aglv/Horos/commit/d57e0f04daf477f1c108974fb23a64c9721cc66e)
Date:   Thu Sep 24 11:00:12 2009 +0000

UID_EnhancedMRImageStorage bug during C-GET


##### commit [cf42ddeae5ec085a5d27255bbeb4e03977133aab](https://github.com/aglv/Horos/commit/cf42ddeae5ec085a5d27255bbeb4e03977133aab)
Date:   Tue Oct 20 18:53:19 2009 +0000

QR retrieve


##### commit [7e0a1d2154b73d24a1a0c7796391cf33c4d6ff00](https://github.com/aglv/Horos/commit/7e0a1d2154b73d24a1a0c7796391cf33c4d6ff00)
Date:   Thu Oct 22 09:27:00 2009 +0000

TransferSyntax bug, timeout for abort connection reduced to 2 s, MAXWindowSize option in Preferences


##### commit [9d44a19a655a946993edd3df8e4e7f1bcbbc219b](https://github.com/aglv/Horos/commit/9d44a19a655a946993edd3df8e4e7f1bcbbc219b)
Date:   Fri Oct 23 17:21:43 2009 +0000

abort incoming connections


##### commit [b42cc3a2e86882d03f9dcfc8afa6fed375526e1e](https://github.com/aglv/Horos/commit/b42cc3a2e86882d03f9dcfc8afa6fed375526e1e)
Date:   Wed Nov 4 16:02:48 2009 +0000

reduce time for waitunlockfile


##### commit [71bd806af4b471e283e0bf2094d928c38bb8eb16](https://github.com/aglv/Horos/commit/71bd806af4b471e283e0bf2094d928c38bb8eb16)
Date:   Thu Nov 5 07:57:29 2009 +0000

reduced timeout for waitunlock file system


##### commit [e33d957da10aca22c8eb03b5b6b7accd03675833](https://github.com/aglv/Horos/commit/e33d957da10aca22c8eb03b5b6b7accd03675833)
Date:   Sat Nov 7 08:46:08 2009 +0000

bug clut 16bit


##### commit [a8e1472921967c328a39616372f25251a014f278](https://github.com/aglv/Horos/commit/a8e1472921967c328a39616372f25251a014f278)
Date:   Sun Nov 8 20:45:38 2009 +0000

OsiriX Lite


##### commit [2e95ee9fd245a0c3ed96fddcc8a08b41b0646a3f](https://github.com/aglv/Horos/commit/2e95ee9fd245a0c3ed96fddcc8a08b41b0646a3f)
Date:   Sun Nov 15 22:18:48 2009 +0000

WADO support, work in progress


##### commit [4258f02dbe02032620d8ffcd972c1fccd33d9ded](https://github.com/aglv/Horos/commit/4258f02dbe02032620d8ffcd972c1fccd33d9ded)
Date:   Sat Nov 21 08:32:05 2009 +0000

todo


##### commit [05be3060acfabee05a756c063d454ad6f8cf04b4](https://github.com/aglv/Horos/commit/05be3060acfabee05a756c063d454ad6f8cf04b4)
Date:   Tue Nov 24 09:09:10 2009 +0000

misc


##### commit [a8d0e6c020c10e692cfa051f8513c4cd737d7ce2](https://github.com/aglv/Horos/commit/a8d0e6c020c10e692cfa051f8513c4cd737d7ce2)
Date:   Sun Dec 13 17:14:48 2009 +0000

misc


##### commit [671f9a136b8b2b55d86403da20a7014763b09ba9](https://github.com/aglv/Horos/commit/671f9a136b8b2b55d86403da20a7014763b09ba9)
Date:   Sun Dec 13 17:18:41 2009 +0000

misc


##### commit [c253f19c6cb5ca878e1032e0aa9827aece2577e0](https://github.com/aglv/Horos/commit/c253f19c6cb5ca878e1032e0aa9827aece2577e0)
Date:   Fri Jan 1 13:12:59 2010 +0000

QuickLook


##### commit [6a77b3778ac34eaf9611f1b57f37819b71be34c1](https://github.com/aglv/Horos/commit/6a77b3778ac34eaf9611f1b57f37819b71be34c1)
Date:   Sat Jan 16 15:06:45 2010 +0000

OsiriX Lite


##### commit [5868c55868f27f04d3d02e746f587849ac5dbbd2](https://github.com/aglv/Horos/commit/5868c55868f27f04d3d02e746f587849ac5dbbd2)
Date:   Mon Jan 18 16:55:21 2010 +0000

DICOM TLS Store SCP. Work in progress.


##### commit [0f67789984d6fe31184de6d2fd18ae576750e3e6](https://github.com/aglv/Horos/commit/0f67789984d6fe31184de6d2fd18ae576750e3e6)
Date:   Wed Jan 20 16:49:07 2010 +0000

DICOM TLS Store SCP. Work in progress.


##### commit [04fde87a342107cda158645a67098854b19c5c68](https://github.com/aglv/Horos/commit/04fde87a342107cda158645a67098854b19c5c68)
Date:   Sat Jan 23 09:58:16 2010 +0000

GPL -> LGPL


##### commit [2c7bcfef9af8ff5ade575cbe562240096f88aa4c](https://github.com/aglv/Horos/commit/2c7bcfef9af8ff5ade575cbe562240096f88aa4c)
Date:   Mon Jan 25 10:25:43 2010 +0000

DICOM TLS Store SCP.


##### commit [a1025393bfde30314b05dcecd96b41907db59bc7](https://github.com/aglv/Horos/commit/a1025393bfde30314b05dcecd96b41907db59bc7)
Date:   Fri Jan 29 07:29:54 2010 +0000

SR report cleaning


##### commit [b791dc7e0c3f4cd8766a46c3ac04d1a393f051ab](https://github.com/aglv/Horos/commit/b791dc7e0c3f4cd8766a46c3ac04d1a393f051ab)
Date:   Mon Feb 8 15:58:23 2010 +0000

test Q&R


##### commit [bc53d9e7c186aa10f69a3dee517140d90089c2ec](https://github.com/aglv/Horos/commit/bc53d9e7c186aa10f69a3dee517140d90089c2ec)
Date:   Sun Feb 28 22:53:26 2010 +0000

tests with dcm4chee and cget


##### commit [52cbc7cadb2f9e3a3b56e1d2940b4990e45fbd6f](https://github.com/aglv/Horos/commit/52cbc7cadb2f9e3a3b56e1d2940b4990e45fbd6f)
Date:   Wed Mar 3 17:20:51 2010 +0000

default encoding is UTF-8


##### commit [1f59b5c2af8cf583a0ac43ffc55f37582175f138](https://github.com/aglv/Horos/commit/1f59b5c2af8cf583a0ac43ffc55f37582175f138)
Date:   Sat Mar 13 09:14:59 2010 +0000

cache bug for outlineview selection


##### commit [9898e9bca72f14ab87cc1c36c1423ae8544d37a1](https://github.com/aglv/Horos/commit/9898e9bca72f14ab87cc1c36c1423ae8544d37a1)
Date:   Tue Apr 13 14:35:11 2010 +0000

do not share the same instance of NSManagedObjectController with child process


##### commit [69497a405b9a51cb0edc60fa7cc9ce81a27f2e25](https://github.com/aglv/Horos/commit/69497a405b9a51cb0edc60fa7cc9ce81a27f2e25)
Date:   Wed Apr 14 07:13:51 2010 +0000

do not share the same instance of NSManagedObjectController with child process


##### commit [2f522e710a4313e02af3a8fb5947e826789ec7c9](https://github.com/aglv/Horos/commit/2f522e710a4313e02af3a8fb5947e826789ec7c9)
Date:   Fri Apr 30 11:17:10 2010 +0000

svn bug 2994600 corrected


##### commit [d3904fcfd7a9d938abb14d10cd687dbe60ae6f81](https://github.com/aglv/Horos/commit/d3904fcfd7a9d938abb14d10cd687dbe60ae6f81)
Date:   Wed May 12 11:17:31 2010 +0000

Bug Corrected: correct AETitle when receiving images through C-GET


##### commit [b97418adeb6ce9416392c606e7eb59b008c4adb5](https://github.com/aglv/Horos/commit/b97418adeb6ce9416392c606e7eb59b008c4adb5)
Date:   Wed May 12 14:02:54 2010 +0000

misc


##### commit [d9a3be52df641186e423341190707e41d05e8a79](https://github.com/aglv/Horos/commit/d9a3be52df641186e423341190707e41d05e8a79)
Date:   Mon May 17 19:37:11 2010 +0000

DICOM SR -> PDF : work in progress


##### commit [2b79fc5c5cf1f0d2ba9101133e59eed5c09d0eca](https://github.com/aglv/Horos/commit/2b79fc5c5cf1f0d2ba9101133e59eed5c09d0eca)
Date:   Wed Jun 2 08:02:05 2010 +0000

todo


##### commit [d4dda4b080ba398563c0064711db96534608cbfb](https://github.com/aglv/Horos/commit/d4dda4b080ba398563c0064711db96534608cbfb)
Date:   Fri Jun 11 12:05:25 2010 +0000

tests with restartSTORESCP


##### commit [1b54929f2bf7f7532b8c2385c5f7d599b2634b4c](https://github.com/aglv/Horos/commit/1b54929f2bf7f7532b8c2385c5f7d599b2634b4c)
Date:   Wed Jul 7 13:01:20 2010 +0000

apply manually an autorouting rule for generatedByOsiriX, cachedRawNoFiles, better Q&R refresh, todo, ...


##### commit [6e4c37a05afb321fe373534054dbe56420c0631e](https://github.com/aglv/Horos/commit/6e4c37a05afb321fe373534054dbe56420c0631e)
Date:   Sun Jul 11 15:08:11 2010 +0000

dcmtk updates


##### commit [35bbc655e85349fc6799ba9593d356b5d498778c](https://github.com/aglv/Horos/commit/35bbc655e85349fc6799ba9593d356b5d498778c)
Date:   Sun Jul 11 15:20:33 2010 +0000

dcmtk updates


##### commit [fbacbd0d2d05bbe5c9c198a3b4755a669c4e0bba](https://github.com/aglv/Horos/commit/fbacbd0d2d05bbe5c9c198a3b4755a669c4e0bba)
Date:   Sun Jul 11 21:50:12 2010 +0000

DICOM SR support for OsiriX QuickLook plugin


##### commit [a1c0ecdc2d2b9ce7ee42a084e8a1008e623803eb](https://github.com/aglv/Horos/commit/a1c0ecdc2d2b9ce7ee42a084e8a1008e623803eb)
Date:   Mon Jul 12 16:46:25 2010 +0000

DUL bug - tests


##### commit [88c601c405eb02427629d519103622052b066ff2](https://github.com/aglv/Horos/commit/88c601c405eb02427629d519103622052b066ff2)
Date:   Fri Jul 16 14:19:31 2010 +0000

activity pane


##### commit [015e82d4886ab3b3eab47bc55f2219e6fb069eb5](https://github.com/aglv/Horos/commit/015e82d4886ab3b3eab47bc55f2219e6fb069eb5)
Date:   Fri Jul 16 14:20:09 2010 +0000

activity pane


##### commit [d7915f6c1b69187054c69e776d3a432cc38ab1ca](https://github.com/aglv/Horos/commit/d7915f6c1b69187054c69e776d3a432cc38ab1ca)
Date:   Tue Jul 20 20:14:41 2010 +0000

DcmRepresentationParameter bug


##### commit [2a6725b7081ec14b7871aea4311409dd55097465](https://github.com/aglv/Horos/commit/2a6725b7081ec14b7871aea4311409dd55097465)
Date:   Tue Jul 27 13:23:49 2010 +0000

depth protection for computesequencelength, retain/autorelease removed for forked app


##### commit [029c47efea5a682b85d92d9d37842fbf73021917](https://github.com/aglv/Horos/commit/029c47efea5a682b85d92d9d37842fbf73021917)
Date:   Thu Jul 29 13:55:44 2010 +0000

better sub-processes management: reduce spin-lock risk


##### commit [8e211d9fc7b5502598f5b28c9738714c8c85d4ab](https://github.com/aglv/Horos/commit/8e211d9fc7b5502598f5b28c9738714c8c85d4ab)
Date:   Fri Jul 30 12:18:37 2010 +0000

search for locked processes


##### commit [58fb76a1f47a8db7a331092974bccf4cf1b25f72](https://github.com/aglv/Horos/commit/58fb76a1f47a8db7a331092974bccf4cf1b25f72)
Date:   Sun Aug 1 08:01:16 2010 +0000

Thread for DICOM services SCP


##### commit [3edd0cd56df193e84220e5a489e61fde275ca33a](https://github.com/aglv/Horos/commit/3edd0cd56df193e84220e5a489e61fde275ca33a)
Date:   Sun Aug 1 08:46:14 2010 +0000

Thread for DICOM services SCP


##### commit [32f9d8efdf1e4bad14560a0e0bc84b965fbd51ba](https://github.com/aglv/Horos/commit/32f9d8efdf1e4bad14560a0e0bc84b965fbd51ba)
Date:   Sun Aug 1 15:49:43 2010 +0000

reduce logs


##### commit [ae5d93238b6df911ab6c82063dd3703766dfe638](https://github.com/aglv/Horos/commit/ae5d93238b6df911ab6c82063dd3703766dfe638)
Date:   Wed Aug 4 13:45:58 2010 +0000

test automatic store-scp restart


##### commit [7247bf6233f68d62b943fa40891d756b8184c3cf](https://github.com/aglv/Horos/commit/7247bf6233f68d62b943fa40891d756b8184c3cf)
Date:   Wed Aug 4 19:07:00 2010 +0000

check for null pointers


##### commit [104e3bac1ae9dd693079f24f9c4f1b100fc8af3e](https://github.com/aglv/Horos/commit/104e3bac1ae9dd693079f24f9c4f1b100fc8af3e)
Date:   Fri Aug 6 15:37:33 2010 +0000

misc


##### commit [dd31effdec0e65e5a5d83232aae6b53674d976c9](https://github.com/aglv/Horos/commit/dd31effdec0e65e5a5d83232aae6b53674d976c9)
Date:   Tue Aug 10 12:57:51 2010 +0000

tests with CoreData


##### commit [bbe49c2f6df560984304bd8de8de21274c4595b6](https://github.com/aglv/Horos/commit/bbe49c2f6df560984304bd8de8de21274c4595b6)
Date:   Tue Aug 17 20:34:29 2010 +0000

tests for DIMSE_NODATAAVAILABLE bug


##### commit [7673db8d6c65499a93595ceec921d2ef419c9985](https://github.com/aglv/Horos/commit/7673db8d6c65499a93595ceec921d2ef419c9985)
Date:   Wed Aug 18 13:38:52 2010 +0000

Autorelease Pool for DICOM Service Provider loop


##### commit [78f7f8d46853f52c8c86de3b0d7aa0c2bd83fd3d](https://github.com/aglv/Horos/commit/78f7f8d46853f52c8c86de3b0d7aa0c2bd83fd3d)
Date:   Wed Aug 18 15:15:50 2010 +0000

close the connection immediately on the father side


##### commit [c8c570ce429b9124984013a5acd88e6eb79cc90c](https://github.com/aglv/Horos/commit/c8c570ce429b9124984013a5acd88e6eb79cc90c)
Date:   Wed Sep 22 13:04:03 2010 +0000

misc, simplePing removed


##### commit [ed7c3cc989c99626973294b961ce86bcf6955aae](https://github.com/aglv/Horos/commit/ed7c3cc989c99626973294b961ce86bcf6955aae)
Date:   Fri Oct 1 14:28:14 2010 +0000

weasis bug


##### commit [ca50c3792c8cae2c66f897e523080dcd8053876e](https://github.com/aglv/Horos/commit/ca50c3792c8cae2c66f897e523080dcd8053876e)
Date:   Thu Oct 7 06:51:18 2010 +0000

smaller delay


##### commit [217f2e2e7e54633a123c9e0fb99f93bc565317b0](https://github.com/aglv/Horos/commit/217f2e2e7e54633a123c9e0fb99f93bc565317b0)
Date:   Fri Oct 8 07:31:55 2010 +0000

anonymized folder


##### commit [59b85565d1478681fe11648c1182ee7a20e2dee9](https://github.com/aglv/Horos/commit/59b85565d1478681fe11648c1182ee7a20e2dee9)
Date:   Wed Oct 13 07:51:28 2010 +0000

todo


##### commit [387132b214168ac2d95273f902b5a9aac916fabf](https://github.com/aglv/Horos/commit/387132b214168ac2d95273f902b5a9aac916fabf)
Date:   Wed Oct 20 10:15:53 2010 +0000

check PDU size


##### commit [f76d16785b820c772fc0d6c4e5a6f460f5276b0f](https://github.com/aglv/Horos/commit/f76d16785b820c772fc0d6c4e5a6f460f5276b0f)
Date:   Fri Oct 29 08:23:28 2010 +0000

misc


##### commit [03a6e7f22fe3d24a877bfe907751494cfc927d5f](https://github.com/aglv/Horos/commit/03a6e7f22fe3d24a877bfe907751494cfc927d5f)
Date:   Sun Oct 31 16:43:40 2010 +0000

calloc instead of malloc for T_ASC_Network


##### commit [4b00cc19101dc15eb22b72d5caad3bb1df2c9482](https://github.com/aglv/Horos/commit/4b00cc19101dc15eb22b72d5caad3bb1df2c9482)
Date:   Sun Oct 31 16:56:30 2010 +0000

calloc instead of malloc for T_ASC_Network


##### commit [f96ef396f246f3685a2a6c19859b9fcb38fd3cee](https://github.com/aglv/Horos/commit/f96ef396f246f3685a2a6c19859b9fcb38fd3cee)
Date:   Thu Nov 4 13:02:21 2010 +0000

misc


##### commit [1999e8e779827c803fe3cb21cd0282c40d831d0b](https://github.com/aglv/Horos/commit/1999e8e779827c803fe3cb21cd0282c40d831d0b)
Date:   Sun Nov 7 14:41:51 2010 +0000

JP2K support in dcmtk


##### commit [45aafc42491462b13c06df21292897d2a20705ff](https://github.com/aglv/Horos/commit/45aafc42491462b13c06df21292897d2a20705ff)
Date:   Sun Nov 7 16:17:46 2010 +0000

JP2K encoding for dcmtk


##### commit [eab564773535f52c7811c9edbef789360351ae8c](https://github.com/aglv/Horos/commit/eab564773535f52c7811c9edbef789360351ae8c)
Date:   Sun Nov 7 16:18:46 2010 +0000

JP2K encoding for dcmtk


##### commit [b53e56f9e534a40e14d791186d0ff2dfb12d6249](https://github.com/aglv/Horos/commit/b53e56f9e534a40e14d791186d0ff2dfb12d6249)
Date:   Sun Nov 7 21:17:55 2010 +0000

encode decode JP2K in dcmtk


##### commit [80c842cc78da71f47b6710d296985f9a5f03bd83](https://github.com/aglv/Horos/commit/80c842cc78da71f47b6710d296985f9a5f03bd83)
Date:   Mon Nov 8 07:32:58 2010 +0000

useDCMTKForJP2K


##### commit [2be562f1263d57a5b5a2a8ee12e11b3fb253ff67](https://github.com/aglv/Horos/commit/2be562f1263d57a5b5a2a8ee12e11b3fb253ff67)
Date:   Mon Nov 8 10:28:42 2010 +0000

useDCMTK for JPEG 2000


##### commit [e72af6adcabfdd09530a396631ad6837ab5cdbec](https://github.com/aglv/Horos/commit/e72af6adcabfdd09530a396631ad6837ab5cdbec)
Date:   Tue Nov 9 16:50:45 2010 +0000

better support for JP2K in DCMTK, support for bugged GE files with GEIIS


##### commit [f219f0d357198b830984dc9c85f7e5f5ef9029f7](https://github.com/aglv/Horos/commit/f219f0d357198b830984dc9c85f7e5f5ef9029f7)
Date:   Tue Nov 16 15:48:12 2010 +0000

minor optimizations for checkIncomingThread


##### commit [3ca489d8c1de5313eb166c94578f84cfe923208d](https://github.com/aglv/Horos/commit/3ca489d8c1de5313eb166c94578f84cfe923208d)
Date:   Wed Nov 17 14:33:31 2010 +0000

dont regenerate uid when compressing the images


##### commit [8ba17bdb50db1fad91d993daab866dadbc6d1954](https://github.com/aglv/Horos/commit/8ba17bdb50db1fad91d993daab866dadbc6d1954)
Date:   Wed Nov 17 15:38:18 2010 +0000

dont regenerate uid when compressing the images


##### commit [c686596b611a2c435b12edc322bd5d89fb42e0e2](https://github.com/aglv/Horos/commit/c686596b611a2c435b12edc322bd5d89fb42e0e2)
Date:   Thu Nov 18 13:02:32 2010 +0000

misc


##### commit [1a840ceb842c52f16b59681ebcb6105541e46f09](https://github.com/aglv/Horos/commit/1a840ceb842c52f16b59681ebcb6105541e46f09)
Date:   Thu Nov 25 09:58:29 2010 +0000

Kakadu JPEG 2K tests


##### commit [e70863b6fb4500b974254a6c81cb24c8a63f14bd](https://github.com/aglv/Horos/commit/e70863b6fb4500b974254a6c81cb24c8a63f14bd)
Date:   Fri Nov 26 12:08:37 2010 +0000

kdu files


##### commit [76e11e057432538c22b6306543156c62a57c8d2a](https://github.com/aglv/Horos/commit/76e11e057432538c22b6306543156c62a57c8d2a)
Date:   Thu Dec 9 15:40:55 2010 +0000

reduce lock/unlock for DICOM Services SCP


##### commit [4c90b2be70bf07656a59f171301f3b9351ff7553](https://github.com/aglv/Horos/commit/4c90b2be70bf07656a59f171301f3b9351ff7553)
Date:   Thu Dec 16 20:36:11 2010 +0000

support color model in JP2K support for dcmtk


##### commit [266b0d8117ec1767eb2b5015bbe2f47d74188aeb](https://github.com/aglv/Horos/commit/266b0d8117ec1767eb2b5015bbe2f47d74188aeb)
Date:   Sun Dec 19 10:54:53 2010 +0000

KDU tests


##### commit [8b9954748780bc24fed756f93df1e9ab18253cec](https://github.com/aglv/Horos/commit/8b9954748780bc24fed756f93df1e9ab18253cec)
Date:   Sun Dec 19 16:11:44 2010 +0000

jpeg2klossless <-> jpeg2k : fast switch for dcmtk


##### commit [531d4b0c04b9b000cc4db69e92328f3f07697ba9](https://github.com/aglv/Horos/commit/531d4b0c04b9b000cc4db69e92328f3f07697ba9)
Date:   Fri Dec 24 10:43:34 2010 +0000

check pointer for nil in association release


##### commit [164f1517118acf752ac00b8ebf16ae414dabc206](https://github.com/aglv/Horos/commit/164f1517118acf752ac00b8ebf16ae414dabc206)
Date:   Fri Dec 24 10:55:42 2010 +0000

check pointer for nil in association release


##### commit [5bd459f2d788c49ea18fd8134a32aa05b701491e](https://github.com/aglv/Horos/commit/5bd459f2d788c49ea18fd8134a32aa05b701491e)
Date:   Mon Dec 27 11:57:37 2010 +0000

persistent store dictionary


##### commit [bb233324432ee67b2325ea6e5dbf707079924df7](https://github.com/aglv/Horos/commit/bb233324432ee67b2325ea6e5dbf707079924df7)
Date:   Tue Dec 28 13:09:41 2010 +0000

code cleaning


##### commit [ddbbc4e6358f8837a13fdae61eb54230ef0f4045](https://github.com/aglv/Horos/commit/ddbbc4e6358f8837a13fdae61eb54230ef0f4045)
Date:   Wed Dec 29 10:04:26 2010 +0000

waitUnlockPID on a separate thread: avoid blocking, decompress/compress dcmtk bug corrected


##### commit [38df35ea7e69d0894d0a4f162e2ad9077d0cd982](https://github.com/aglv/Horos/commit/38df35ea7e69d0894d0a4f162e2ad9077d0cd982)
Date:   Wed Dec 29 10:12:25 2010 +0000

waitUnlockPID on a separate thread: avoid blocking, decompress/compress dcmtk bug corrected


##### commit [8851ecb8072651f71a03c5eeb61a9fb387777a36](https://github.com/aglv/Horos/commit/8851ecb8072651f71a03c5eeb61a9fb387777a36)
Date:   Sat Jan 1 09:38:54 2011 +0000

jp2k slope intercept bug founded


##### commit [2d291b01573340721360f592ade9532f36491cb9](https://github.com/aglv/Horos/commit/2d291b01573340721360f592ade9532f36491cb9)
Date:   Sat Jan 1 16:57:00 2011 +0000

jp2k bug: min/max and YcBr/RGB bug corrected


##### commit [b66ea6b68fc9b72e5e1829eedea9adb0c9352fc4](https://github.com/aglv/Horos/commit/b66ea6b68fc9b72e5e1829eedea9adb0c9352fc4)
Date:   Sun Jan 2 08:22:02 2011 +0000

dicomExport planarConfiguration bug corrected


##### commit [55cf43b34c3bae6fbdc08af9772866d4a6b58bd0](https://github.com/aglv/Horos/commit/55cf43b34c3bae6fbdc08af9772866d4a6b58bd0)
Date:   Sun Jan 23 21:34:04 2011 +0000

monchrome 1 support when decompressing jp2k


##### commit [b53c9ed7817acb3c2ffc38fcf1ce2090cd03ab81](https://github.com/aglv/Horos/commit/b53c9ed7817acb3c2ffc38fcf1ce2090cd03ab81)
Date:   Tue Feb 1 08:37:35 2011 +0000

KDU SDK


##### commit [d5a41f8ac34f07dbee2c5aca1aeecdac550588c2](https://github.com/aglv/Horos/commit/d5a41f8ac34f07dbee2c5aca1aeecdac550588c2)
Date:   Sun Mar 6 22:55:04 2011 +0000

version 3.9b5


##### commit [c72441b3326a5d95b5b04e352fe47fbafaebf069](https://github.com/aglv/Horos/commit/c72441b3326a5d95b5b04e352fe47fbafaebf069)
Date:   Thu Mar 17 21:18:46 2011 +0000

Quicklook plugin


##### commit [b1a2527a42560104f68c7a033597f63ee50d4756](https://github.com/aglv/Horos/commit/b1a2527a42560104f68c7a033597f63ee50d4756)
Date:   Fri Mar 18 09:08:37 2011 +0000

minor leaks


##### commit [6e8afec2f5457db7f5a3673f854e4ae1d8dbf174](https://github.com/aglv/Horos/commit/6e8afec2f5457db7f5a3673f854e4ae1d8dbf174)
Date:   Fri Mar 18 09:50:28 2011 +0000

misc


##### commit [23740f26e7bebe319f40f4d29ef6a742548ccd74](https://github.com/aglv/Horos/commit/23740f26e7bebe319f40f4d29ef6a742548ccd74)
Date:   Fri Mar 18 14:53:28 2011 +0000

support for symlink for INCOMING and TEMP folder


##### commit [af40693d6cbbca1e0234bbf8265d3bec1040848e](https://github.com/aglv/Horos/commit/af40693d6cbbca1e0234bbf8265d3bec1040848e)
Date:   Mon Mar 28 06:41:02 2011 +0000

check for nil in DICOM Network functions


##### commit [4b6c4fd8dd272a8e8a429c55704cd5958c1689ec](https://github.com/aglv/Horos/commit/4b6c4fd8dd272a8e8a429c55704cd5958c1689ec)
Date:   Mon Mar 28 06:42:06 2011 +0000

check for nil in DICOM Network functions


##### commit [89556868042846050fa1faec724cf243831e9aec](https://github.com/aglv/Horos/commit/89556868042846050fa1faec724cf243831e9aec)
Date:   Thu Mar 31 08:13:19 2011 +0000

remove all 0x0028 fields when exporting secondary captures


##### commit [023cb982bd0962c9389c8302ec689ec7e89f6303](https://github.com/aglv/Horos/commit/023cb982bd0962c9389c8302ec689ec7e89f6303)
Date:   Thu Mar 31 09:38:00 2011 +0000

memory leak if association failed: corrected


##### commit [2c3f8aca54540194b7e1968d81f5bdc770de4f26](https://github.com/aglv/Horos/commit/2c3f8aca54540194b7e1968d81f5bdc770de4f26)
Date:   Tue Apr 12 14:28:38 2011 +0000

silent crashes for child processes


##### commit [11a41d55957ecf0d4464e27dd066f07a158c58cb](https://github.com/aglv/Horos/commit/11a41d55957ecf0d4464e27dd066f07a158c58cb)
Date:   Tue Apr 12 14:28:57 2011 +0000

silent crashes for child processes


##### commit [1d25d90c17dcda01996f7728c7e14972e70e80f9](https://github.com/aglv/Horos/commit/1d25d90c17dcda01996f7728c7e14972e70e80f9)
Date:   Tue Apr 12 14:39:48 2011 +0000

silent crashes for child processes


##### commit [84dde2f7d297f4d05c6a0e30a5a2187edd97340c](https://github.com/aglv/Horos/commit/84dde2f7d297f4d05c6a0e30a5a2187edd97340c)
Date:   Tue Apr 12 15:20:12 2011 +0000

silent crashes for child processes


##### commit [20a06ced13e3616326ea59fb5f1fffeed335167d](https://github.com/aglv/Horos/commit/20a06ced13e3616326ea59fb5f1fffeed335167d)
Date:   Fri Apr 29 16:03:37 2011 +0000

work on trunk


##### commit [d80b2677d6e55349e93ed16882bb285ead1c8305](https://github.com/aglv/Horos/commit/d80b2677d6e55349e93ed16882bb285ead1c8305)
Date:   Sat May 14 08:59:00 2011 +0000

added support for new SOPClassUID : EnhancedXAImageStorage, EnhancedXRFImageStorage, XRay3DAngiographicImageStorage, XRay3DCraniofacialImageStorage


##### commit [67924a2e295629cd7df121de1d80b4649e35bfdb](https://github.com/aglv/Horos/commit/67924a2e295629cd7df121de1d80b4649e35bfdb)
Merge: ea8b656 a820ca2
Date:   Mon May 16 07:06:12 2011 +0000

merge -r8495:8513 ../osirix-trunk/ .


##### commit [5074028553752dec900e2ab0a08f7e5b0ae94334](https://github.com/aglv/Horos/commit/5074028553752dec900e2ab0a08f7e5b0ae94334)
Date:   Tue Aug 2 08:22:02 2011 +0000

megamerge svn merge -r8623:8723 ../osirix-trunk/ .


##### commit [d9430e67eb3515c193e7a454d28ea6728cae3b0e](https://github.com/aglv/Horos/commit/d9430e67eb3515c193e7a454d28ea6728cae3b0e)
Date:   Wed Aug 3 09:36:04 2011 +0000

builds ok svn merge -r8736:8738 ../osirix-trunk/ .


##### commit [bb159a15ea778f8ecb752eb06a1db7518a908cb3](https://github.com/aglv/Horos/commit/bb159a15ea778f8ecb752eb06a1db7518a908cb3)
Date:   Thu Aug 4 12:43:58 2011 +0000

svn merge -r8738:8742 ../osirix-trunk/ .


##### commit [28a85ec5fddf556738c6e7043218002e05724c5a](https://github.com/aglv/Horos/commit/28a85ec5fddf556738c6e7043218002e05724c5a)
Date:   Mon Aug 8 09:23:04 2011 +0000

svn merge -r8742:8756 ../osirix-trunk/ .


##### commit [ef2f729c9ac878fc20dbda2132e04f991a55bc67](https://github.com/aglv/Horos/commit/ef2f729c9ac878fc20dbda2132e04f991a55bc67)
Date:   Fri Aug 12 12:26:03 2011 +0000

svn merge -r8774:8793 ../osirix-trunk/ .


##### commit [705930d672add30c91ab4e296e8ad8116b8d1829](https://github.com/aglv/Horos/commit/705930d672add30c91ab4e296e8ad8116b8d1829)
Date:   Mon Aug 29 14:29:24 2011 +0000

svn merge -r8822:8843 ../osirix-trunk .


##### commit [a525a3ab01f0d29bf3840349ef2d8f2ef8f1b8ea](https://github.com/aglv/Horos/commit/a525a3ab01f0d29bf3840349ef2d8f2ef8f1b8ea)
Date:   Tue Aug 30 12:31:26 2011 +0000

massive usage of N2LogExceptionWithStackTrace


##### commit [18260aa7c7a9d909b8a08124f32128efb029d0f7](https://github.com/aglv/Horos/commit/18260aa7c7a9d909b8a08124f32128efb029d0f7)
Date:   Wed Aug 31 10:22:10 2011 +0000

svn merge -r8851:8864 ../osirix-trunk .


##### commit [18c37b739170d527aa640ba55752786f9d931415](https://github.com/aglv/Horos/commit/18c37b739170d527aa640ba55752786f9d931415)
Date:   Mon Sep 5 09:39:24 2011 +0000

svn merge -r8864:8885 ../osirix-trunk .


##### commit [6f185c9952d12d1c4d901d26c2e3d093e5544b8f](https://github.com/aglv/Horos/commit/6f185c9952d12d1c4d901d26c2e3d093e5544b8f)
Date:   Wed Sep 7 12:13:36 2011 +0000

DICOM SCP bug corrected


##### commit [c8808338b89758e9068dc5279bfd327f584e4f4b](https://github.com/aglv/Horos/commit/c8808338b89758e9068dc5279bfd327f584e4f4b)
Date:   Wed Sep 28 06:15:02 2011 +0000

DICOM Store: save SourceApplicationEntityTitle


##### commit [0acc54348211bd27b77bda762c17d02ada688f5c](https://github.com/aglv/Horos/commit/0acc54348211bd27b77bda762c17d02ada688f5c)
Date:   Thu Oct 20 16:03:59 2011 +0000

svn merge -r8948:9045 ../osirix-trunk . untested, still needs some checking with BrowserController -> DicomDatabase methods


##### commit [66924c1444504240fb466a85f59504cf5f23c048](https://github.com/aglv/Horos/commit/66924c1444504240fb466a85f59504cf5f23c048)
Date:   Tue Nov 1 10:54:37 2011 +0000

merge -r9045:9080 ../osirix-trunk .


##### commit [7c7cf0ebd6cd5a881055031060295751d0d2a352](https://github.com/aglv/Horos/commit/7c7cf0ebd6cd5a881055031060295751d0d2a352)
Date:   Mon Jan 23 11:16:47 2012 +0000

merge -r9107:9286 ../osirix-trunk . (untested)


##### commit [be5c10ac2449d56aa3dcad7887f3842d13d1695b](https://github.com/aglv/Horos/commit/be5c10ac2449d56aa3dcad7887f3842d13d1695b)
Date:   Wed Feb 1 17:02:57 2012 +0000

MIVA optimization attempt number 1 - when receiving files, every addIncomingFiles causes the coredata SQL file to be written to disk, and with big databases the SQL file can take GigaBytes of space, which takes a lot of time to write to disk and slows down the user (because it locks the managedObjectContext) ---- here we try to write to disk only every 30 seconds, and intermediary unsaved added files are stored in a separated much smaller plist file. if OsiriX crashes without saving the added files in the SQL index, it reloads them in when reloading the database


##### commit [b85afd55096efb87c36664bd5fe105df8b094e43](https://github.com/aglv/Horos/commit/b85afd55096efb87c36664bd5fe105df8b094e43)
Date:   Thu Feb 16 14:15:55 2012 +0000

merge -r9286:9385 ../osirix-trunk .


##### commit [534089b1c56dc38bed164952edbf58a7deb2426e](https://github.com/aglv/Horos/commit/534089b1c56dc38bed164952edbf58a7deb2426e)
Date:   Mon Feb 27 10:17:37 2012 +0000

merge -r9389:9443 ../osirix-trunk/ .


##### commit [176ade180a9d7e387f2547dbf9b646ac2131b685](https://github.com/aglv/Horos/commit/176ade180a9d7e387f2547dbf9b646ac2131b685)
Date:   Mon Feb 27 11:12:52 2012 +0000

bug


##### commit [3938f51e61d8438d5c9a93afaae956cfcd8ce6b5](https://github.com/aglv/Horos/commit/3938f51e61d8438d5c9a93afaae956cfcd8ce6b5)
Date:   Wed Feb 29 16:20:03 2012 +0000

dicom related bug solved: independent NSManagedObjectContext for forked dcmtk (OsiriXSCPDataHandler) created without accessing DicomDatabase (because the extra stuff had buggy consequences through the fork)


##### commit [639f2dbb43f47e7de1dd45f3d6433ced467cb4b5](https://github.com/aglv/Horos/commit/639f2dbb43f47e7de1dd45f3d6433ced467cb4b5)
Date:   Thu Mar 1 18:24:21 2012 +0000

DICOM server access to CoreData removed. These forked processes now access CoreData through a pipe shared with the main process. Still needs some testing


##### commit [59b524928d1961a220ad115c1439e059d100609d](https://github.com/aglv/Horos/commit/59b524928d1961a220ad115c1439e059d100609d)
Date:   Mon Mar 5 07:42:11 2012 +0000

work on dcmtk process child-to-parent communication, giving up for now


##### commit [90ecdb86f5a4a0f94d37e9553e61f9f694f768d9](https://github.com/aglv/Horos/commit/90ecdb86f5a4a0f94d37e9553e61f9f694f768d9)
Date:   Mon Mar 5 07:47:37 2012 +0000

rolled back to revision 9468


##### commit [0dde253cbd4e3574bd6f4331eda06fb51e46acc4](https://github.com/aglv/Horos/commit/0dde253cbd4e3574bd6f4331eda06fb51e46acc4)
Date:   Wed Mar 7 13:27:13 2012 +0000

Just cleaning commented code


##### commit [df9290b90f35ab62f601283092ae37cbbe47434a](https://github.com/aglv/Horos/commit/df9290b90f35ab62f601283092ae37cbbe47434a)
Date:   Mon Mar 12 14:33:47 2012 +0000

merge -r9481:9537 ../osirix-trunk .


##### commit [81008837c7d30ef36c2d55aad4b2d82634477ab5](https://github.com/aglv/Horos/commit/81008837c7d30ef36c2d55aad4b2d82634477ab5)
Date:   Wed Mar 14 16:48:54 2012 +0000

DICOM SCP : independent persistentstore for the fork child


##### commit [a7563fd307857207b89209c715277edeeee092a5](https://github.com/aglv/Horos/commit/a7563fd307857207b89209c715277edeeee092a5)
Date:   Wed Mar 14 16:53:09 2012 +0000

DICOM SCP : independent persistentstore for the fork child


##### commit [2476f3552a85bb7594ee78651f9dad7c2f40b76d](https://github.com/aglv/Horos/commit/2476f3552a85bb7594ee78651f9dad7c2f40b76d)
Date:   Thu Mar 15 07:14:12 2012 +0000

Forked process: code cleaning


##### commit [4e1a81cb70a5f0614f9b1d42eec527d1011acfbe](https://github.com/aglv/Horos/commit/4e1a81cb70a5f0614f9b1d42eec527d1011acfbe)
Date:   Fri Mar 16 12:12:35 2012 +0000

merge -r9537:9574 ../osirix-trunk .


##### commit [97847c4a314f68c03f6204fbc0a5a0a3f192cb77](https://github.com/aglv/Horos/commit/97847c4a314f68c03f6204fbc0a5a0a3f192cb77)
Date:   Wed Mar 21 16:33:02 2012 +0000

Memory leak with NSPersistentStoreCoordinator creating unlimited number of opened db files


##### commit [c615ebd566ee2120afc355cfbdbb88b817ed17fa](https://github.com/aglv/Horos/commit/c615ebd566ee2120afc355cfbdbb88b817ed17fa)
Date:   Mon Apr 2 09:18:25 2012 +0000

misc 64-bit compiling warnings removed


##### commit [10f00804ce4128073bd758594bcc8a3e07003e21](https://github.com/aglv/Horos/commit/10f00804ce4128073bd758594bcc8a3e07003e21)
Date:   Wed May 2 09:39:43 2012 +0000

merge -r9749:9760 ../osirix-trunk .


##### commit [541e40d71be63eb8d6cb1f5aeae88104b6fe5a42](https://github.com/aglv/Horos/commit/541e40d71be63eb8d6cb1f5aeae88104b6fe5a42)
Date:   Thu May 10 20:01:27 2012 +0000

Support for DICOMConnectionTimeout, and automatically retry 3 times the TCP/IP connection


##### commit [220b9389a703a3716a20e23113c77d0f641b7763](https://github.com/aglv/Horos/commit/220b9389a703a3716a20e23113c77d0f641b7763)
Date:   Fri May 11 08:14:06 2012 +0000

todo


##### commit [b14fea9f6b406d254b5d2000cdf7ef5d107f1f8a](https://github.com/aglv/Horos/commit/b14fea9f6b406d254b5d2000cdf7ef5d107f1f8a)
Date:   Fri Jun 22 15:27:38 2012 +0000

KDU Signing bug corrected


##### commit [d94f8e4a2ddd7c509990af7b53d7b29e7e6250d6](https://github.com/aglv/Horos/commit/d94f8e4a2ddd7c509990af7b53d7b29e7e6250d6)
Date:   Sun Jul 1 07:37:59 2012 +0000

MPProcessors removed


##### commit [f1f678303b2ffe6e2c361ab103cdb8181bfb3f3e](https://github.com/aglv/Horos/commit/f1f678303b2ffe6e2c361ab103cdb8181bfb3f3e)
Date:   Wed Jul 25 15:07:00 2012 +0000

Cloud


##### commit [47c5c877175c55154924bb296c5f4f10bed2dab7](https://github.com/aglv/Horos/commit/47c5c877175c55154924bb296c5f4f10bed2dab7)
Date:   Tue Jul 31 14:06:14 2012 +0000

DICOM SCP: short timeout for the first connection


##### commit [91356c779f9e41a2de63d0b83aa33cde3d37ecd7](https://github.com/aglv/Horos/commit/91356c779f9e41a2de63d0b83aa33cde3d37ecd7)
Date:   Tue Jul 31 14:10:28 2012 +0000

DICOM SCP: short timeout for the first connection


##### commit [974970b7ce23b8990caeed58982d05b925888e6e](https://github.com/aglv/Horos/commit/974970b7ce23b8990caeed58982d05b925888e6e)
Date:   Wed Aug 1 08:49:08 2012 +0000

dciodvfy updated to 5.2012, More retina icons


##### commit [bee6f9ce12a34b2776c890f2a580d5042af184c3](https://github.com/aglv/Horos/commit/bee6f9ce12a34b2776c890f2a580d5042af184c3)
Date:   Thu Aug 16 08:22:04 2012 +0000

DcmDicomDir::moveRecordToTree protection against unfinite recursive loops


##### commit [390f00bcb025c64e5537d1f83566042321b3efb1](https://github.com/aglv/Horos/commit/390f00bcb025c64e5537d1f83566042321b3efb1)
Date:   Thu Aug 23 16:49:09 2012 +0000

Validate DICOMDIR file, before reading


##### commit [c18dee619f587d7e5d515477b0075156aee21726](https://github.com/aglv/Horos/commit/c18dee619f587d7e5d515477b0075156aee21726)
Date:   Sun Aug 26 16:43:08 2012 +0000

DCMTK misc


##### commit [a6f500fce0d7a65c98d5a382f7a30924bfc13d84](https://github.com/aglv/Horos/commit/a6f500fce0d7a65c98d5a382f7a30924bfc13d84)
Date:   Mon Sep 17 09:33:13 2012 +0000

WebServer: independent contexts


##### commit [f701adf45103c131a2fd3420fae2a2bc59c99b8b](https://github.com/aglv/Horos/commit/f701adf45103c131a2fd3420fae2a2bc59c99b8b)
Date:   Mon Sep 17 15:41:42 2012 +0000

Tests for not using NSManagedObject in sub-processes


##### commit [190480993b256ef6f21fe95553242b776ca14235](https://github.com/aglv/Horos/commit/190480993b256ef6f21fe95553242b776ca14235)
Date:   Tue Sep 18 12:10:21 2012 +0000

DICOM Listener: single-process / multi-threads mode


##### commit [a38c2a2a4de2145420aa4b65fbb071bf1948fd7b](https://github.com/aglv/Horos/commit/a38c2a2a4de2145420aa4b65fbb071bf1948fd7b)
Date:   Tue Sep 18 12:42:25 2012 +0000

DICOM Listener: single-process / multi-threads mode


##### commit [7443955f8159d25857f8e79d6c53c3c23e7e73d3](https://github.com/aglv/Horos/commit/7443955f8159d25857f8e79d6c53c3c23e7e73d3)
Date:   Tue Sep 18 14:27:47 2012 +0000

DICOM Listener: single-process / multi-threads mode


##### commit [3765f9f6ac21bc7fa2731f406978cf16d0603d1b](https://github.com/aglv/Horos/commit/3765f9f6ac21bc7fa2731f406978cf16d0603d1b)
Date:   Tue Sep 18 15:06:26 2012 +0000

DICOM Listener: single-process / multi-threads mode


##### commit [09c3697e0106a0a1c5dcc4b513cf1eec3d891777](https://github.com/aglv/Horos/commit/09c3697e0106a0a1c5dcc4b513cf1eec3d891777)
Date:   Wed Sep 19 05:14:07 2012 +0000

SCP: multi-threaded, instead of multi-processes


##### commit [30575a22a29f2695f4c5fcfe722d77bf8252061f](https://github.com/aglv/Horos/commit/30575a22a29f2695f4c5fcfe722d77bf8252061f)
Date:   Wed Sep 19 07:29:09 2012 +0000

DICOM Listener: single-process / multi-threads mode


##### commit [dbf3aa5e9e4df1e7aebdfb46e998af9b50b6a1a6](https://github.com/aglv/Horos/commit/dbf3aa5e9e4df1e7aebdfb46e998af9b50b6a1a6)
Date:   Sat Sep 22 08:17:28 2012 +0000

misc


##### commit [b1aa826a84972fbf7363334837fbf28b03c5f361](https://github.com/aglv/Horos/commit/b1aa826a84972fbf7363334837fbf28b03c5f361)
Date:   Sat Sep 22 09:58:22 2012 +0000

DICOM SCP: support for cancel


##### commit [40cdb6acd9ba79157cbd78d7716f259da5ee4566](https://github.com/aglv/Horos/commit/40cdb6acd9ba79157cbd78d7716f259da5ee4566)
Date:   Sat Sep 22 14:07:55 2012 +0000

WADO Download thread: progress bar


##### commit [30c2cb3e22253375038d8c72251b3c9ae05f77f2](https://github.com/aglv/Horos/commit/30c2cb3e22253375038d8c72251b3c9ae05f77f2)
Date:   Sun Sep 23 08:33:39 2012 +0000

misc


##### commit [559d1c43417eb670a52453ddc7d56178261a38c9](https://github.com/aglv/Horos/commit/559d1c43417eb670a52453ddc7d56178261a38c9)
Date:   Sun Sep 23 13:29:58 2012 +0000

DICOM: dont rename thread


##### commit [9947738b2d7f7c3cf92e87a6f1a9c65644fea489](https://github.com/aglv/Horos/commit/9947738b2d7f7c3cf92e87a6f1a9c65644fea489)
Date:   Tue Sep 25 09:37:24 2012 +0000

misc


##### commit [386cb39de5a131e4d0c98c228329ef12bbdb047d](https://github.com/aglv/Horos/commit/386cb39de5a131e4d0c98c228329ef12bbdb047d)
Date:   Tue Sep 25 15:53:42 2012 +0000

Protect DICOM server against unlimited queries and unlimited results


##### commit [93bdebcb5192c5949cd2ad360081e0cf43f13eb1](https://github.com/aglv/Horos/commit/93bdebcb5192c5949cd2ad360081e0cf43f13eb1)
Date:   Mon Oct 8 17:20:09 2012 +0000

DICOM Files retrieving: refresh database at first and last file received


##### commit [69cd36da615fa956e36be927f98200955c502b32](https://github.com/aglv/Horos/commit/69cd36da615fa956e36be927f98200955c502b32)
Date:   Wed Oct 10 14:50:00 2012 +0000

Dont use std::nothrow


##### commit [40bea40d27c79c82225c5457e8ebab896fe0d3c5](https://github.com/aglv/Horos/commit/40bea40d27c79c82225c5457e8ebab896fe0d3c5)
Date:   Thu Oct 11 15:48:35 2012 +0000

LogManager


##### commit [07386a6b1fe06fbf71ff426d7db6049dc4a0eafa](https://github.com/aglv/Horos/commit/07386a6b1fe06fbf71ff426d7db6049dc4a0eafa)
Date:   Tue Nov 6 12:35:28 2012 +0000

Correct logging for CGET SCP


##### commit [1cbf7a5bf510bff9c38a55c2d0105a4ad32dc481](https://github.com/aglv/Horos/commit/1cbf7a5bf510bff9c38a55c2d0105a4ad32dc481)
Date:   Fri Nov 16 05:50:53 2012 +0000

misc


##### commit [6dfbbbd138c66bafc7ee2d113ac02ba5e3f2af4c](https://github.com/aglv/Horos/commit/6dfbbbd138c66bafc7ee2d113ac02ba5e3f2af4c)
Date:   Fri Nov 16 09:27:19 2012 +0000

replacing all '@selector( ' with '@selector(' so we can more easliy navigate code


##### commit [0413827d6905dbd378b03ad5b8e52168569f09ca](https://github.com/aglv/Horos/commit/0413827d6905dbd378b03ad5b8e52168569f09ca)
Date:   Sat Nov 17 17:07:48 2012 +0000

DICOM Network logs: Cocoa based (NSDictionary)


##### commit [e7e2d909c0893410ee92473f4c80f844cde876b9](https://github.com/aglv/Horos/commit/e7e2d909c0893410ee92473f4c80f844cde876b9)
Date:   Tue Dec 4 08:01:46 2012 +0000

C-FIND SCP: small memory leak corrected


##### commit [42b551b560909c5c0e964e910e17a85f64b9856f](https://github.com/aglv/Horos/commit/42b551b560909c5c0e964e910e17a85f64b9856f)
Date:   Tue Dec 4 08:44:40 2012 +0000

DICOM SCP: code cleaning for assoc release


##### commit [d94c831ffea83914eb43ea5642f9593b3c86fe6c](https://github.com/aglv/Horos/commit/d94c831ffea83914eb43ea5642f9593b3c86fe6c)
Date:   Tue Dec 4 10:46:09 2012 +0000

DCMTK memory leak in destroyAssociationKey, corrected


##### commit [773d22f2447c361c98d586ccf16a144cc0f5abfe](https://github.com/aglv/Horos/commit/773d22f2447c361c98d586ccf16a144cc0f5abfe)
Date:   Wed Jan 30 12:28:59 2013 +0000

MD-89


##### commit [43f04e6a946d56be4686516b520915ddd43d83be](https://github.com/aglv/Horos/commit/43f04e6a946d56be4686516b520915ddd43d83be)
Date:   Tue Feb 26 18:44:57 2013 +0100

MD-155

##### commit [9b7c7c7968d59c37cd85895830d1e711b3e8db3d](https://github.com/aglv/Horos/commit/9b7c7c7968d59c37cd85895830d1e711b3e8db3d)
Date:   Thu Feb 28 09:13:14 2013 +0100

MD-160

Option to turn off C-FIND SCP support

##### commit [23ebdbc2c6fe7f7938fd858f58baba59ad1a135f](https://github.com/aglv/Horos/commit/23ebdbc2c6fe7f7938fd858f58baba59ad1a135f)
Date:   Mon Mar 11 18:39:14 2013 +0100

MD-190

UID_EncapsulatedCDAStorage

##### commit [771e1fcba267ee30881a43c95fc6a02c0b3825d5](https://github.com/aglv/Horos/commit/771e1fcba267ee30881a43c95fc6a02c0b3825d5)
Date:   Thu Mar 14 17:20:23 2013 +0100

MD-198

DCMTK bug corrected; Decompress process now in 64-bit;

##### commit [2c2b1e864c9e0547033d6eb1ce7c267931618a3a](https://github.com/aglv/Horos/commit/2c2b1e864c9e0547033d6eb1ce7c267931618a3a)
Date:   Wed Mar 20 08:56:38 2013 +0100

MD-203

##### commit [e12b8689730cc0afd7ebeb0ccf91339eda0b9d68](https://github.com/aglv/Horos/commit/e12b8689730cc0afd7ebeb0ccf91339eda0b9d68)
Date:   Wed Apr 10 09:44:29 2013 +0200

MD-259

And limits number of processors for JP2K compression

##### commit [dc1e6c3476dc0ef14ad9fcaa401600b6b2bc2081](https://github.com/aglv/Horos/commit/dc1e6c3476dc0ef14ad9fcaa401600b6b2bc2081)
Date:   Thu Apr 11 11:26:51 2013 +0200

MD-233

##### commit [66127e94f6cdc6bc6a0b72e8833a909e8c13bd2e](https://github.com/aglv/Horos/commit/66127e94f6cdc6bc6a0b72e8833a909e8c13bd2e)
Date:   Thu Apr 11 14:06:31 2013 +0200

MD-233

##### commit [3aaa98ac603cbc5f51b9e34af4950aa100420672](https://github.com/aglv/Horos/commit/3aaa98ac603cbc5f51b9e34af4950aa100420672)
Date:   Sat May 18 18:20:01 2013 +0200

MD-349

##### commit [cb5fe7f1fca82b482c5fec02ea8c3b450556df87](https://github.com/aglv/Horos/commit/cb5fe7f1fca82b482c5fec02ea8c3b450556df87)
Date:   Sat May 18 18:56:19 2013 +0200

MD-349

##### commit [c6f133f9d16b2d86c7282f3ccea061e2b5f23c8f](https://github.com/aglv/Horos/commit/c6f133f9d16b2d86c7282f3ccea061e2b5f23c8f)
Date:   Sat May 18 19:05:07 2013 +0200

MD-349

##### commit [94f257ebd7b5d71258b652b836f5847053975d9e](https://github.com/aglv/Horos/commit/94f257ebd7b5d71258b652b836f5847053975d9e)
Date:   Sat May 18 19:34:21 2013 +0200

MD-349

##### commit [f8e0c98618fb0f4e253ce0bcae2ef8fdaa8e54a1](https://github.com/aglv/Horos/commit/f8e0c98618fb0f4e253ce0bcae2ef8fdaa8e54a1)
Date:   Sun May 19 00:33:30 2013 +0200

MD-349

##### commit [feadd323631aaf4314d72bcf5300c293d075f571](https://github.com/aglv/Horos/commit/feadd323631aaf4314d72bcf5300c293d075f571)
Date:   Mon May 20 17:31:25 2013 +0200

MD-350

##### commit [bc8b3faa8dffc5f3c2ff7ce64d131786bed52b99](https://github.com/aglv/Horos/commit/bc8b3faa8dffc5f3c2ff7ce64d131786bed52b99)
Date:   Fri Jun 21 13:43:38 2013 +0200

MD-438

##### commit [a6a9bb65ff0b52af695d94ece837cb10113173cd](https://github.com/aglv/Horos/commit/a6a9bb65ff0b52af695d94ece837cb10113173cd)
Date:   Fri Jun 21 18:03:19 2013 +0200

MD-438

##### commit [87acd613bd8b749d3fe041aca4b985e67b9e5f62](https://github.com/aglv/Horos/commit/87acd613bd8b749d3fe041aca4b985e67b9e5f62)
Date:   Sat Aug 3 11:54:21 2013 +0200

JP2K compression: avoid int overflow

##### commit [537931decfc8577c6d6958873983a6a25253f867](https://github.com/aglv/Horos/commit/537931decfc8577c6d6958873983a6a25253f867)
Date:   Sat Aug 3 15:50:23 2013 +0200

JP2K compression: avoid int overflow

##### commit [7f5dc9303f2c54d99aec1c9753ee6b034edad4eb](https://github.com/aglv/Horos/commit/7f5dc9303f2c54d99aec1c9753ee6b034edad4eb)
Date:   Thu Aug 8 13:53:47 2013 +0200

MD-520

##### commit [1c66212f5243c46a5d649d0e7b32597296cc1685](https://github.com/aglv/Horos/commit/1c66212f5243c46a5d649d0e7b32597296cc1685)
Date:   Thu Oct 24 18:58:48 2013 +0200

MD-695

##### commit [a4c440977d9b579e362e539d1b2e8ec656754ceb](https://github.com/aglv/Horos/commit/a4c440977d9b579e362e539d1b2e8ec656754ceb)
Date:   Fri Nov 8 13:33:21 2013 +0100

MD-507

##### commit [e0c75e4ad019f4363fcb0c20762635da7c9728ed](https://github.com/aglv/Horos/commit/e0c75e4ad019f4363fcb0c20762635da7c9728ed)
Date:   Sun Dec 8 16:17:13 2013 +0100

MD-809

##### commit [3085e28b045e81bb2bd8767c3ef3e35717722cbd](https://github.com/aglv/Horos/commit/3085e28b045e81bb2bd8767c3ef3e35717722cbd)
Date:   Thu Jan 16 17:36:24 2014 +0100

MD-888

##### commit [96d0d2d91d5cc323d3e7716bcdb76ea63bf51c62](https://github.com/aglv/Horos/commit/96d0d2d91d5cc323d3e7716bcdb76ea63bf51c62)
Date:   Mon Feb 3 15:41:56 2014 +0100

Force 8 bits for samplesPerPixel > 1 (from PALETTE 16 bits)

##### commit [1afbaf8c1f266431db527379239c7ed8d0d26a13](https://github.com/aglv/Horos/commit/1afbaf8c1f266431db527379239c7ed8d0d26a13)
Date:   Mon Feb 10 17:26:52 2014 +0100

TimeOut for store SCU

##### commit [797fa15c8c31aff596ae95a6d9d9c47e8623fc5d](https://github.com/aglv/Horos/commit/797fa15c8c31aff596ae95a6d9d9c47e8623fc5d)
Date:   Sun Feb 23 22:01:12 2014 +0100

misc (OpenGL error on ROI arrow)

##### commit [bea2383a85b94410ac7ef373c55621e0ac16ccce](https://github.com/aglv/Horos/commit/bea2383a85b94410ac7ef373c55621e0ac16ccce)
Date:   Tue Feb 25 09:51:47 2014 +0100

unused variables

##### commit [cf1bc913088f28c34afbb69d9dbdec899994d63c](https://github.com/aglv/Horos/commit/cf1bc913088f28c34afbb69d9dbdec899994d63c)
Date:   Tue Feb 25 15:50:28 2014 +0100

unused variables

##### commit [a4f67d42c006fd7adc0a86bdce2e48fa7dde9062](https://github.com/aglv/Horos/commit/a4f67d42c006fd7adc0a86bdce2e48fa7dde9062)
Date:   Sat Mar 15 15:59:25 2014 +0100

Xcode 5.1

##### commit [08db8611e5db99218b3ee4d03b0da3d9046a9620](https://github.com/aglv/Horos/commit/08db8611e5db99218b3ee4d03b0da3d9046a9620)
Date:   Sat Apr 19 11:01:10 2014 +0200

v.5.9

##### commit [81590e691dc571ce114fc957019ddb6f9cc1336f](https://github.com/aglv/Horos/commit/81590e691dc571ce114fc957019ddb6f9cc1336f)
Date:   Tue Nov 25 15:42:28 2014 +0900

First ##### commit [to build the 64-bit application](https://github.com/aglv/Horos/commit/to build the 64-bit application)

##### commit [2aa9d0cffbf01db1e45469c7a4768dd771840abf](https://github.com/aglv/Horos/commit/2aa9d0cffbf01db1e45469c7a4768dd771840abf)
Date:   Fri Jan 30 16:48:33 2015 -0500

Removed References

##### commit [8d405d4ab090a32cb02e640a66d1e89e8b938952](https://github.com/aglv/Horos/commit/8d405d4ab090a32cb02e640a66d1e89e8b938952)
Date:   Wed Feb 18 11:54:07 2015 -0500

Updated Copyright Information

##### commit [cd9816ea32354135b4cb0cee5de0e6a7d495e542](https://github.com/aglv/Horos/commit/cd9816ea32354135b4cb0cee5de0e6a7d495e542)
Date:   Mon Mar 2 14:44:43 2015 -0500

JPEG2000 Encoding, Plist Naming, Web Server Rebranding

##### commit [637d7e38d528ae72d821974f7200cd7ff74fd94e](https://github.com/aglv/Horos/commit/637d7e38d528ae72d821974f7200cd7ff74fd94e)
Date:   Sun Aug 16 18:21:01 2015 -0300

Keep dummy variable isolated to module

##### commit [d178d549579d8d6fb4a602bef99c70135edb359b](https://github.com/aglv/Horos/commit/d178d549579d8d6fb4a602bef99c70135edb359b)
Date:   Sun Oct 11 20:09:08 2015 -0300

Image files can be directly imported into Horos DB

##### commit [71c5742671cad0c9895f53bd148bea7eae22a350](https://github.com/aglv/Horos/commit/71c5742671cad0c9895f53bd148bea7eae22a350)
Date:   Thu Nov 12 02:03:00 2015 -0200

Reliability Improvements of J2K Codec

##### commit [758fc09845e0724af35f72fa4fb7fd9bab2e28a0](https://github.com/aglv/Horos/commit/758fc09845e0724af35f72fa4fb7fd9bab2e28a0)
Date:   Tue Nov 24 17:17:10 2015 -0200

[REF] License term updated on .m and .mm files

##### commit [83026738b2e18b106441597ecc06907293288d7f](https://github.com/aglv/Horos/commit/83026738b2e18b106441597ecc06907293288d7f)
Date:   Wed Feb 3 18:43:41 2016 -0200

[REF] Type casting for enabling future SDK migration
