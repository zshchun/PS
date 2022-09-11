#!/usr/bin/python3
#-*- coding: utf-8 -*-
import random
import numpy as np
#from scipy import stats
import subprocess

n = random.randint(1,500000)
fmt = "{}\n".format(n)
a = []
for i in range(n):
    a += [random.randint(-4000,4000)]
fmt += "\n".join([str(x) for x in a])
out = subprocess.check_output(['./a.out'], input=fmt.encode())

r = out.decode().split('\n')[:4]
r = [int(x) for x in r]

open("test1", "w").write(fmt)
a1 = sum(a) // n
print(r[0], a1)
assert r[0] == a1, "sum error"
x = np.array(a)
a2 = np.median(x) // 1
print(r[1], a2)
assert r[1] == a2, "median error"
a4 = sorted(a)
a4 = a4[n-1] - a4[0]
print(r[3], a4)
assert r[3] == a4, "range error"

arr = [0] * 8002
for i in a:
    arr[i+4000] += 1;
a3 = []
mx = max(arr)
for i in range(8002):
    if arr[i] == mx and not (i-4000) in a3:
        a3 += [(i-4000)]
print(a3)

#a3 = stats.mode(x)[0]
#print(stats.mode(x)[0], stats.mode(x)[1])
if len(a3) > 1:
    a3 = sorted(a3)[1]
else:
    a3 = a3[0]
print(r[2], a3)
assert r[2] == a3, "mode error"
#print(r)
