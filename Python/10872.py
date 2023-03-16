## 팩토리얼
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)

import sys
input = sys.stdin.readline

n = int(input())
if n == 0:
    print(1)
else:
    print(factorial(n))