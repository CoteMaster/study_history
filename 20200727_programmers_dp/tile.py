def solution(N):
    arr = [1, 1, 2, 3, 5, 8]
    for i in range(6, N+1):
        arr.append(arr[i-2]+arr[i-1])
    answer = (arr[N]+arr[N-1])*2
    return answer
