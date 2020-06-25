"""
K번째수

i-j까지의 수를 정렬하고 k번째 수를 구하라.

알고리즘: 정렬
"""


def solution(array, commands):
    answer = []
    for i, j, k in commands:
        sorted_array = sorted(array[i-1:j])
        answer.append(sorted_array[k-1])
    return answer
