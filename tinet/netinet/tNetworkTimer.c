/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tNetworkTimer_template.c => src/tNetworkTimer.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * timeout          int32_t*         VAR_timeout
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSemaphoreNetworkTimer signature: sSemaphore context:task
 *   ER             cSemaphoreNetworkTimer_signal( );
 *   ER             cSemaphoreNetworkTimer_wait( );
 *   ER             cSemaphoreNetworkTimer_waitPolling( );
 *   ER             cSemaphoreNetworkTimer_waitTimeout( TMO timeout );
 *   ER             cSemaphoreNetworkTimer_initialize( );
 *   ER             cSemaphoreNetworkTimer_refer( T_RSEM* pk_semaphoreStatus );
 * call port: ciSemaphoreNetworkTimer signature: siSemaphore context:non-task
 *   ER             ciSemaphoreNetworkTimer_signal( );
 * call port: cSemaphoreCalloutLock signature: sSemaphore context:task
 *   ER             cSemaphoreCalloutLock_signal( );
 *   ER             cSemaphoreCalloutLock_wait( );
 *   ER             cSemaphoreCalloutLock_waitPolling( );
 *   ER             cSemaphoreCalloutLock_waitTimeout( TMO timeout );
 *   ER             cSemaphoreCalloutLock_initialize( );
 *   ER             cSemaphoreCalloutLock_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cCallTimerFunction signature: sCallTimerFunction context:task optional:true
 *   bool_t     is_cCallTimerFunction_joined(int subscript)        check if joined
 *   void           cCallTimerFunction_callFunction( subscript );
 *       subscript:  0...(NCP_cCallTimerFunction-1)
 * call port: cTCPTask signature: sTask context:task optional:true
 *   bool_t     is_cTCPTask_joined()                     check if joined
 *   ER             cTCPTask_activate( );
 *   ER_UINT        cTCPTask_cancelActivate( );
 *   ER             cTCPTask_getTaskState( STAT* p_tskstat );
 *   ER             cTCPTask_changePriority( PRI priority );
 *   ER             cTCPTask_getPriority( PRI* p_priority );
 *   ER             cTCPTask_refer( T_RTSK* pk_taskStatus );
 *   ER             cTCPTask_wakeup( );
 *   ER_UINT        cTCPTask_cancelWakeup( );
 *   ER             cTCPTask_releaseWait( );
 *   ER             cTCPTask_suspend( );
 *   ER             cTCPTask_resume( );
 *   ER             cTCPTask_raiseTerminate( );
 *   ER             cTCPTask_terminate( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tNetworkTimer_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eNetworkTimer
 * entry port: eNetworkTimer
 * signature:  sNetworkTimer
 * context:    task
 * entry port array size:  NEP_eNetworkTimer
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eNetworkTimer_timeout
 * name:         eNetworkTimer_timeout
 * global_name:  tNetworkTimer_eNetworkTimer_timeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eNetworkTimer_timeout(int_t subscript, RELTIM timout)
{
}

/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tNetworkTimer_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main()
{
}

/* #[<ENTRY_PORT>]# eiHandlerBody
 * entry port: eiHandlerBody
 * signature:  siHandlerBody
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiHandlerBody_main
 * name:         eiHandlerBody_main
 * global_name:  tNetworkTimer_eiHandlerBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiHandlerBody_main()
{
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
