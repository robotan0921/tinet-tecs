/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tEthernetOutput_template.c => src/tEthernetOutput.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cRawOutput signature: sEthernetRawOutput context:task
 *   ER             cRawOutput_ethernetRawOutput( int8_t* outputp, int32_t size, TMO tmout );
 * call port: cNicDriver signature: sNicDriver context:task
 *   void           cNicDriver_init( );
 *   void           cNicDriver_start( int8_t* outputp, int32_t size, uint8_t align );
 *   T_NET_BUF*     cNicDriver_read( int8_t** inputp, int32_t* size, uint8_t align );
 *   void           cNicDriver_probe( uint8_t* macaddress );
 *   void           cNicDriver_reset( );
 * call port: cArpOutput signature: sArpOutput context:task optional:true
 *   bool_t     is_cArpOutput_joined()                     check if joined
 *   ER             cArpOutput_arpResolve( int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, const uint8_t* macaddress, TMO tmout );
 * allocator port for call port:cRawOutput func:ethernetRawOutput param: outputp
 *   ER             cRawOutput_ethernetRawOutput_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cRawOutput_ethernetRawOutput_outputp_dealloc( const void* buf );
 *   ER             cRawOutput_ethernetRawOutput_outputp_reuse( void* buf );
 *   ER_UINT        cRawOutput_ethernetRawOutput_outputp_bufferSize( const void* buf );
 *   uint32_t       cRawOutput_ethernetRawOutput_outputp_bufferMaxSize( );
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
 * allocator port for call port:cArpOutput func:arpResolve param: outputp
 *   ER             cArpOutput_arpResolve_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cArpOutput_arpResolve_outputp_dealloc( const void* buf );
 *   ER             cArpOutput_arpResolve_outputp_reuse( void* buf );
 *   ER_UINT        cArpOutput_arpResolve_outputp_bufferSize( const void* buf );
 *   uint32_t       cArpOutput_arpResolve_outputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tEthernetOutput_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
