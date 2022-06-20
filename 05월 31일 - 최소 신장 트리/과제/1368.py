import sys
import heapq as hq
input = sys.stdin.readline
INF = 10**5 + 1

"""
 [물대기]

 각 논들 사이의 간선도 고려하고, 우물을 파는 경우도 고려? -> 복잡
 논에 추가로 모든 우물과 연결되는 수원이 있다고 가정!
 ->직접 논에 우물을 파는 경우는 수원과 각 논 사이의 간선 가중치라고 할 수 있음
 
 0 2 2 2 5
 2 0 3 3 4
 2 3 0 4 4
 2 3 4 0 3
 5 4 4 3 0
 
 인덱스 0 ~ n-1은 논, 인덱스 n은 수원
 1개 이상의 논은 반드시 직접 우물을 파야 하므로 수원(n)에서 시작하는 프림 알고리즘
"""

def prim(size, start, graph):
    total = 0
    pq = []
    visited = [False] * size  # 논 방문 여부
    dist = [INF] * size     # 각 논까지의 비용

    # 초기화
    dist[start] = 0
    hq.heappush(pq, (0, start))

    while pq:
        cost, curr = hq.heappop(pq)

        if visited[curr]:
            continue

        visited[curr] = True
        total += cost

        for i in range(size):
            if not visited[i] and graph[curr][i] < dist[i]:
                dist[i] = graph[curr][i]
                hq.heappush(pq, (graph[curr][i], i))

    return total


# 입력
n = int(input())
cost = [int(input()) for _ in range(n)]

# 논들 사이에서 물을 끌어오는 비용
graph = [list(map(int, input().split())) for _ in range(n)]

# 수원지로부터 물을 끌어오는 비용
graph.append(cost + [0])
for i in range(n):
    graph[i].append(cost[i])

# 연산 & 출력
print(prim(n+1, n, graph))