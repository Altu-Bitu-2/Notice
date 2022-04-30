import sys
from collections import deque
input = sys.stdin.readline

"""
[인구이동]

0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
3. 인구이동이 전혀 일어나지 않을 때까지 반복

"""

def bfs(n, left, right, i, j, day):
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    que = deque()
    que.append((i, j))
    total = 0   # 연합의 인구 수 합계
    count = 0   # 연합에 포함된 나라의 수
    cord = []   # 연합에 포함된 나라의 좌표
    
    while que:
        r, c = que.popleft()
        count += 1
        total += board[r][c]
        cord.append((r, c))

        for x in range(4):
            new_r = r + dr[x]
            new_c = c + dc[x]
            if not (0 <= new_r < n and 0 <= new_c < n) or visited[new_r][new_c] == day:
                continue

            # 이 때 여기서 visited에 표기를 하면 안됨
            # 현재는 조건에 맞지 않지만, 이후에 연합에 있는 다른 나라에 의해 연합에 들어올 수 있음

            if left <= abs(board[new_r][new_c] - board[r][c]) <= right:
                que.append((new_r, new_c))
                visited[new_r][new_c] = day

    # 적어도 나라 2개 이상이 모여야 연합을 이루었다고 볼 수 있음
    if count > 1:
        avg = total // count
        # 인구 이동
        for r, c in cord:
            board[r][c] = avg
            # 인구의 이동이 있는 나라는 다음 이동이 시작될 가능성이 있음
            countries.append((r, c))
    
    return count > 1

def simulation(n, left, right):
    day = 0
    while True:
        size = len(countries)   # 이번에 탐색할 수 있는 나라의 수
        flag = False
        day += 1
        for _ in range(size):
            i, j = countries.popleft()
            if visited[i][j] == day:
                continue
            visited[i][j] = day
            if bfs(n, left, right, i, j, day):   # bfs 결과 true면 연합을 이루었다는 의미이므로 flag 표시
                flag = True

        if not flag:
            return day - 1

# 입력
n, left, right = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

# 방문배열
visited = [[0]*n for _ in range(n)]
# 나라
countries = deque([(i, j) for i in range(n) for j in range(n)])

# 연산 + 출력
print(simulation(n, left, right))