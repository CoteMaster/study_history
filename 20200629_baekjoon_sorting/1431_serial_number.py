"""
1431 시리얼 번호

시리얼 번호를 기준에 따라 정렬한다.
1. 길이가 짧은순으로
2. 시리얼 번호의 숫자들의 합이 작은순으로
3. 사전순으로

알고리즘: 정렬

1. 길이별로 딕셔너리에 담기
2. 자리합으로 솔팅
"""

import sys
read = sys.stdin.readline

n = int(read())
serials = [read().strip() for _ in range(n)]


def f(s):
    result = 0
    for c in s:
        if c.isdigit():
            result += int(c)
    return result


serials.sort(key=lambda x: (len(x), f(x), x))
print("\n".join(serials))
