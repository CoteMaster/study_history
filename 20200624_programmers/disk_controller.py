"""
적게 걸리는 순으로 heapq를 만든 후
매 초당 반복문을 도는데
    heapq에서 하나 뺀후
    현재 초에 아무런 작업이 없는데 새로운 작업이 있으면
        새로운 작업 시작
    현재 초에 작업이 있으면
        heapq에 다시 넣기?

"""

import heapq


def solution(jobs):
    answer = 0
    time = 0
    jobs_time = [[y, x] for x, y in jobs]
    heapq.heapify(jobs_time)
    nxt_jobs_time = []
    while True:
        flag = False
        for i in range(len(jobs_time)):
            job, t = heapq.heappop(jobs_time)
            if time >= t and not flag:
                time += job
                answer += time - t
                flag = True
            else:
                heapq.heappush(nxt_jobs_time, [job, t])
        jobs_time = nxt_jobs_time
        if not flag:
            time += 1
        if len(jobs_time) == 0:
            break
    return answer // len(jobs)


print(solution([[0, 3], [1, 9], [2, 6]]))
print(solution([[0, 3], [4, 3], [7, 3]]))