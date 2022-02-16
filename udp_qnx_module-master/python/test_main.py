# -*- coding: utf-8 -*-
"""
Created on Wed Aug 25 21:29:56 2021

@author: Mouse
"""

import udp_class
import message_class 
import struct
import errors



#  ВНИМАНИЕ!!!!!!
# Название функций соотвествуют функциями из tests.cpp



def testCreateAndReciev(ip, port,ip_qnx,port_qnx, size, payload):
    
    """
    
   Посылаем пакет на ЭВМ с QNX
    
    size : int - размер принимаемого сообщения
    payload : int - полезная нагрузка передаваемого сообщения, в виде числа 
    (исключательно в целях примера)
    
    """
    #  создаеем нагрузку
    payload = struct.pack('i', payload)      
    # формируем передаваемое сообщение
    mes = message_class.message_data(payload,size,ip_qnx,port_qnx) 
    # создаем совет для работы сервера, в  НЕБЛОКИРУЮЩЕМ режиме,
    # с временем ожидания 0.5 c
    first_sock  = udp_class.udp_socket(ip, port, True, False,0.5) 
    
    # посылаем сообщение
    first_sock.send_message(mes)
    
   
    first_sock.close()
    


def testCreateAndSend(ip, port,ip_qnx,port_qnx, size, payload):
    
    """
    
    создаем блокирубющий сокет и ждем пакет от QNX
    
    """

    first_sock  = udp_class.udp_socket(ip, port, True, True,10) 
    
    # принимаем
    mes = first_sock.rec_message(1024)
    
    print(mes.payload)
    first_sock.close()    

    


if __name__ == '__main__':
    
    
    
    ip_qnx = '10.1.1.44'
    port_qnx = 8007
    
    ip = '10.1.1.136'
    port = 8800
    size = 1024
    payload = 65536
    
    print ('test   test_point_to_point(ip, port, size, payload)\n')
    # testCreateAndReciev(ip, port,ip_qnx,port_qnx, size, payload)\
    testCreateAndSend(ip, port,ip_qnx,port_qnx, size, payload)
 
