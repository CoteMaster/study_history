"""
조이스틱

AAA -> JAZ로 이동할때 최소로 움직이는 동작은 11번이다.
문자열이 주어지면 최소 움직여서 만들 수 있는 동작 횟수를 구해라.

알고리즘: 그리디 알고리즘

현재 위치에서 왼쪽으로 가서 문자를 고치는 것과 오른쪽으로 가서 문자를 고치는 것중 작은 곳으로 계속 이동하면 되지 않을까
"""
answer = 1000000000


def solution(name):
    global answer
    answer = 10000000000
    length = len(name)

    def next_step(now_answer, pos):
        if sum(name) == 0:
            global answer
            answer = min(answer, now_answer)
            return

        left, l_pos = 1, pos - 1 if pos - 1 >= 0 else length - 1
        while name[l_pos] == 0:
            l_pos = l_pos - 1 if l_pos - 1 >= 0 else length - 1
            left += 1

        right, r_pos = 1, pos + 1 if pos + 1 < length else 0
        while name[r_pos] == 0:
            r_pos = r_pos + 1 if r_pos + 1 < length else 0
            right += 1

        if left < right:
            add = name[l_pos] if name[l_pos] <= 13 else 26-name[l_pos]
            tmp, name[l_pos] = name[l_pos], 0
            next_step(now_answer+left+add, l_pos)
            name[l_pos] = tmp
        elif right < left:
            add = name[r_pos] if name[r_pos] <= 13 else 26-name[r_pos]
            tmp, name[r_pos] = name[r_pos], 0
            next_step(now_answer+right+add, r_pos)
            name[r_pos] = tmp
        else:
            add = name[l_pos] if name[l_pos] <= 13 else 26-name[l_pos]
            tmp, name[l_pos] = name[l_pos], 0
            next_step(now_answer+left+add, l_pos)
            name[l_pos] = tmp

            add = name[r_pos] if name[r_pos] <= 13 else 26-name[r_pos]
            tmp, name[r_pos] = name[r_pos], 0
            next_step(now_answer+right+add, r_pos)
            name[r_pos] = tmp

    name = [ord(c) - 65 for c in name]
    tmp = name[0] if name[0] <= 13 else 26-name[0]
    name[0] = 0

    next_step(tmp, 0)

    return answer


print(solution("JAZ"))
print(solution("JAN"))
print(solution("JEROEN"))