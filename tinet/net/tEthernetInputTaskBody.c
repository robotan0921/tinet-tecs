/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tEthernetInputTaskBody_template.c => src/tEthernetInputTaskBody.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSemaphoreReceive signature: sSemaphore context:task
 *   ER             cSemaphoreReceive_signal( );
 *   ER             cSemaphoreReceive_wait( );
 *   ER             cSemaphoreReceive_waitPolling( );
 *   ER             cSemaphoreReceive_waitTimeout( TMO timeout );
 *   ER             cSemaphoreReceive_initialize( );
 *   ER             cSemaphoreReceive_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cNicDriver signature: sNicDriver context:task
 *   void           cNicDriver_init( );
 *   void           cNicDriver_start( int8_t* outputp, int32_t size, uint8_t align );
 *   T_NET_BUF*     cNicDriver_read( int8_t** inputp, int32_t* size, uint8_t align );
 *   void           cNicDriver_probe( uint8_t* macaddress );
 *   void           cNicDriver_reset( );
 * call port: cTaskEthernetOutput signature: sTask context:task optional:true
 *   bool_t     is_cTaskEthernetOutput_joined()                     check if joined
 *   ER             cTaskEthernetOutput_activate( );
 *   ER_UINT        cTaskEthernetOutput_cancelActivate( );
 *   ER             cTaskEthernetOutput_getTaskState( STAT* p_tskstat );
 *   ER             cTaskEthernetOutput_changePriority( PRI priority );
 *   ER             cTaskEthernetOutput_getPriority( PRI* p_priority );
 *   ER             cTaskEthernetOutput_refer( T_RTSK* pk_taskStatus );
 *   ER             cTaskEthernetOutput_wakeup( );
 *   ER_UINT        cTaskEthernetOutput_cancelWakeup( );
 *   ER             cTaskEthernetOutput_releaseWait( );
 *   ER             cTaskEthernetOutput_suspend( );
 *   ER             cTaskEthernetOutput_resume( );
 *   ER             cTaskEthernetOutput_raiseTerminate( );
 *   ER             cTaskEthernetOutput_terminate( );
 * call port: cArpInput signature: sArpInput context:task optional:true
 *   bool_t     is_cArpInput_joined()                     check if joined
 *   void           cArpInput_arpInitialize( );
 *   void           cArpInput_arpInput( int8_t* inputp, int32_t size, const uint8_t* macaddress );
 * call port: cIPv4Input signature: sIPv4Input context:task optional:true
 *   bool_t     is_cIPv4Input_joined()                     check if joined
 *   void           cIPv4Input_IPv4Input( int8_t* inputp, int32_t size );
 * allocator port for call port:cNicDriver func:start param: outputp
 *   ER             cNicDriver_start_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cNicDriver_start_outputp_dealloc( const void* buf );
 *   ER             cNicDriver_start_outputp_reuse( void* buf );
 *   ER_UINT        cNicDriver_start_outputp_bufferSize( const void* buf );
 *   uint32_t       cNicDriver_start_outputp_bufferMaxSize( );
 * allocator port for call port:cNicDriver func:read param: inputp
 *   ER             cNicDriver_read_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cNicDriver_read_inputp_dealloc( const void* buf );
 *   ER             cNicDriver_read_inputp_reuse( void* buf );
 *   ER_UINT        cNicDriver_read_inputp_bufferSize( const void* buf );
 *   uint32_t       cNicDriver_read_inputp_bufferMaxSize( );
 * allocator port for call port:cArpInput func:arpInput param: inputp
 *   ER             cArpInput_arpInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cArpInput_arpInput_inputp_dealloc( const void* buf );
 *   ER             cArpInput_arpInput_inputp_reuse( void* buf );
 *   ER_UINT        cArpInput_arpInput_inputp_bufferSize( const void* buf );
 *   uint32_t       cArpInput_arpInput_inputp_bufferMaxSize( );
 * allocator port for call port:cIPv4Input func:IPv4Input param: inputp
 *   ER             cIPv4Input_IPv4Input_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cIPv4Input_IPv4Input_inputp_dealloc( const void* buf );
 *   ER             cIPv4Input_IPv4Input_inputp_reuse( void* buf );
 *   ER_UINT        cIPv4Input_IPv4Input_inputp_bufferSize( const void* buf );
 *   uint32_t       cIPv4Input_IPv4Input_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tEthernetInputTaskBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tEthernetInputTaskBody_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main(CELLIDX idx)
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
