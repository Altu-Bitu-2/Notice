import sys
import heapq as hq  # heapq를 hq라는 이름으로 import
input = sys.stdin.readline

"""
[최대 힙]

python의 heapq는 기본적으로 min heap!!
따라서, max heap으로 사용하고 싶으면 값에 -1를 곱해서 사용
"""

n = int(input())
max_heap = []    # 최대 힙으로 쓰일 리스트

for _ in range(n):
    # 입력
    x = int(input())
    
    if x == 0:
        # max_heap이 비어있지 않은 경우
        if len(max_heap):
            print(-hq.heappop(max_heap))    # 음수로 바꾸어 삽입했으므로 양수로 바꾸어 출력
        # 비어있는 경우
        else:
            print(0)
    else:
        hq.heappush(max_heap, -x)   # 최대힙으로 사용하기 위해 음수로 바꾸어 삽입