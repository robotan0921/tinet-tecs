/*
 * This file was automatically generated by tecsgen.
 * Move and rename like below before editing,
 *   gen/tNetworkBuffer_template.c => src/tNetworkBuffer.c
 * to avoid to be overwritten by tecsgen.
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cFixedSizeMemoryPool signature: sFixedSizeMemoryPool context:task optional:true
 *   bool_t     is_cFixedSizeMemoryPool_joined(int subscript)        check if joined
 *   ER             cFixedSizeMemoryPool_get( subscript, void** p_block );
 *   ER             cFixedSizeMemoryPool_getPolling( subscript, void** p_block );
 *   ER             cFixedSizeMemoryPool_getTimeout( subscript, void** p_block, TMO timeout );
 *   ER             cFixedSizeMemoryPool_release( subscript, const void* block );
 *   ER             cFixedSizeMemoryPool_initialize( subscript );
 *   ER             cFixedSizeMemoryPool_refer( subscript, T_RMPF* pk_fixedSizeMemoryPoolStatus );
 *       subscript:  0...(NCP_cFixedSizeMemoryPool-1)
 * call port: cMemoryPoolStatus signature: sMemoryPoolStatus context:task optional:true
 *   bool_t     is_cMemoryPoolStatus_joined(int subscript)        check if joined
 *   uint32_t       cMemoryPoolStatus_getSize( subscript );
 *       subscript:  0...(NCP_cMemoryPoolStatus-1)
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "tNetworkBuffer_tecsgen.h"
#include "t_syslog.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eNetworkAlloc
 * entry port: eNetworkAlloc
 * signature:  sNetworkAlloc
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eNetworkAlloc_alloc
 * name:         eNetworkAlloc_alloc
 * global_name:  tNetworkBuffer_eNetworkAlloc_alloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eNetworkAlloc_alloc(void** buf, const int32_t minlen, TMO tmout)
{
	int32_t len = minlen+sizeof(T_NET_BUF);
	
	if (minlen > cMemoryPoolStatus_getSize(0)) {
		syslog(LOG_EMERG, "[NET BUF] E_PAR, minlen=%4d > %4d",minlen,cMemoryPoolStatus_getSize(0));
		return E_PAR;
	}

	int_t	ix, req_ix;
	ER	error = E_OK;
	T_NET_BUF* tmp;
	/* 最適なサイズの固定長メモリプールを探す。*/
	ix = N_CP_cFixedSizeMemoryPool;
	while (ix -- > 0 && len > cMemoryPoolStatus_getSize(ix));
	req_ix = ix;

	while (1) {
		if(ix == 0)
		  error = cFixedSizeMemoryPool_getTimeout(ix,buf,tmout);
		if((ix > 0) && (ix < N_CP_cFixedSizeMemoryPool))
		  error = cFixedSizeMemoryPool_getPolling(ix,buf);
		if (error == E_OK) {
			tmp = (T_NET_BUF *)(*buf);
			tmp->idix  = (uint8_t)ix;
			tmp->len   = minlen;
			tmp->flags = 0;
			return error;
		}
		else if(ix == 0 || cMemoryPoolStatus_getSize(ix) < len)
		  break;
		ix --;
	}

	*buf = NULL;
	return error;
	
}

/* #[<ENTRY_FUNC>]# eNetworkAlloc_dealloc
 * name:         eNetworkAlloc_dealloc
 * global_name:  tNetworkBuffer_eNetworkAlloc_dealloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eNetworkAlloc_dealloc(const void* buf)
{

	T_NET_BUF *tmp = (T_NET_BUF *)buf;
	ER error;
	
	/* ネットワークバッファの ID の正当性を検証する。*/
	if ((int_t)tmp->idix >= (int_t)N_CP_cFixedSizeMemoryPool) {
		syslog(LOG_EMERG, "[NET BUF] E_ID, ID=%d.", tmp->idix);
		error = E_ID;
		}
	else {

		error = cFixedSizeMemoryPool_release(tmp->idix,buf);

	}
	   
	return error;
	
}

/* #[<ENTRY_FUNC>]# eNetworkAlloc_reuse
 * name:         eNetworkAlloc_reuse
 * global_name:  tNetworkBuffer_eNetworkAlloc_reuse
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eNetworkAlloc_reuse(void* buf)
{
	ER error;
	T_NET_BUF* tmp = (T_NET_BUF *)buf;

	/* ネットワークバッファの ID の正当性を検証する。*/
	if (tmp->idix >= (int_t)N_CP_cFixedSizeMemoryPool) {
		syslog(LOG_EMERG, "[NET BUF] E_ID, ID=%d.", tmp->idix);
		error = E_ID;
	}
	else {
		tmp->len   = cMemoryPoolStatus_getSize(tmp->idix);
		tmp->flags = 0;
		error = E_OK;
	}

	return error;
}

/* #[<ENTRY_FUNC>]# eNetworkAlloc_bufferSize
 * name:         eNetworkAlloc_bufferSize
 * global_name:  tNetworkBuffer_eNetworkAlloc_bufferSize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eNetworkAlloc_bufferSize(const void* buf)
{
	T_NET_BUF* tmp = (T_NET_BUF *)buf;

	if(tmp->idix >= N_CP_cFixedSizeMemoryPool)
	  return E_ID;
	return (ER_UINT)cMemoryPoolStatus_getSize(tmp->idix);

}

/* #[<ENTRY_FUNC>]# eNetworkAlloc_bufferMaxSize
 * name:         eNetworkAlloc_bufferMaxSize
 * global_name:  tNetworkBuffer_eNetworkAlloc_bufferMaxSize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint32_t
eNetworkAlloc_bufferMaxSize()
{
	return cMemoryPoolStatus_getSize(0);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
