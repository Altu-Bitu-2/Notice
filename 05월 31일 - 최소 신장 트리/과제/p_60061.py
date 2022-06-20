"""
[기둥과 보 설치]

들어오는 입력에 대해 설치 또는 삭제 이후에도 기본 조건에 만족하는지 확인

[기본 조건]
1. 기둥
    a. 바닥 위
    b. 보의 한 쪽 끝
    c. 다른 기둥 위
2. 보
    a. 한쪽 끝이 기둥 위
    b. 양쪽 끝이 보와 연결

- 설치: 설치하려는 좌표가 조건을 만족하는지 확인
- 삭제: 해당 기둥/보를 삭제했을 시 영향을 받는 인접한 기둥/보가 여전히 조건을 만족하고 있는지 확인
"""

board = []

# 현재 상태가 조건에 만족하는지 (x, y) 중심으로 확인 
def validate(x, y, a, n):
    # 기둥
    if a == 0:
        # 바닥 위
        if y == 0:
            return True
        # 보의 왼쪽/오른쪽 끝
        if board[x][y][1] or (x > 0 and board[x-1][y][1]):
            return True
        # 기둥 위
        if y > 0 and board[x][y-1][0]:
            return True
        
    # 보
    else:
        # 왼쪽 끝이 기둥 위
        if y > 0 and board[x][y-1][0]:
            return True
        # 오른쪽 끝이 기둥 위
        if x < n and y > 0 and board[x+1][y-1][0]:
            return True
        # 양쪽 끝이 보와 연결
        if 0 < x < n-1 and board[x-1][y][1] and board[x+1][y][1]:
            return True
        
    return False

# (x, y)에 있는 구조물을 삭제할 수 있는지 확인
def check_removable(x, y, n):
    # 기둥이 삭제된 경우, 해당 기둥 위에 보가 있었을 수 있으므로 (조건 2-b) 대각선도 확인이 필요
    for dx in (-1, 0, 1):
        for dy in (-1, 0, 1):
            nx, ny = x+dx, y+dy
            if not (0<= nx <= n and 0 <= ny <= n):
                continue
            for j in range(2):
                if board[nx][ny][j] and not validate(nx, ny, j, n):
                    return False

    return True

def solution(n, build_frame):
    global board
    
    board = [[[False] * 2 for _ in range(n+1)] for _ in range(n+1)] # 현재 설치 현황
    answer = []

    for x, y, a, b in build_frame:
        # 삭제
        if b == 0:
            board[x][y][a] = False
            # 삭제할 수 없으면
            if not check_removable(x, y, n):
                board[x][y][a] = True
        # 설치
        else:
            # 설치 가능한 경우
            if validate(x, y, a, n):
                board[x][y][a] = True
                
    for i in range(n+1):
        for j in range(n+1):
            for k in range(2):
                if board[i][j][k]:
                    answer.append([i, j, k])
    return answer

if __name__ == "__main__":
    n = 5
    build_frame = [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]
    print(solution(n, build_frame))