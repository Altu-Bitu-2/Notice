import sys
import heapq as hq
input = sys.stdin.readline

"""
[해킹]
- 기본적인 다익스트라 문제
- 우선순위 큐에 삽입을 할 때는 이후 더 빠른 시간이 큐에 들어올 가능성이 있으므로 삽입할 때는 표기하지 않고, 큐에서 제거하는 시점에서 방문 표기 (큐에서 제거하는 시점에는 그때의 시간이 이후로 등장할 수 있는 가장 빠른시간이다.)

 !주의! 그래프 생성 시, a가 b를 의존한다는 건 b 감염 후 a가 감염된다는 뜻이므로 b -> a 방향임
"""

def dijkstra(n, c, graph):
    visited = [False] * (n+1)

    pq = [(0, c)]
    
    t = 0
    cnt = 0

    while pq:
        curr_t, curr = hq.heappop(pq)
        if visited[curr]:
            continue
        visited[curr] = True
        t = curr_t
        cnt += 1
        for next, weight in graph[curr]:
            if not visited[next]:
                hq.heappush(pq, (t + weight, next))
    
    return cnt, t


# 입력
t = int(input())

for _ in range(t):
    # 입력
    n, d, c = map(int, input().split())
    graph = [[] for _ in range(n+1)]

    # 인접 리스트로 저장
    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))
    
    # 연산 + 출력
    print(*dijkstra(n, c, graph))