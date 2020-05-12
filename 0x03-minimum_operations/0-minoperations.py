#!/usr/bin/python3
"""
Minimum operations
"""


def minOperations(n):
    result = 0
    i = 2

    while (i <= n):
        if n % i == 0:
            result = result + i
            n = n / i
        else:
            i += 1

    return result
