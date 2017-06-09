/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tUDPApplicationBody_template.c => src/tUDPApplicationBody.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * require port: signature:sKernel context:task
 *   ER             getExtendedInformation( intptr_t* p_exinf );
 *   ER             sleep( );
 *   ER             sleepTimeout( TMO timeout );
 *   ER             delay( RELTIM delayTime );
 *   ER             exit( );
 *   ER             disableTerminate( );
 *   ER             enableTerminate( );
 *   bool_t         senseTerminate( );
 *   ER             setTime( SYSTIM systemTime );
 *   ER             getTime( SYSTIM* p_systemTime );
 *   ER             adjustTime( int32_t adjustTime );
 *   HRTCNT         fetchHighResolutionTimer( );
 *   ER             rotateReadyQueue( PRI taskPriority );
 *   ER             getTaskId( ID* p_taskId );
 *   ER             getLoad( PRI taskPriority, uint_t* p_load );
 *   ER             getNthTask( PRI taskPriority, uint_t nth, ID* p_taskID );
 *   ER             lockCpu( );
 *   ER             unlockCpu( );
 *   ER             disableDispatch( );
 *   ER             enableDispatch( );
 *   bool_t         senseContext( );
 *   bool_t         senseLock( );
 *   bool_t         senseDispatch( );
 *   bool_t         senseDispatchPendingState( );
 *   bool_t         senseKernel( );
 *   ER             exitKernel( );
 *   ER             changeInterruptPriorityMask( PRI interruptPriority );
 *   ER             getInterruptPriorityMask( PRI* p_interruptPriority );
 * call port: cUDPAPI4 signature: sUDPCEPAPI4 context:task
 *   ER_UINT        cUDPAPI4_send( const int8_t* data, int32_t len, T_IN4_ADDR dstaddr, uint16_t dstport, TMO tmout );
 *   ER_UINT        cUDPAPI4_receive( int8_t* data, int32_t len, TMO tmout );
 *   ER             cUDPAPI4_cancelSend( ER error );
 *   ER             cUDPAPI4_cancelReceive( ER error );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tUDPApplicationBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#define NUM_SEND_DATA 300
#define COUNT 10000
#define HIST 10000

#define TCP_REPID	1
#define TCP_CEPID	1

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tUDPApplicationBody_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main()
{
	ID		tskid;
	ER_UINT len;
	ER		error = E_OK;
	uint32_t i;
	int8_t data[NUM_SEND_DATA];

	getTaskId(&tskid);
	syslog(LOG_EMERG, "[UDP] Application started!! [ID:%d]", tskid);

	// T_IN4_ADDR myaddr  = MYIP4ADDRESS;
	T_IN4_ADDR dstaddr = MAKE_IPV4_ADDR(192,168,1,56);
	uint16_t   dstport = 50000;

	if ((len = cUDPAPI4_receive(data, len, TMO_FEVR)) >= 0) {
		data[len] = '\0';
		syslog(LOG_NOTICE, "[receive] from: %s.%d\n"
		                   "msg: %s", ip2str(NULL, &dstaddr), dstport, data);
		if (len > 0) {
			len = cUDPAPI4_send(data, len, dstaddr, dstport, TMO_FEVR);
			if (len >= 0)
				syslog(LOG_NOTICE, "[send] len: %d", (uint16_t)len);
			else
				syslog(LOG_NOTICE, "[send] error: %s", itron_strerror(len));
		}
	}
	else {
		syslog(LOG_NOTICE, "[receive] error: %s", itron_strerror(len));
	}

	// return len >= 0 || len == E_TMOUT ? E_OK : len;
	syslog(LOG_EMERG, "[UDP] Application ended!! [ID:%d]", tskid);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
