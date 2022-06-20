import sys
import heapq as hq
input = sys.stdin.readline

"""
 [문제집]

 - 조건 1, 2까지는 평범한 위상정렬
 - 조건 3 "가능하면 쉬운 문제부터 풀어야 한다." -> 위상정렬 시, 정점이 작은 순서부터
 - 조건 3을 만족시키기 위해, 진입차수가 0인 정점을 담는 컨테이너로 우선순위 큐 사용
"""

# 위상정렬
def topological_sort(n, indegree, graph):
    pq = []
    ans = []

    for i in range(1, n+1):
        if not indegree[i]:
            hq.heappush(pq, i)
    
    while pq:
        curr = hq.heappop(pq)
        ans.append(curr)

        for next in graph[curr]:
            indegree[next] -= 1
            if not indegree[next]:
                hq.heappush(pq, next)
    
    return ans

# 입력
n, m = map(int, input().split())
indegree = [0] * (n+1)
graph = [list() for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    indegree[b] += 1
    graph[a].append(b)  # a -> b

# 연산 + 출력
print(*topological_sort(n, indegree, graph))