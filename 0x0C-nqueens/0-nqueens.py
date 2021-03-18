#!/usr/bin/python3
"""N queens
"""
import sys


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    N = sys.argv[1]

    try:
        N = int(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)


def solution(N, i=0, a=[], b=[], c=[]):
    """Solution for the problem
    """
    if i < N:
        for j in range(N):
            if j not in a and i+j not in b and i-j not in c:
                for res in solution(N, i+1, a+[j], b+[i+j], c+[i-j]):
                    yield res
    else:
        yield a

for i in solution(N):
    res = [[c, r] for c, r in enumerate(i)]
    print(res)
