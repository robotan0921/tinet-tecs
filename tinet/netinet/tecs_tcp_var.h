#ifndef _TECS_TCP_VAR_H_
#define _TECS_TCP_VAR_H_

/*
 * TCP で使用する変数の型の定義
 */

typedef uint32_t T_TCP_SEQ;
typedef uint16_t T_TCP_SEG;
typedef uint16_t T_TCP_WND;
typedef int16_t  T_TCP_TIME;

/*
 *  TCP タイマ変数
 */

#define NUM_TCP_TIMERS		4	/* TCP のタイマ数	*/

/*
 *  TCP 通信端点
 */

#ifndef T_NET_BUF_DEFINED

typedef struct t_net_buf T_NET_BUF;

#define T_NET_BUF_DEFINED

#endif	/* of #ifndef T_NET_BUF_DEFINED */

#ifndef T_TCP_CEP_DEFINED

typedef struct t_tcp_cep {

	/*
	 * ITRON TCP/IP API、TCP 通信端点と同じメンバ
	 */
	//ATR			cepatr;		/* 通信端点属性			*/
	//void		*sbuf;		/* 送信用ウィンドバッファ	*/
	//int_t		sbufsz;		/* 送信用ウィンドバッファサイズ	*/
	//void		*rbuf;		/* 受信用ウィンドバッファ	*/
	//int_t		rbufsz;		/* 受信用ウィンドバッファサイズ	*/
	//t_tcp_callback	callback;	/* コールバック関数		*/

	/*
	 * TINET 独自のメンバ
	 */
	//uint32_t	flags;		/* 通信端点フラグ		*/
	//ID			semid_lock;	/* 通信端点ロック		*/
	//ID			est_flgid;	/* コネクション状態イベントフラグ	*/
	//ID			snd_flgid;	/* 送信イベントフラグ		*/
	//ID			rcv_flgid;	/* 受信イベントフラグ		*/
	ID			snd_tskid;	/* 送信タスク識別子		*/
	ID			rcv_tskid;	/* 受信タスク識別子		*/
	uint8_t		*sbuf_rptr;	/* 送信用読み出しポインタ	*/
	uint8_t		*sbuf_wptr;	/* 送信用書き込みポインタ	*/
	uint8_t		*rbuf_rptr;	/* 受信用読み出しポインタ	*/
	uint8_t		*rbuf_wptr;	/* 受信用書き込みポインタ	*/
	T_TCP_SEQ	snd_ssthresh;	/* 輻輳ウィンドサイズ(snd_cwnd)	*/
					/* のしきい値			*/
	T_TCP_TIME	rxtcur;		/* 現在の再送タイムアウト	*/
	T_TCP_TIME	srtt;		/* 平滑化された RTT		*/
	T_TCP_TIME	rttvar;		/* 平滑化された分散		*/
	T_TCP_WND	snd_cwnd;	/* 輻輳ウィンドサイズ		*/

	/*
	 *  相手の最大受信セグメントサイズ
	 *
	 *    オリジナルでは、一般のセグメントの最大サイズ (t_maxseg) と、
	 *    オプション付きのセグメントの最大サイズ (t_maxopd) が別に
	 *    なっている。これは、現在のインターネットでは、オプション付きの
	 *    セグメントのほうが多いからと説明されているためである。
	 *    本実装では、最大セグメントサイズオプション以外のオプションは
	 *    実装しないので、t_maxseg の使用する。
	 */
	T_TCP_SEG	maxseg;

	int16_t		snd_tfn;		/* 送信動作中の API 機能コード	*/
	int16_t		rcv_tfn;		/* 受信動作中の API 機能コード	*/

#ifdef TCP_CFG_NON_BLOCKING

	//T_IPEP 		*p_dstaddr;		/* 相手のアドレスへのポインタ	*/
	//T_IPEP	 	*p_myaddr;		/* 自分のアドレスへのポインタ	*/

#if defined(_IP6_CFG) && defined(_IP4_CFG)
	T_IPV4EP	*p_dstaddr4;	/* 相手のアドレスへのポインタ	*/
	T_IPV4EP 	*p_myaddr4;		/* 自分のアドレスへのポインタ	*/
#endif

	int16_t		snd_nblk_tfn;	/* 送信動作中の API 機能コード	*/
	int16_t		rcv_nblk_tfn;	/* 受信動作中の API 機能コード	*/
	void		*snd_data;		/* 送信データ領域の先頭アドレス	*/
	int_t		snd_len;		/* 送信データ領域の長さ		*/
	void		*rcv_data;		/* 受信データ領域の先頭アドレス	*/
	int_t		rcv_len;		/* 受信データ領域の長さ		*/
	void		**snd_p_buf;	/* 送信バッファへのポインタ	*/
	void		**rcv_p_buf;	/* 受信バッファへのポインタ	*/

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */

#ifdef TCP_CFG_SWBUF_CSAVE
	T_NET_BUF	*swbufq;	/* 送信ウィンドバッファキュー	*/
#endif

	/*
	 *  これ以降のメンバーは tcp_init_cep() 関数でゼロクリアーされる。
	 */

	T_TCP_TIME	timer[NUM_TCP_TIMERS];	/* TCP のタイマ		*/
	//T_IPEP		dstaddr;				/* 相手のアドレス		*/
	//T_IPEP		myaddr;					/* 自分のアドレス		*/
	T_NET_BUF	*reassq;				/* 受信再構成キュー		*/

#if defined(_IP6_CFG)

#if defined(_IP4_CFG)

	T_TCP4_REP	*rep4;		/* IPv4 用受付口		*/

#endif	/* of #if defined(_IP4_CFG) */

	T_TCP6_REP	*rep;		/* IPv6 用受付口		*/

#else	/* of #if defined(_IP6_CFG) */

#if defined(_IP4_CFG)

	T_TCP4_REP	*rep;		/* IPv4 用受付口		*/

#endif	/* of #if defined(_IP4_CFG) */

#endif	/* of #if defined(_IP6_CFG) */


#ifdef TCP_CFG_RWBUF_CSAVE
	T_NET_BUF	*rwbufq;	/* 受信ウィンドバッファキュー	*/
#endif

#ifdef TCP_CFG_EXTENTIONS
	T_TCP_HDR	*urg_tcph;	/* 緊急データ入りのセグメントの TCP ヘッダ	*/
	T_TCP_SEQ	snd_up;		/* 送信した緊急ポインタ		*/
	T_TCP_SEQ	rcv_up;		/* 受信した緊急ポインタ		*/
#endif	/* of #ifdef TCP_CFG_EXTENTIONS */

	T_TCP_SEQ	snd_una;	/* 未確認の最小送信 SEQ つまり	*/
							/* 確認された最大送信 SEQ	*/
	T_TCP_SEQ	snd_max;	/* 送信した最大 SEQ		*/
	T_TCP_SEQ	snd_nxt;	/* 次に送信する SEQ		*/
	T_TCP_SEQ	snd_old_nxt;	/* 元の snd_nxt			*/
	T_TCP_SEQ	snd_wl1;	/* 前回ウィンドを更新した SEQ	*/
	T_TCP_SEQ	snd_wl2;	/* 前回ウィンドを更新した ACK	*/
	T_TCP_SEQ	iss;		/* 自分の SEQ の初期値		*/
	T_TCP_SEQ	irs;		/* 相手の SEQ の初期値		*/
	T_TCP_SEQ	rcv_nxt;	/* 受信を期待している最小の SEQ	*/
	T_TCP_SEQ	rcv_adv;	/* 受信を期待している最大の SEQ	*/
	T_TCP_SEQ	rcv_wnd;	/* 受信可能なウィンドサイズ	*/
	T_TCP_SEQ	rtseq;		/* 時間計測を始めた SEQ		*/
	T_TCP_SEQ	last_ack_sent;	/* 最後に送信した ACK		*/
	T_TCP_TIME	idle;		/* アイドル時間			*/
	ER			error;		/* 非同期に発生したエラー	*/
	ER			net_error;	/* ネットワークのエラー状態	*/
	T_TCP_WND	snd_wnd;	/* 相手の受信可能ウィンドサイズ	*/
	T_TCP_WND	max_sndwnd;	/* 今までの最大送信ウィンドサイズ	*/
	T_TCP_TIME	rtt;		/* 往復時間				*/
	uint16_t	swbuf_count;	/* 送信ウィンドバッファの使用中サイズ	*/
	uint16_t	rwbuf_count;	/* 受信ウィンドバッファの使用中サイズ	*/
	uint16_t	rcv_buf_len;	/* tcp_rcv_buf の割当て長	*/
	uint16_t	get_buf_len;	/* tcp_rcv_buf の割当て長	*/
	uint8_t		rxtshift;	/* 再送信回数の log(2)		*/
	uint8_t		fsm_state;	/* FSM 状態			*/
	uint8_t		dupacks;	/* 再送 ACK 数			*/

#if defined(TCP_CFG_RWBUF_CSAVE) && defined(TCP_CFG_RWBUF_CSAVE_MAX_QUEUES)
	uint16_t	rwbufq_entries;	/* 受信ウィンドバッファキューのエントリ数	*/
#endif

} T_TCP_CEP;

#define T_TCP6_CEP	T_TCP_CEP
#define T_TCP4_CEP	T_TCP_CEP

#define T_TCP_CEP_DEFINED

#endif	/* of #ifndef T_TCP_CEP_DEFINED */

#endif	/* of #ifndef _TECS_TCP_VAR_H_ */