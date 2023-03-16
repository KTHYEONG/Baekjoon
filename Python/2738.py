## 행렬 덧셈
import sys

n, m = map(int, sys.stdin.readline().split())

arr1 = [0 for _ in range(n)]
for i in range(n):
    arr1[i] = list(map(int, sys.stdin.readline().split()))

arr2 = [0 for _ in range(n)]
for i in range(n):
    arr2[i] = list(map(int, sys.stdin.readline().split()))

for i in range(n):
    for j in range(m):
        print(f"{arr1[i][j] + arr2[i][j]} ", end = '')
    print()