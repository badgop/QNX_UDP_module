# -*- coding: utf-8 -*-
"""
Created on Wed Aug 25 11:33:09 2021

@author: tatarchuk
Was given by Komarova the Python Dealer
"""
import socket
import message_class 
import errors
import sys


"""

Класс для работы с UDP сокетами

"""
class udp_socket():
    
          
    """
  
    Класс для работы с UDP сокетами.
    Настоящий класс лишь обертка для класса socket
    после объявления объекта, следуется обращаться
    к self.socket если необходим стандартный интерфейс
    или использовать методы из класса, что бы 
    использовать расширенные возможности для отправки
    и приёма сообщений.
    
    Аргументы конструктора
    
    host       : str 
                 строка с IP адресом интерфейса сетеового НА котором можно открыть сокет
                 напр. '127.0.0.1'
    
    port       : int 
                 аналогично - порт
            
    is_server  : boolean (True = является сервером)
                 определяет является ли сокет сервеным
    is_bloking : boolean
                 определяет является ли сокет блокирующим (True - блокирующий)
    time_out   : float
                 интервал ожидания времени приёма сообщений. по истечении
                 вызывается исключение socket.timeout 
    
    констркутор создает объект класса socket
            
    """
    def __init__(self, host = None , port = None, is_server = None, is_blocking = None, time_out = None):
        
        if (host and port ) == None:
            self.sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
            
            print('UDP client created \n ')
        else:
            print ('UDP Serever created\n ')
            self.host      = host
            self.port      = port
            self.is_server = is_server
        
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)   
           
            if (self.is_server):
                try:
                    self.__open_sock()
                # если произошла какая-то ошибка - программа выводит описание
                # закрыват СОКЕТ
                # и прекращает работу
                except OSError as err:
                    print("OS error: {0}".format(err))
                    print('system exit')
                    self.sock.close()
                    sys.exit(0)                   
                
                        
        if not is_blocking:            
            self.sock.setblocking(False)            
            self.sock.settimeout(time_out)
            
  
    def __del__(self):
        self.sock.close()
        
    def __open_sock(self):
            
       """
  
       открыть сокет для приёма UDP дейтаграмм
       (адрес и порт заданы при создании обьекта)
  
       """         
       self.sock.bind((self.host,self.port))
       
    def close(self):        
        self.sock.close()

    def send_txt(self, txt, encoding, adress):    
        """
  
        отправить текст в UDP датаграмме
       
        txt   : str
        encoding  : str , например 'utf-8'
        adress    : tuple (ip,port) as socket class
  
        """                             
        self.sock.sendto(txt.encode(encoding), adress)
    
    def send_message(self, message):  
        """
  
        отправить сообщние в UDP датаграмме
        сообщение хранться в объекте типа message_class
       
        message   : message_class       
  
        """                             
        self.sock.sendto(message.payload,( message.ip, message.port))
        
    def rec_message(self, payload_size):
        
        """
  
        отправить сообщние в UDP датаграмме
        сообщение хранться в объекте типа message_class
       
        message   : message_class       
  
        """
        #  пробуем принять
        try:
            message_rx , adddres = self.sock.recvfrom(payload_size)            
        except socket.timeout as err:
            print ('socket Error ' + format(err))
            # поднимаем ошибку для внешнего обработчика
            raise errors.Nothing_Recieved_due_timeoout('timed out')
        else:
             mess = message_class.message_data(message_rx,payload_size,adddres[0],adddres[1] )
             return mess        
        

    # def recv_from_server(self, buff_size):
    #     message, addr = self.sock.recvfrom(buff_size)
    #     self.client_address = addr
    #     return message.decode('utf-8')

    # def get_client_addr(self):
    #     return self.client_address