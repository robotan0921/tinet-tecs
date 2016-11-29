#ifndef _TECS_IF_MBED_H_
#define _TECS_IF_MBED_H_

/*
 *  ネットワークインタフェースに依存するソフトウェア情報 
 */
typedef struct tecs_t_mbed_softc {
	bool_t link_pre;
	bool_t link_now;
	bool_t over_flow;
} TECS_T_MBED_SOFTC;

/*
 *  ネットワークインタフェースに依存しないソフトウェア情報
 */
typedef struct tecs_t_if_softc {
	uint8_t		*ifaddr;			/* ネットワークインタフェースのアドレス	*/
	uint16_t	timer;			/* 送信タイムアウト			*/
	TECS_T_MBED_SOFTC	*sc;	/* ディバイス依存のソフトウェア情報	*/
	ID			semid_txb_ready;	/* 送信セマフォ				*/
	ID			semid_rxb_ready;	/* 受信セマフォ				*/

#ifdef _IP6_CFG

	T_IF_ADDR 	maddrs[MAX_IF_MADDR_CNT];	/* マルチキャストアドレスリスト	*/

#endif	/* of #ifdef _IP6_CFG */
} TECS_T_IF_SOFTC;


#endif /* _TECS_IF_MBED_H_ */
