#!/usr/bin/python3
""" Calculate rain
"""


def rain(walls):
    """ Given a list of non-negative integers representing walls of width 1,
        calculate how much water will be retained after it rains
    """
    rain = 0
    length = len(walls)

    if length and walls:
        for i in range(1, length - 1):
            left = walls[i]
            for j in range(i):
                left = max(left, walls[j])
            right = walls[i]
            for j in range(i + 1, length):
                right = max(right, walls[j])
            rain += min(left, right) - walls[i]
    return rain
