"""
5585 거스름돈

내야하는 돈이 주어졌을때
가장 적게 거스름돈을 돌려주는 동전개수는?

알고리즘: 그리디 알고리즘

1. 500엔짜리 하나 빼고
2. 100엔짜리 몇개 빼고
3. 50엔짜리 하나 빼고
4. 10엔짜리로 몇개 빼고
5. 5엔짜리 하나 빼고
6. 1엔짜리로 다 뺀다.
"""

import sys
read = sys.stdin.readline

change = 1000 - int(read())
count = 0

for i in range(2, -1, -1):
    unit = 10**i
    if change >= 5*unit:
        count += 1
        change -= 5*unit

    if change >= unit:
        count += change // unit
        change %= unit

print(count)
