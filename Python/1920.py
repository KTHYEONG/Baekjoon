## 수 찾기
import sys
input = sys.stdin.readline

def binary_search(arr, find_num, left, right):
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == find_num:
            return True
        elif arr[mid] > find_num:
            right = mid - 1
        else:
            left = mid + 1
    
    return False

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

m = int(input())
find = list(map(int, input().split()))

for i in find:
    if binary_search(arr, i, 0, n - 1) == True:
        print(1)
    else:
        print(0)


"""
순차탐색 --> 시간초과
def check(arr, find_num):
    for i in arr:
        if i == find_num:
            return True
        
    return False
"""