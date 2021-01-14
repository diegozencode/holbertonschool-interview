#!/usr/bin/python3
"""
Minimum operations
"""


def minOperations(n):
    """ Calculates the fewest number of operations needed
    """
    result = 0
    op = 2

    while (op <= n):
        if n % op == 0:
            result = result + op
            n = n / op
        else:
            op += 1

    return result
