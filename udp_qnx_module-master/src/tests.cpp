/*
 * tests.cpp
 *
 *  Created on: 08.09.2021
 *      Author: tatarchuk
 */

#include "tests.h"
#include <cstdlib>
#include <iostream>
#include <sys/neutrino.h>
#include "time_aaux.h"


//создаем сокет в блокирующем режиме и принимаем одно сообщение от другого ПК
// необходимо послать сообщение с другого ПК руками путем запуска программы на питоне -
// тогда покажут ip и порт отправителя
void testCreateAndReciev(uint8_t ip_a,uint8_t ip_b,uint8_t ip_c,uint8_t ip_d,uint16_t port)
{
	    using namespace std;
		uint32_t     recIp=0;
		uint16_t     recPort=0;
		uint32_t    rez =0;

		// параметры сокета этого ПК
		socket_params parametersLocal;
		// параметры сокета удаленного ПК
		socket_params parametersRemote;

		char			sendBuffer[512];
		struct timespec timeStamp;

		// настройка сокета на этом ПК
		parametersLocal.buff_size = 512;
		// ip адрес начиная со старшеего октета
		parametersLocal.ipOctets.a = ip_a;
		parametersLocal.ipOctets.b = ip_b;
		parametersLocal.ipOctets.c = ip_c;
		parametersLocal.ipOctets.d = ip_d;
		parametersLocal.ip_addr = (ippack(parametersLocal.ipOctets)); // сборка ip адреса в прямом порядке
		parametersLocal.port = port;
		parametersLocal.isBlocking = true;

	//	remoteSocket = Udp::createSocket(remoteIp, remotePort, 1);
	//	rez = Udp::recvFrom(remoteSocket, recvBuffer, sizeof(recvBuffer), recvIp, &recvPort);


		// создание объекта типа сокет
		UdpSocket socket1(parametersLocal.ip_addr,parametersLocal.port,parametersLocal.isBlocking);
		cout << "waiting" << endl; //
		// прием данных
		// сокет будет в блокирующем режиме и будет ждать прихода udp сообщение по порту 8007
		rez = socket1.recvFrom(sendBuffer,512,recIp,recPort,timeStamp);
		// распаковка ip отправителя
	    ipUnpack(recIp, parametersRemote.ipOctets);
		cout << parametersRemote.ipOctets.a <<"." <<parametersRemote.ipOctets.b <<"." <<parametersRemote.ipOctets.c<<"." <<parametersRemote.ipOctets.d<< endl; // prints !!!Hello World!!!
		cout << recPort << endl; //
//		cout << "time in sec" << endl;
		cout << timeStamp.tv_sec << " time in sec" << endl;
		cout << timeStamp.tv_nsec <<" part of sec in nan secs"<< endl;

		cout << "!!Done" << endl; //

}

//создаем сокет в неблокирующем режиме и
// посылаем сообщение на жругой ПК. Адрес и порт назначения - переменные с суффиксом tr
void testCreateAndSend(uint8_t ip_a,uint8_t ip_b,uint8_t ip_c,uint8_t ip_d,uint16_t port, uint8_t ip_atr,uint8_t ip_btr,uint8_t ip_ctr,uint8_t ip_dtr,uint16_t porttr)
{

	 using namespace std;
			uint32_t     recIp=0;
			uint16_t     recPort=0;
			uint32_t    rez =0;

			// параметры сокета этого ПК
			socket_params parametersLocal;
			// параметры сокета удаленного ПК
			socket_params parametersRemote;

			char			sendBuffer[128];
			struct timespec timeStamp;


			// настройка сокета на этом ПК
			parametersLocal.buff_size = 512;
			// ip адрес начиная со старшеего октета
			parametersLocal.ipOctets.a = ip_a;
			parametersLocal.ipOctets.b = ip_b;
			parametersLocal.ipOctets.c = ip_c;
			parametersLocal.ipOctets.d = ip_d;
			parametersLocal.ip_addr = (ippack(parametersLocal.ipOctets)); // сборка ip адреса в прямом порядке
			parametersLocal.port = port;
			parametersLocal.isBlocking = true;


            // настройка параметров отправителя
			// ip адрес начиная со старшеего октета
			parametersRemote.ipOctets.a = ip_atr;
			parametersRemote.ipOctets.b = ip_btr;
			parametersRemote.ipOctets.c = ip_ctr;
			parametersRemote.ipOctets.d = ip_dtr;
			parametersRemote.ip_addr = (ippack(parametersRemote.ipOctets)); // сборка ip адреса в прямом порядке
			parametersRemote.port = porttr;

			// создание объекта типа сокет
			UdpSocket socket1(parametersLocal.ip_addr,parametersLocal.port,parametersLocal.isBlocking);

            // забиваем пакет нулями, просто что бы было
			memset(&sendBuffer, 0x00, sizeof(sendBuffer));

             // посылаем пакет
			rez = socket1.sendTo(sendBuffer,sizeof(sendBuffer),parametersRemote.ip_addr, parametersRemote.port);

}

void testTimer(uint64_t sec, uint64_t nsec)
{
	 using namespace std;
	int32_t flag = 0;
	int32_t notifyType = SIGEV_PULSE;
	int32_t priorityType = 0;
	char  sigevCodein1 = 35;
	char  sigevCodein2 = 33;
	uint32_t rez;

	struct timespec start, stop;
	memset(&start,0,sizeof(start));
	memset(&stop,0,sizeof(stop));

	struct timespec res;

	    if ( clock_getres( CLOCK_REALTIME, &res) == -1 ) {
	      perror( "clock get resolution" );

	    }
	    printf( "Resolution is %ld micro seconds.\n",
	          res.tv_nsec / 1000 );



	Timer  Timer1( flag, notifyType, priorityType,   sigevCodein1);
	Timer  Timer2( flag, notifyType, priorityType,   sigevCodein2);
//	cout<< Timer1.timerChid<<endl;
//	cout<< Timer1.errorCreate<<endl;
   // надо ставить время до начала работы НЕ НУЛЕВОЕ, хотя бы 1 нс
	rez =Timer1.start(0,1,sec,nsec);






	// Lazikov
		uint32_t i=0;
	while(i<10)
	{   cout<<"go"<<endl;

		if (Timer1.checkTime()==0)

			{

			    clock_gettime( CLOCK_REALTIME, &start);
				cout<<"timer1     "<<endl;

//				cout<< start.tv_sec<<endl;
//				cout<< stop.tv_sec<<endl;
//				cout<< start.tv_sec- stop.tv_sec<<endl;
//				cout<< double(stop.tv_nsec-start.tv_nsec)/double(1*1000*1000*1000)<<endl;
				cout<<"diff " << getTimeDiff(&start,&stop)<<endl;

				stop.tv_nsec = start.tv_nsec;
				stop.tv_sec  = start.tv_sec;

				i++;

			}

	}


}

