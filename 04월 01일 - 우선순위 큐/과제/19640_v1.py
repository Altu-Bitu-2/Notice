import sys
import heapq as hq
from collections import deque
input = sys.stdin.readline

"""
[화장실의 규칙] - 시뮬레이션 문제

1. 각 사람은 온 순서 % m 번째 줄의 뒤에 서게 된다.
2. 매 순간, 모든 줄의 앞 사람 중에 우선 순위가 가장 높은 사람부터 화장실을 이용한다.

<우선순위>
1. 근무 일자가 많은 사람
2. 더 급한 사람
3. 줄 번호가 앞선 사람

---
1. 각 줄은 먼저 온 사람이 먼저 나가기 때문에, 큐를 이용해 저장한다.
2. 모든 줄의 선두를 우선순위 큐에 넣고, 우선순위가 가장 앞선 사람부터 삭제한다.
3. 어떤 줄의 선두가 화장실을 이용했으면, 그 줄의 선두를 우선 순위 큐에 넣는다.

!주의! 큐에서 사람을 빼서 우선 순위 큐에 넣을 때, 항상 큐가 비어있지 않은지 확인

---
우선순위를 구현하기 위해, 각 사람의 정보를 (key, value)로 저장해서 힙에 삽입한다.
key1 = 근무일자 크면 유리 -> -1을 곱해서 넣기
key2 = 급한 정도 크면 유리 -> -1 곱해서 넣기
key3 = 줄 번호 작아야 유리 -> 그대로 넣기
value = 도착한 순서 (단, 첫번째 사람을 0번으로 표기하므로 데카의 번호는 k가 된다)
"""

def simulation(que_list, k):
    count = 0
    leading = []    # 선두를 저장할 우선순위 큐

    for que in que_list:
        # 큐에 사람이 있으면
        if que:
            hq.heappush(leading, que.popleft())

    # 데카의 차레가 올 때까지
    while leading[0][1] != k:
        count += 1
        person = hq.heappop(leading)
        line = person[0][-1]
        # 줄에 사람이 남아 있으면
        if que_list[line]:
            hq.heappush(leading, que_list[line].popleft())

    return count

# 입력
n, m, k = map(int, input().split())

que_list = [deque() for _ in range(m)]  # m개의 줄

for order in range(n):
    # 입력
    days, hurrying = map(int, input().split())
    que_list[order % m].append(((-days, -hurrying, order % m), order))

print(simulation(que_list, k))