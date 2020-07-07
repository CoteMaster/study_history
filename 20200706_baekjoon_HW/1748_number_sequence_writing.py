"""
1748 수 이어 쓰기

1부터 N까지 수를 이어쓰면 몇자리 수 일까?

알고리즘: 완전탐색

120 -> 1-9 9
    -> 10-99 90*2
    -> 100-120 21*3
    -> 9 + 180 + 63 = 252
"""

import sys
read = sys.stdin.readline

n = int(read())
s = list(str(n))[::-1]
result = 0
for i, c in enumerate(s[:-1]):
    result += 9 * 10**i * (i+1)
result += (n - 10**(len(s)-1) + 1) * len(s)
print(result)
