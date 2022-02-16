/*
 * socket_params.cpp
 *
 *  Created on: 06.09.2021
 *      Author: tatarchuk
 */

#include <stdint.h>
#include "socket_params.h"


// пакуем октеты из ipAddres в uint32_t
uint32_t ippack(const ipAddres  &ip)
{
	uint32_t ret;
	ret = 0;
	const uint32_t mask = 0xff;
	uint8_t shift = 0;

	ret  = bit_field_pack_u32(ret,(uint32_t) ip.a,(uint8_t) 24 , mask);
	ret  = bit_field_pack_u32(ret,(uint32_t) ip.b,(uint8_t) 16 , mask);
	ret  = bit_field_pack_u32(ret,(uint32_t) ip.c,(uint8_t) 8 , mask);
	ret  = bit_field_pack_u32(ret,(uint32_t) ip.d,(uint8_t) 0 , mask);
	return ret;
}

void ipUnpack(const uint32_t ip, ipAddres &ipAddrStruct)
{
	const uint32_t mask = 0xff;
	ipAddrStruct.a = (ip&(mask<<24))>>24;
	ipAddrStruct.b = (ip&(mask<<16))>>16;
	ipAddrStruct.c = (ip&(mask<<8))>>8;
	ipAddrStruct.d = (ip&(mask<<0))>>0;
}
