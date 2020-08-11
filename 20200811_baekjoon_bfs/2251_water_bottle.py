"""
2251 물통

ABC 물통이 있고 00C의 상태로 시작한다.
두 물통을 골라 하나에서 다른 쪽으로 물을 붓고
담을 수 있을 지까지 붓는다.
A의 물의 양이 0일 때 가능한 C의 물의 양을 모두 구하고
오름차순으로 출력하라.
"""

import sys
read = sys.stdin.readline

a_max, b_max, c_max = tuple(map(int, read().split()))

result = set()

q = [(0, 0, c_max)]
visit = {(0, 0, c_max)}
while q:
    nxt_q = []
    for a, b, c in q:
        if a == 0:
            result.add(c)
            
        if a != 0:
            if a+b <= b_max:
                nxt_state = (0, a+b, c)
            else:
                nxt_state = (a+b-b_max, b_max, c)
            if nxt_state not in visit:
                nxt_q.append(nxt_state)
                visit.add(nxt_state)
                    
            if a+c <= c_max:
                nxt_state = (0, b, a+c)
            else:
                nxt_state = (a+c-c_max, b, c_max)
            if nxt_state not in visit:
                nxt_q.append(nxt_state)
                visit.add(nxt_state)
                
        if b != 0:
            if b+a <= a_max:
                nxt_state = (b+a, 0, c)
            else:
                nxt_state = (a_max, b+a-a_max, c)
            if nxt_state not in visit:
                nxt_q.append(nxt_state)
                visit.add(nxt_state)
                
            if b+c <= c_max:
                nxt_state = (a, 0, b+c)
            else:
                nxt_state = (a, b+c-c_max, c_max)
            if nxt_state not in visit:
                nxt_q.append(nxt_state)
                visit.add(nxt_state)
                
        if c != 0:
            if c+a <= a_max:
                nxt_state = (c+a, b, 0)
            else:
                nxt_state = (a_max, b, c+a-a_max)
            if nxt_state not in visit:
                nxt_q.append(nxt_state)
                visit.add(nxt_state)
                
            if c+b <= b_max:
                nxt_state = (a, c+b, 0)
            else:
                nxt_state = (a, b_max, c+b-b_max)
            if nxt_state not in visit:
                nxt_q.append(nxt_state)
                visit.add(nxt_state)
                
    q = nxt_q

print(" ".join(map(str, sorted(result))))