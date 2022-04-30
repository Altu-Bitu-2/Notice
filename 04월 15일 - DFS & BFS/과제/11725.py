import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

"""
[트리의 부모 찾기]

- 1번 노드에서 출발해서 탐색
- 루트 노드에서 출발 했기 때문에, 현재 노드의 부모는 이전 노드가 된다.
- (주의) 트리 노드의 최대 수가 100,000이므로, 가능한 트리의 최대 깊이는 100,000번이 된다. 즉, 재귀 깊이 또한 100,000번이 되므로 재귀 깊이 제한을 재설정 해야한다.
"""

def dfs_recursion(prev, curr):
    if parent[curr]:
        return
    
    parent[curr] = prev

    for next in adj_list[curr]:
        dfs_recursion(curr, next)
    return

n = int(input())
adj_list = [list() for _ in range(n+1)]
parent = [0] * (n + 1)

for _ in range(n-1):
    a, b = map(int, input().split())
    adj_list[a].append(b)
    adj_list[b].append(a)

dfs_recursion(1, 1)   # 1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정
print(*parent[2:], sep='\n')