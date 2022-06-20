import sys
from collections import deque
SIZE = 26

"""
 [프로젝트 스케줄링]

 위상 정렬의 끝나는 정점이 여러 개일 경우, 가장 긴 시간을 선택해야 하기 때문에 정답을 항상 max처리 해주어야 함

 !주의! 입력으로 들어오는 그 전에 해야 할 작업은 0개일 수 있음. 즉 주어지지 않을 수 있음.
"""

#  위상정렬 + DP
def topological_sort(day, indegree, graph):
    que = deque()
    dp = day[:]
    ans = 0

    for i in range(SIZE):
        if not indegree[i]:
            que.append(i)

    while que:
        curr = que.popleft()
        # 정답 갱신 - 마지막 정점이 여러개일 경우, 가장 긴 시간을 선택해야 하기 때문
        ans = max(ans, dp[curr])

        for next in graph[curr]:
            indegree[next] -= 1
            if not indegree[next]:
                que.append(next)
            # 다음 정점의 시작 시간 계산 -> 사전 작업 중 가장 늦게 끝난 작업으로 갱신
            dp[next] = max(dp[next], dp[curr] + day[next])

    return ans

# 입력의 끝이 따로 주어지지 않았기 때문에 한번에 입력 받음
lines = sys.stdin.readlines()
day = [0] * SIZE
indegree = [0] * SIZE
graph = [list() for _ in range(SIZE)]

for line in lines:
    line = line.split()
    task_num = ord(line[0]) - ord('A')  # 작업 번호
    day[task_num] = int(line[1])    # 해당 작업에 소요되는 일 수
    
    # 사전 작업이 없다면
    if len(line) == 2:
        continue

    indegree[task_num] = len(line[2])

    for i in line[2]:
        graph[ord(i) - ord('A')].append(task_num)

# 연산 + 출력
print(topological_sort(day, indegree, graph))