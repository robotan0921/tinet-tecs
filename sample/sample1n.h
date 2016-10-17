/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2012 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次の条件を満たすこと．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: sample1n.h 936 2016-05-02 11:18:27Z coas-nagasima $
 */

#ifndef _SAMPLE1N_H_
#define _SAMPLE1N_H_

#include <tinet_defs.h>

/*
 *  ネットワーク対応サンプルプログラム(1)のヘッダファイル
 */

/*  TCP 送受信ウィンドバッファサイズ  */

#define TCP_SWBUF_SIZE	512
#define TCP_RWBUF_SIZE	512

/*  リネーム  */

#define syslog		net_syslog
#define serial_rea_dat	net_serial_rea_dat
#define serial_ctl_por	net_serial_ctl_por

#ifndef _MACRO_ONLY

/*  TCP 送受信ウィンドバッファ  */

extern uint8_t tcp_swbuf[];
extern uint8_t tcp_rwbuf[];

/*  ネットワーク対応化関数  */

extern void	net_syslog(uint_t prio, const char *format, ...) throw();
extern ER_UINT	net_serial_rea_dat(ID portid, char *buf, uint_t len) throw();
extern ER	net_serial_ctl_por(ID portid, uint_t ioctl) throw();

/*  ノンブロッキングコールのコールバック関数  */

extern ER	callback_nblk_tcp(ID cepid, FN fncd, void *p_parblk);

#endif /* _MACRO_ONLY */

#endif	/* of #ifndef _SAMPLE1N_H_ */
