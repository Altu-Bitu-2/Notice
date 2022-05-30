import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

"""
 [친구 네트워크]

 1. weighted union find -> 루트 정점에 친구의 수(집합 원소 수) 저장
 2. 친구 네트워크에 몇 명 있는지 구하기 -> 루트 정점의 parent값 접근

 !주의! 정점이 문자열로 들어오므로 map을 활용해 string을 int로 매핑
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
        return

    if parent[px] < parent[py]:
        parent[px] += parent[py]
        parent[py] = px
    else:
        parent[py] += parent[px]
        parent[px] = py
    return

# 입력
t = int(input())

for _ in range(t):
    # 입력
    f = int(input())
    
    # 초기화
    name_to_idx = dict()
    idx = 0
    parent = [-1] * (2 * f) # 입력이 모두 다른 이름으로 들어올 경우 -> 최대 2*f개

    for _ in range(f):
        a, b = input().split()

        if a not in name_to_idx:
            name_to_idx[a] = idx
            idx += 1
        if b not in name_to_idx:
            name_to_idx[b] = idx
            idx += 1

        x, y = name_to_idx[a], name_to_idx[b]

        union(x, y)

        print(-parent[find_parent(x)])