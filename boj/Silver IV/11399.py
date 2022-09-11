#!/usr/bin/python3
#-*- coding: utf-8 -*-

a = [1, 2, 3, 3, 4]
a = sorted(a)
print(a)
s = 0
p = 0
for i in a:
    s = s + i
    p += s
    print(s, p)

