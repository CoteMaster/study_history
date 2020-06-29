"""
10814 나이순 정렬

나이와 이름이 가입한 순으로 주어짐
나이가 증가하는 순으로
나이가 같으면 먼저 가입한 사람이 앞에

알고리즘: 정렬

1. 입력 받을때 들어온 순 즉 인덱스도 추가하자.
2. 솔팅
3. 출력
"""

import sys
read = sys.stdin.readline

n = int(read())
ids = []
for i in range(n):
    age, name = read().split()
    ids.append((int(age), i, name))
ids.sort()

for age, _, name in ids:
    print("{} {}".format(age, name))
