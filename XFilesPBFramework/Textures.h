#define _TEXTURES_H

#include "RawTextures.h"
#define playersswat ((Stride == 52) || (Stride == 64) || (Stride == 32))
#define playersterror ((Stride == 44) || (Stride == 48) || (Stride == 32))
//#define dc5 ((����� �������� �5 ��))


#define Dino ((primCount == 57) || (primCount == 161) || (primCount == 186) || (primCount == 197) || (primCount == 349) || (primCount == 495) || (primCount == 955) || (NumVertices == 2517 && primCount == 57) || (NumVertices == 3721 && primCount == 275) || (NumVertices == 0 && primCount == 52) || (NumVertices == 0 && primCount == 105) || (NumVertices ==0 && primCount == 186) || (NumVertices == 0 && primCount == 197) || (primCount == 579) || (primCount == 488))
#define K400 ((NumVertices == 1002 && primCount == 980))
#define C5 ((NumVertices == 772 && primCount == 849))
#define NewT ((NumVertices == 60 && primCount == 122) || (NumVertices == 150 && primCount == 186)||(NumVertices == 593 && primCount == 774) || (NumVertices == 650 && primCount == 830)||(NumVertices == 3952 && primCount == 1280) || (NumVertices == 421 && primCount == 504)||(NumVertices == 478 && primCount == 604) || (NumVertices == 549 && primCount == 960)||(NumVertices == 68 && primCount == 57) || (NumVertices == 117 && primCount == 116)||(NumVertices == 257 && primCount == 433) || (NumVertices == 367 && primCount == 437)||(NumVertices == 1271 && primCount == 866))
#define NewT_H ((NumVertices == 593 && primCount == 744)||(NumVertices == 478 && primCount == 604) || (NumVertices == 367 && primCount == 437))
#define NewCT ((NumVertices == 118 && primCount == 195) || (NumVertices == 198 && primCount == 310)||(NumVertices == 589 && primCount == 755) || (NumVertices == 1085 && primCount == 1962)||(NumVertices == 3412 && primCount == 1677) || (NumVertices == 43 && primCount == 38)||(NumVertices == 491 && primCount == 613) || (NumVertices == 600 && primCount == 1062)||(NumVertices == 1729 && primCount == 1909) || (NumVertices == 296 && primCount == 492)||(NumVertices == 386 && primCount == 466) || (NumVertices == 942 && primCount == 840))
#define NewCT_H ((NumVertices == 491 && primCount == 613)||(NumVertices == 386 && primCount == 466) || (NumVertices == 589 && primCount == 755))
#define PlayerAlmapsTero ( primCount == 108 || primCount == 341 || primCount == 304 || primCount == 266 )
#define PlayerAlmapsCete ( primCount == 504 || primCount == 270 || NumVertices == 338 || NumVertices == 154 || NumVertices == 661 || NumVertices == 366 || primCount == 218 || primCount == 254 || primCount == 400 || primCount == 281 || primCount == 426 || NumVertices == 363 || NumVertices == 638)
#define playerHEAD ((NumVertices == 628 || primCount == 748)) || ((NumVertices == 186 || primCount == 214)) || ((NumVertices == 348 || primCount == 520)) || ((NumVertices == 638 || primCount == 648)) || ((primCount == 562)) 
#define tesaja ( Stride == 90 || Stride == 62 || Stride == 32 || Stride == 36 || NumVertices == 684 ||NumVertices == 611||NumVertices == 108 || Stride == 76 || NumVertices == 80 || NumVertices == 133 || NumVertices == 490 || NumVertices == 99 || NumVertices == 221 || NumVertices == 95 || NumVertices == 78 || NumVertices == 520 || NumVertices == 684 || NumVertices == 490 /*|| (Stride == 32 && primCount == 526)||(Stride == 32 && primCount == 84)*/)
#define testeraja ((Stride == 78)||(Stride == 41)||(Stride == 52)||(Stride == 36) || (Stride == 36) || (Stride == 32)|| (Stride == 64)|| (Stride == 68))
#define Leopard ( primCount == 504 || primCount == 270 || NumVertices == 338 || NumVertices == 154 || NumVertices == 661 || NumVertices == 366 || primCount == 218 || primCount == 254 || primCount == 400 || primCount == 281 || primCount == 426 || NumVertices == 363 || NumVertices == 638)
#define playerHEAD ((NumVertices == 628 || primCount == 748)) || ((NumVertices == 186 || primCount == 214)) || ((NumVertices == 348 || primCount == 520)) || ((NumVertices == 638 || primCount == 648)) || ((primCount == 562)) 
#define TeamX ( Stride == 90 || Stride == 62 || Stride == 32 || Stride == 36 || NumVertices == 684 ||NumVertices == 611||NumVertices == 108 || Stride == 76 || NumVertices == 80 || NumVertices == 133 || NumVertices == 490 || NumVertices == 99 || NumVertices == 221 || NumVertices == 95 || NumVertices == 78 || NumVertices == 520 || NumVertices == 684 || NumVertices == 490 || (Stride == 32 && primCount == 526)||(Stride == 32 && primCount == 84))


#define CT /*����� ������*/((Stride == 44 && NumVertices == 154) || (Stride == 44 && NumVertices == 338)\
	 || (Stride == 44 && NumVertices == 661) || (Stride == 44 && NumVertices == 1053) || (Stride == 32 && NumVertices == 818)\
/*��� �������� ������*/ || (NumVertices == 40 && primCount == 50) || (NumVertices == 38 && primCount == 52)\
	 || (NumVertices == 270 && primCount == 354) || (NumVertices == 259 && primCount == 472)\
	 || (NumVertices == 638 && primCount == 648) || (NumVertices == 988 && primCount == 708)\
	 || (NumVertices == 3155 && primCount == 1134) || (NumVertices == 1253 && primCount == 1660)\
     || (NumVertices == 3155 && primCount == 1678)\
/*��� �� �� ������*/ || (NumVertices == 366 && primCount == 270) || (NumVertices == 4705 && primCount == 281)\
	 || (NumVertices == 363 && primCount == 636) || (NumVertices == 4705 && primCount == 660)\
	 || (NumVertices == 4705 && primCount == 987) || (NumVertices == 4705 && primCount == 2442)\
/*��� +30% ������*/ || (NumVertices == 12 && primCount == 8) || (NumVertices == 20 && primCount == 16)\
	 || (NumVertices == 21 && primCount == 19) || (NumVertices == 30 && primCount == 36)\
	 || (NumVertices == 39 && primCount == 44) || (NumVertices == 79 && primCount == 120)\
	 || (NumVertices == 101 && primCount == 150) || (NumVertices == 186 && primCount == 218)\
	 || (NumVertices == 3796 && primCount == 254) || (NumVertices == 3796 && primCount == 320)\
	 || (NumVertices == 307 && primCount == 320) || (NumVertices == 324 && primCount == 400)\
	 || (NumVertices == 854 && primCount == 1494) || (NumVertices == 1619 && primCount == 1946)\
	 || (NumVertices == 3796 && primCount == 3152)\
/*��� �������*/ || (NumVertices == 17 && primCount == 8)\
	 || (NumVertices == 78 && primCount == 56) || (NumVertices == 95 && primCount == 110)\
	 || (NumVertices == 125 && primCount == 185) || (NumVertices == 221 && primCount == 240)\
	 || (NumVertices == 520 && primCount == 592) || (NumVertices == 33 && primCount == 20)\
	 || (NumVertices == 128 && primCount == 102) || (NumVertices == 200 && primCount == 230)\
	 || (NumVertices == 227 && primCount == 373) || (NumVertices == 285 && primCount == 214)\
	 || (NumVertices == 654 && primCount == 706) || (NumVertices == 998 && primCount == 1154)\
	 || (NumVertices == 62 && primCount == 110) || (NumVertices == 88 && primCount == 42)\
	 || (NumVertices == 95 && primCount == 102) || (NumVertices == 167 && primCount == 100)\
	 || (NumVertices == 223 && primCount == 246) || (NumVertices == 361 && primCount == 406)\
	 || (NumVertices == 113 && primCount == 208) || (NumVertices == 134 && primCount == 90)\
	 || (NumVertices == 198 && primCount == 212) || (NumVertices == 307 && primCount == 183)\
	 || (NumVertices == 595 && primCount == 725) || (NumVertices == 793 && primCount == 885)\
	 || (NumVertices == 67 && primCount == 110) || (NumVertices == 85 && primCount == 56)\
	 || (NumVertices == 95 && primCount == 102) || (NumVertices == 490 && primCount == 504)\
	 /*��� �������*/ || (NumVertices == 198 && primCount == 212) || (NumVertices == 307 && primCount == 183)\
	|| (NumVertices == 134 && primCount == 90) || (NumVertices == 285 && primCount == 94)\
	|| (NumVertices == 595 && primCount == 752) || (NumVertices == 793 && primCount == 885)\
	|| (NumVertices == 118 && primCount == 208) || (NumVertices == 141 && primCount == 102)\
	|| (NumVertices == 198 && primCount == 212) || (NumVertices == 592 && primCount == 453)\
	|| (NumVertices == 1184 && primCount == 1387) || (NumVertices == 133 && primCount == 150)\
	|| (NumVertices == 128 && primCount == 102) || (NumVertices == 143 && primCount == 100)\
	|| (NumVertices == 200 && primCount == 238) || (NumVertices == 227 && primCount == 373)\
	|| (NumVertices == 654 && primCount == 706) || (NumVertices == 998 && primCount == 1154))
#define T /*��� �� �� ������*/((NumVertices == 88 && primCount == 130) || (NumVertices == 142 && primCount == 266)\
	 || (NumVertices == 472 && primCount == 304) || (NumVertices == 384 && primCount == 346)\
	 || (NumVertices == 348 && primCount == 520) || (NumVertices == 596 && primCount == 590)\
	 || (NumVertices == 628 && primCount == 748) || (NumVertices == 3487 && primCount == 1737)\
	 || (NumVertices == 3487 && primCount == 1766)\
/*��� �� �� ������*/ || (NumVertices == 262 && primCount == 196) || (NumVertices == 142 && primCount == 266)\
	 || (NumVertices == 244 && primCount == 406) || (NumVertices == 1846 && primCount == 414)\
	 || (NumVertices == 528 && primCount == 540) || (NumVertices == 520 && primCount == 593)\
	 || (NumVertices == 2728 && primCount == 1344) || (NumVertices == 1091 && primCount == 1390)\
	 || (NumVertices == 1095 && primCount == 1460) || (NumVertices == 1846 && primCount == 2090)\
/*��� +20% ������*/|| (NumVertices == 2263 && primCount == 45) || (NumVertices == 370 && primCount == 278)\
	 || (NumVertices == 482 && primCount == 390) || (NumVertices == 734 && primCount == 688)\
	 || (NumVertices == 2263 && primCount == 1023) || (NumVertices == 812 && primCount == 1246)\
	 || (NumVertices == 2263 && primCount == 1434)\
/*��� +30% ������*/|| (NumVertices == 2041 && primCount == 1561) || (NumVertices == 1530 && primCount == 1534)\
	 || (NumVertices == 749 && primCount == 1374) || (NumVertices == 1831 && primCount == 1267)\
	 || (NumVertices == 2010 && primCount == 426) || (NumVertices == 287 && primCount == 396)\
	 || (NumVertices == 1831 && primCount == 341) || (NumVertices == 1831 && primCount == 278)\
	 || (NumVertices == 185 && primCount == 254) || (NumVertices == 74 && primCount == 66)\
	 || (NumVertices == 56 && primCount == 40) || (NumVertices == 185 && primCount == 271)\
/*��� �������*/|| (NumVertices == 45 && primCount == 56) || (NumVertices == 92 && primCount == 56)\
	 || (NumVertices == 611 && primCount == 114)\
	 || (NumVertices == 611 && primCount == 526) || (NumVertices == 18 && primCount == 12)\
	 || (NumVertices == 96 && primCount == 92)\
	 || (NumVertices == 99 && primCount == 61) || (NumVertices == 133 && primCount == 205)\
	 || (NumVertices == 245 && primCount == 276) || (NumVertices == 398 && primCount == 487)\
	 || (NumVertices == 26 && primCount == 20) || (NumVertices == 1204 && primCount == 241)\
	 || (NumVertices == 80 && primCount == 52) || (NumVertices == 1204 && primCount == 124)\
	 || (NumVertices == 113 && primCount == 139) || (NumVertices == 1204 && primCount == 56)\
	 || (NumVertices == 684 && primCount == 740) || (NumVertices == 1204 && primCount == 42)\
	 || (NumVertices == 45 && primCount == 56) || (NumVertices == 1204 && primCount == 35)\
	 || (NumVertices == 334 && primCount == 360)\
	 || (NumVertices == 175 && primCount == 246) || (NumVertices == 195 && primCount == 109)\
	 /*��� �������*/|| (NumVertices == 71 && primCount == 120) || (NumVertices == 88 && primCount == 130)\
	|| (NumVertices == 201 && primCount == 157) || (NumVertices == 224 && primCount == 200)\
	|| (NumVertices == 296 && primCount == 166) || (NumVertices == 1353 && primCount == 386)\
	|| (NumVertices == 18 && primCount == 20) || (NumVertices == 41 && primCount == 30)\
	|| (NumVertices == 62 && primCount == 67)\
	|| (NumVertices == 152 && primCount == 168) || (NumVertices == 202 && primCount == 174)\
	|| (NumVertices == 237 && primCount == 395) || (NumVertices == 647 && primCount == 716)\
	|| (NumVertices == 727 && primCount == 936) || (NumVertices == 90 && primCount == 136)\
	|| (NumVertices == 120 && primCount == 170) || (NumVertices == 142 && primCount == 128)\
	|| (NumVertices == 218 && primCount == 322) || (NumVertices == 285 && primCount == 94)\
	|| (NumVertices == 1316 && primCount == 1574) || (NumVertices == 1316 && primCount == 134)\
	|| (NumVertices == 56 && primCount == 158) || (NumVertices == 73 && primCount == 112)\
	|| (NumVertices == 143 && primCount == 94) || (NumVertices == 246 && primCount == 120)\
	|| (NumVertices == 353 && primCount == 464) || (NumVertices == 381 && primCount == 234)\
	|| (NumVertices == 547 && primCount == 700) || (NumVertices == 1353 && primCount == 1404))
#define playerheads/*����� ������*/ ((NumVertices == 196 && primCount == 242) || (NumVertices == 812 && primCount == 1246)\
	 || (NumVertices == 237 && primCount == 355) || (NumVertices == 184 && primCount == 240)\
	 || (NumVertices == 749 && primCount == 1374) || (NumVertices == 51 && primCount == 42)\
	 || (NumVertices == 133 && primCount == 205) || (NumVertices == 142 && primCount == 266)\
	 || (NumVertices == 628 && primCount == 748) || (NumVertices == 224 && primCount == 338)\
	 || (NumVertices == 1095 && primCount == 1460) || (NumVertices == 71 && primCount == 120)\
	 || (NumVertices == 338 && primCount == 446) || (NumVertices == 128 && primCount == 170)\
 	 || (NumVertices == 218 && primCount == 322) || (NumVertices == 45 && primCount == 56)\
	 || (NumVertices == 68 && primCount == 126) || (NumVertices == 67 && primCount == 84)\
	 || (NumVertices == 113 && primCount == 139) || (NumVertices == 175 && primCount == 246)\
	 || (NumVertices == 40 && primCount == 1115) || (NumVertices == 196 && primCount == 242)\
	 /*���� ������*/  || (NumVertices == 95 && primCount == 102) || (NumVertices == 62 && primCount == 110)\
	 || (NumVertices == 113 && primCount == 208) || (NumVertices == 198 && primCount == 212)\
	 || (NumVertices == 118 && primCount == 208) || (NumVertices == 259 && primCount == 472)\
	 || (NumVertices == 638 && primCount == 648) || (NumVertices == 67 && primCount == 110)\
	 || (NumVertices == 363 && primCount == 636) || (NumVertices == 638 && primCount == 648)\
	 || (NumVertices == 125 && primCount == 185) || (NumVertices == 70 && primCount == 80)\
 	 || (NumVertices == 79 && primCount == 120) || (NumVertices == 186 && primCount == 218)\
	 || (NumVertices == 854 && primCount == 1494) || (NumVertices == 115 && primCount == 122)\
 	 || (NumVertices == 133 && primCount == 150) || (NumVertices == 638 && primCount == 648))





// Red Bulls
#define kerahred (Stride==36&&((primCount==130&&NumVertices==88)||(primCount==50&&NumVertices==42)||(primCount==126&&NumVertices==68)))
#define headred (Stride==40&&((primCount==748&&NumVertices==628)||(primCount==446&&NumVertices==338)))
#define bodyred (Stride==44&&((primCount==520&&NumVertices==348)||(primCount==346&&NumVertices==384)||(primCount==304&&NumVertices==472)||(primCount==590&&NumVertices==596)||((primCount==485||primCount==1737||primCount==1766)&&NumVertices==3487)||(primCount==157&&NumVertices==201)||(primCount==200&&NumVertices==224)||(primCount==166&&NumVertices==296)||((primCount==386||primCount==1404)&&NumVertices==1353)||(primCount==56&&NumVertices==92)||(primCount==84&&NumVertices==108)||(primCount==64&&NumVertices==114)||((primCount==114||primCount==526)&&NumVertices==611)))
#define redbulls (kerahred||headred||bodyred)
// Keen Eyes
#define headayse (Stride==40&&((primCount==636&&NumVertices==363)||(primCount==208&&NumVertices==118)||(primCount==110&&NumVertices==67)))
#define bodyayse (Stride==44&&((primCount==270&&NumVertices==366)||((primCount==660||primCount==987||primCount==2442)&&NumVertices==4705)||(primCount==102&&NumVertices==141)||(primCount==1387&&NumVertices==1184)||(primCount==56&&NumVertices==85)||(primCount==504&&NumVertices==490)))
#define ayse (headayse||bodyayse)
// Tarantula
#define hairtar (Stride==36&&((primCount==593&&NumVertices==520)||(primCount==168&&NumVertices==139)||(primCount==60&&NumVertices==42)||(primCount==196&&NumVertices==262)))
#define bodytar (Stride==44&&((primCount==1344&&NumVertices==2728)||(primCount==406&&NumVertices==244)||(primCount==540&&NumVertices==528)||(primCount==1390&&NumVertices==1091)||(primCount==1460&&NumVertices==1095)||((primCount==414||primCount==2090)&&NumVertices==1846)||(primCount==128&&NumVertices==142)||(primCount==136&&NumVertices==90)||(primCount==322&&NumVertices==218)||((primCount==134||primCount==1574)&&NumVertices==1316)||(primCount==20&&NumVertices==26)||(primCount==52&&NumVertices==80)||(primCount==139&&NumVertices==113)||((primCount==44||primCount==740)&&NumVertices==684)))
#define tarantula (hairtar||bodytar)
// CT Hide
#define hairhide (Stride==36&&((primCount==8||primCount==12||primCount==14||primCount==16||primCount==19||primCount==36&&NumVertices==10||NumVertices==12||NumVertices==14||NumVertices==16||NumVertices==19||NumVertices==20||NumVertices==21||NumVertices==30)||(primCount==238&&NumVertices==200)||(primCount==110&&NumVertices==95)))
#define headhide (Stride==40&&(primCount==120&&NumVertices==79))
#define bodyhide (Stride==44&&((primCount==150&&NumVertices==101)||(primCount==320&&NumVertices==307)||(primCount==400&&NumVertices==324)||(primCount==1494&&NumVertices==854)||(primCount==1946&&NumVertices==1619)||((primCount==254||primCount==320||primCount==3152)&&NumVertices==3796)||(primCount==102&&NumVertices==128)||(primCount==138&&NumVertices==158)||(primCount==373&&NumVertices==227)||(primCount==706&&NumVertices==654)||(primCount==1154&&NumVertices==998)||(primCount==56&&NumVertices==78)||(primCount==78&&NumVertices==86)||(primCount==185&&NumVertices==125)||(primCount==240&&NumVertices==221)||(primCount==592&&NumVertices==520)))
#define hide (hairhide||headhide||bodyhide)
// Viper Red
#define hairviper (Stride==36&&((primCount==310&&NumVertices==342)||(primCount==56&&NumVertices==40)||(primCount==12&&NumVertices==12)||(primCount==20&&NumVertices==18)||(primCount==28&&NumVertices==24)||(primCount==174&&NumVertices==202)||(primCount==92&&NumVertices==96)))
#define headviper (Stride==40&&((primCount==1374&&NumVertices==749)||(primCount==396&&NumVertices==287)||(primCount==271&&NumVertices==185)||(primCount==43&&NumVertices==32)||(primCount==56&&NumVertices==40)||(primCount==168&&NumVertices==152)||(primCount==205&&NumVertices==133)))
#define bodyviper (Stride==44&&((primCount==66&&NumVertices==74)||(primCount==78&&NumVertices==71)||(primCount==254&&NumVertices==185)||(primCount==738&&NumVertices==934)||(primCount==1534&&NumVertices==1530)||(primCount==1561&&NumVertices==2041)||((primCount==278||primCount==341||primCount==1267)&&NumVertices==1831)||(primCount==30&&NumVertices==41)||(primCount==32&&NumVertices==35)||(primCount==67&&NumVertices==62)||(primCount==80&&NumVertices==114)||(primCount==95&&NumVertices==144)||(primCount==337&&NumVertices==516)||(primCount==395&&NumVertices==237)||(primCount==716&&NumVertices==647)||(primCount==936&&NumVertices==727)||(primCount==12&&NumVertices==18)||(primCount==13&&NumVertices==23)||(primCount==32&&NumVertices==66)||(primCount==38&&NumVertices==41)||(primCount==61&&NumVertices==99)||(primCount==276&&NumVertices==245)||(primCount==487&&NumVertices==398)))
#define viper (hairviper||headviper||bodyviper)
// D-Fox
#define headdfox (Stride==44&&((primCount==464&&NumVertices==353)||(primCount==246&&NumVertices==175)))
#define bodydfox (Stride==48&&((primCount==76&&NumVertices==92)||(primCount==278&&NumVertices==370)||(primCount==390&&NumVertices==482)||(primCount==688&&NumVertices==734)||(primCount==1246&&NumVertices==812)||(primCount==1326&&NumVertices==1089)||((primCount==45||primCount==386||primCount==1023||primCount==1434)&&NumVertices==2263)||(primCount==40&&NumVertices==92)||(primCount==120&&NumVertices==165)||(primCount==158&&NumVertices==246)||(primCount==324&&NumVertices==381)||(primCount==700&&NumVertices==547)||((primCount==41||primCount==402||primCount==749)&&NumVertices==1348)||(primCount==20&&NumVertices==32)||(primCount==38&&NumVertices==71)||(primCount==86&&NumVertices==122)||(primCount==109&&NumVertices==195)||(primCount==360&&NumVertices==334)||((primCount==27||primCount==32||primCount==35||primCount==42||primCount==46||primCount==56||primCount==121||primCount==241)&&NumVertices==1204)))
#define dfox (headdfox||bodydfox)
// Leopard
#define headleo (Stride==40&&(NumVertices==1143&&primCount==1408))
#define bodyleo (Stride==44&&((NumVertices==154&&primCount==114)||(NumVertices==338&&primCount==434)||(NumVertices==661&&primCount==664)||(NumVertices==1053&&primCount==1722)||((primCount==263||primCount==312||primCount==529||primCount==574||primCount==1132)&&NumVertices==3770)))
#define leopard (headleo||bodyleo)
// Acid Pool
#define headacid (Stride==48&&((NumVertices==259&&primCount==472)||(NumVertices==113&&primCount==208)))
#define headpool (Stride==44&&(NumVertices==62&&primCount==110))
#define bodyacid (Stride==52&&((NumVertices==40&&primCount==50)||(NumVertices==354&&primCount==270)||(NumVertices==988&&primCount==708)||(NumVertices==1253&&primCount==1660)||(NumVertices==3155&&(primCount==1134||primCount==1678))||(NumVertices==10&&primCount==10)||(NumVertices==134&&primCount==90)||(NumVertices==307&&primCount==183)||(NumVertices==595&&primCount==752)||(NumVertices==793&&primCount==885)||(NumVertices==68&&primCount==42)||(NumVertices==167&&primCount==100)||(NumVertices==223&&primCount==246)||(NumVertices==361&&primCount==406)))
#define acid (headacid||headpool||bodyacid)
// Rica
#define bodyr (Stride==44&&((primCount==122&&NumVertices==65)||(primCount==186&&NumVertices==150)||(primCount==830&&NumVertices==650)||(primCount==1626&&NumVertices==923)||((primCount==523||primCount==1280||primCount==1502||primCount==1743)&&NumVertices==3952)||(primCount==44&&NumVertices==26)||(primCount==144&&NumVertices==124)||(primCount==504&&NumVertices==421)||(primCount==890&&NumVertices==549)||((primCount==895||primCount==1398)&&NumVertices==2197)||(primCount==8&&NumVertices==6)||(primCount==57&&NumVertices==68)||(primCount==116&&NumVertices==117)||(primCount==433&&NumVertices==257)||(primCount==437&&NumVertices==367)||((primCount==369||primCount==866)&&NumVertices==1271)))
#define hairr (Stride==36&&((primCount==604&&NumVertices==478)||(primCount==774&&NumVertices==593)))
#define rica (bodyr||hairr)
// Dinosaurs
#define dinos (Stride==44&&(NumVertices==2517||NumVertices==3721||NumVertices==4402||NumVertices==8341))
// Helm
#define helmred (Stride==40&&((primCount==266&&NumVertices==142)||(primCount==120&&NumVertices==71)||(primCount==56&&NumVertices==45)))
#define hacidayse (Stride==32&&((primCount==52&&NumVertices==38)||(primCount==648&&NumVertices==638)||(primCount==212&&NumVertices==198)||(primCount==102&&NumVertices==95)))
#define helmtar (Stride==32&&((primCount==338&&NumVertices==224)||(primCount==170&&NumVertices==128)||(primCount==84&&NumVertices==67)))
#define helmhid (Stride==32&&((primCount==218&&NumVertices==186)||(primCount==150&&NumVertices==133)||(primCount==80&&NumVertices==70)))
#define helmvip (Stride==32&&((primCount==240&&NumVertices==184)||(primCount==42&&NumVertices==51)))
#define helmfox (Stride==32&&((primCount==242&&NumVertices==196)||(primCount==112&&NumVertices==73)||(primCount==54&&NumVertices==40)))
#define helmleo (Stride==32&&((NumVertices==818&&primCount==866)||(NumVertices==269&&primCount==272)||(NumVertices==115&&primCount==122)))
#define topeng1 (Stride==32&&((NumVertices==653&&primCount==902)||(NumVertices==404&&primCount==484)||((NumVertices==189||NumVertices==191)&&primCount==158)))
#define helmegg (Stride==32&&((NumVertices==575&&primCount==768)||(NumVertices==381&&primCount==434)||(NumVertices==177&&primCount==142)))
#define helmking1 (Stride==32&&((NumVertices==1049&&primCount==1492)||(NumVertices==673&&primCount==843)||(NumVertices==293&&primCount==302)))
#define prohead (helmred||hacidayse||helmtar||helmhid||helmvip||helmfox||helmleo||topeng1||helmegg||helmking1)
// ALL PLAYERS
// Chou
#define bchou (Stride==44&&((NumVertices==589&&primCount==755)||(NumVertices==1085&&primCount==1962)||(NumVertices==3412&&(primCount==1412||primCount==1481||primCount==1677))||(NumVertices==491&&primCount==613)||(NumVertices==600&&primCount==1062)||(NumVertices==1729&&(primCount==241||primCount==1909))||(NumVertices==296&&primCount==492)||(NumVertices==386&&primCount==466)||(NumVertices==942&&primCount==309||primCount==840)))
#define kchou (Stride==32&&((NumVertices==298&&primCount==310)||(NumVertices==162&&primCount==140)||(NumVertices==92&&primCount==72)))
#define mchou (Stride==40&&((NumVertices==118&&primCount==195)||(NumVertices==43&&primCount==38)||(NumVertices==26&&primCount==20)))
#define chou (bchou||kchou||mchou)
#define helmegg (Stride==32&&((NumVertices==575&&primCount==768)||(NumVertices==381&&primCount==434)||(NumVertices==177&&primCount==142)))
#define allp (redbulls||acid||ayse||tarantula||hide||viper||dfox||leopard||dinos||prohead||rica||chou||helmegg)
#define ct (acid||chou||hide||ayse||leopard)
#define tero (redbulls||tarantula||viper||dfox||rica)
// haseup
#define SmokeStride (Stride==24&&(NumVertices==256||NumVertices==192))
//pDevice->Clear(0, 0, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);



#define PlayerTerorist ((NumVertices == 88 && primCount == 130) || (NumVertices == 142 && primCount == 266)|| (NumVertices == 472 && primCount == 304) || (NumVertices == 384 && primCount == 346) || (NumVertices == 348 && primCount == 520) || (NumVertices == 596 && primCount == 590)|| (NumVertices == 628 && primCount == 748) || (NumVertices == 3487 && primCount == 1737)|| (NumVertices == 3487 && primCount == 1766) || (NumVertices == 262 && primCount == 196) || (NumVertices == 142 && primCount == 266) || (NumVertices == 244 && primCount == 406) || (NumVertices == 1846 && primCount == 414) || (NumVertices == 528 && primCount == 540) || (NumVertices == 520 && primCount == 593) || (NumVertices == 2728 && primCount == 1344) || (NumVertices == 1091 && primCount == 1390) || (NumVertices == 1095 && primCount == 1460) || (NumVertices == 1846 && primCount == 2090) || (NumVertices == 2263 && primCount == 45) || (NumVertices == 370 && primCount == 278) || (NumVertices == 482 && primCount == 390) || (NumVertices == 734 && primCount == 688) || (NumVertices == 2263 && primCount == 1023) || (NumVertices == 812 && primCount == 1246) || (NumVertices == 2263 && primCount == 1434) || (NumVertices == 2041 && primCount == 1561) || (NumVertices == 1530 && primCount == 1534) || (NumVertices == 749 && primCount == 1374) || (NumVertices == 1831 && primCount == 1267) || (NumVertices == 2010 && primCount == 426) || (NumVertices == 287 && primCount == 396) || (NumVertices == 1831 && primCount == 341) || (NumVertices == 1831 && primCount == 278) || (NumVertices == 185 && primCount == 254) || (NumVertices == 74 && primCount == 66) || (NumVertices == 56 && primCount == 40) || (NumVertices == 185 && primCount == 271) || (NumVertices == 45 && primCount == 56) || (NumVertices == 92 && primCount == 56) || (NumVertices == 611 && primCount == 114) || (NumVertices == 611 && primCount == 526) || (NumVertices == 18 && primCount == 12) || (NumVertices == 96 && primCount == 92) || (NumVertices == 99 && primCount == 61) || (NumVertices == 133 && primCount == 205)|| (NumVertices == 245 && primCount == 276) || (NumVertices == 398 && primCount == 487) || (NumVertices == 26 && primCount == 20) || (NumVertices == 1204 && primCount == 241) || (NumVertices == 80 && primCount == 52) || (NumVertices == 1204 && primCount == 124) || (NumVertices == 113 && primCount == 139) || (NumVertices == 1204 && primCount == 56) || (NumVertices == 684 && primCount == 740) || (NumVertices == 1204 && primCount == 42) || (NumVertices == 45 && primCount == 56) || (NumVertices == 1204 && primCount == 35) || (NumVertices == 334 && primCount == 360) || (NumVertices == 175 && primCount == 246) || (NumVertices == 195 && primCount == 109) || (NumVertices == 71 && primCount == 120) || (NumVertices == 88 && primCount == 130) || (NumVertices == 201 && primCount == 157) || (NumVertices == 224 && primCount == 200) || (NumVertices == 296 && primCount == 166) || (NumVertices == 1353 && primCount == 386) || (NumVertices == 18 && primCount == 20) || (NumVertices == 41 && primCount == 30) || (NumVertices == 62 && primCount == 67) || (NumVertices == 152 && primCount == 168) || (NumVertices == 202 && primCount == 174) || (NumVertices == 237 && primCount == 395) || (NumVertices == 647 && primCount == 716) || (NumVertices == 727 && primCount == 936) || (NumVertices == 90 && primCount == 136) || (NumVertices == 120 && primCount == 170) || (NumVertices == 142 && primCount == 128) || (NumVertices == 218 && primCount == 322) || (NumVertices == 285 && primCount == 94) || (NumVertices == 1316 && primCount == 1574) || (NumVertices == 1316 && primCount == 134) || (NumVertices == 56 && primCount == 158) || (NumVertices == 73 && primCount == 112) || (NumVertices == 143 && primCount == 94) || (NumVertices == 246 && primCount == 120) || (NumVertices == 353 && primCount == 464) || (NumVertices == 381 && primCount == 234) || (NumVertices == 547 && primCount == 700) || (NumVertices == 1353 && primCount == 1404))
#define TeroHead ((NumVertices == 196 && primCount == 242) || (NumVertices == 812 && primCount == 1246) || (NumVertices == 237 && primCount == 355) || (NumVertices == 184 && primCount == 240) || (NumVertices == 749 && primCount == 1374) || (NumVertices == 51 && primCount == 42) || (NumVertices == 133 && primCount == 205) || (NumVertices == 142 && primCount == 266) || (NumVertices == 628 && primCount == 748) || (NumVertices == 224 && primCount == 338) || (NumVertices == 1095 && primCount == 1460) || (NumVertices == 71 && primCount == 120) || (NumVertices == 338 && primCount == 446) || (NumVertices == 128 && primCount == 170) || (NumVertices == 218 && primCount == 322) || (NumVertices == 45 && primCount == 56) || (NumVertices == 68 && primCount == 126) || (NumVertices == 67 && primCount == 84) || (NumVertices == 113 && primCount == 139) || (NumVertices == 175 && primCount == 246) || (NumVertices == 40 && primCount == 1115) || (NumVertices == 196 && primCount == 242) || (NumVertices == 95 && primCount == 102) || (NumVertices == 62 && primCount == 110) || (NumVertices == 113 && primCount == 208) || (NumVertices == 198 && primCount == 212) || (NumVertices == 118 && primCount == 208) || (NumVertices == 259 && primCount == 472) || (NumVertices == 638 && primCount == 648) || (NumVertices == 67 && primCount == 110) || (NumVertices == 363 && primCount == 636) || (NumVertices == 638 && primCount == 648) || (NumVertices == 125 && primCount == 185) || (NumVertices == 70 && primCount == 80) || (NumVertices == 79 && primCount == 120) || (NumVertices == 186 && primCount == 218) || (NumVertices == 854 && primCount == 1494) || (NumVertices == 115 && primCount == 122) | (NumVertices == 133 && primCount == 150) || (NumVertices == 638 && primCount == 648))
#define PlayerCT   ((NumVertices == 40 && primCount == 50) || (NumVertices == 38 && primCount == 52) || (NumVertices == 270 && primCount == 354) || (NumVertices == 259 && primCount == 472) || (NumVertices == 638 && primCount == 648) || (NumVertices == 988 && primCount == 708) || (NumVertices == 3155 && primCount == 1134) || (NumVertices == 1253 && primCount == 1660) || (NumVertices == 3155 && primCount == 1678) || (NumVertices == 366 && primCount == 270) || (NumVertices == 4705 && primCount == 281) || (NumVertices == 363 && primCount == 636) || (NumVertices == 4705 && primCount == 660) || (NumVertices == 4705 && primCount == 987) || (NumVertices == 4705 && primCount == 2442) || (NumVertices == 12 && primCount == 8) || (NumVertices == 20 && primCount == 16) || (NumVertices == 21 && primCount == 19) || (NumVertices == 30 && primCount == 36) || (NumVertices == 39 && primCount == 44) || (NumVertices == 79 && primCount == 120) || (NumVertices == 101 && primCount == 150) || (NumVertices == 186 && primCount == 218) || (NumVertices == 3796 && primCount == 254) || (NumVertices == 3796 && primCount == 320) || (NumVertices == 307 && primCount == 320) || (NumVertices == 324 && primCount == 400) || (NumVertices == 854 && primCount == 1494) || (NumVertices == 1619 && primCount == 1946) || (NumVertices == 3796 && primCount == 3152) || (NumVertices == 17 && primCount == 8) || (NumVertices == 78 && primCount == 56) || (NumVertices == 95 && primCount == 110) || (NumVertices == 125 && primCount == 185) || (NumVertices == 221 && primCount == 240) || (NumVertices == 520 && primCount == 592) || (NumVertices == 33 && primCount == 20) || (NumVertices == 128 && primCount == 102) || (NumVertices == 200 && primCount == 230) || (NumVertices == 227 && primCount == 373) || (NumVertices == 285 && primCount == 214) || (NumVertices == 654 && primCount == 706) || (NumVertices == 998 && primCount == 1154) || (NumVertices == 62 && primCount == 110) || (NumVertices == 88 && primCount == 42) || (NumVertices == 95 && primCount == 102) || (NumVertices == 167 && primCount == 100) || (NumVertices == 223 && primCount == 246) || (NumVertices == 361 && primCount == 406) || (NumVertices == 113 && primCount == 208) || (NumVertices == 134 && primCount == 90) || (NumVertices == 198 && primCount == 212) || (NumVertices == 307 && primCount == 183) || (NumVertices == 595 && primCount == 725) || (NumVertices == 793 && primCount == 885) || (NumVertices == 67 && primCount == 110) || (NumVertices == 85 && primCount == 56) || (NumVertices == 95 && primCount == 102) || (NumVertices == 490 && primCount == 504) || (NumVertices == 198 && primCount == 212) || (NumVertices == 307 && primCount == 183) || (NumVertices == 134 && primCount == 90) || (NumVertices == 285 && primCount == 94) || (NumVertices == 595 && primCount == 752) || (NumVertices == 793 && primCount == 885)|| (NumVertices == 118 && primCount == 208) || (NumVertices == 141 && primCount == 102) || (NumVertices == 198 && primCount == 212) || (NumVertices == 592 && primCount == 453) || (NumVertices == 1184 && primCount == 1387) || (NumVertices == 133 && primCount == 150) || (NumVertices == 128 && primCount == 102) || (NumVertices == 143 && primCount == 100) || (NumVertices == 200 && primCount == 238) || (NumVertices == 227 && primCount == 373) || (NumVertices == 654 && primCount == 706) || (NumVertices == 998 && primCount == 1154))
#define CTHead ( primCount == 504 || primCount == 270 || NumVertices == 338 || NumVertices == 154 || NumVertices == 661 || NumVertices == 366 || primCount == 218 || primCount == 254 || primCount == 400 || primCount == 281 || primCount == 426 || NumVertices == 363 || NumVertices == 638)
#define WeaponX ((NumVertices == 42 && primCount == 28) || (NumVertices == 5968 && primCount == 3844) || (NumVertices == 98 && primCount == 70) || (NumVertices == 62 && primCount == 44) || (NumVertices == 2355 && primCount == 1791) || (NumVertices == 40 && primCount == 28) || (NumVertices == 68 && primCount == 76) || (NumVertices == 30 && primCount == 16) || (NumVertices == 23 && primCount == 13) || (NumVertices == 99 && primCount == 120) || (NumVertices == 109 && primCount == 48) || (NumVertices == 522 && primCount == 220) || (NumVertices == 50 && primCount == 36) || (NumVertices == 387 && primCount == 285) || (NumVertices == 46 && primCount == 30) || (NumVertices == 668 && primCount == 449) || (NumVertices == 72 && primCount == 54) || (NumVertices == 82 && primCount == 54) || (NumVertices == 364 && primCount == 318) || (NumVertices == 855 && primCount == 678) || (NumVertices == 834 && primCount == 483) || (NumVertices == 98 && primCount == 88) || (NumVertices == 217 && primCount == 176) || (NumVertices == 560 && primCount == 594) || (NumVertices == 774 && primCount == 756) || (NumVertices == 1714 && primCount == 1256) || (NumVertices == 82 && primCount == 64) || (NumVertices == 797 && primCount == 562) || (NumVertices == 542 && primCount == 470) || (NumVertices == 721 && primCount == 427) || (NumVertices == 62 && primCount == 56) || (NumVertices == 2693 && primCount == 2353) || (NumVertices == 46 && primCount == 28) || (NumVertices == 1976 && primCount == 1672) || (NumVertices == 3917 && primCount == 2552) || (NumVertices == 21 && primCount == 68) || (NumVertices == 1805 && primCount == 1721) || (NumVertices == 1583 && primCount == 1432) || (NumVertices == 1805 && primCount == 1721) || (NumVertices == 52 && primCount == 38) || (NumVertices == 73 && primCount == 46) || (NumVertices == 529 && primCount == 452) || (NumVertices == 4328 && primCount == 2905) || (NumVertices == 46 && primCount == 44) || (NumVertices == 30 && primCount == 16) || (NumVertices == 86 && primCount == 78) || (NumVertices == 94 && primCount == 48) || (NumVertices == 124 && primCount == 68) || (NumVertices == 521 && primCount == 448) || (NumVertices == 57 && primCount == 36) || (NumVertices == 1982 && primCount == 1462) || (NumVertices == 48 && primCount == 36) || (NumVertices == 62 && primCount == 40) || (NumVertices == 68 && primCount == 36) || (NumVertices == 43 && primCount == 48) || (NumVertices == 184 && primCount == 136) || (NumVertices == 345 && primCount == 238) || (NumVertices == 767 && primCount == 688) || (NumVertices == 3102 && primCount == 2108) || (NumVertices == 85 && primCount == 40) || (NumVertices == 274 && primCount == 152) || (NumVertices == 446 && primCount == 416) || (NumVertices == 521 && primCount == 148) || (NumVertices == 106 && primCount == 82) || (NumVertices == 72 && primCount == 72) || (NumVertices == 26 && primCount == 14) || (NumVertices == 2008 && primCount == 1375) || (NumVertices == 1365 && primCount == 982) || (NumVertices == 78 && primCount == 102) || (NumVertices == 974 && primCount == 952) || (NumVertices == 1925 && primCount == 1514) || (NumVertices == 74 && primCount == 36) || (NumVertices == 897 && primCount == 702) || (NumVertices == 151 && primCount == 132) || (NumVertices == 1428 && primCount == 1096) || (NumVertices == 864 && primCount == 644) || (NumVertices == 790 && primCount == 834) || (NumVertices == 446 && primCount == 480) || (NumVertices == 212 && primCount == 251) || (NumVertices == 908 && primCount == 626) || (NumVertices == 536 && primCount == 556))
#define Dino ((primCount == 57) || (primCount == 161) || (primCount == 186) || (primCount == 197) || (primCount == 349) || (primCount == 495) || (primCount == 955) || (NumVertices == 2517 && primCount == 57) || (NumVertices == 3721 && primCount == 275) || (NumVertices == 0 && primCount == 52) || (NumVertices == 0 && primCount == 105) || (NumVertices ==0 && primCount == 186) || (NumVertices == 0 && primCount == 197) || (primCount == 579) || (primCount == 488))
#define K400 ((NumVertices == 1002 && primCount == 980))
#define C5 ((NumVertices == 772 && primCount == 849))
#define allp2 (PlayerTerorist||TeroHead||PlayerCT||CTHead||Dino||WeaponX)