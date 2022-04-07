import sys
import heapq as hq  # heapq 모듈을 hq 이름으로 import
input = sys.stdin.readline

"""
[N번째 큰 수]

메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
"""

n = int(input())

# 첫 줄은 n이니까 그대로 받아서 min heap으로 만들기
min_heap = list(map(int, input().split()))
hq.heapify(min_heap)

# 이후 n-1 줄에 대해 들어오는 수들을 검사
for _ in range(n-1):
    line = map(int, input().split())
    for x in line:
        # 상위 n개 중 가장 작은 수보다 커야 상위 n개 힙에 삽입할 수 있음
        if x > min_heap[0]:
            # x를 push하고, pop한다
            # 순서 중요! pop부터 해야 되는 상황에는 쓰지 않도록 주의한다.
            hq.heappushpop(min_heap, x)

print(min_heap[0])