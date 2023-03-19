## 제로
import sys
input = sys.stdin.readline

k = int(input())

stack = []
for _ in range(k):
    num = int(input())
    if num == 0 and len(stack) != 0:
        stack.pop()
    else:
        stack.append(num)

if len(stack) == 0:
    print(0)
else:
    print(sum(stack))