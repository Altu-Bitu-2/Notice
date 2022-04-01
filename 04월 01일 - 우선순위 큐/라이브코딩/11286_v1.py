import sys
import heapq as hq  # heapq를 hq라는 이름으로 import
input = sys.stdin.readline

"""
[절댓값 힙]

- heapq에 데이터를 삽입할 때, 튜플의 첫 값으로 키가 되는 값을 전달
"""

# 입력
n = int(input())
abs_heap = []

for _ in range(n):
    # 입력
    x = int(input())
    if x == 0:  # 삭제
        if abs_heap:
            # 값을 넣을 때 튜플의 두번째 요소로 원본을 입력했기 때문에 pop된 값의 1번 인덱스를 출력
            print(hq.heappop(abs_heap)[1])
        else:
            print(0)
    else:   # 삽입
        # key1. 절댓값이 작으면 우선순위
        # key2. 값이 작으면 우선순위
        hq.heappush(abs_heap, (abs(x), x))