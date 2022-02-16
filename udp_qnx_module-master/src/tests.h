/*
 * tests.h
 *
 *  Created on: 08.09.2021
 *      Author: tatarchuk
 */

#ifndef TESTS_H_
#define TESTS_H_


#include <cstdlib>
#include <iostream>
#include <sys/neutrino.h>
#include <math.h>
#include <sys/syspage.h>
#include "socket_params.h"
#include "UdpSocket.h"
#include "times_wrapper.h"


void testCreateAndReciev(uint8_t ip_a,uint8_t ip_b,uint8_t ip_c,uint8_t ip_d,uint16_t port);
void testCreateAndSend(uint8_t ip_a,uint8_t ip_b,uint8_t ip_c,uint8_t ip_d,uint16_t port, uint8_t ip_atr,uint8_t ip_btr,uint8_t ip_ctr,uint8_t ip_dtr,uint16_t porttr);
void testTimer(uint64_t sec, uint64_t nsec);
#endif /* TESTS_H_ */
