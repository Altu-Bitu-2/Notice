import sys
input = sys.stdin.readline

"""
[우주신과의 교감]

4386번 : 별자리 만들기의 응용 문제
 이미 연결된 정점들이 존재한다는 것을 제외하고는 4386번과 동일

 1. 임의의 두 별에 대한 거리(간선) 모두 구하기
 2. 이미 존재하는 통로들 표시
    !주의! 통로의 개수가 m개라면 v-m-1개의 간선만 더 추가하면 될까?
          이미 연결된 통로들도 사이클을 이룰 수 있기 때문에 유니온 연산을 하며 사이클 없이 연결된 간선만 세기
 3. 이미 연결된 통로의 수를 k개라고 하면 v-k-1개의 간선을 추가로 선택
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

# 입력
n, m = map(int, input().split())
position = [tuple(map(int, input().split())) for _ in range(n)]
edge = []

for i in range(n):
    for j in range(i):
        dx = position[i][0] - position[j][0]
        dy = position[i][1] - position[j][1]

        edge.append((i, j, (dx**2 + dy**2)**(1/2)))

# 초기화
parent = [-1]*(n)

cnt = 0

for _ in range(m):
    u, v = map(int, input().split())
    # 이미 연결한 통로
    if union(u-1, v-1):
        cnt += 1

edge.sort(key=lambda x:x[2])  # 정렬

# 연산 & 출력
print("%.2f" %(kruskal(n - cnt, edge)))