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
우선순위를 구현하기 위해, 각 사람의 정보를 나타낼 클래스를 만들어 __lt__오버라이딩

클래스의 필드는 아래와 같다.
    - days(근무일자)
    - hurrying(급한 정도)
    - order(도착한 순서 - 0번부터 표기하므로 데카의 order는 k가 된다)
    - line(몇번 줄에 섰는지)
"""

class data:
    def __init__(self, days, hurrying, order):
        self.days = days
        self.hurrying = hurrying
        self.order = order
        self.line = order % m
    
    # self가 next보다 우선순위가 높도록 작성!
    def __lt__(self, next):
        # 근무 일수가 같으면
        if self.days == next.days:
            # 급한 정도도 같으면
            if self.hurrying == next.hurrying:
                # 줄 숫자가 적은 사람
                return self.line < next.line
            # 더 급한 사람
            return self.hurrying > next.hurrying
        # 근무 일수가 많은 사람
        return self.days > next.days

def simulation(que_list, k):
    count = 0
    leading = []    # 선두를 저장할 우선순위 큐

    for que in que_list:
        # 큐에 사람이 있으면
        if que:
            hq.heappush(leading, que.popleft())

    while leading[0].order != k:
        count += 1
        person = hq.heappop(leading)
        # 해당 줄에 사람이 있으면
        if que_list[person.line]:
            hq.heappush(leading, que_list[person.line].popleft())

    return count

n, m, k = map(int, input().split())

que_list = [deque() for _ in range(m)]  # m개의 줄

for i in range(n):
    days, hurrying = map(int, input().split())
    que_list[i % m].append(data(days, hurrying, i))

print(simulation(que_list, k))