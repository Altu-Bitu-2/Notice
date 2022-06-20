import sys
from collections import deque
input = sys.stdin.readline

"""
[장난감 부품]

- 완제품을 만들기 위해 필요한 기본 부품의 개수를 구하는 문제
- x(만들어지는 부품) <- y(필요한 부품) 의 관계를 역으로 만들면 x -> y가 되면서 루트노드가 완제품이 되고 리프노드가 기본 부품이 됨
- 따라서, BFS/DFS 탐색을 통해 필요한 리프노드의 총 개수를 구함
"""

def bfs(n, graph):
    que = deque()
    cnt = [0] * (n + 1)
    ans = [0] * (n + 1)

    que.append(n)
    cnt[n] = 1  # 큐에 있는 부품 번호에 따른 개수 저장

    while que:
        x = que.popleft()

        # 리프노드(기본부품)인 경우
        if not graph[x]:
            ans[x] += cnt[x]
        # 중간부품인 경우
        for y, k in graph[x]:
            # 큐에 없으면 삽입
            if not cnt[y]:
                que.append(y)
            cnt[y] += k * cnt[x]

        cnt[x] = 0  # 처리가 끝나면 0으로 리셋
    return ans

# 입력
n = int(input())
m = int(input())

graph = [list() for _ in range(n+1)]
for _ in range(m):
    x, y, k = map(int, input().split())
    graph[x].append((y, k))

# 연산
ans = bfs(n, graph)

# 출력
for i in range(1, n+1):
    if ans[i]:
        print(i, ans[i])