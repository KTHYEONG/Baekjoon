## 약수들의 합
import sys
input = sys.stdin.readline

n = int(input())
while n != -1:
    arr = []
    sum = 0
    for i in range(1, n):
        if n % i == 0:
            sum += i
            arr.append(i)

    if sum == n:
        print(n, "= ", end = '')
        print(*arr, sep = ' + ')
        """print(f"{n} = ", end = '')
        for i in range(len(arr) - 1):
            print(f"{arr[i]} + ", end = '')
        print(f"{arr[len(arr) - 1]}")"""
    else:
        print(f"{n} is NOT perfect.")
    
    n = int(input())