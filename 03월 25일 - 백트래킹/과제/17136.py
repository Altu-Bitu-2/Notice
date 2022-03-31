import sys
input = sys.stdin.readline

"""
1. 붙일 수 있는 색종이의 최소 개수를 구하는 것이므로, 큰 색종이부터 붙여가면서 세어보아야 함
2. 색종이의 개수가 각 5장씩으로 제한되어 있기 때문에, 사용한 색종이의 개수를 기록해야 함
"""

SIZE = 10
MAX = 26

# (r, c)부터 시작해서 paper_size크기의 색종이를 붙일 수 있는지 확인하는 함수
def promising(r, c, paper_size):
    for i in range(r, r + paper_size):
        for j in range(c, c + paper_size):
            if board[i][j] == 0:
                return False
    return True

# board의 (r, c)부터 시작해서 paper_size크기를 num으로 채우는 함수
def fill_board(r, c, paper_size, num):
    for i in range(r, r + paper_size):
        for j in range(c, c + paper_size):
            board[i][j] = num
    return

def backtracking(idx, count):
    global answer   # 전역변수 사용
    
    if count > answer:
        return

    if idx == SIZE * SIZE:
        answer = min(answer, count)
        return

    x, y = idx // SIZE, idx % SIZE  # x행 y열
    
    if board[x][y] == 0:    # 현재 칸이 0이라면 넘어감
        backtracking(idx + 1, count)
        return

    for i in range(5, 0, -1):
        if x + i > SIZE or y + i > SIZE:
            continue
        if promising(x, y, i) and paper_cnt[i] > 0:
            paper_cnt[i] -= 1
            fill_board(x, y, i, 0)
            backtracking(idx + i, count + 1)
            paper_cnt[i] += 1
            fill_board(x, y, i, 1)

    return

# 입력
board = [list(map(int, input().split())) for _ in range(SIZE)]

paper_cnt = [5] * 6 # 남은 색종이의 수 (index 1~5 사용)
answer = MAX    # 최솟값 갱신할 변수

# 연산
backtracking(0, 0)

if answer == MAX: # 불가한 경우
    print(-1)
else:
    print(answer)