"""
1182 부분수열의 합

n개의 정수에서 부분수열의 합이 s인 경우의 수를 구하라.

알고리즘: 완전탐색

1. 1-n개를 고르는 조합을 모두 구해서 다비교하자.
"""
from itertools import combinations
import sys
read = sys.stdin.readline

n, s = map(int, read().split())
arr = list(map(int, read().split()))

result = 0
for i in range(1, n+1):
    for subsequence in combinations(arr, i):
        if sum(subsequence) == s:
            result += 1
print(result)
