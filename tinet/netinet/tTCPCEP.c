/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTCPCEP_template.c => src/tTCPCEP.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * sbufSizeInit     int32_t          ATTR_sbufSizeInit
 * rbufSizeInit     int32_t          ATTR_rbufSizeInit
 * ipLength         int8_t           ATTR_ipLength
 * offset           T_OFF_BUF        VAR_offset
 * myport           uint16_t         VAR_myport
 * dstport          uint16_t         VAR_dstport
 * sbufSize         int32_t          VAR_sbufSize
 * rbufSize         int32_t          VAR_rbufSize
 * sbuf             int8_t*          VAR_sbuf
 * rbuf             int8_t*          VAR_rbuf
 * flags            uint32_t         VAR_flags
 * cep              T_TCP_CEP        VAR_cep
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
 * call port: cCopySave signature: sCopySave context:task
 *   void           cCopySave_tcpWriteRwbuf( T_TCP_CEP* cep, int8_t* inputp, int32_t size, uint8_t thoff, int8_t* rbuf, int32_t len );
 *   void           cCopySave_tcpReadSwbuf( T_TCP_CEP* cep, int8_t* outputp, int32_t size, uint32_t doff, int8_t* sbuf, int32_t buflen, int32_t hoff, int32_t len );
 *   ER             cCopySave_tcpWaitSwbuf( T_TCP_CEP* cep, uint32_t* flags, int32_t sbufSize, TMO tmout );
 *   ER_UINT        cCopySave_tcpWriteSwbuf( T_TCP_CEP* cep, int8_t* data, int32_t datalen, int8_t* sbuf, int32_t buflen );
 *   ER             cCopySave_tcpIsSwbufFull( T_TCP_CEP* cep, int32_t sbufSize );
 *   uint32_t       cCopySave_tcpReadRwbuf( T_TCP_CEP* cep, int8_t* data, int32_t datalen, int8_t* rbuf, int32_t buflen );
 *   void           cCopySave_tcpDropSwbuf( T_TCP_CEP* cep, uint32_t len, const int8_t* sbuf, int32_t sbufSize, uint32_t* flags );
 *   void           cCopySave_tcpFreeRwbufq( T_TCP_CEP* cep );
 *   void           cCopySave_tcpFreeSwbufq( T_TCP_CEP* cep );
 * call port: cTCPOutput signature: sTCPOutput context:task
 *   ER             cTCPOutput_output( int8_t* outputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen );
 *   ER             cTCPOutput_getOffset( T_OFF_BUF* offset );
 *   T_IN4_ADDR     cTCPOutput_getIPv4Address( );
 *   ER             cTCPOutput_respond( int8_t* outputp, int32_t size, T_TCP_CEP* cep, T_TCP_SEQ ack, T_TCP_SEQ seq, uint32_t rbfree, uint8_t flags );
 *   ER             cTCPOutput_allocAndRespond( const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen, uint16_t dstport, uint16_t srcport, T_TCP_SEQ ack, T_TCP_SEQ seq, uint32_t rbfree, uint8_t flags, T_OFF_BUF offset );
 * call port: cTCPFunctions signature: sTCPFunctions context:task
 *   T_TCP_SEQ      cTCPFunctions_getTcpIss( );
 *   void           cTCPFunctions_setTcpIss( T_TCP_SEQ iss );
 *   T_TCP_SEQ      cTCPFunctions_initTcpIss( );
 *   T_TCP_TIME     cTCPFunctions_tcpRexmtValue( T_TCP_TIME srtt, T_TCP_TIME rttvar );
 *   T_TCP_TIME     cTCPFunctions_tcpRangeSet( T_TCP_TIME value, T_TCP_TIME tvmin, T_TCP_TIME tvmax );
 * call port: cGetAddress signature: sGetAddress2 context:task
 *   int8_t*        cGetAddress_getMyAddress( );
 *   int8_t*        cGetAddress_getDstAddress( );
 *   void           cGetAddress_setMy4Address( T_IN4_ADDR addr );
 *   void           cGetAddress_setDst4Address( T_IN4_ADDR addr );
 * call port: cSemaphore signature: sSemaphore context:task
 *   ER             cSemaphore_signal( );
 *   ER             cSemaphore_wait( );
 *   ER             cSemaphore_waitPolling( );
 *   ER             cSemaphore_waitTimeout( TMO timeout );
 *   ER             cSemaphore_initialize( );
 *   ER             cSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cSemaphoreTcppost signature: sSemaphore context:task
 *   ER             cSemaphoreTcppost_signal( );
 *   ER             cSemaphoreTcppost_wait( );
 *   ER             cSemaphoreTcppost_waitPolling( );
 *   ER             cSemaphoreTcppost_waitTimeout( TMO timeout );
 *   ER             cSemaphoreTcppost_initialize( );
 *   ER             cSemaphoreTcppost_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cSemaphoreTcpcep signature: sSemaphore context:task
 *   ER             cSemaphoreTcpcep_signal( );
 *   ER             cSemaphoreTcpcep_wait( );
 *   ER             cSemaphoreTcpcep_waitPolling( );
 *   ER             cSemaphoreTcpcep_waitTimeout( TMO timeout );
 *   ER             cSemaphoreTcpcep_initialize( );
 *   ER             cSemaphoreTcpcep_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cSendFlag signature: sEventflag context:task
 *   ER             cSendFlag_set( FLGPTN setPattern );
 *   ER             cSendFlag_clear( FLGPTN clearPattern );
 *   ER             cSendFlag_wait( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cSendFlag_waitPolling( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cSendFlag_waitTimeout( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern, TMO timeout );
 *   ER             cSendFlag_initialize( );
 *   ER             cSendFlag_refer( T_RFLG* pk_eventflagStatus );
 * call port: cRcvFlag signature: sEventflag context:task
 *   ER             cRcvFlag_set( FLGPTN setPattern );
 *   ER             cRcvFlag_clear( FLGPTN clearPattern );
 *   ER             cRcvFlag_wait( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cRcvFlag_waitPolling( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cRcvFlag_waitTimeout( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern, TMO timeout );
 *   ER             cRcvFlag_initialize( );
 *   ER             cRcvFlag_refer( T_RFLG* pk_eventflagStatus );
 * call port: cEstFlag signature: sEventflag context:task
 *   ER             cEstFlag_set( FLGPTN setPattern );
 *   ER             cEstFlag_clear( FLGPTN clearPattern );
 *   ER             cEstFlag_wait( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cEstFlag_waitPolling( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cEstFlag_waitTimeout( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern, TMO timeout );
 *   ER             cEstFlag_initialize( );
 *   ER             cEstFlag_refer( T_RFLG* pk_eventflagStatus );
 * call port: cREP4 signature: sREP4 context:task optional:true
 *   bool_t     is_cREP4_joined()                     check if joined
 *   T_IPV4EP       cREP4_getEndpoint( );
 *   ER             cREP4_signal( );
 *   ER             cREP4_wait( );
 *   ER             cREP4_waitPolling( );
 *   ER             cREP4_waitTimeout( TMO timeout );
 *   ER             cREP4_initialize( );
 *   ER             cREP4_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cCallingSendTask signature: sTask context:task optional:true
 *   bool_t     is_cCallingSendTask_joined()                     check if joined
 *   ER             cCallingSendTask_activate( );
 *   ER_UINT        cCallingSendTask_cancelActivate( );
 *   ER             cCallingSendTask_getTaskState( STAT* p_tskstat );
 *   ER             cCallingSendTask_changePriority( PRI priority );
 *   ER             cCallingSendTask_getPriority( PRI* p_priority );
 *   ER             cCallingSendTask_refer( T_RTSK* pk_taskStatus );
 *   ER             cCallingSendTask_wakeup( );
 *   ER_UINT        cCallingSendTask_cancelWakeup( );
 *   ER             cCallingSendTask_releaseWait( );
 *   ER             cCallingSendTask_suspend( );
 *   ER             cCallingSendTask_resume( );
 *   ER             cCallingSendTask_raiseTerminate( );
 *   ER             cCallingSendTask_terminate( );
 * call port: cCallingReceiveTask signature: sTask context:task optional:true
 *   bool_t     is_cCallingReceiveTask_joined()                     check if joined
 *   ER             cCallingReceiveTask_activate( );
 *   ER_UINT        cCallingReceiveTask_cancelActivate( );
 *   ER             cCallingReceiveTask_getTaskState( STAT* p_tskstat );
 *   ER             cCallingReceiveTask_changePriority( PRI priority );
 *   ER             cCallingReceiveTask_getPriority( PRI* p_priority );
 *   ER             cCallingReceiveTask_refer( T_RTSK* pk_taskStatus );
 *   ER             cCallingReceiveTask_wakeup( );
 *   ER_UINT        cCallingReceiveTask_cancelWakeup( );
 *   ER             cCallingReceiveTask_releaseWait( );
 *   ER             cCallingReceiveTask_suspend( );
 *   ER             cCallingReceiveTask_resume( );
 *   ER             cCallingReceiveTask_raiseTerminate( );
 *   ER             cCallingReceiveTask_terminate( );
 * allocator port for call port:cTCPOutput func:output param: outputp
 *   ER             cTCPOutput_output_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cTCPOutput_output_outputp_dealloc( const void* buf );
 *   ER             cTCPOutput_output_outputp_reuse( void* buf );
 *   ER_UINT        cTCPOutput_output_outputp_bufferSize( const void* buf );
 *   uint32_t       cTCPOutput_output_outputp_bufferMaxSize( );
 * allocator port for call port:cTCPOutput func:respond param: outputp
 *   ER             cTCPOutput_respond_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cTCPOutput_respond_outputp_dealloc( const void* buf );
 *   ER             cTCPOutput_respond_outputp_reuse( void* buf );
 *   ER_UINT        cTCPOutput_respond_outputp_bufferSize( const void* buf );
 *   uint32_t       cTCPOutput_respond_outputp_bufferMaxSize( );
 * allocator port for call port:eCEPInput func:input param: inputp
 *   ER             eCEPInput_input_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eCEPInput_input_inputp_dealloc( const void* buf );
 *   ER             eCEPInput_input_inputp_reuse( void* buf );
 *   ER_UINT        eCEPInput_input_inputp_bufferSize( const void* buf );
 *   uint32_t       eCEPInput_input_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTCPCEP_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#ifdef TARGET_KERNEL_ASP

#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include "kernel_cfg.h"

#endif	/* of #ifdef TARGET_KERNEL_ASP */

#ifdef TARGET_KERNEL_JSP

#include <s_services.h>
#include <t_services.h>
#include "kernel_id.h"

#endif	/* of #ifdef TARGET_KERNEL_JSP */

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/if_ppp.h>
#include <net/if_loop.h>
#include <net/ethernet.h>
#include <net/net.h>
#include <net/net_var.h>
#include <net/net_buf.h>
#include <net/net_timer.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/in_itron.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
#include <netinet/tcp_fsm.h>
#include <netinet/tcp_seq.h>
#include <netinet/tcp_timer.h>

/*
 *  関数
 */

static void tcp_output(CELLCB *p_cellcb);

static ER send_segment(CELLCB *p_cellcb, bool_t *sendalot, uint_t doff, uint_t win, uint_t len, uint8_t flags);

/*
 *  変数
 */

/* 出力時のフラグを FSM 状態により選択するための表 */

const static uint8_t tcp_outflags[] = {
	TCP_FLG_RST | TCP_FLG_ACK,	/*  0, クローズ						*/
	0,							/*  1, 受動オープン						*/
	TCP_FLG_SYN,				/*  2, 能動オープン、SYN 送信済み			*/
	TCP_FLG_SYN | TCP_FLG_ACK,	/*  3, SYM を受信し、SYN 送信済み		*/
	TCP_FLG_ACK,				/*  4, コネクション開設完了				*/
	TCP_FLG_ACK,				/*  5, FIN 受信、クローズ待ち				*/
	TCP_FLG_FIN | TCP_FLG_ACK,	/*  6, 終了して、FIN 送信済み			*/
	TCP_FLG_FIN | TCP_FLG_ACK,	/*  7, 終了、FIN 交換済み、ACK 待ち		*/
	TCP_FLG_FIN | TCP_FLG_ACK,	/*  8, FIN 受信、終了、ACK 待ち			*/
	TCP_FLG_ACK,				/*  9, 終了、FIN 伝達確認受信、FIN待ち	*/
	TCP_FLG_ACK,				/* 10, 終了、時間待ち					*/
};


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTCPOutputStart
 * entry port: eTCPOutputStart
 * signature:  sTCPOutputStart
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTCPOutputStart_outputStart
 * name:         eTCPOutputStart_outputStart
 * global_name:  tTCPCEP_eTCPOutputStart_outputStart
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTCPOutputStart_outputStart(CELLIDX idx)
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
#if 0
#ifdef TCP_CFG_SWBUF_CSAVE

	if ((cep->flags & TCP_CEP_FLG_WBCS_NBUF_REQ) != 0 &&
	    ((cep->flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_FREE ||
	     (cep->flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_NBUF_RSVD)) {
		tcptsk_alloc_swbufq(cep);
		sel_ix = ix;
	}

	if ((cep->flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_ACKED &&
	    (cep->swbufq->flags & NB_FLG_NOREL_IFOUT) == 0) {
		tcptsk_free_swbufq(cep);
		sel_ix = ix;
	}

	/*
	 *  ネットワークインタフェースから送信が終わっていないときは、
	 *  送信を予約する。
	 */
	if (cep->flags & TCP_CEP_FLG_POST_OUTPUT &&
	   (cep->flags & TCP_CEP_FLG_WBCS_MASK) >= TCP_CEP_FLG_WBCS_SENT) {
		syscall(wai_sem(cep->semid_lock));
		if (cep->swbufq == NULL)
			cep->flags &= ~TCP_CEP_FLG_POST_OUTPUT;
		else if (cep->swbufq->flags & NB_FLG_NOREL_IFOUT) {
			cep->flags &= ~TCP_CEP_FLG_POST_OUTPUT;
			cep->flags |=  TCP_CEP_FLG_RESERVE_OUTPUT;
		}
		syscall(sig_sem(cep->semid_lock));
	}

	/*
	 *  送信予約中に、ネットワークインタフェースから送信が終了したら、
	 *  送信を開始する。ただし、完全に送信が終了したときは何もしない。
	 */
	if (cep->flags & TCP_CEP_FLG_RESERVE_OUTPUT) {
		syscall(wai_sem(cep->semid_lock));
		if (cep->swbufq != NULL && (cep->swbufq->flags & NB_FLG_NOREL_IFOUT) == 0) {
			cep->flags |=  TCP_CEP_FLG_POST_OUTPUT;
		}
		syscall(sig_sem(cep->semid_lock));
		cep->flags &= ~TCP_CEP_FLG_RESERVE_OUTPUT;
	}

#endif	/* of #ifdef TCP_CFG_SWBUF_CSAVE */
#endif 	/* of #if 0 */

	if (VAR_flags & TCP_CEP_FLG_POST_OUTPUT) {

		VAR_flags &= ~TCP_CEP_FLG_POST_OUTPUT;

#if 0
#ifdef TCP_CFG_NON_BLOCKING

		if (cep->snd_nblk_tfn == TFN_TCP_CON_CEP && cep->myaddr.portno == TCP_PORTANY) {
	 		ER	error;

			/*
			 *  tcp_con_cep のノンブロッキングコールで、
			 *  未割当のの場合は、ポート番号を割り当てる。
			 *  p_myaddr が NADR (-1) か、
			 *  自ポート番号が TCP_PORTANY なら、自動で割り当てる。
			 */
			if (cep->p_myaddr == NADR || cep->p_myaddr->portno == TCP_PORTANY)
				tcp_alloc_auto_port(cep);
			else if ((error = tcp_alloc_port(cep, cep->p_myaddr->portno)) != E_OK) {

				if (IS_PTR_DEFINED(cep->callback))
#ifdef TCP_CFG_NON_BLOCKING_COMPAT14
					(*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, (void*)error);
#else
					(*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, (void*)&error);
#endif
				else
					syslog(LOG_WARNING, "[TCP] no call back, CEP: %d.", GET_TCP_CEPID(cep));

				/* 記憶されているタスク ID と API 機能コードをクリアーする。*/
				cep->snd_tfn   = cep->snd_nblk_tfn = TFN_TCP_UNDEF;
				cep->snd_tskid = TA_NULL;
				continue;
			}
		}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

		tcp_output( p_cellcb );

		if (VAR_flags & TCP_CEP_FLG_CLOSE_AFTER_OUTPUT) {
			/* コネクションを閉じる。*/
			tcp_close( p_cellcb );
			VAR_flags &= ~TCP_CEP_FLG_CLOSE_AFTER_OUTPUT;
		}

		if (VAR_flags & TCP_CEP_FLG_RESTORE_NEXT_OUTPUT) {
			/* snd_nxt を元に戻す。*/
			if (SEQ_GT(VAR_cep.snd_old_nxt, VAR_cep.snd_nxt))
				VAR_cep.snd_nxt = VAR_cep.snd_old_nxt;
			VAR_flags &= ~TCP_CEP_FLG_RESTORE_NEXT_OUTPUT;
		}
	}

	return E_OK;
}

/* #[<ENTRY_FUNC>]# eTCPOutputStart_timerFunction
 * name:         eTCPOutputStart_timerFunction
 * global_name:  tTCPCEP_eTCPOutputStart_timerFunction
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTCPOutputStart_timerFunction(CELLIDX idx)
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

/* #[<ENTRY_PORT>]# eCEPInput
 * entry port: eCEPInput
 * signature:  sTCPCEPInput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCEPInput_check
 * name:         eCEPInput_check
 * global_name:  tTCPCEP_eCEPInput_check
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCEPInput_check(CELLIDX idx, const int8_t* dstaddr, const int8_t* srcaddr, int32_t len, uint16_t dstport, uint16_t srcport)
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

/* #[<ENTRY_FUNC>]# eCEPInput_input
 * name:         eCEPInput_input
 * global_name:  tTCPCEP_eCEPInput_input
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCEPInput_input(CELLIDX idx, int8_t* inputp, int32_t size)
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

/* #[<ENTRY_FUNC>]# eCEPInput_notify
 * name:         eCEPInput_notify
 * global_name:  tTCPCEP_eCEPInput_notify
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCEPInput_notify(CELLIDX idx, ER error)
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

/* #[<ENTRY_PORT>]# eAPI
 * entry port: eAPI
 * signature:  sTCPCEPAPI
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eAPI_accept
 * name:         eAPI_accept
 * global_name:  tTCPCEP_eAPI_accept
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_accept(CELLIDX idx, intptr_t sREP4, uint16_t* dstport, TMO tmout)
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

/* #[<ENTRY_FUNC>]# eAPI_connect
 * name:         eAPI_connect
 * global_name:  tTCPCEP_eAPI_connect
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_connect(CELLIDX idx, const int8_t* myaddr, uint16_t myport, const int8_t* dstaddr, uint16_t dstport, int32_t addrlen, TMO tmout)
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

/* #[<ENTRY_FUNC>]# eAPI_send
 * name:         eAPI_send
 * global_name:  tTCPCEP_eAPI_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eAPI_send(CELLIDX idx, const int8_t* data, int32_t len, TMO tmout)
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

/* #[<ENTRY_FUNC>]# eAPI_receive
 * name:         eAPI_receive
 * global_name:  tTCPCEP_eAPI_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eAPI_receive(CELLIDX idx, int8_t* data, int32_t len, TMO tmout)
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

/* #[<ENTRY_FUNC>]# eAPI_cancel
 * name:         eAPI_cancel
 * global_name:  tTCPCEP_eAPI_cancel
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_cancel(CELLIDX idx, FN fncd)
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

/* #[<ENTRY_FUNC>]# eAPI_close
 * name:         eAPI_close
 * global_name:  tTCPCEP_eAPI_close
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_close(CELLIDX idx, TMO tmout)
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

/* #[<ENTRY_FUNC>]# eAPI_shutdown
 * name:         eAPI_shutdown
 * global_name:  tTCPCEP_eAPI_shutdown
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_shutdown(CELLIDX idx)
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

/* #[<ENTRY_PORT>]# eInitializeRoutineBody
 * entry port: eInitializeRoutineBody
 * signature:  sRoutineBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInitializeRoutineBody_main
 * name:         eInitializeRoutineBody_main
 * global_name:  tTCPCEP_eInitializeRoutineBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eInitializeRoutineBody_main(CELLIDX idx)
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

/*
 *  tcp_output -- TCP 出力処理
 */

static void
tcp_output (CELLCB *p_cellcb)
{
	bool_t	sendalot = true, idle;
	ER	error = E_OK;
	int32_t	len;
	uint_t	doff, win;
	uint8_t	flags;

	/*
	 *  snd_una: 未確認の最小送信 SEQ	 または、確認された最大送信 SEQ
	 *  snd_max: 送信した最大 SEQ
	 */
	idle = (VAR_cep.snd_max == VAR_cep.snd_una);

	/*
	 *  idle:   アイドル時間
	 *  rxtcur: 現在の再送タイムアウト
	 */
	if (idle && VAR_cep.idle >= VAR_cep.rxtcur)

		/*
		 *  snd_cwnd: 輻輳ウィンドサイズ
		 *  maxseg  : 相手の最大受信セグメントサイズ
		 *
		 *  長時間アイドルだったのでスロースタート制御に設定する。
		 */
		VAR_cep.snd_cwnd = VAR_cep.maxseg;

	while (error == E_OK && sendalot) {
		sendalot = false;

		/*
		 *  snd_nxt: 次に送信する SEQ、この時点では、前回送信した SEQ
		 *  snd_una: 未確認の最小送信 SEQ、または確認された最大送信 SEQ
		 *
		 *  doff: 送信を開始するオフセット。
		 *                                    swbuf_count (送信バッファにあるオクテット数)
		 *    0                               V
		 *    +-------------------------------------------+
		 *    |                    sbuf                   |
		 *    +-------------------------------------------+
		 *    ^               ^
		 *    |<------------->snd_nxt (前回送信した SEQ)
		 *    |       doff
		 *    snd_una (まだ確認されていない)
		 */
		doff = (uint_t)(VAR_cep.snd_nxt - VAR_cep.snd_una);

		/*
		 *  snd_wnd:  相手の受信可能ウィンドサイズ
		 *  snd_cwnd: 輻輳ウィンドサイズ
		 *
		 *  win: どちらか小さいウィンドサイズに設定する。
		 */
		win = VAR_cep.snd_wnd < VAR_cep.snd_cwnd ? VAR_cep.snd_wnd : VAR_cep.snd_cwnd;

		/* 出力フラグの設定 */
		flags = tcp_outflags[VAR_cep.fsm_state];
		if (VAR_flags & TCP_CEP_FLG_NEED_FIN)
			flags |= TCP_FLG_FIN;
		if (VAR_flags & TCP_CEP_FLG_NEED_SYN)
			flags |= TCP_FLG_SYN;
		if (VAR_flags & TCP_CEP_FLG_FORCE) {

			/*
			 *  もし、送信ウインドサイズ (win) が 0 なら 1 オクテット送信する。
			 *  そうでなければ、持続タイムアウトをキャンセルし、
			 *  再送信回数 (rxtshift) を 0 にする。
			 */
			if (win == 0) {

				/*
				 *  doff:        送信するオクテット数。
				 *  swbuf_count: 送信バッファの使用中サイズ
				 *
				 *  送信バッファに残っているオクテットが、これから
				 *  送信しようとしているオクテット数より多ければ
				 *  FIN フラグをクリアする。
				 */
				if (doff < VAR_cep.swbuf_count)
					flags &=~TCP_FLG_FIN;
				win = 1;
			}
			else {
				/*
				 *  TCP_TIM_PERSIST: 持続タイマ
				 *  rxtshift:        再送信回数の log(2)
				 */
				VAR_cep.timer[TCP_TIM_PERSIST] = 0;
				VAR_cep.rxtshift = 0;
			}
		 }

		/*
		 *  len: 今回送信するオクテット数
		 *        swbuf_count (送信バッファにあるオクテット数)
		 *                                    |
		 *    0                               V
		 *    +-------------------------------------------+
		 *    |                    sbuf       |           |
		 *    +-------------------------------------------+
		 *    ^               ^<------------->
		 *    |               |      len
		 *    |<------------->snd_nxt (前回送信した SEQ)
		 *    |       doff
		 *    snd_una (まだ確認されていない)
		 */
		if (VAR_cep.swbuf_count < win)
			len = (int32_t)VAR_cep.swbuf_count - doff;
		else
			len = (int32_t)win - doff;

		/*
		 *  すでに送信されていれば、SYN ビットをオフする。
		 *  しかし、以下の条件では送信を控える。
		 *
		 *    ・状態が SYN 送信。
		 *    ・セグメントがデータを含んでいる。
		 */
		if ((flags & TCP_FLG_SYN) && SEQ_GT(VAR_cep.snd_nxt, VAR_cep.snd_una)) {
			flags &= ~TCP_FLG_SYN;
			doff --;		/* -1 は SYN フラグ分 */
			len ++;			/* +1 は SYN フラグ分 */
			if (len > 0 && VAR_cep.fsm_state == TCP_FSM_SYN_SENT)
				break;
		}

		if (flags & TCP_FLG_SYN) {
			len = 0;
			flags &= ~TCP_FLG_FIN;
		}

		if (len < 0) {

			/*
			 *  len が 0 以下なら、0 に設定する。
			 *  もし、送信ウィンドウサイズが 0 なら、
			 *  再送信タイマをキャンセルし、
			 *  前回送信した SEQ (snd_nxt) を
			 *  確認された最大送信 SEQ (snd_una) に戻す。
			 *  そして、持続タイマーが止まっていれば、再設定する。
			 */
			len = 0;
			if (win == 0) {
				VAR_cep.timer[TCP_TIM_REXMT] = 0;
				VAR_cep.rxtshift = 0;
				VAR_cep.snd_nxt  = VAR_cep.snd_una;
				if (VAR_cep.timer[TCP_TIM_PERSIST] == 0)
					tcp_set_persist_timer( p_cellcb );
			}
		}


		/*
		 *  今回送信するオクテット数 (len) は、
		 *  相手の最大受信セグメントサイズ (maxseg) を超えないようにする。
		 */
		if (len > VAR_cep.maxseg) {
			len = VAR_cep.maxseg;
			sendalot = true;
		}

		/*
         *        swbuf_count (送信バッファにあるオクテット数)
         *                                           |
		 *    0                                      V
		 *    +-------------------------------------------+
		 *    |                    sbuf       |           |
		 *    +-------------------------------------------+
		 *    ^               ^<------------->
		 *    |               |      len
		 *    |<------------->snd_nxt (前回送信した SEQ)
		 *    |       doff
		 *    snd_una (まだ確認されていない)
		 *
		 *  今回送信後も、送信バッファにデータが残っていれば
		 *  FIN フラグをクリアする。
		 */
		if (SEQ_LT(VAR_cep.snd_nxt + len, VAR_cep.snd_una + VAR_cep.swbuf_count))
			flags &= ~TCP_FLG_FIN;

		/*
		 *  ここから win は、受信ウィンドウサイズ。
		 *  受信バッファの空き容量
		 */
		win = VAR_rbufSize - VAR_cep.rwbuf_count;

		/*
		 *  愚かなウィンドウ・シンドロームの回避処理 (送信側)
		 *
		 *  以下の条件で、送信を行う。
		 *
		 *    ・フルサイズ (maxseg) のセグメントを送ることができる。
		 *    ・相手の最大の受信ウィンドウサイズの 1/2 のデータを
		 *      送ることができる。
		 *    ・送信バッファを空にでき、アイドルか非遅延オプションが有効なとき。
		 */
		if (len) {

			/*
			 *  今回送信するオクテット数 (len) が
			 *  相手の最大受信セグメントサイズ (maxseg) に
			 *  一致するときは送信する。
			 */
			if (len == VAR_cep.maxseg) {
				error = send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
				continue;
			}

			/*
			 *  今回の送信で、送信バッファを空にでき、
			 *  アイドルか非 PUSH オプションが有効なとき。
			 */
			if ((idle || (VAR_flags & TCP_CEP_FLG_NO_DELAY)) &&
			    (VAR_flags & TCP_CEP_FLG_NO_PUSH) == 0 &&
			    len + doff >= VAR_cep.swbuf_count) {
				error = send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
				continue;
			}

			/*
			 *  max_sndwnd: 今までの最大送信ウィンドサイズ
			 *  snd_nxt:    次に送信する SEQ
			 *  snd_max:    送信した最大 SEQ
			 *
			 *  次の条件では送信を行う。
			 *
			 *    ・強制送信フラグがセットされている。
			 *    ・データ長が相手の最大の受信ウィンドウサイズの 1/2 以上で、
			 *      相手の最大の受信ウィンドウサイズが 0 より大きい。
			 *    ・次に送信する SEQ が送信した最大 SEQ より小さい、
			 *      つまり、再送するとき。
			 */
			if ((VAR_flags & TCP_CEP_FLG_FORCE) ||
			    (len >= VAR_cep.max_sndwnd / 2 && VAR_cep.max_sndwnd > 0) ||
			    SEQ_LT(VAR_cep.snd_nxt, VAR_cep.snd_max)) {
				error = send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
				continue;
			}
		}


		/*
		 *  愚かなウィンドウ・シンドロームの回避処理 (受信側)
		 *
		 *  ウィンドウサイズがフルサイズの 2 倍のセグメント、あるいは
		 *  受信バッファ容量の 1/2 の、いずれか小さいほうの
		 *  サイズで増加される場合は、ウィンドウサイズの更新を行う。
		 */
		if (win > 0) {
			long adv;

			/*
			 *  win:              受信バッファの空き容量
			 *  MAX_TCP_WIN_SIZE: TCP ヘッダの win フィールドに設定できる最大値
			 *  rcv_adv:          受信を期待している最大の SEQ
			 *  rcv_nxt:          受信を期待している最小の SEQ
			 */
			if (win < MAX_TCP_WIN_SIZE)
				adv = win - (VAR_cep.rcv_adv - VAR_cep.rcv_nxt);
			else
				adv = MAX_TCP_WIN_SIZE - (VAR_cep.rcv_adv - VAR_cep.rcv_nxt);

			if (adv     >= (long)(VAR_cep.maxseg * 2) ||
			    adv * 2 >= (long) VAR_rbufSize) {
				error = send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
				continue;
			}
		}

		/*
		 *  ACK を送信する。
		 */
		if (VAR_flags & TCP_CEP_FLG_ACK_NOW) {
			error = send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
			continue;
		}

		if ( (flags & TCP_FLG_RST) ||
		    ((flags & TCP_FLG_SYN) && (VAR_flags & TCP_CEP_FLG_NEED_SYN) == 0)) {
			error = send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
			continue;
		}

#ifdef TCP_CFG_EXTENTIONS

		if (SEQ_GT(VAR_cep.snd_up, VAR_cep.snd_una)) {
			error = send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
			continue;
		}

#endif	/* of #ifdef TCP_CFG_EXTENTIONS */

		/*
		 *  snd_nxt: 次に送信する SEQ
		 *  snd_una: 未確認の最小送信 SEQ、または確認された最大送信 SEQ
		 *
		 *  相手から FIN を受信し、まだ FIN を送信していないか、
		 *  送るデータがないときは、FIN を相手に届けるため、
		 *  セグメントを送信する。
		 */
		if ((flags & TCP_FLG_FIN) &&
		    ((VAR_flags & TCP_CEP_FLG_SENT_FIN) == 0 || VAR_cep.snd_nxt == VAR_cep.snd_una)) {
			error = send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
			continue;
		}

		/*
		 *  送信すべきデータがあり、再送タイマと持続タイマが切れているときは
		 *  持続タイマを設定する。
		 */
		if (VAR_cep.swbuf_count && VAR_cep.timer[TCP_TIM_REXMT	] == 0 &&
		                           VAR_cep.timer[TCP_TIM_PERSIST] == 0) {
			VAR_cep.rxtshift = 0;
			tcp_set_persist_timer( p_cellcb );
			break;
		}

	}
}

/*
 *  tcp_close -- コネクションを開放する。
 */

static T_TCP_CEP *
tcp_close (CELLCB *p_cellcb)
{}

/*
 *  tcp_set_persist_timer -- 持続タイマの設定
 */

static void
tcp_set_persist_timer (CELLCB *p_cellcb)
{}

/*
 *  send_segment -- TCP 出力処理
 */

static ER
send_segment (CELLCB *p_cellcb, bool_t *sendalot, uint_t doff, uint_t win, uint_t len, uint8_t flags)
{
	T_NET_BUF	*output;
	T_TCP_HDR	*tcph;
	uint_t		optlen;
	ER			error;
	int32_t 	offset;
	int32_t 	addrlen;

#ifdef TCP_CFG_OPT_MSS

	uint8_t		*optp;

	if (flags & TCP_FLG_SYN)
		optlen = TCP_OPT_LEN_MAXSEG;
	else
		optlen = 0;

#else/* of #ifdef TCP_CFG_OPT_MSS */

	optlen = 0;

#endif/* of #ifdef TCP_CFG_OPT_MSS */

	if (VAR_offset.protocolflag == 0) {

		VAR_offset.protocolflag |= FLAG_USE_TCP;

		if (ATTR_ipLength == 4)
			VAR_offset.protocolflag |= FLAG_USE_IPV4;
		else
			VAR_offset.protocolflag |= FLAG_USE_IPV6;

		cTCPOutput_getOffset(&VAR_offset);
	}

	offset = VAR_offset.ifhdrlen + VAR_offset.iphdrlen;

	//debug---
	switch (VAR_cep.fsm_state) {
	  case TCP_FSM_SYN_RECVD:
		syslog(LOG_EMERG,"TCP CEP OUTPUT now. CEP mode is SYN_RECVD");
		break;

	  case TCP_FSM_ESTABLISHED:
		syslog(LOG_EMERG,"TCP CEP OUTPUT now. CEP mode is ESTABLISHED");
		break;
	}
	//debug---

	/*
	 *  セグメント長を、相手の最大受信セグメント長に調整する。
	 *  もし、超えている場合は、超えた分を後で送信する。
	 *  このため、FIN ビットをクリアする。
	 *
	 *  オリジナルでは、t_maxopd を制限長にしているが、
	 *  本実装では、相手の最大受信セグメントにする。
	 */
	if (len + optlen > VAR_cep.maxseg) {
		flags &= ~TCP_FLG_FIN;
		len = VAR_cep.maxseg - optlen;
		*sendalot = true;
	}

	/*
	 *  送信バッファが空になるときは PUSH フラグを設定する。
	 */
	if (len && doff + len >= VAR_cep.swbuf_count)
		flags |= TCP_FLG_PUSH;

	/* データ長を 4 オクテット境界に調整する。*/
	int32_t align = (len + optlen + TCP_HDR_SIZE + 3) >> 2 << 2;
	int32_t size;


#if defined(TCP_CFG_SWBUF_CSAVE_ONLY)

	if (len > 0 && ((VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SEND_READY ||
	                (VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SENT)) {

		/*
		 *  送信ウインドバッファが開放されないようにして、
		 *  ネットワークバッファを出力に移す。
		 */
		VAR_cep.swbufq->flags |= NB_FLG_NOREL_IFOUT;
		output = VAR_cep.swbufq;
	}
	else {

		/*
		 *  ACK 完了状態で、この関数が呼び出されることもある。
		 *  この時は、len を 0 にして、処理を継続する。
		 */
		len = 0;
		if ((error = cTCPOutput_output_outputp_alloc((void**)&output, align + offset, TMO_TCP_GET_NET_BUF)) != E_OK) {
			if (VAR_cep.timer[TCP_TIM_REXMT] == 0)
				VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
			goto err_ret;
		}
	}

#elif defined(TCP_CFG_SWBUF_CSAVE)	/* of #if defined(TCP_CFG_SWBUF_CSAVE_ONLY) */

	if (IS_PTR_DEFINED(VAR_sbuf)) {
		if ((error = cTCPOutput_output_outputp_alloc((void**)&output, align + offset, TMO_TCP_GET_NET_BUF)) != E_OK) {
			if (VAR_cep.timer[TCP_TIM_REXMT] == 0)
				VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
			goto err_ret;
		}
	}
	else if (len > 0 && ((VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SEND_READY ||
	                     (VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SENT)) {

		/*
		 *  送信ウインドバッファが開放されないようにして、
		 *  ネットワークバッファを出力に移す。
		 */
		VAR_cep.swbufq->flags |= NB_FLG_NOREL_IFOUT;
		output = VAR_cep.swbufq;
	}
	else {

		/*
		 *  ACK 完了状態で、この関数が呼び出されることもある。
		 *  この時は、len を 0 にして、処理を継続する。
		 */
		len = 0;
		if ((error = cTCPOutput_output_outputp_alloc((void**)&output, align + offset, TMO_TCP_GET_NET_BUF)) != E_OK) {
			if (VAR_cep.timer[TCP_TIM_REXMT] == 0)
				VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
			goto err_ret;
		}
	}

#else	/* of #if defined(TCP_CFG_SWBUF_CSAVE_ONLY) */

	if ((error = cTCPOutput_output_outputp_alloc((void**)&output, align + offset, TMO_TCP_GET_NET_BUF)) != E_OK) {
		if (VAR_cep.timer[TCP_TIM_REXMT] == 0)
			VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
		goto err_ret;
	}

#endif	/* of #if defined(TCP_CFG_SWBUF_CSAVE_ONLY) */

	output->off 			= VAR_offset;
	output->off.tphdrlenall = TCP_HDR_SIZE + optlen;
	output->off.iphdrlenall = VAR_offset.iphdrlen;

	tcph = GET_TCP_HDR(output, offset);

	/* TCP ヘッダに情報を設定する。*/
	tcph->sport	= htons(VAR_myport);
	tcph->dport	= htons(VAR_dstport);
	tcph->doff	= TCP_MAKE_DATA_OFF(TCP_HDR_SIZE + optlen);
	tcph->sum	= tcph->flags = 0;

	/* ネットワークバッファ長を調整する。*/
	output->len = (uint16_t)(offset + TCP_HDR_SIZE + optlen + len - output->off.ifalign);
	size = output->len + sizeof(T_NET_BUF) - 4;

	/*
	 *  TCP オプションの設定を行う。
	 *  本実装では、最大セグメントサイズのみ設定する。
	 */
	if (flags & TCP_FLG_SYN) {
		VAR_cep.snd_nxt = VAR_cep.iss;

#ifdef TCP_CFG_OPT_MSS

		optp = GET_TCP_OPT(output, offset);
		*optp ++ = TCP_OPT_MAXSEG;
		*optp ++ = TCP_OPT_LEN_MAXSEG;
		*(uint16_t*)optp = htons(DEF_TCP_RCV_SEG);

#endif/* of #ifdef TCP_CFG_OPT_MSS */

	}

	/* TCP SDU に送信データをコピーする。*/

	if (len > 0) {
		if (SEQ_LT(VAR_cep.snd_nxt, VAR_cep.snd_max)) {
			NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_REXMIT_SEGS], 1);
			NET_COUNT_MIB(tcp_stats.tcpRetransSegs, 1);
		}
		//TCP_READ_SWBUF(cep, output, len, doff);
		cCopySave_tcpReadSwbuf(&VAR_cep, output, size, doff, VAR_sbuf, VAR_sbufSize, offset, len);
	}
	else {
		if (VAR_flags & TCP_CEP_FLG_ACK_NOW)
			NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_ACKS], 1);
		if (flags & (TCP_FLG_FIN | TCP_FLG_SYN | TCP_FLG_RST))
			NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_CNTL_SEGS],  1);


#ifdef TCP_CFG_EXTENTIONS

		if (SEQ_LT(VAR_cep.snd_up, VAR_cep.snd_una))
			NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_URG_SEGS], 1);

#endif	/* of #ifdef TCP_CFG_EXTENTIONS */

	}

	/*
	 * snd_max: 送信した最大 SEQ
	 * snd_nxt: 次に送信する SEQ
	 *
	 *  相手から FIN を受信し、まだ FIN を送信していないか、
	 *  送るデータがないときは、FIN を相手に届けるため、
	 *  セグメントを送信するが、SEQ は進めない。
	 */
	if ((flags & TCP_FLG_FIN) && (VAR_flags & TCP_CEP_FLG_SENT_FIN) &&
	    VAR_cep.snd_nxt == VAR_cep.snd_max) {
		VAR_cep.snd_nxt --;
	}

	/*
	 *  SEQ、ACK、フラグの設定。
	 */
	if (len > 0 || (flags & (TCP_FLG_SYN | TCP_FLG_FIN)) || VAR_cep.timer[TCP_TIM_PERSIST] != 0)
		tcph->seq = htonl(VAR_cep.snd_nxt);
	else
		tcph->seq = htonl(VAR_cep.snd_max);

	/*
	 *  rcv_nxt: 受信を期待している最小の SEQ
	 */
	tcph->ack   = htonl(VAR_cep.rcv_nxt);
	tcph->flags = flags;

	/*
	 *  受信ウィンドの計算
	 *
	 *  rbufsz: 受信用バッファサイズ
	 *  maxseg: 相手の最大受信セグメントサイズ
	 */
	if (win < (VAR_rbufSize / 4) && win < VAR_cep.maxseg)
		win = 0;

	/*
	 *  rcv_nxt: 受信を期待している最小の SEQ
	 *  rcv_adv: 受信を期待している最大の SEQ
	 */
	if ((int32_t)win < (int32_t)(VAR_cep.rcv_adv - VAR_cep.rcv_nxt))
		win = (uint_t)(VAR_cep.rcv_adv - VAR_cep.rcv_nxt);

	tcph->win = htons(win);

#ifdef TCP_CFG_EXTENTIONS

	/*
	 *  緊急ポインタの設定
	 */
	if (SEQ_GT(VAR_cep.snd_up, VAR_cep.snd_nxt)) {
		if (TCP_CFG_URG_OFFSET)
			tcph->urp    = htons((uint16_t)(VAR_cep.snd_up - VAR_cep.snd_nxt));
		else
			tcph->urp    = htons((uint16_t)(VAR_cep.snd_up - VAR_cep.snd_nxt - 1));
		tcph->flags |= TCP_FLG_URG;
	}
	else
		VAR_cep.snd_up  = VAR_cep.snd_una;

#endif	/* of #ifdef TCP_CFG_EXTENTIONS */

	/*
	 *  チェックサムを設定する。
	 */
	tcph->sum = 0;
	//?? tcph->sum = IN_CKSUM(output, IPPROTO_TCP, hdr_offset, GET_TCP_HDR_SIZE(output, hdr_offset) + len);

	/*
	 *  タイマの調整
	 */
	if ((VAR_flags & TCP_CEP_FLG_FORCE) == 0 || VAR_cep.timer[TCP_TIM_PERSIST] == 0) {
		T_TCP_SEQ startseq = VAR_cep.snd_nxt;

		/*
		 *  次に送信する SEQ (snd_nxt) を今回送信するデータ数分進める。
		 */
		if (flags & TCP_FLG_SYN)
			VAR_cep.snd_nxt ++;
		if (flags & TCP_FLG_FIN) {
			VAR_flags |= TCP_CEP_FLG_SENT_FIN;
			VAR_cep.snd_nxt ++;
		}

		VAR_cep.snd_nxt += len;

		/*
		 *  次に送信する SEQ (snd_nxt) が
		 *  送信した最大 SEQ (snd_max) より進んでいれば、
		 *  送信した最大 SEQ (snd_max) を更新する。
		 */
		if (SEQ_GT(VAR_cep.snd_nxt, VAR_cep.snd_max)) {
			VAR_cep.snd_max = VAR_cep.snd_nxt;
			/*
			 *  もし、往復時間計測を行っていなければ、
			 *  この送信に時間を合わせる。
			 */
			if (VAR_cep.rtt == 0) {
				VAR_cep.rtt   = 1;
				VAR_cep.rtseq = startseq;	/* 更新前の cep->snd_nxt */
			}
		}

		/*
		 *  もし設定されていないか、ACK または保留が発生していなければ、
		 *  再送タイマを設定する。設定する初期値は、
		 * 「滑らかな往復時間 + 2 × 往復時間変動」である。
		 *  再送時間のバックオフに使われるシフトカウントも初期化する。
		 */
		if (VAR_cep.timer[TCP_TIM_REXMT] == 0 && VAR_cep.snd_nxt != VAR_cep.snd_una) {
			VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
			if (VAR_cep.timer[TCP_TIM_PERSIST] != 0) {
				VAR_cep.timer[TCP_TIM_PERSIST] = 0;
				VAR_cep.rxtshift = 0;
			}
		}
	}

	/*
	 *  次に送信する SEQ (snd_nxt) + 今回送信するデータ数 (len) が
	 *  送信した最大 SEQ (snd_max) より進んでいれば、
	 *  送信した最大 SEQ (snd_max) を更新する。
	 */
	else if (SEQ_GT(VAR_cep.snd_nxt + len, VAR_cep.snd_max))
		VAR_cep.snd_max = VAR_cep.snd_nxt + len;

#ifdef TCP_CFG_SWBUF_CSAVE

	if ((VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SEND_READY)
		VAR_flags = (VAR_flags & ~TCP_CEP_FLG_WBCS_MASK) | TCP_CEP_FLG_WBCS_SENT;

#endif	/* of #ifdef TCP_CFG_SWBUF_CSAVE */

#ifdef TCP_CFG_TRACE

	//?? tcp_output_trace(output, cep);

#endif	/* of #ifdef TCP_CFG_TRACE */

	/* ネットワーク層 (IP) の出力関数を呼び出す。*/
	if ((error = cTCPOutput_output(output, size, cGetAddress_getDstAddress( ), cGetAddress_getMyAddress(), ATTR_ipLength)) != E_OK)
		goto err_ret;

	/*
	 *  相手に伝えたウィンドウサイズ (win) が 0 以上で、
	 *  受信を期待している最小の SEQ (rcv_nxt) + win が
	 *  受信を期待している最大の SEQ (rcv_adv) より進んでいれば
	 *  受信を期待している最大の SEQ を更新する。
	 */
	if (win > 0 && SEQ_GT(VAR_cep.rcv_nxt + win, VAR_cep.rcv_adv)) {
		VAR_cep.rcv_adv = VAR_cep.rcv_nxt + win;
	}

	/*
	 *  最後に送信した ACK (last_ack_sent) を更新する。
	 */
	VAR_cep.last_ack_sent = VAR_cep.rcv_nxt;

	/*
	 *  フラグの設定を行う。
	 */
	VAR_flags &= ~(TCP_CEP_FLG_ACK_NOW | TCP_CEP_FLG_DEL_ACK);
	if (VAR_flags & TCP_CEP_FLG_FORCE_CLEAR)
		VAR_flags &= ~(TCP_CEP_FLG_FORCE | TCP_CEP_FLG_FORCE_CLEAR);

	return E_OK;

err_ret:
	/*
	 * 以下に関係しないフラグをクリアーする。
	 * ・送受信ウィンドバッファの省コピー機能
	 * ・動的な通信端点の生成・削除機能
	 */
	VAR_flags &= TCP_CEP_FLG_NOT_CLEAR;

	return error;
}