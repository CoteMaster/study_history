"""
네트워크

컴퓨터 간에 연결 정보가 주어지면 몇개의 네트워크가 존재하는지 리턴하라.
dfs로 모든 정점을 검토하면 된다.

알고리즘: dfs
"""


def solution(n, computers):
    global_visit = {}

    def dfs(start):
        stack, visit = [start], {start: True}
        while stack:
            now = stack.pop()

            for j, nxt in enumerate(computers[now]):
                if nxt and j not in visit and now != j:
                    stack.append(j)
                    visit[j] = True
        global_visit.update(visit)
        return 1

    answer = 0
    for i in range(n):
        if i not in global_visit:
            answer += dfs(i)

    return answer


print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
print(solution(3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]))