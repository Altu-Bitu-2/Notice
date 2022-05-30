import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

"""
 [할로윈의 양아치] - pypy3로 제출

 - weighted union find -> 루트 정점에 아이들의 수(집합 원소 수)와 사탕 개수까지 쌍으로 저장하기
 - dp(냅색)으로 K명 미만의 아이들에게서 뺏을 수 있는 최대 사탕 수 구하기
"""

# find 연산
def find_parent(x):
    if parent[x][0] < 0:
        return x
    parent[x][0] = find_parent(parent[x][0])
    return parent[x][0]

# union 연산
def union(x, y):
    px = find_parent(x)
    py = find_parent(y)

    if px == py:
        return

    if parent[px][0] < parent[py][0]:
        parent[px][0] += parent[py][0]
        parent[px][1] += parent[py][1]
        parent[py][0] = px
    else:
        parent[py][0] += parent[px][0]
        parent[py][1] += parent[px][1]
        parent[px][0] = py
    return

def knapsack(k):
    dp = [0] * k    # 1부터 k-1까지
    count = []      # [아이들의 수, 사탕의 수]
    for p, c in parent:
        if p < 0:
            count.append((-p, c))
    
    for child_cnt, candy_cnt in count:
        for i in range(k-1, child_cnt-1, -1):
            dp[i] = max(dp[i], dp[i-child_cnt] + candy_cnt)

    return dp[-1]

# 입력
n, m, k = map(int, input().split())
parent = [[-1, i] for i in map(int, ("0 "+input()).split())]    #[-아이들의 수, 사탕 개수]

for _ in range(m):
    a, b = map(int, input().split())
    union(a, b)

# 연산 & 출력
print(knapsack(k))