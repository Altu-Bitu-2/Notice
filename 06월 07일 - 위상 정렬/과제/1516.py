import sys
from collections import deque
input = sys.stdin.readline

"""
 [게임 개발]

 - ACM Craft (1005) 와 동일한 문제
 - 최소 시간 = 건물을 동시에 지을 수 있는 건 최대한 동시에 지어야 최소 시간이 걸리므로 그 전 정점 중 가장 오래 걸리는 시간을 선택
"""

def topological_sort(n, time, indegree, graph):
    que = deque()
    dp = [0] * (n+1)

    for i in range(1, n+1):
        dp[i] = time[i]
        if not indegree[i]:
            que.append(i)
    

    while que:
        curr = que.popleft()
        for next in graph[curr]:
            indegree[next] -= 1
            dp[next] = max(dp[next], dp[curr] + time[next])
            if not indegree[next]:
                que.append(next)

    return dp

# 입력
n = int(input())
time = [0] * (n+1)
indegree = [0] * (n+1)
graph = [list() for _ in range(n+1)]

for i in range(1, n+1):
    line = list(map(int, input().split()))
    time[i] = line[0]
    indegree[i] = len(line) - 2
    for v in line[1:-1]:
        graph[v].append(i)

# 연산 + 출력
print(*topological_sort(n, time, indegree, graph)[1:], sep='\n')