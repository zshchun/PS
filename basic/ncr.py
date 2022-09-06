#!/usr/bin/python3
#-*- coding: utf-8 -*-
import sys

D = [[0 for x in range(1000)] for x in range(1000)]
def ncr(n, r):
    if n == r or r == 0:
        return 1;
    if D[n][r] == 0:
        D[n][r] = ncr(n-1, r-1) + ncr(n-1, r)
    return D[n][r]


if len(sys.argv) < 2:
    print("ncr <n> <r>")
    sys.exit()
n = int(sys.argv[1])
r = int(sys.argv[2])
print(ncr(n, r))
