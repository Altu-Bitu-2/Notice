import sys
import heapq
input = sys.stdin.readline

"""
[파일 합치기 3]

- 파일을 전부 합치기 위해서는 어차피 하나로 만들어야 한다!
- 이 때, 여러번 더해지는 값은 작을 수록 좋다
- 따라서, 현재 가장 작은 파일 2개를 합쳐야 비용을 최소화 할 수 있다.
-> 최소 힙으로 구현
"""

def get_cost(pq):
    heapq.heapify(pq)
    
    cost = 0
    while len(pq) > 1:
        file1 = heapq.heappop(pq)
        file2 = heapq.heappop(pq)
        cost += file1 + file2
        heapq.heappush(pq, file1 + file2)

    return cost

t = int(input())

for _ in range(t):
    n = int(input())
    files = list(map(int, input().split()))
    print(get_cost(files))