/*
 * UdpSocket.h
 *
 *  Created on: 05.09.2021
 *      Author: Tatarchuck
 */
#include <iostream>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>




#ifndef UDPSOCKET_H_
#define UDPSOCKET_H_

/*
 * Класс для работы с сокетами
 */
class UdpSocket {
public:
	UdpSocket(uint32_t ipAddr,const uint16_t &port,const bool isBlocking);
	uint32_t recvFrom(char *wBuffer, const uint32_t &wBufSize, uint32_t &wIpAddr, uint16_t &wPort, timespec &timeStamp);
	uint32_t sendTo(char *wBuffer, const uint32_t &wBufSize, uint32_t &wIpAddr, uint16_t &wPort);
	void setStatZero();
	virtual ~UdpSocket();
private:
	// параметры сокета
	uint16_t sockHandler;
	uint32_t bindedIp;
	uint16_t bindedPort;
	unsigned long nonBlocking ; // 0 - блокирующий режим, 1 - блокирующий
	//для обработки ошибок
	bool errorOpenSocket;
	bool errorIoctl;
	bool errorBind;
	// статистика
	uint64_t udpSendCount;
	uint64_t udpSendSize;
	uint64_t udpRecvCount;  // чисдл принятых датаграмм
	uint64_t udpRecvSize; // число принятх байтов


};

#endif /* UDPSOCKET_H_ */
