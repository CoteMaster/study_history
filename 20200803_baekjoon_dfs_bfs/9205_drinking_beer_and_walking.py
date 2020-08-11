"""
9205 맥주 마시면서 걸어가기

출발점, 도착점, 그리고 편의점들이 주어진다.
50미터당 한병의 맥주를 마셔야하고 상자에는 20병의 맥주가 있다.
편의점에 들르면 20병의 맥주를 충전할 수 있다.
맥주가 끊이지 않고 도착할 수 있을까?

알고리즘: dfs or bfs

1. 현재 지점에서 도착점에 바로 갈 수 있는지 체크
    1. 가능하면 끝
    2. 불가능하면
        1. 현재 위치에서 갈 수 있는 편의점을 모두 체크
        2. 그 위치로 하나씩 이동해서 전부 체크
"""

import sys
read = sys.stdin.readline


def bfs(x, y):
    q = [(x, y)]
    visit = {(x, y)}
    while q:
        nxt_q = []
        for x, y in q:
            
            if abs(x-ex)+abs(y-ey) <= 1000:
                return "happy"

            for nx, ny in convenience_stores:
                if abs(x-nx)+abs(y-ny) <= 1000 and (nx, ny) not in visit:
                    nxt_q.append((nx, ny))
                    visit.add((nx, ny))
        q = nxt_q
    return "sad"


for _ in range(int(read())):
    n = int(read())
    sx, sy = map(int, read().split())
    convenience_stores = {tuple(map(int, read().split())) for _ in range(n)}
    ex, ey = map(int, read().split())

    print(bfs(sx, sy))
    