import sys
from collections import deque
input = sys.stdin.readline

"""
[Puyo Puyo] - bfs, 시뮬레이션 문제

1. bfs 탐색을 통해 4개 이상의 뿌요가 모였는지 확인
2. 4개 이상의 뿌요가 모였다면, 해당되는 영역을 '.'으로 바꾸어 비워줌
3. 전체 필드에 대해 1~2를 다 수행한 후, 뿌요를 떨어뜨림
    - 바닥부터 시작해서 남아있는 뿌요들을 모으고, 남은 부분은 '.'으로 채우는 방식
4. 터뜨릴 수 없을 때까지 반복

여기서, 3번 과정을 편하게 하기 위해 12*6으로 들어오는 입력을 6*12로 바꾸어준다.
같은 열에 있는 데이터를 다루는 것보다 같은 행에 있는 데이터를 다루는 것이 편하기 때문이다.
"""

# 행과 열을 바꾸어 사용하므로 ROW를 6, COL은 12로 설정
ROW = 6
COL = 12

def bfs(i, j):
    dr = [-1, +1, 0, 0]
    dc = [0, 0, -1, +1]
    que = deque()
    
    que.append((i, j))
    visited = [[False]*COL for _ in range(ROW)]
    visited[i][j] = True
    color = board[i][j]
    count = 1   # 모여있는 뿌요의 개수
    cords = []  # 포함된 좌표 저장할 리스트

    while que:
        cords.append(que[0])
        r, c = que.popleft()
        for x in range(4):
            nr, nc = r+dr[x], c+dc[x]
            if not (0 <= nr < ROW and 0 <= nc < COL):
                continue
            if not visited[nr][nc] and board[nr][nc] == color:
                visited[nr][nc] = True
                que.append((nr, nc))
                count += 1
    
    if count < 4:
        return False

    for r, c in cords:
        board[r][c] = '.'

    return True

# 뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
def make_new_board(board):
    new_board = []
    for i in range(ROW):
        temp = []
        for j in range(COL):
            # 남아있는 뿌요를 임시 리스트에 모으기
            if board[i][j] != '.':
                temp.append(board[i][j])
        # 비어 있는 부분을 '.'로 채우기
        while len(temp) < COL:
            temp.append('.')
        new_board.append(temp[:])
    return new_board

# 입력
board = [[None]*COL for _ in range(ROW)]

# 행과 열을 바꾸어 저장
for i in range(COL):
    line = input().rstrip()
    for j in range(ROW):
        board[j][12-i-1] = line[j]
        
ans = 0

while True:
    flag = False
    for i in range(ROW):
        for j in range(COL):
            if board[i][j] == '.':
                continue
            if bfs(i, j):
                flag = True
    
    if not flag:
        break
    ans += 1
    board = make_new_board(board)

print(ans)