#!/usr/bin/python3
#-*- coding: utf-8 -*-

n = int(input().strip())
s = input().strip()
q = 31
h = 0
h2 = 0
x=0
for i in s:
    h = h + ((q**x) * (ord(i)-ord('a')+1)) % 1234567891
    x+= 1
#    q *= 31

print(h)
q2 = 1
for i in s:
    h2 += q2 * (ord(i)-ord('a')+1) % 1234567891
    q2 = q2 * 31 % 1234567891

print(h2)


