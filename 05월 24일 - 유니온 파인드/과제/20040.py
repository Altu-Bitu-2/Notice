import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

"""
 [사이클 게임]

 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 union 함수의 리턴값을 boolean으로 주어 cycle이 생성되는 순간 발견하기
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

# 입력
n, m = map(int, input().split())
parent = [-1]*n     # 초기화

for i in range(m):
    x, y = map(int, input().split())
    if not union(x, y):
        # 사이클이 생성됨
        print(i+1)
        break
else:   # for-else문: for문이 break에 걸리지 않고 정상 종료된 경우에만 else문 실행
    print(0)