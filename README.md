# Combinatory Logic in C++

This repo was coded via the livestreams linked below:

* 1️⃣ [Combinatory Logic in C++](https://www.youtube.com/watch?v=Y0KKPYkeOTA)
* 2️⃣ [Refactoring C++](https://www.youtube.com/watch?v=4rGxav_T7gs)
* 3️⃣ [Combinatory Logic in C++ & Python (Part 2)](https://youtube.com/live/PMsJl8fxcOU)

![image](https://user-images.githubusercontent.com/36027403/224843294-ff1a967b-0d5b-4f98-8500-854fd5da2017.png)

Results from more recent run:
```
B: ["S(KS)K", "SWCΦK", "SWSΦK", "CSSWΦK", "SCKΦWK", "WW(KS)K", "CSCWΦK", "S(SΦ)K", "WCSWΦK", "WΦCKSK"]
C: ["B(ΦBS)KK", "ΦBS(B₁Kκ)"]
B₂: ["SSBBB", "SSWBB", "SWBBB", "BBB₁", "SBSWBB", "SBWBBB", "BB₁B", "WSBBBB", "BWSSBB", "CSBSBB"]
B₁: ["BBB", "WWB", "WBB", "CWBB", "CWBW", "WCBB", "CBBB", "KWSWB", "BWWCB", "SSKBB"]
I: ["KK", "WK", "SKS", "Wκ", "Cκ", "SKC", "κC", "WCK", "WKK", "SKK"]
K: ["κW", "Cκ", "κS", "κC", "κB", "Wκ", "κκ", "κΦ", "BκSC", "WSκB"]
M: ["SBK", "SWK", "BWBK", "BWWK", "WBWK", "CSKB", "CSKW", "CBWWK", "WWSBK", "BWκC"]
Φ: ["BBBSB", "WWBSB", "WBBSB", "CBBBSB", "B₁SB", "WCBBSB", "CWBBSB", "B(BS)B", "CWBWSB", "CB₁BS"]
Ψ: ["B(SΦCB)B"]
R: ["CC", "KCBC", "KCWC", "KCSC", "KCKC", "WKCC", "BKCC", "SKWCC", "BKCCK", "BBCSK"]
S: ["BΦBK", "BΦWK", "BΦκC", "CBBΦK", "WCBΦK", "BΦWκ", "BΦκB", "CBWΦK", "BΦκK", "BΦκW"]
W: ["CSK", "SSκ", "SCκ", "CCKS", "KCCSK", "CSκS", "CSκC", "KCBSK", "KCSSK", "SCκS"]
κ: ["CK", "SK", "ΦBK", "WΦK", "WKSK", "WKCK", "SWSK", "SWCK", "SBSK", "SBCK"]
```
Results from another recent run:
```
B: ["DWDK", "DDWK", "DDCK", "SWSDK", "WCDWK", "DWΦK", "CDWDK", "B₃K", "CDDWK", "CDCDK", "SWCDK", "ΦDKC", "ΦDKD", "ΦDKK", "ΦDKS", "ΦDKW", "ΨCKS", "ΨWKS", "WDWCDK", "WKDDCK", "DDCCSK", "DDCKSK", "WDWSDK", "WDWKSK", "D(CKS)", "WKDWDK", "D(CKK)", "DDWKSK", "D(CKD)", "WCSWDK"]
C: ["WSDSKK", "SDDSKK", "BDΨWKS", "B(ΨWK)S", "W(WSDS)K", "D(ΨW)KS", "DS(DS)KK", "W(SDDS)K", "Ψ(BSW)K", "Ψ(BWBS)K", "D₁ΨWKS", "D₂SDSKK", "Ψ(SWBS)K", "B(ΦBS)KK", "BB(ΨW)KS", "BΨ(BS)WK", "BΨW(BS)K", "D(ΦB)SKK", "ΦBS(ΦBK)", "ΦBS(ΦKK)", "D₁ΦBSKK", "ΦBS(WΦK)", "B₁ΨBSWK", "B₃ΨWBSK", "SBΦ(ΨWK)", "B₁BΨWKS", "D₁SB(KK)S", "D₂(SB)KKS", "W(D₂SDS)K", "Ψ(ΨΦWK)K"]
D: ["BB", "CBB", "WCB", "KBCB", "KBSB", "WΨB", "CCBB", "KBWB", "KBBB", "CWBC", "BKBB", "ΨBB", "SSKB", "KBKB", "WKBB", "BSKB", "SCBBK", "CSKSB", "BKBBS", "KCWBB", "BKBBK", "KCSBB", "BKBBC", "CBBKB", "SBKBS", "SKSBB", "SBKBW", "KBΨB", "κKBB", "BKBBB"]
B₂: ["WBDB", "DDBB", "SBDB", "BDDB", "CWDBB", "BWDDB", "WDBDB", "CBDDB", "CSDBB", "CDBDB", "SCDBB", "BBDBB", "SSBBB", "SWBBB", "DB₁", "SSWBB", "DBBDB", "ΦSKDB", "KWWBDB", "KWCBDB", "BWSWBB", "BWSSBB", "SWKDDB", "B(DB)B", "BWCBDB", "BWBWDB", "BSWCDB", "BSKDDB", "BSCBDB", "BDWWBB"]
B₃: ["BDB", "WDBB", "CBBD", "DBBB", "WCBD", "CCBBD", "CWBCD", "BSKDB", "KBCDB", "WWBBB", "KBWDB", "KBSDB", "KBKDB", "KBDDB", "KBBDB", "D₁B", "CWBDB", "BWWDB", "WKBDB", "BWDBB", "WBBBB", "SWKDB", "SSKBD", "CDBBB", "WBWDB", "SKBBDB", "κBBDB", "CWWBDB", "κCBDB", "CWBWBB"]
B₁: ["DB", "BBB", "WBB", "WWB", "KDWB", "BKDB", "KDKB", "KDDB", "DDSK", "CBBB", "KDBB", "WKDB", "KDSB", "KDCB", "CWBW", "WCBB", "CWBB", "WBWCB", "CDSDK", "DWKDB", "SκDB", "SKWDB", "SKBDB", "KWBWB", "SKCDB", "CKWDB", "KWBBB", "KDΦB", "SSKBB", "CKSDB"]
I: ["KK", "WK", "DK", "κB", "WKK", "Cκ", "KKC", "κK", "KKW", "CKW", "κW", "KKB", "SKC", "CKS", "DKK", "SKD", "KKS", "WSK", "WBK", "CKK", "SKS", "κD", "κC", "CKD", "CKB", "CKC", "WCK", "WWK", "Wκ", "SKW"]
K: ["Cκ", "κC", "κS", "κB", "κD", "Wκ", "κW", "κκ", "κΨ", "κΦ", "BκBC", "BκSW", "BκDB", "BκBD", "SSWκ", "SCCκ", "BκSS", "BκBS", "BκDC", "BκBB", "WSκW", "BκDD", "SWκB", "SWWκ", "WBκC", "BκSD", "WWκS", "WBκW", "BκCC", "BκWD"]
M: ["SWK", "SDK", "SBK", "CSKD", "DWWK", "BWWK", "BWBK", "WBWK", "CSKW", "CSKB", "DWCK", "WDWK", "DWSK", "BSCWK", "DWCWK", "WCWDK", "DCBKK", "CDCWK", "WCWBK", "CWWDK", "BSCCK", "SWκC", "CBWWK", "SWCSK", "WSSWK", "KSBBK", "SDWWK", "KSBDK", "KSBWK", "SBBWK"]
Φ: ["DBSB", "WBBSB", "BBBSB", "SDKSB", "WWBSB", "CDSBB", "CBBBSB", "CCSDBB", "WKDBSB", "DDSKSB", "KDWBSB", "KDSBSB", "KDKBSB", "KDDBSB", "KDCBSB", "KDBBSB", "WCBBSB", "B(BS)B", "CSKDSB", "BCDBBS", "CWBBSB", "B₁SB", "CWBWSB", "BΨBKBS", "κWDBSB", "DS(KS)B", "κKDBSB", "WκDBSB", "WBΨKBS", "KDκBSB"]
Ψ: ["ΦDΦCBB", "DDSCCD₂", "D(SΦC)BB", "B(SΦCB)B", "W(ΦDΦC)B", "DS(CC)D₂", "BW(B₃DCD)", "D(BSC)CD₂", "D₂SCCD₂", "D₂SD(CB)B", "DS(D₁CB)B", "B₃(BWD)CD", "BW(DD₁CD)", "BW(DBCD₂)", "B₃WD(BCD)", "BBS(CC)D₂", "W(DDS)CD₂", "B(B₃WDC)D", "B₃W(BDC)D", "B(BSCC)D₂", "B(DS)CCD₂", "S(D₁Φ)CBB", "B₃BSCCD₂", "ΦW(D₂S)DC", "DB₃WD₁CD", "DB₃WBCD₂", "D₂(ΦB)CBB", "BWD₂SCD₂", "D₁(SΦ)CBB", "D₁ΦB(CB)B"]
R: ["CC", "KCBC", "DSCK", "DCCK", "KCKC", "WDCK", "WKCC", "KCDC", "KCSC", "KCWC", "DCSK", "BKCC", "SKWCC", "WSKCC", "SKSCC", "BKCCB", "ΨKCC", "SBKCW", "SBKCS", "BWWKC", "SBKCK", "SκCC", "CWCDK", "SKKCC", "SBKCD", "SBKCC", "κDCC", "SBKCB", "BKCCS", "BWBKC"]
S: ["BΦWK", "BΦBK", "CBBΦK", "BΦΨK", "WCBΦK", "BΦκW", "BΦκK", "DCΦBK", "CBWΦK", "BΦκD", "DCΦWK", "BΦκB", "BΦκC", "BΦWκ", "DCΦκD", "KBDΦBK", "WDCBKΦ", "CCBBΦK", "WDCWKΦ", "DBΦCKD", "CBκΦW", "DBΦCKC", "DBΦCKB", "DBΦBWK", "DBΦBCK", "DCΦκC", "Φ(CKW)", "CWBCΦK", "KBDΦWK", "DCΦκB"]
W: ["CSK", "CCKS", "SCκ", "SSκ", "CSκS", "KCDSK", "DSCSK", "KCCSK", "DCCSK", "KCBSK", "DCSDK", "SCκS", "DSSCK", "KCSSK", "CSκC", "DSSKK", "DSCCK", "DSDCSK", "KCDCKS", "DSCKKS", "DSCKκ", "BBSCSK", "BBSCCK", "BΦCBK", "SKDCSK", "DCSκD", "SKBCSK", "DCCKκ", "DCSκC", "DCSκB"]
D₂: ["DD", "BBD", "DBDB", "WKDD", "KDBD", "SBBB", "BKDD", "KDSD", "KDWD", "KDCD", "CBDB", "KDKD", "WSBB", "BDBB", "SKCDD", "SκDD", "KBWBD", "WSKDD", "SKKDD", "BWBKD", "BWBDB", "ΨKDD", "CKKDD", "κWDD", "CCDBB", "SKBDD", "κBDD", "SBKDB", "SBKDC", "BWKDD"]
D₁: ["BD", "WDB", "DBB", "CBD", "KBCD", "KBSD", "SCBB", "BKBD", "CWBD", "BBBB", "KBWD", "WBBB", "SWKD", "CCDB", "CΨB", "BSKD", "CDBB", "KBDD", "KBKD", "WKBD", "KBBD", "WWBB", "BWKBD", "κSBD", "KDSBB", "DSBKD", "KCBBD", "KCCBD", "WκBD", "κWBD"]
κ: ["SK", "CK", "KSSK", "DCKW", "DCKD", "DSKD", "KCWK", "KSDK", "DCKK", "DSKK", "DCKS", "DSKS", "DSKW", "BSDK", "KCCK", "WΦK", "KSBK", "ΦBK", "KCBK", "ΦKK", "BKSK", "SDSK", "SDCK", "KSCK", "WKSK", "SBCK", "KCSK", "BKCK", "KCDK", "KSWK"]
```
