import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

"""
 [트리의 지름]

 1. 지름을 이루는 두 점은 모두 리프 노드
 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드

 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
"""

def dfs(node, parent, graph):
    pos = node
    dist = 0
    for next, weight in graph[node]:
        if next == parent:
            continue
        
        child_node, child_dist = dfs(next, node, graph)

        if weight + child_dist > dist:
            dist = weight + child_dist
            pos = child_node

    return pos, dist

# 입력
n = int(input())

graph = [list() for _ in range(n+1)]

for _ in range(n-1):
    p, c, w = map(int, input().split())
    # 무방향 그래프로 만들기
    graph[p].append((c, w))
    graph[c].append((p, w))

# 연산
first_node, _ = dfs(1, -1, graph)
_, radius = dfs(first_node, -1, graph)

print(radius)