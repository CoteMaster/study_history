def solution(people, limit):
    answer = 0
    start, end = 0, len(people)-1
    people.sort()
    while start <= end:
        weight = 0
        while start <= end:
            if people[end]+weight <= limit:
                weight += people[end]
                end -= 1
            else:
                break
            if start <= end and people[start]+weight <= limit:
                weight += people[start]
                start += 1
            else:
                break
        answer += 1
    return answer
