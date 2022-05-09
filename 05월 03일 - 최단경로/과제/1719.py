import sys
input = sys.stdin.readline

"""
 [택시]

 graph : 플로이드-워셜 결과 행렬 그래프
 table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점

 1. i->j의 중간 경로를 i로 초기화
 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
    line 24을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
"""

def floyd_warshall(n, graph, table):
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
                    table[i][j] = table[i][k]
    return

INF = 10**5 * 2
n, m = map(int, input().split())
graph = [[INF]*(n+1) for _ in range(n+1)]
table = [[0]*(n+1) for _ in range(n+1)]

for _ in range(m):
    a, b, s = map(int, input().split())
    graph[a][b] = graph[b][a] = s

    table[a][b] = b
    table[b][a] = a

floyd_warshall(n, graph, table)

for i in range(1, n+1):
    table[i][i] = '-'

for line in table[1:]:
    print(*line[1:])