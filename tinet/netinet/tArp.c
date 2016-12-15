/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tArp_template.c => src/tArp.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * arpEntry         int32_t          ATTR_arpEntry
 * arp_cache        T_ARP_ENTRY*     VAR_arp_cache
 *
 * 呼び口関数 #_TCPF_#
 * call port: cEthernetRawOutput signature: sEthernetRawOutput context:task
 *   ER             cEthernetRawOutput_ethernetRawOutput( int8_t* outputp, int32_t size, TMO tmout );
 * call port: cNetworkTimer signature: sNetworkTimer context:task
 *   ER             cNetworkTimer_timeout( RELTIM timout );
 * call port: cArpSemaphore signature: sSemaphore context:task
 *   ER             cArpSemaphore_signal( );
 *   ER             cArpSemaphore_wait( );
 *   ER             cArpSemaphore_waitPolling( );
 *   ER             cArpSemaphore_waitTimeout( TMO timeout );
 *   ER             cArpSemaphore_initialize( );
 *   ER             cArpSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * allocator port for call port:cEthernetRawOutput func:ethernetRawOutput param: outputp
 *   ER             cEthernetRawOutput_ethernetRawOutput_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cEthernetRawOutput_ethernetRawOutput_outputp_dealloc( const void* buf );
 *   ER             cEthernetRawOutput_ethernetRawOutput_outputp_reuse( void* buf );
 *   ER_UINT        cEthernetRawOutput_ethernetRawOutput_outputp_bufferSize( const void* buf );
 *   uint32_t       cEthernetRawOutput_ethernetRawOutput_outputp_bufferMaxSize( );
 * allocator port for call port:eArpInput func:arpInput param: inputp
 *   ER             eArpInput_arpInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eArpInput_arpInput_inputp_dealloc( const void* buf );
 *   ER             eArpInput_arpInput_inputp_reuse( void* buf );
 *   ER_UINT        eArpInput_arpInput_inputp_bufferSize( const void* buf );
 *   uint32_t       eArpInput_arpInput_inputp_bufferMaxSize( );
 * allocator port for call port:eArpOutput func:arpResolve param: outputp
 *   ER             eArpOutput_arpResolve_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eArpOutput_arpResolve_outputp_dealloc( const void* buf );
 *   ER             eArpOutput_arpResolve_outputp_reuse( void* buf );
 *   ER_UINT        eArpOutput_arpResolve_outputp_bufferSize( const void* buf );
 *   uint32_t       eArpOutput_arpResolve_outputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tArp_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include <net/if_arp.h>
#include <net/net_timer.h>

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eArpInput
 * entry port: eArpInput
 * signature:  sArpInput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eArpInput_arpInitialize
 * name:         eArpInput_arpInitialize
 * global_name:  tArp_eArpInput_arpInitialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eArpInput_arpInitialize(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	cNetworkTimer_timeout(ARP_TIMER_TMO);
}

/* #[<ENTRY_FUNC>]# eArpInput_arpInput
 * name:         eArpInput_arpInput
 * global_name:  tArp_eArpInput_arpInput
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eArpInput_arpInput(CELLIDX idx, int8_t* inputp, int32_t size, const uint8_t* macaddress)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
}

/* #[<ENTRY_PORT>]# eArpOutput
 * entry port: eArpOutput
 * signature:  sArpOutput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eArpOutput_arpResolve
 * name:         eArpOutput_arpResolve
 * global_name:  tArp_eArpOutput_arpResolve
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eArpOutput_arpResolve(CELLIDX idx, int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, const uint8_t* macaddress, TMO tmout)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_PORT>]# eArpTimer
 * entry port: eArpTimer
 * signature:  sCallTimerFunction
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eArpTimer_callFunction
 * name:         eArpTimer_callFunction
 * global_name:  tArp_eArpTimer_callFunction
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eArpTimer_callFunction(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
