"""
쇠막대기
"""

def solution(arrangement):
    answer = 0
    stack_length = 0
    for arr in arrangement:
        if arr == '(':
            stack_length += 1
        else:
            stack_length -= 1
            if before == '(':
                answer += stack_length
            else:
                answer += 1
        before = arr
    return answer