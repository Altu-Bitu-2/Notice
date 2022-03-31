import sys
input = sys.stdin.readline

"""
[외판원 순회2]
모든 도시를 방문할 수 있는 사이클을 만들고, 그 중 최소비용을 구한다.
사이클이 형성되므로 출발 도시는 중요하지 않다 -> 0으로 고정
"""

MAX = 10**8

# curr_city: 현재 도시의 index, left: 남은 도시의 수, cost: 현재까지의 경비
def backtracking(count, curr_city, cost):
    global answer   # 전역변수 answer 업데이트 필요
    
    if cost > answer:   # 생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        return

    if count == n - 1:   # 모든 도시를 다 방문했다면 0(출발도시)으로 돌아올 수 있는지 확인
        if matrix[curr_city][0] > 0:
            answer = min(answer, cost + matrix[curr_city][0])
        return

    for next_city in range(n):
        if visited[next_city] or matrix[curr_city][next_city] == 0:
            continue
        visited[next_city] = True
        backtracking(count + 1, next_city, cost + matrix[curr_city][next_city])
        visited[next_city] = False

    return


# 입력
n = int(input())
matrix = [list(map(int, input().split())) for _ in range(n)]

visited = [False] * n
answer = MAX

visited[0] = True
backtracking(0, 0, 0)   # 0에서 출발해 n - 1개 도시를 방문
print(answer)