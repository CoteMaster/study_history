import heapq


def solution(stock, dates, supplies, k):
    answer = 0
    h = []
    d = 0
    while stock < k:
        while d < len(dates) and dates[d] <= stock:
            heapq.heappush(h, -supplies[d])
            d += 1
        stock += -heapq.heappop(h)
        answer += 1
    return answer
