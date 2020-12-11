#!/usr/bin/python3
"""Module to determine if all the boxes can be opened
    Args:
        boxes: is a list of lists
"""


def canUnlockAll(boxes):
    """Function that determines if all the boxes can be opened
        Return: True if all boxes can be opened, else return False
    """
    keys = [0]
    length = len(boxes)
    for box in keys:
        for key in boxes[box]:
            if key not in keys and key < length:
                keys.append(key)
    if length == len(keys):
        return True
    else:
        return False
