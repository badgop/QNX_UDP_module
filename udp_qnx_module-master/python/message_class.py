# -*- coding: utf-8 -*-
"""
Created on Wed Aug 25 14:31:54 2021

@author: tatarchuk
"""

class message_data():
    
    def __init__(self, payload,size , ip, port):
        
        self.payload       = payload
        self.payload_size  = size
        self.ip            = ip
        self.port          = port
        
        
    