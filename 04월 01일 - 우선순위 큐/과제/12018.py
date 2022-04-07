import sys
import heapq as hq
input = sys.stdin.readline

"""
[Yonsei TOTO]
 수강 인원이 미달일 때 필요한 마일리지는 0이 아니라 1
 1. 각 과목을 듣기 위해 필요한 최소 마일리지를 계산 (정렬)
 2. 가장 마일리지가 적게 드는 과목부터 수강 신청 (우선순위 큐 or 정렬)
"""

def maxClass(m, min_heap):
    count = 0
    # 더이상 들을 과목이 없거나, 마일리지가 모자르면 반복문 탈출
    while min_heap and min_heap[0] <= m:
        m -= hq.heappop(min_heap)
        count += 1

    return count


# 입력
n, m = map(int, input().split())
min_heap = []   # 필요한 최소 마일리지 저장할 최소 힙

for _ in range(n):
    # 입력
    p, l = map(int, input().split())
    mileage = list(map(int, input().split()))

    # 수강인원보다 적게 수강신청한 경우 1만 있으면 됨
    if p < l:
        hq.heappush(min_heap, 1)
        continue

    mileage.sort(reverse=True)
    # l번째로 마일리지를 많이 넣은 사람과 같은 양의 마일리지를 넣어야 수강 가능
    hq.heappush(min_heap, mileage[l-1])

# 연산 + 출력
print(maxClass(m, min_heap))