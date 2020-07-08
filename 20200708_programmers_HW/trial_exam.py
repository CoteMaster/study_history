"""
모의고사

1번 수포자: 1 2 3 4 5
2번 수포자: 2 1 2 3 2 4 2 5
3번 수포자: 3 3 1 1 2 2 4 4 5 5
문제가 주어질때 정답을 많이 맞춘 사람은?

알고리즘: 완전탐색
"""


def solution(answers):
    a = [1, 2, 3, 4, 5]
    b = [2, 1, 2, 3, 2, 4, 2, 5]
    c = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    result = [0, 0, 0]
    for i, answer in enumerate(answers):
        if answer == a[i%5]:
            result[0] += 1
        if answer == b[i%8]:
            result[1] += 1
        if answer == c[i%10]:
            result[2] += 1

    result2 = []
    max_result = max(result)
    for i, r in enumerate(result):
        if r == max_result:
            result2.append(i+1)
    return result2


print(solution([1, 2, 3, 4, 5]))
print(solution([1, 3, 2, 4, 2]))