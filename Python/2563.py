## 색종이
import sys
input = sys.stdin.readline

t = int(input())
arr = [[0 for _ in range(100)] for _ in range(100)]
for _ in range(t):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            arr[i][j] = 1
    
ans = 0
for i in range(100):
    for j in range(100):
        if arr[i][j] == 1:
            ans += 1
print(ans)