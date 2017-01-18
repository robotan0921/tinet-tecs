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

	return(ercd);
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
