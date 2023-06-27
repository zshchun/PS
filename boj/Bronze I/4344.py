#!/usr/bin/python3
#-*- coding: utf-8 -*-

import sys

n = int(input().encode('utf-8'))
total = 0
s = 0
lines = []
for i in range(n):
    s = 0
    total = 0
    cnt = 0
    buf = input().encode('utf-8')
    lines.append(buf)
    l = buf.split()
    total += int(l[0])
    for j in l[1:]:
        s += int(j)
    mid = s / total
    for j in l[1:]:
        if int(j) > mid:
            cnt += 1
    print("{:.3f}%".format(cnt / int(l[0]) * 100))
