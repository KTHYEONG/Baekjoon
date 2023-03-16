## 가로수
import sys
input = sys.stdin.readline

def gcd(a, b):
    while b > 0:
        a, b = b, a % b

    return a

n = int(input())

temp = int(input())

arr = []
for _ in range(n - 1):
    num = int(input())
    arr.append(num - temp)
    temp = num

g = arr[0]
for i in range(1, len(arr)):
    g = gcd(g, arr[i])

ans = 0
for num in arr:
    ans += num // g - 1
print(ans)