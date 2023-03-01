## 약수 구하기
import sys

n, k = map(int, sys.stdin.readline().split())

arr = []
for i in range(1, n + 1):
    if n % i == 0:
        arr.append(i)
arr.sort()

if len(arr) < k:
    print(0)
else:
    print(arr[k - 1])
