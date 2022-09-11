#!/usr/bin/python3
#-*- coding: utf-8 -*-
from random import randint

cnt = 0
line = 500
print(line)
for i in range(1, line+1):
    for j in range(i):
        print("{} ".format(randint(0, 9999)), end='')
        cnt += 1
    print("")
print(cnt)
