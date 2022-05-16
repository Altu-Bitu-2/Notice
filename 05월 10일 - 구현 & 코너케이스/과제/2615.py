import sys
input = sys.stdin.readline

SIZE = 19

"""
 [오목]

 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 2. (주의) 육목이상이 되는지 확인해야 함
"""

def promising(r, c, stone, board):
    return 0 <= r < SIZE and 0 <= c < SIZE and board[r][c] == stone

def check_dir(r, c, d, board):
    stone = board[r][c]

    # 가로, 세로, 우하향 대각선, 우상향 대각선
    dr = [0, 1, 1, -1]
    dc = [1, 0, 1, 1]

    if promising(r-dr[d], c-dc[d], stone, board):
        return False
    
    cnt = 0 # (r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수

    while cnt < 6 and promising(r, c, stone, board):
        cnt += 1
        r += dr[d]
        c += dc[d]
    
    return cnt == 5

def is_end(r, c, board):
    # 가로, 세로, 우하향 대각선, 우상향 대각선
    for i in range(4):
        if check_dir(r, c, i, board):
            return True
    return False

def simulation(board):
    for i in range(SIZE):
        for j in range(SIZE):
            # 돌이 없는 경우
            if not board[i][j]:
                continue
            # 누군가 이겼으면
            if is_end(i, j, board):
                return "{}\n{} {}".format(board[i][j], i+1, j+1)

    return 0

# 입력
board = [list(map(int, input().split())) for _ in range(SIZE)]
# 연산 + 출력
print(simulation(board))