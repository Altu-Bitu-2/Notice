import sys
input = sys.stdin.readline

"""
[도시 분할 계획]

마을을 두개로 분리하고, 각 집끼리 이동할 수 있는 최소한의 도로만 남기는 문제
즉, 2개의 최소신장트리를 만들어야 하는 문제
-> 하나의 최소신장트리를 만들고, 그 중 가장 유지비가 큰 도로를 삭제
-> 크루스칼 알고리즘에서 가장 마지막에 삭제되는 도로가 유지비가 가장 큼
-> 크루스칼 알고리즘에서 간선을 n-2개만 선택하여 그 합을 구하여 해결
"""

# find 연산
def find_parent(x):
    if parent[x] < 0:
        return x
    
    parent[x] = find_parent(parent[x])
    return parent[x]

# union 연산
def union(x, y):
    px = find_parent(x)
    py = find_parent(y)

    if px == py:
        return False
    
    if parent[px] < parent[py]:
        parent[px] += parent[py]
        parent[py] = px
    else:
        parent[py] += parent[px]
        parent[px] = py

    return True

def kruskal(n, edge):
    cost = 0
    cnt = 0
    for u, v, w in edge:
        if not union(u, v):
            continue

        cost += w
        cnt += 1

        if cnt == n-1:
            return cost

    return 0


n, m = map(int, input().split())

edge = [tuple(map(int, input().split())) for _ in range(m)]

# 초기화
parent = [-1]*(n+1)

edge.sort(key=lambda x:x[2])  # 정렬

# 연산 & 출력
print(kruskal(n-1, edge))