## 소수 찾기
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

ans = 0
for num in arr:
    flag = False
    if num == 1:
        continue
    for i in range(2, num):
        if num % i == 0:
            flag = True
            break

    if flag == False:
        ans += 1
        
print(ans)