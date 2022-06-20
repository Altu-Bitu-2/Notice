import sys
input = sys.stdin.readline

"""
[MST 게임]

 MST 알고리즘을 여러 번 실행해도 될까?
 1. 크루스칼 알고리즘의 시간 복잡도는 O(ElogE)
    이는 오직 간선을 정렬하는 연산의 시간 복잡도!
    즉, 모든 간선을 한 번 정렬해서 저장해두면 이후 몇 번의 알고리즘을 수행하여도 연산 시간에 큰 영향이 없음
 2. 간선 재사용을 위해 우선순위 큐가 아닌 배열에 저장하고 크루스칼 알고리즘 k번 실행
 3. 매번 크루스칼을 수행할 때마다 제일 먼저 추가한 간선을 제외함
    -> 첫번째 간선은 모든 점이 분리된 상태에서 들어오기 때문에 무조건 사용하게 되어 있고, 이는 사용한 간선 중 가장 짧은 간선
    -> 제외될 간선은 배열의 첫번째 간선부터 순차적 제외
 4. 만약 한 번 MST를 만들 수 없다는게 확인됐다면 이후에도 MST를 만들 수 없음
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

def kruskal(n, m, edge, turn):
    cost = 0
    cnt = 0
    for w in range(turn, m+1):
        u, v = edge[w]
        if not union(u, v):
            continue

        cost += w
        cnt += 1

        if cnt == n-1:
            return cost

    return 0

n, m, k = map(int, input().split())

edge = [None] + [tuple(map(int, input().split())) for _ in range(m)]

result = []

for turn in range(1, k+1):
    # 초기화
    parent = [-1]*(n+1)
    # 연산
    result.append(kruskal(n, m, edge, turn))

    if result[-1] == 0: # 이후의 턴은 모두 0점이므로
        break

result += [0]*(k-len(result))

# 출력
print(*result)