## 팰린드롬인지 확인하기
"""import sys

input_str = sys.stdin.readline()

flag = 0
str_len = len(input_str) - 1
for i in range(str_len // 2):
    if input_str[i] != input_str[str_len - i - 1]:
        flag = 1
        break

if flag == 1:
    print(0)
else:
    print(1)"""

"""import sys

input_str = sys.stdin.readline().rstrip()

if input_str == input_str[::-1]:
    print(1)
else:
    print(0)"""

import sys

input_str = sys.stdin.readline().rstrip()

reverse_str = ''.join(reversed(input_str))
if input_str == reverse_str:
    print(1)
else:
    print(0)