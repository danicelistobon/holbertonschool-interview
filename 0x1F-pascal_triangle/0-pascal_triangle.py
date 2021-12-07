#!/usr/bin/python3
""" Pascal's Triangle
"""


def pascal_triangle(n):
    """ returns a list of lists of ints representing the Pascal’s triangle of n
    """
    a = []
    if n <= 0:
        return a
    for i in range(n):
        b = [1]
        if a:
            for j in range(i):
                b.append(sum(a[-1][j:j+2]))
        a.append(b)
    return a
