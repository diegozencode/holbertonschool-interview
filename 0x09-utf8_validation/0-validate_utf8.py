#!/usr/bin/python3
"""
Validates data set representing UTF-8 encoding
"""


import re


def validUTF8(data):
    """validation
    """
    dec = 0
    for num in data:
        binary = bin(num)
        binary_part = re.split("0b", binary)
        binary_complete = binary_part[1].rjust(8, '0')
        if dec != 0:
            dec -= 1
            if not binary_complete.startswith('10'):
                return(False)
        elif binary_complete[0] == '1':
            dec = len(binary_complete.split('0')[0]) - 1
    return(True)
