## 소수
import sys
input = sys.stdin.readline

m = int(input())
n = int(input())

arr = []
for i in range(m, n + 1):
    flag = 0
    for j in range(2, i):
        if i % j == 0:
            flag = 1
            break
    
    if flag == 0 and i != 1:
        arr.append(i)

if len(arr) > 0:
    print(f"{sum(arr)}\n{arr[0]}")
else:
    print(-1)