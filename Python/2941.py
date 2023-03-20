## 크로아티아 알파벳
import sys
input = sys.stdin.readline

croatia = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
n = input().rstrip()
for i in croatia:
    n = n.replace(i, 'a')

print(len(n))