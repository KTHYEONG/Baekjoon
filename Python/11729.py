## 하노이 탑 이동 순서
import sys
input = sys.stdin.readline

def hanoi(start, temp, end, n):
    if n == 1:
        print(f"{start} {end}")
    else:
        ## 맨 밑의 원판을 제외한 나머지 원판을 임시 기둥 temp로 이동
        hanoi(start, end, temp, n - 1)
        ## 남은 맨 맽의 원판 하나를 목적지 기둥 end로 이동
        hanoi(start, temp, end, 1)
        ## temp에 옮겨두었던 n - 1개의 기둥을 end로 이동
        hanoi(temp, start, end, n - 1)

n = int(input())
print(2 ** n - 1)
hanoi(1, 2, 3, n)