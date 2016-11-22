/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tIfMbed_template.c => src/tIfMbed.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * macaddr0         uint8_t          VAR_macaddr0    
 * macaddr1         uint8_t          VAR_macaddr1    
 * macaddr2         uint8_t          VAR_macaddr2    
 * macaddr3         uint8_t          VAR_macaddr3    
 * macaddr4         uint8_t          VAR_macaddr4    
 * macaddr5         uint8_t          VAR_macaddr5    
 * timer            uint16_t         VAR_timer       
 * sc               TECS_T_MBED_SOFTC*  VAR_sc          
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
 * call port: cSemaphoreSend signature: sSemaphore context:task
 *   ER             cSemaphoreSend_signal( );
 *   ER             cSemaphoreSend_wait( );
 *   ER             cSemaphoreSend_waitPolling( );
 *   ER             cSemaphoreSend_waitTimeout( TMO timeout );
 *   ER             cSemaphoreSend_initialize( );
 *   ER             cSemaphoreSend_refer( T_RSEM* pk_semaphoreStatus );
 * call port: ciSemaphoreReceive signature: siSemaphore context:non-task
 *   ER             ciSemaphoreReceive_signal( );
 * call port: cInterruptRequest signature: sInterruptRequest context:task
 *   ER             cInterruptRequest_disable( );
 *   ER             cInterruptRequest_enable( );
 * allocator port for call port:eNicDriver func:start param: outputp
 *   ER             eNicDriver_start_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eNicDriver_start_outputp_dealloc( const void* buf );
 *   ER             eNicDriver_start_outputp_reuse( void* buf );
 *   ER_UINT        eNicDriver_start_outputp_bufferSize( const void* buf );
 *   uint32_t       eNicDriver_start_outputp_bufferMaxSize( );
 * allocator port for call port:eNicDriver func:read param: inputp
 *   ER             eNicDriver_read_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eNicDriver_read_inputp_dealloc( const void* buf );
 *   ER             eNicDriver_read_inputp_reuse( void* buf );
 *   ER_UINT        eNicDriver_read_inputp_bufferSize( const void* buf );
 *   uint32_t       eNicDriver_read_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tIfMbed_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#define CAST(type, val)		((type)(val))

#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "kernel/kernel_impl.h"

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <net/net.h>
#include <net/net_timer.h>
#include <net/net_count.h>
#include <net/net_buf.h>
#include <net/ethernet.h>

#include "mbed_interface.h"
#include "ethernet_api.h"
#include "ethernetext_api.h"
#include <string.h>
#include "if_mbed.h"
#include "iodefine.h"

#ifdef _MSC_VER
#include <stdlib.h>
#endif

extern uint8_t mac_addr[ETHER_ADDR_LEN];
extern T_IF_SOFTC if_softc;
extern struct t_mbed_softc mbed_softc;

/*
 *  局所変数
 */

static void if_mbed_stop ( TECS_T_MBED_SOFTC *sc);
static void if_mbed_init_sub ( CELLCB *p_cellcb , TECS_T_IF_SOFTC *tecsic);

#ifdef SUPPORT_INET6

static uint32_t ds_crc (uint8_t *addr);
static void ds_getmcaf (T_IF_SOFTC *ic, uint32_t *mcaf);


/*
 *  ds_crc -- イーサネットアドレスの CRC を計算する。
 */

#define POLYNOMIAL	0x04c11db6

static uint32_t
ds_crc (uint8_t *addr) {
	uint32_t	crc = ULONG_C(0xffffffff);
	int_t		carry, len, bit;
	uint8_t		byte;

	for (len = ETHER_ADDR_LEN; len -- > 0; ) {
		byte = *addr ++;
		for (bit = 8; bit -- > 0; ) {
			carry   = ((crc & ULONG_C(0x80000000)) ? 1 : 0) ^ (byte & UINT_C(0x01));
			crc   <<= 1;
			byte   >>= 1;
			if (carry)
				crc = (crc ^ POLYNOMIAL) | carry;
		}
	}
	return crc;
}

#undef POLYNOMIAL

/*
 *  ds_getmcaf -- マルチキャストアドレスのリストからマルチキャストアドレス
 *                フィルタを計算する。
 */

static void
ds_getmcaf (T_IF_SOFTC *ic, uint32_t *mcaf) {
	uint32_t	count, index;
	uint8_t		*af = (uint8_t*)mcaf;

	mcaf[0] = mcaf[1] = 0;

	for (count = MAX_IF_MADDR_CNT; count -- > 0; ) {
		index = ds_crc(ic->maddrs[count].lladdr) >> 26;
		af[index >> 3] |= 1 << (index & 7);
	}
}

/*
 * mbed_setrcr -- 受信構成レジスタ (RCR) を設定する。
 */

static void
if_mbed_setrcr (T_IF_SOFTC *ic) {
	T_MBED_SOFTC	*sc = ic->sc;
}

/*
 * mbed_addmulti -- マルチキャストアドレスを追加する。
 */

ER
if_mbed_addmulti (T_IF_SOFTC *ic) {
	mbed_setrcr(ic);
	return E_OK;
}

#endif	/* of #ifdef SUPPORT_INET6 */

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eNicDriver
 * entry port: eNicDriver
 * signature:  sNicDriver
 * context:    task
 * #[</ENTRY_PORT>]# */

#define ETHER_EESR0_TC 0x00200000

/*
 * mbed_init -- ネットワークインタフェースの初期化
 */
/* #[<ENTRY_FUNC>]# eNicDriver_init
 * name:         eNicDriver_init
 * global_name:  tIfMbed_eNicDriver_init
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNicDriver_init(CELLIDX idx, TECS_T_IF_SOFTC *tecsic)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	syslog(LOG_NOTICE, "Debug: eNicDriver_init\n");
	/**
	*	Debug用
	*/
	VAR_timer = 0;
		VAR_sc = &mbed_softc;
	syslog(LOG_NOTICE, "Debug: p_cellcb = %x\n", p_cellcb);
	syslog(LOG_NOTICE, "Debug: if_softc = %x\n", &if_softc);
	syslog(LOG_NOTICE, "Debug: sc = %x\n", p_cellcb->sc);
	syslog(LOG_NOTICE, "Debug: mbed_softc = %x\n", &mbed_softc);

	/* mbed_init 本体を呼び出す。*/
	if_mbed_init_sub( p_cellcb , tecsic);

	act_tsk( IF_MBED_PHY_TASK );

	ethernet_set_link(-1, 0);

	ETHER.EESIPR0 |= ETHER_EESR0_TC;

}

/* #[<ENTRY_FUNC>]# eNicDriver_start
 * name:         eNicDriver_start
 * global_name:  tIfMbed_eNicDriver_start
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNicDriver_start(CELLIDX idx, int8_t* outputp, int32_t size, uint8_t align)
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

/* #[<ENTRY_FUNC>]# eNicDriver_read
 * name:         eNicDriver_read
 * global_name:  tIfMbed_eNicDriver_read
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNicDriver_read(CELLIDX idx, int8_t** inputp, int32_t* size, uint8_t align)
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

/* #[<ENTRY_FUNC>]# eNicDriver_getMac
 * name:         eNicDriver_getMac
 * global_name:  tIfMbed_eNicDriver_getMac
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNicDriver_getMac(CELLIDX idx, uint8_t* macaddress)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	syslog(LOG_NOTICE, "Debug: eNicDriver_getMac\n");
	//mikanちゃんとハードウェアからとってくるべき
// TODO	
/*
	macaddress[0] = VAR_macaddr0;
	macaddress[1] = VAR_macaddr1;
	macaddress[2] = VAR_macaddr2;
	macaddress[3] = VAR_macaddr3;
	macaddress[4] = VAR_macaddr4;
	macaddress[5] = VAR_macaddr5;
*/
}

/* #[<ENTRY_FUNC>]# eNicDriver_reset
 * name:         eNicDriver_reset
 * global_name:  tIfMbed_eNicDriver_reset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNicDriver_reset(CELLIDX idx, TECS_T_IF_SOFTC *tecsic)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	ethernetext_start_stop(0);

	NET_COUNT_ETHER_NIC(net_count_ether_nic[NC_ETHER_NIC_RESETS], 1);
	if_mbed_stop( p_cellcb->sc );
	if_mbed_init_sub( p_cellcb , tecsic);

    ethernetext_start_stop(1);
}

/* #[<ENTRY_PORT>]# eiBody
 * entry port: eiBody
 * signature:  siHandlerBody
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiBody_main
 * name:         eiBody_main
 * global_name:  tIfMbed_eiBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiBody_main(CELLIDX idx)
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

static void rza1_recv_callback(void) {
	CELLCB	*p_cellcb;
    sig_sem(if_softc.semid_rxb_ready);
    //ciSemaphoreReceive_signal();
}

static void
if_mbed_init_sub ( CELLCB *p_cellcb , TECS_T_IF_SOFTC *tecsic) {
    ethernet_cfg_t ethcfg;
	uint8_t *macaddress;
    eNicDriver_getMac(p_cellcb, macaddress);
    macaddress = 0x2002023c;	// TODO
    syslog(LOG_NOTICE, "Debug: macaddress = 0x%x\n", macaddress);

    /* Initialize the hardware */
    ethcfg.int_priority = 6;
    ethcfg.recv_cb      = &rza1_recv_callback;
    //ethcfg.ether_mac    = (char *)ic->ifaddr.lladdr;
    ethcfg.ether_mac    = (char *)macaddress;

    ethernetext_init(&ethcfg);
}	

static void
if_mbed_stop ( TECS_T_MBED_SOFTC *sc) {
	ethernetext_start_stop(0);
}