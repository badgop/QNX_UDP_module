# -*- coding: utf-8 -*-
"""
Created on Mon Aug 30 11:52:53 2021

@author: tatarchuk
"""

import struct

fl = float (415646465.0)

s = struct.pack('f', fl)

ba = bytearray(struct.pack("f", fl))  
print (str(s))
print([ "0x%02x" % b for b in ba ])