import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

"""
 [거짓말]

 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 2. 연결된 사람들은 같은 집합에 속함
 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음

 !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
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

def count_liar_party(party):
    cnt = 0

    for i in party:
        if find_parent(i) != find_parent(0):
            cnt += 1
    
    return cnt

# 입력
n, m = map(int, input().split())
parent = [-1] * (n+1)     # 초기화

party = []  # 각 파티의 대표자 저장할 리스트

# 진실을 아는 사람들
for i in map(int, input().split()[1:]):
    union(i, 0)

# 각 파티에 대한 입력 & 연산
for _ in range(m):
    arr = list(map(int, input().split()))
    party.append(arr[1])    # 파티 정보로 각 파티의 첫번째 사람만 저장
    for i in range(2, arr[0] + 1):
        union(arr[i], arr[1])

# 연산 & 출력
print(count_liar_party(party))