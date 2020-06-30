"""
1427 소트인사이드

각 자리수의 수들을 정렬하여 출력

알고리즘: 정렬
"""

import sys
read = sys.stdin.readline

print("".join(sorted(read().strip(), reverse=True)))
