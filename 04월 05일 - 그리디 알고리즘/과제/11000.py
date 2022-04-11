import sys
import heapq as hq
input = sys.stdin.readline

"""
[강의실 배정]

- 강의실 수를 최소로 하기 위해서, 현재 사용하는 강의실 중 가장 빨리 끝나는 강의실에 가장 먼저 시작하는 강의실을 배치해야 한다.
- 이 문제는 모든 강의를 다 진행해야 하므로, 회의실 배정 문제와는 다르다! 먼저 시작하는 순으로 정렬할 것.
- 현재 가장 빨리 끝나는 시간을 구하기 위해 최소 힙(우선순위 큐) 사용
"""

# 필요한 강의실 수를 구하는 함수
def get_min_classroom(lectures):
    lectures.sort()
    pq = [-1]   # 처음 인덱스 에러를 피하기 위해 음수 값 삽입. (첫번째 강의 때 갱신될 값)

    for start, end in lectures:
        if pq[0] <= start:  # 가장 빨리 끝나는 강의실을 사용할 수 있는 경우
            hq.heappop(pq)
        hq.heappush(pq, end)    # 끝나는 시간 삽입
    
    return len(pq)  # pq의 길이가 사용 중인 강의실의 수가 된다.

n = int(input())
lectures = [tuple(map(int, input().split())) for _ in range(n)]

print(get_min_classroom(lectures))