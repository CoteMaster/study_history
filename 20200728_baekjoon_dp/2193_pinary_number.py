"""
2193 이친수

이친수는 0으로 시작하지 않고 1이 반복되지 않는 이진수다.
1 - 1
2 - 10
3 - 100 101 
4 - 1000 1001 1010
5 - 10000 10001 10010 10100 10101
6 - 100000 100001 100010 100100 100101 101000 101001 101010

arr[n] = arr[n-1] + arr[n-2]
"""

import sys

read = sys.stdin.readline

n = int(read())

arr = [1, 1, 2, 3, 5, 8]

for i in range(6, n):
    arr.append(arr[i-1] + arr[i-2])
print(arr[n-1])
