#ifndef _TECS_IF_MBED_H_
#define _TECS_IF_MBED_H_

/*
 *  ネットワークインタフェースに依存するソフトウェア情報 
 */
typedef struct t_mbed_softc {
	bool_t link_pre;
	bool_t link_now;
	bool_t over_flow;
} T_MBED_SOFTC;

#endif /* _TECS_IF_MBED_H_ */
