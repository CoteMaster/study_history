"""
11399 ATM

사람마다 걸리는 시간이 다르다.
기다리는 시간 포함 가장 적게 걸리는 경우에서의 총 기다리는 시간을 구하라.

알고리즘: 그리디 알고리즘

1. 솔팅
2. 누적 합계?
"""

import sys
read = sys.stdin.readline

n = int(read())
times = list(sorted(map(int, read().split())))
result = 0
for i, t in enumerate(times):
    result += sum(times[:i+1])
print(result)
