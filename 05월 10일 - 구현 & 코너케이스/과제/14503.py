import sys
input = sys.stdin.readline

"""
 [로봇 청소기]

 board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미

 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
"""

def cnt_clean_robot(r, c, d, board):
    # 상, 우, 하, 좌
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]

    step = ans = 0

    while True:
        if board[r][c] == 0:
            board[r][c] = 2
            ans += 1

        if step == 4:
            if board[r - dr[d]][c - dc[d]] == 1:
                return ans
                
            r -= dr[d]
            c -= dc[d]
            step = 0
        else:
            d = (d + 3) % 4
            if board[r + dr[d]][c + dc[d]]:
                step += 1
                continue

            r += dr[d]
            c += dc[d]
            step = 0

# 입력
n, m = map(int, input().split())
r, c, d = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]

# 연산 + 출력
print(cnt_clean_robot(r, c, d, board))