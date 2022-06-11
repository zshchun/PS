#!/usr/bin/python3
#-*- coding: utf-8 -*-

import time
import random
import subprocess
s = time.time()
ii = "1\n{}\n".format(1)
for i in range(1000000):
    ii += "I " + str(i) + "\n"

out = subprocess.check_output(['./a.out'], input=ii.encode())
print(out)
print(time.time()-s)
