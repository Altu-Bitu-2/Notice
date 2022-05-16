import sys
input = sys.stdin.readline
MAX = 1000

"""
 [테트로미노]

 1. 보라색 블럭을 제외하고는 모두 한붓 그리기로 그릴 수 있음
    -> 일반적인 백트래킹으로 모양을 만들 수 있음
 2. 보라색 블럭은 3개의 블럭이 결정된 이후에, 가운데에서 탐색을 해야 만들 수 있음
    -> 3번째 블럭을 결정하면서 현재 좌표를 갱신하지 않고, 직전 좌표에서 다시 한번 백트래킹을 진행하여 얻을 수 있음
 3. 각 블럭에 대해 깊이가 4인 백트래킹 함수를 수행하며 최댓값 갱신

 방문처리 -> board를 활용해서 0을 저장하는 것으로
 가지치기 -> 현재 탐색이 남은 칸을 모두 MAX라 해도 ans이 더 큰 경우
"""

# 한붓 그리기가 가능한 블럭들 백트래킹 탐색
def backtracking(row, col, cnt, total):
    global ans  # 전역변수 값에 업데이트가 있으므로 

    # 기저조건 : 4개의 블럭을 탐색함
    if cnt == 4:
        ans = max(ans, total)
        return

    if ans >= MAX * (4 - cnt) + total:
        return

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    for i in range(4):
        nr = row + dr[i]
        nc = col + dc[i]

        # 범위를 벗어나거나, 이미 방문 했다면
        if not (0 <= nr < n and 0 <= nc <m) or not board[nr][nc]:
            continue

        if cnt == 2:
            save = board[nr][nc]
            board[nr][nc] = 0
            backtracking(row, col, cnt + 1, total + save)
            board[nr][nc] = save

        save = board[nr][nc]
        board[nr][nc] = 0
        backtracking(nr, nc, cnt + 1, total + save)
        board[nr][nc] = save


# 입력
n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

ans = 0

# 연산
for i in range(n):
    for j in range(m):
        save = board[i][j]
        board[i][j] = 0
        backtracking(i, j, 1, save)     # 모양 처리
        board[i][j] = save

# 출력
print(ans)