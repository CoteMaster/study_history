"""
2309 백설공주와 일곱 난장이

9명 중에 7명의 합이 100인 경우를 출력
"""

from itertools import combinations
import sys
read = sys.stdin.readline

group = [int(input()) for _ in range(9)]
for now_group in combinations(group, 7):
    if sum(now_group) == 100:
        print("\n".join(map(str, sorted(now_group))))
        exit()
