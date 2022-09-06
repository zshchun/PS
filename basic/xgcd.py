#!/usr/bin/python3
#-*- coding: utf-8 -*-
import sys

def xgcd(a, b):
    s1 = 1
    s2 = 0
    t1 = 0
    t2 = 1
    r1 = a
    r2 = b
    while r2:
        q = r1 // r2
        r = r1 - q*r2
        r1 = r2
        r2 = r
        s = s1 - q*s2
        s1 = s2
        s2 = s
        t = t1 - q*t2
        t1 = t2
        t2 = t
    t1 = t1+a if t1 < 0 else t1
    return r1, s1, t1

x, y = map(int, input().split())
print(xgcd(x, y))
