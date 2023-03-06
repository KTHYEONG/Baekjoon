## 수 정렬하기
import sys
input = sys.stdin.readline

n = int(input())

arr = []
for _ in range(n):
    arr.append(int(input()))

## 내장함수 sort 이용
"""arr.sort()"""

## 버블정렬
"""for i in range(len(arr) - 1):
    for j in range(len(arr) - 1 - i):
        if (arr[j] > arr[j + 1]):
            arr[j], arr[j + 1] = arr[j + 1], arr[j]"""

## 삽입정렬
"""for end in range(1, len(arr)):
    i = end
    while (i > 0) and (arr[i - 1] > arr[i]):
        arr[i - 1], arr[i] = arr[i], arr[i - 1]
        i -= 1"""

## 선택정렬
for i in range(len(arr) - 1):
    min_idx = i
    for j in range(i + 1, len(arr)):
        if arr[min_idx] > arr[j]:
            min_idx = j
    arr[i], arr[min_idx] = arr[min_idx], arr[i]

print(*arr, sep = '\n')