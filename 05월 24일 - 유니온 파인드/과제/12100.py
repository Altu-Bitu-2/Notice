import sys
input = sys.stdin.readline

"""
 [2048 (Easy)]

 - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦

 - 상 <-> 하: 행 순서를 뒤집어서 해결
 - 상/하 <-> 좌/우: Transpose Matrix 활용

 - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
       2 2 2
       4 4 4
  -상: 원래 배열에서 상으로 움직이는 함수 실행
       2 2 1    4 4 1
       2 2 2 -> 4 4 2
       4 4 4    0 0 4
  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
       2 2 1    4 4 4    4 4 4
       2 2 2 -> 2 2 2 -> 4 4 2
       4 4 4    2 2 1    0 0 1
  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
       2 2 1    2 2 4    4 4 8
       2 2 2 -> 2 2 4 -> 1 2 4
       4 4 4    1 2 4    0 0 0
  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
       2 2 1    1 2 4    1 4 8
       2 2 2 -> 2 2 4 -> 4 2 4
       4 4 4    2 2 4    0 0 0

 - zip(): 두개 이상의 iterable한 객체를 인자로 받아서, 순서대로 하나씩 묶어서 반환한다.
    ex) zip([1, 2, 3], ['a', 'b', 'c']) -> [1, 'a'], [2, 'b'], [3, 'c']
    따라서 zip의 인자로 각 행을 넣어주면, 행과 열이 바뀐 Transpose matrix가 나오게 된다.
"""

def up(board):
    """
    위로 움직이는 함수
    한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
    이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
    """
    temp = [[0]*n for _ in range(n)]
    for c in range(n):
        idx = 0
        prev = 0
        for r in range(n):
            if not board[r][c]:
                continue
            if board[r][c] == prev:
                temp[idx-1][c] *= 2
                prev = 0
            else:
                temp[idx][c] = board[r][c]
                prev = board[r][c]
                idx += 1

    return temp

def backtracking(cnt, board):
    global ans
    if cnt == 5:
        for line in board:
            ans = max(ans, max(line))
        return

    # Transpose matrix 구하기 (상 -> 좌)
    board_t = list(zip(*board))

    # 상
    backtracking(cnt+1, up(board))
    # 하
    backtracking(cnt+1, up(board[::-1]))
    # 좌
    backtracking(cnt+1, up(board_t))
    # 우
    backtracking(cnt+1, up(board_t[::-1]))

    return

# 입력
n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

ans = 0
backtracking(0, board)

# 출력
print(ans)