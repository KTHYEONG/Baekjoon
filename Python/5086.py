## 배수와 약수
import sys
input = sys.stdin.readline

a, b = 1, 1
while 1:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    
    if a > b and a % b == 0:
        print("multiple")
    elif b > a and b % a == 0:
        print("factor")
    else:
        print("neither")