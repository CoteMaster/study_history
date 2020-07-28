"""
정수 삼각형

정수로 이루어진 삼각형에서 위에서 아래로 내려오며 값을 더할때
가장 큰 합은?

알고리즘: dp

다음층으로 넘어갈 때 값이 합쳐지면 그때 대소비교를 할 수 있다.
즉, 마지막 층이 5개 값이 있으면 5가지 경우의 합을 구할 수 있다.
"""


def solution(triangle):
    for i in range(1, len(triangle)):
        triangle[i][0] += triangle[i-1][0]

        for j in range(1, len(triangle[i])-1):
            triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j])

        triangle[i][-1] += triangle[i-1][-1]
    return max(triangle[-1])
    

print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))
