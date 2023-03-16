## 분수 합
import sys
input = sys.stdin.readline

def gcd(a, b):
    while b > 0:
        a, b = b, a % b

    return a

a, b = map(int, input().split())
c, d = map(int, input().split())

g = gcd(b, d)

## 분모(b 와 d의 최소공배수)
denominator = b * d // g

## 분자
numerator = a * (d // g) + c * (b // g)

## 기약 분수로 만든 후 출력(분자와 분모의 최대공약수를 각각 나눠줌)
temp = gcd(denominator, numerator)
print(numerator // temp, denominator // temp)