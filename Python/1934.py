## 최소공배수
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    gcd = 1
    for i in range(min(a, b), 1, -1):
        if (a % i == 0) and (b % i == 0):
            gcd = i
            break
    print(int(a * b / gcd))