"""
11652 카드

카드 N장중에 가장 많이 가지고 있는 정수를 구하라.

알고리즘: 정렬
"""

from collections import Counter
import sys
read = sys.stdin.readline

n = int(read())
numbers = [int(read()) for _ in range(n)]
counter = Counter(numbers)

result = counter.most_common()
max_num, max_cnt = result[0]
result2 = [max_num]
for num, cnt in result[1:]:
    if max_cnt == cnt:
        result2.append(num)
    else:
        break
print(min(result2))
