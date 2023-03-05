## 벌집
import sys
input = sys.stdin.readline

n = int(input())

ans = 1
start = 1
while n > start:
    start += 6 * ans
    ans += 1
print(ans)