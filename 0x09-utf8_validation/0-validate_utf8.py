#!/usr/bin/python3
"""Method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """Return: True if data is a valid UTF-8 encoding, else return False
    """
    num_bytes = 0

    maskone = 1 << 7
    masktwo = 1 << 6

    for i in data:
        mask_n_byte = 1 << 7

        if num_bytes == 0:
            while mask_n_byte & i:
                num_bytes += 1
                mask_n_byte = mask_n_byte >> 1

            if num_bytes == 0:
                continue

            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            if not (i & maskone and not (i & masktwo)):
                    return False

        num_bytes -= 1

    if num_bytes == 0:
        return True

    return False
