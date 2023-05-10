#include "iodefine.h"
#include  "misratypes.h"
#include  "iwdt.h"

//  独立ウオッチドックタイマ (IWDT)の設定
//  
//・レジスタスタートモード
//  タイムアウト期間 : 2048サイクル(07ffh)
//  クロック分周比 :分周なし
//  ウインドウ終了位置: 0% 
//  ウインドウ開始位置:100%
//
// ・リセット出力の許可
//
//・独立ウオッチドックタイマ専用クロック = 15[KHz]
//
//  クロック分周比,  サイクル数, IWDTクロック数,  タイムアウト時間 
// 　 分周無し(1),    2048     ,   2048(=1x2048),  136.5[msec]  (= 1/15 * 2048 )    
//
//
//注: IWDTCR レジスタは、1回しか変更できない。
//     IWDT.IWDTCR.BIT.CKS = 0;
//     IWDT.IWDTCR.BIT.TOPS = 3;　と記述すると、TOPS = 3が反映されない。
//     1ワードで設定する。

void IWDT_Set(void)
{
	
	IWDT.IWDTCR.WORD = 0x3303;	// タイムアウト期間=2048サイクル, クロック分周=無し,  (1/15)*2048 = 136.5[msec] 
					// ウインドウ終了位置=0% , ウインドウ終了位置=100%
	
	IWDT.IWDTRCR.BYTE = 0x80;	// リセット出力を許可
	
}


// 独立ウオッチドックタイマのリフレッシュ
//
void IWDT_Refresh(void)
{
	IWDT.IWDTRR = 0x00;
	
	IWDT.IWDTRR = 0xff;
}