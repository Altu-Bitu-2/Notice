import sys
import heapq as hq
input = sys.stdin.readline

"""
[크리스마스 선물] - 단순 구현 문제

- 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력
- 최대 힙의 연산을 하기 위해, 힙에 넣을 때는 -1을 곱해서 삽입하고, 출력할 때 다시 -1을 곱해서 출력
"""

n = int(input())
present = []

for _ in range(n):
    nums = list(map(int, input().split()))

    # 아이를 만난 경우
    if len(nums) == 1:
        if len(present) == 0:
            print(-1)
        else:
            print(-hq.heappop(present))
    # 선물을 충전하는 경우
    else:
        for value in num[1:]:
            hq.heappush(present, -value)