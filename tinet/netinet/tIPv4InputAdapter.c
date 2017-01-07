/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tIPv4InputAdapter_template.c => src/tIPv4InputAdapter.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cIPv4Input signature: sIPv4Input context:task
 *   void           cIPv4Input_IPv4Input( int8_t* inputp, int32_t size );
 * allocator port for call port:cIPv4Input func:IPv4Input param: inputp
 *   ER             cIPv4Input_IPv4Input_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cIPv4Input_IPv4Input_inputp_dealloc( const void* buf );
 *   ER             cIPv4Input_IPv4Input_inputp_reuse( void* buf );
 *   ER_UINT        cIPv4Input_IPv4Input_inputp_bufferSize( const void* buf );
 *   uint32_t       cIPv4Input_IPv4Input_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tIPv4InputAdapter_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/*
 *  icmp_input -- ICMP の入力関数
 *
 *    input には IF ヘッダと IP ヘッダも含まれている。
 */

uint_t
icmp_input (T_NET_BUF **inputp, uint_t *offp, uint_t *nextp)
{
	int32_t size;
	cIPv4Input_IPv4Input(&inputp, size);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
