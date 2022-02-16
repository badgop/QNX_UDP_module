//============================================================================
// Name        : lazikovs_finest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <iostream>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
//------------------------------------------
#include "UdpSocket.h"
#include "udp.h"
#include "vRtApi.h"
#include "tests.h"

using namespace std;





int main() {


	// ip адрес по октетам и порты ЭТОГО ПК
	uint8_t ip_a = 10;
	uint8_t ip_b= 1;
	uint8_t ip_c =1;
	uint8_t ip_d =44;

	uint16_t port1= 8007;



	// ip адрес по октетам и порты удаленного ПК
	// настроить руками !!!!!
	uint8_t ip_atr = 10;
	uint8_t ip_btr= 1;
	uint8_t ip_ctr =1;
	uint8_t ip_dtr =136;
	uint16_t port2= 8800;



//	   testCreateAndReciev(ip_a,ip_b,ip_c,ip_d,port1);
//	   testCreateAndSend( ip_a, ip_b, ip_c, ip_d, port1,
//			   ip_atr, ip_btr, ip_ctr, ip_dtr, port2);

	uint64_t sec = 0;
	uint64_t nsec = 500*1000*1000;
	testTimer( sec,  nsec);


	return 0;
}
