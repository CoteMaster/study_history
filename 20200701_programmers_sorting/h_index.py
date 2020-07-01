"""
6 5 3 1 0
x x 3 1 0

6 5 4 3 2 1
x x x 3 2 1

6 3 1
x x 1

5 3 3
x x 3

5 4 4
x x x
"""


def solution(citations):
    answer = 0
    citations.sort(reverse=True)
    for i, c in enumerate(citations):
        answer = max(min(i+1, c), answer)
    return answer
