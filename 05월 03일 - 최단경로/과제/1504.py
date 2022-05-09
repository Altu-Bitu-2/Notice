import sys
import heapq as hq
input = sys.stdin.readline

"""
 [특정한 최단 경로]

 가능한 경로
 1. 1 -> v1 -> v2 -> n
 2. 1 -> v2 -> v1 -> n
 -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기

 !주의!
 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
"""

INF = 8*(10**5) * 3   # 최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

def dijkstra(n, graph, start):
    dist = [INF]*(n+1)
    pq = [(0, start)]

    dist[start] = 0 

    while pq:
        weight, curr = hq.heappop(pq)
        if weight > dist[curr]:
            continue
        for next, next_weight in graph[curr]:
            new_weight = next_weight + weight
            if new_weight < dist[next]:
                dist[next] = new_weight
                hq.heappush(pq, (new_weight, next))

    return dist


n, e = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

v1, v2 = map(int, input().split())

dist = []
for s in (1, v1, v2):
    dist.append(dijkstra(n, graph, s))

# 1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
# 무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n])

if ans >= INF:
    print(-1)
else:
    print(ans)