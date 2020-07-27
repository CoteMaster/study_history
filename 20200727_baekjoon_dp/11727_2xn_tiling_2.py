"""
1 - 1           1
2 - 1 1 1       3
3 - 1 2 2       5
4 - 3 4 4       11
5 - 5 8 8       21

arr[n] = arr[n-2]*2 + arr[n-1]
"""

import sys
read = sys.stdin.readline

n = int(read())
arr = [1, 3, 5, 11, 21]
for i in range(5, n):
    arr.append((arr[i-2]*2+arr[i-1]) % 10007)
print(arr[n-1])
