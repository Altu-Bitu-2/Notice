import sys
input = sys.stdin.readline

INF = 10**3
ans = INF

"""
 [게리맨더링]

 1. 구역을 나누는 모든 경우의 수 구하기 - 백트래킹
 - 두 선거구로 나누는 경우이므로 모든 구역에 대해 true/false로 구분해서 경우의 수 구하기
 - 이때, 중복 연산 피하기 위해 1번 구역은 true로 고정. (집합끼리 구분할 필요가 없으므로 1번이 false일 때의 경우의 수는 1번이 true일 때와 정확히 일치)
 2. 각 경우마다 나눈 두 구역이 조건(구역 내 정점이 모두 연결)을 만족하는지 확인 - dfs
 - 구역 내 한 정점에서 dfs 탐색을 시작해서 구역 내의 모든 정점을 방문했다면 조건 만족한 것임
 3. 두 구역이 조건을 만족한다면 인구 수의 차이 구해서 최솟값 갱신
"""

# 두 선거구의 인구 수 차이 구하는 함수
def calc_diff():
    sum1 = sum2 = 0
    for i in range(1, n+1):
        if is_ward[i]:
            sum1 += people[i]
        else:
            sum2 += people[i]

    return abs(sum1 - sum2)

# 선거구 내의 정점 연결됐는지 탐색하는 dfs 함수
def dfs(curr, state):
    if visited[curr]:
        return 0

    visited[curr] = True
    cnt = 1
    for next in graph[curr]:
        if is_ward[next] == state:
            cnt += dfs(next, state)
    
    return cnt

def backtracking(cnt, true_area):
    global visited, ans
    # (기저조건) 모든 구역 탐색
    if cnt == n+1:
        if true_area == n:
            return
            
        false_node = is_ward.index(False)

        visited = [False] * (n+1)
        if true_area == dfs(1, True) and n - true_area == dfs(false_node, False):
            ans = min(ans, calc_diff())
        return

    is_ward[cnt] = False
    backtracking(cnt + 1, true_area)
    is_ward[cnt] = True
    backtracking(cnt + 1, true_area + 1)
    return


# 입력

n = int(input())
people = list(map(int, ("0 " + input()).split()))
graph = [list() for _ in range(n+1)]    # 인접리스트
is_ward = [False] * (n+1)

for i in range(1, n+1):
    graph[i] = list(map(int, input().split()[1:]))

# 연산
is_ward[0] = is_ward[1] = True    # 1번 구역 고정
backtracking(2, 1)

# 출력
if ans == INF:
    print(-1)
else:
    print(ans)