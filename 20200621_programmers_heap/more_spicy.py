"""
더 맵게

모든 음식이 k이상 되도록 만들어야한다.
새로운 음식  = 가장 안매운 음식 + 그다음 안매운 음식 * 2
몇번 돌면 될까?
안되면 -1

알고리즘: 우선순위 큐
"""

import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while True:
        new_food = heapq.heappop(scoville) + heapq.heappop(scoville)*2
        heapq.heappush(scoville, new_food)
        answer += 1
        if scoville[0] >= K:
            break
        if len(scoville) == 1:
            answer = -1
            break
    return answer
