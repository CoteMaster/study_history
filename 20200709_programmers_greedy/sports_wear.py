"""
체육복

도난당한 학생은 여분을 가져온 학생의 체육복을 빌려입어야 한다.
바로 전번호나 다음번호만 빌릴 수 있다.
본인이 여분을 가져왔는데 도난당했으면 본인꺼를 입는다.

알고리즘: 그리디 알고리즘
"""


def solution(n, lost, reserve):
    answer = n - len(lost)
    for i in lost:
        if i in reserve:
            reserve.remove(i)
            answer += 1
        elif i-1 in reserve:
            reserve.remove(i-1)
            answer += 1
        elif i+1 in reserve:
            if i+1 not in lost:
                reserve.remove(i+1)
                answer += 1
    return answer
