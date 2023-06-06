#!/usr/bin/python3
def dfs(n, s):
    global ans
    if n == 0:
        if s % 15 == 0:
            return 1
        return 0;
    x1 = s * 10 + 1
    x2 = s * 10 + 5

    return dfs(n-1, x1) + dfs(n-1, x2)

for i in range(10):
    print(i, dfs(i, 0))
