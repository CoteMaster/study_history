"""
타겟 넘버

주어진 수들을 더하거나 빼서 타겟수를 만들어야한다.
dfs로 전부 검토해야함.
1을 고르면
그다음 +2, +3, +4, +5, -2, -3, -4, -5중 하나를 고를 수 있음
cnt가 주어진 수의 개수가 되면 종료

알고리즘: dfs
"""
answer = 0


def solution(numbers, target):
    def dfs(remain, result):
        if len(remain) == 0:
            if result == target:
                global answer
                answer += 1
            return

        num = remain.pop()
        dfs(remain, result+num)
        dfs(remain, result-num)
        remain.append(num)

    numbers.reverse()
    dfs(numbers, 0)

    return answer


print(solution([1, 1, 1, 1, 1], 3))
