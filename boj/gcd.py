#!/usr/bin/python3
#-*- coding: utf-8 -*-
import sys

def gcd(a, b):
    while b:
        r = a % b
        a = b
        b = r
    return a

x, y = map(int, input().split())
print(gcd(x, y))
