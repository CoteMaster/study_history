"""
소수 찾기

한자리 숫자들을 조합해서 만들 수 있는 소수의 개수는?

알고리즘: 순열, 완전탐색

1. 1-n개 고르면서 순열에 대해 모두 소수인지 확인
"""
from itertools import permutations


def solution(numbers):
    def check_prime_number(n):
        if n in [0, 1]:
            return False
        if n == 2:
            return True
        if n % 2 == 0:
            return False
        for j in range(3, int(n**0.5)+1, 2):
            if n % j == 0:
                return False
        return True

    result = set()
    for i in range(1, len(numbers)+1):
        for case in permutations(numbers, i):
            case = int("".join(case))
            if check_prime_number(case):
                result.add(case)
    return len(result)


print(solution("17"))
print(solution("011"))
