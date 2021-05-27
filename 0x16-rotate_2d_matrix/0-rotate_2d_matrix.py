#!/usr/bin/python3
""" Rotate 2D Matrix module
"""


def rotate_2d_matrix(matrix):
    """ Given an n x n 2D matrix, rotate it 90 degrees clockwise
    """
    n = len(matrix[0])

    for i in range(n - 1, -1, -1):
        for x in range(0, n):
            matrix[x].append(matrix[i].pop(0))
