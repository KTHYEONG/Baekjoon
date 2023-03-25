## 알고리즘 수업 - 알고리즘의 수행 시간 4
import sys
input = sys.stdin.readline

n = int(input())
arr = [i for i in range(1, n)]
print(sum(arr), 2, sep = '\n')