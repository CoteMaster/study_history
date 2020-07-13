def solution(number, k):
    number = list(number)
    answer = [number[0]]
    tos = 0
    for i in number[1:]:
        answer.append(i)
        tos += 1
        correct = 1
        while correct and k != 0:
            correct -= 1
            for j in range(tos, len(answer)):
                if answer[j-1] < answer[j]:
                    answer[j-1], answer[j] = answer[j], answer[j-1]
                    answer.pop()
                    correct += 1
                    tos -= 1
                    k -= 1
                    break
    return "".join(answer[:len(answer)-k])
