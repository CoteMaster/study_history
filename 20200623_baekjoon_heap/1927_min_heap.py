"""
1927 최소 힙

최소 힙을 구현하자.
1. 배열에 자연수 x를 넣는다.
2. 배열에서 가장 작은 값 출력, 배열에서 제거

알고리즘: 힙
"""
import heapq
import sys
read = sys.stdin.readline

n = int(read())
hq = []
for _ in range(n):
    x = int(read())
    if x > 0:
        heapq.heappush(hq, x)
    else:
        if len(hq):
            print(heapq.heappop(hq))
        else:
            print(0)
