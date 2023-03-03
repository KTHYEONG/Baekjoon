## 최댓값
"""import sys

arr = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]

ans = -1
x, y = 0, 0
for i in range(9):
    for j in range(9):
        if arr[i][j] > ans:
            ans = arr[i][j]
            x, y = i + 1, j + 1
print(ans)
print(x, y)"""

import sys

input = sys.stdin.readline

arr = []
for _ in range(9):
    arr += list(map(int, input().split()))

idx = arr.index(max(arr))
print(max(arr))
print(idx // 9 + 1, idx % 9 + 1)