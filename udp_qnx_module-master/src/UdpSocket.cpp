/*
 * UdpSocket.cpp
 *
 *  Created on: 05.09.2021
 *      Author: Mouse
 */

#include "UdpSocket.h"

UdpSocket::UdpSocket(uint32_t ipAddr,const uint16_t &port,const bool isBlocking)
{

	// ipAddr  - адрес в формате "xxx.xxx.xxx.xxx" где xxx  литералы
	// port - порт для сокета
	// isBlocking - блокирующий
	// isServer - является ли севером (будет ли привязан(bind) адрес)

	bindedPort = port;
	bindedIp = ipAddr;


	errorOpenSocket = false;

	// Создаем сокет для работы с потоком данных
	sockHandler  = socket(AF_INET , SOCK_DGRAM, IPPROTO_UDP);
	if (sockHandler == -1)
	{
		errorOpenSocket = true;
	}

	errorIoctl = false;

	nonBlocking = (isBlocking)?0:1;
	if (ioctl(sockHandler, FIONBIO, (unsigned long *)&nonBlocking) == -1 )
	{
		// При ошибке закрываем сокет
		close(sockHandler);
		errorIoctl = true;

	}

	false;
	sockaddr_in	addr;
	// Устанавливаем адрес IP и номер порта
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET ;
	addr.sin_port = htons(bindedPort);
	addr.sin_addr.s_addr =htonl( ipAddr);
	// Связываем адрес IP с сокетом
	errorBind = false;
	if (bind (sockHandler, (sockaddr *)&addr, sizeof(addr)) == -1 )
	{
		// При ошибке закрываем сокет
		errorBind = true;
		close(sockHandler);

	}



}
// wIpAddr - старшим вперед
// wPort - аналогично
// timeStamp - время приема сообщения
uint32_t UdpSocket::recvFrom(char *wBuffer, const uint32_t &wBufSize, uint32_t &wIpAddr, uint16_t &wPort, timespec &timeStamp)
{

	  sockaddr_in addr;
	  socklen_t addrSize;
	  int ctrl;

//	  // Задаем структуру адреса
	  memset(&addr, 0, sizeof(addr));
	  addrSize = sizeof(addr);

	  // Принимаем данные
	  ctrl = recvfrom(sockHandler, wBuffer, wBufSize, 0, (sockaddr *)&addr, &addrSize);

	  // получаем время прихода сообщения
	  if( clock_gettime( CLOCK_REALTIME, &timeStamp) == -1 )
	  {
	 	      perror( "clock gettime" );
	 	      return EXIT_FAILURE;
	 	 }


	  if (ctrl > 0){
		  udpRecvSize += ctrl;
		  ++udpRecvCount;
	  }

	  // Обработка ошибки приёма
	  if (ctrl != -1)
	  {
//
//		  // Возвращаем IP-адрес отправителя
//		  strcpy(wIpAddr, inet_ntoa(addr.sin_addr));
//
//		  // Возвращаем порт отправителя
//		  *wPort = ntohs(addr.sin_port);
		  wPort = ntohs(addr.sin_port);
		  wIpAddr = htonl (addr.sin_addr.s_addr);

	  }

		// Возвращаем кол-во принятых байт
		return ctrl;

}

uint32_t  UdpSocket::sendTo(char *wBuffer, const uint32_t &wBufSize, uint32_t &wIpAddr, uint16_t &wPort)
{
	  sockaddr_in	addr;

	  memset(&addr, 0, sizeof(addr));
	  addr.sin_family      = AF_INET;
	  addr.sin_port = htons(wPort);
	  addr.sin_addr.s_addr =htonl( wIpAddr);

	  // Посылаем сообщение
	  int ctrl = sendto(		sockHandler, wBuffer, wBufSize, 0, (sockaddr *)&addr, sizeof(addr));
	  if (ctrl > 0){
		  udpSendSize += ctrl;
		  ++udpSendCount;
	  }
	  return ctrl;

}

void UdpSocket::setStatZero()
{
	udpSendCount = 0;
	udpSendSize= 0;
	udpRecvCount=0;
	udpRecvSize = 0;
}

UdpSocket::~UdpSocket()
{
	close(sockHandler);

}
