## 공 넣기
import sys

n, m = map(int, sys.stdin.readline().split())

arr = [0 for _ in range(n + 1)]
for _ in range(m):
    start, end, num = map(int, sys.stdin.readline().split())
    for j in range(start, end + 1):
        arr[j] = num

for i in range(1, n + 1):
    print(arr[i])