"""
숫자 야구

숫자는 맞는데 위치가 아니면 볼
숫자 위치 모두 맞으면 스트라이크
숫자와 위치 모두 틀리면 아웃

주어진 게임 결과에 맞는 숫자의 개수를 구하라.

알고리즘: 완전탐색

1. 순열로 9개 숫자중 3개를 고른다.
2. 조건에 맞는지 확인해본다.
3. 다 맞으면 경우의수 += 1
"""
from itertools import permutations


def solution(baseball):
    def get_strike_and_ball():
        n_s, n_b = 0, 0
        for c1, c2 in zip(nums, target):
            if c1 == c2:
                n_s += 1
            elif c1 in target:
                n_b += 1
        return n_s, n_b

    cnt = 0
    for nums in permutations(map(str, range(1, 10)), 3):
        flag = True
        for target, strike, ball in baseball:
            target = list(str(target))
            n_strike, n_ball = get_strike_and_ball()

            if strike != n_strike or ball != n_ball:
                flag = False
                break

        if flag:
            cnt += 1

    return cnt


print(solution([[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]]))