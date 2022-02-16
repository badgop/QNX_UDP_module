# -*- coding: utf-8 -*-
"""
Created on Fri Aug 27 11:03:22 2021

@author: tatarchuk
"""

class Nothing_Recieved_due_timeoout(Exception):
    """
    
    Ошибка для обработки socket.timeout при вызову udp_class.rec_message()
    
    """
    
    def __init__(self, message):
        self.message = message
        

    
 
    