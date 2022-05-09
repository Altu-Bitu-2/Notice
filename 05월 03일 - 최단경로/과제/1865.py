import sys
input = sys.stdin.readline

"""
 [웜홀]

 벨만-포드 문제

 시간이 되돌아가서 출발 지점에 도착하는 경우 = 음의 사이클이 생긴 경우

 특별히 시작점이 주어지지 않았으므로, 벨만-포드를 특정 정점에서 시작하는 경우만 돌릴 시 해당 정점에서 닿을 수 없는 음의 사이클의 존재를 판단할 수 없음
 그러나, 모든 정점에서 벨만-포드 연산을 하게 되면 O(n^2*E)의 시간 복잡도가 걸려서 효율적이지 않음
 => 모든 정점에 도달할 수 있는 임의의 가짜 정점 0을 만들어서 시작점을 0으로 하는 한 번의 벨만-포드 연산으로 그래프 전체에 대한 음의 사이클 존재 여부 판단!
 => 이때, 가짜 정점 0에서 모든 정점으로의 거리가 0인 간선이 있다고 가정하여 dist배열을 0으로 초기화
"""

def bellman_ford(n, edges):
    dist = [0] * (n+1)  # (추가 제출 시) 0으로 초기화한 이유 꼭 적어주세요!

    for i in range(n+1):
        flag = False

        for s, e, t in edges:
            if dist[s] + t < dist[e]:
                dist[e] = dist[s] + t
                flag = True

        if not flag:
            return "NO"

        if i == n:
            return "YES"

tc = int(input())
for _ in range(tc):

    # 입력
    n, m, w = map(int, input().split())

    edges = []

    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))

    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t))
    
    
    print(bellman_ford(n, edges))