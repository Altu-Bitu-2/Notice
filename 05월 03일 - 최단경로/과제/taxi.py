"""
 [합승 택시 요금]

 합승할 수 있는 지점의 개수는 n개
 1. s인 경우는 합승을 하지 않을 때
 2. a인 경우는 A의 집까지 합승한 뒤, B 혼자 이동
 3. b인 경우는 B의 집까지 합승한 뒤, A 혼자 이동
 4. 나머지 경우는 특정 지점까지 합승한 뒤, 각자의 집으로 가는 것
 -> 다익스트라를 사용하면 시간초과이므로 플로이드-워셜 알고리즘 사용

 1. 플로이드-워셜 알고리즘으로 모든 지점들 사이의 최단 거리 계산
 2. n개의 지점에 대해 n번 지점까지 합승을 하고 각자의 집으로 가는 최단거리 계산
"""

INF = 2*10**7   # 최대 n-1개의 간선을 지나게 됨

def floyd_warshall(n, graph):
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]
    return graph

def solution(n, s, a, b, fares):
    answer = 0
    graph = [[INF]*(n+1) for _ in range(n+1)]
        
    # 간선을 인접 행렬 그래프에 삽입
    for node1, node2, weight in fares:
        graph[node1][node2] = weight
        graph[node2][node1] = weight
        
    for i in range(1, n+1):
        graph[i][i] = 0
    graph = floyd_warshall(n, graph)
    
    answer = INF

    for i in range(1, n+1):
        answer = min(answer, graph[s][i]+graph[i][a]+graph[i][b])
    
    return answer