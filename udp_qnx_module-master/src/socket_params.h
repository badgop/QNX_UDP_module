/*
 * socket_params.h
 *
 *  Created on: 06.09.2021
 *      Author: tatarchuk
 */

#include <stdint.h>
#include "bit_field_pack.h"

#ifndef SOCKET_PARAMS_H_
#define SOCKET_PARAMS_H_

// структура для хранения ip адреса по октетам
struct ipAddres
	{
		uint32_t a; // [31-24]
		uint32_t b; // [23-16]
		uint32_t c; // [15-8]
		uint32_t d; // [7-0]
	};



struct socket_params
{
	uint16_t buff_size;
	ipAddres ipOctets;
	uint32_t ip_addr;
	uint16_t port ;
	bool isBlocking;
};


uint32_t ippack(const ipAddres &ip);
void ipUnpack(const uint32_t ip, ipAddres &ipAddrStruct);

#endif /* SOCKET_PARAMS_H_ */
