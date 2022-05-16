import sys
from collections import deque
input = sys.stdin.readline

INF = 401

"""
 [아기 상어]

 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복

 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 가능한 물고기의 최대 마리 수 : 399마리
 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 총 연산 횟수 약 160000번으로 충분히 가능

 해설 : https://myunji.tistory.com/378
 *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
"""

def next_pos(n, shark_size, shark, board):
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    min_dist = INF
    que = deque()   # 상어가 갈 수 있는 곳
    dist = [[0]*n for _ in range(n)]     # 상어로부터의 거리 - 초기값은 0으로
    pos_list = []    # 상어가 먹을 수 있는 물고기들의 위치

    dist[shark[0]][shark[1]] = 1
    que.append(shark)

    while que:
        row, col = que.popleft()

        # 최단거리 이상은 탐색할 필요 없음
        if dist[row][col] >= min_dist:
            continue

        for i in range(4):
            nr = row + dr[i]
            nc = col + dc[i]
            if not (0 <= nr < n and 0 <= nc < n) or dist[nr][nc] or board[nr][nc] > shark_size:
                continue

            dist[nr][nc] = dist[row][col] + 1
            
            # 먹을 수 있는 물고기 발견
            if board[nr][nc] and board[nr][nc] < shark_size:
                pos_list.append((nr, nc))
                min_dist = dist[nr][nc]
                continue
            
            que.append((nr, nc))

    # 상어가 갈 수 있는 곳이 없음
    if not pos_list:
        return min_dist, (-1, -1)

    pos_list.sort()

    return min_dist - 1, pos_list[0]

def simulation(n, shark, board):
    ans = cnt = 0
    size = 2

    while True:
        dist, pos = next_pos(n, size, shark, board)
        # 더 이상 먹을 수 있는 물고기가 공간에 없음
        if dist == INF:
            break
        
        ans += dist
        cnt += 1
        
        # 상어 크기 증가
        if cnt == size:
            cnt = 0
            size += 1

        # 상어 이동
        board[shark[0]][shark[1]] = 0
        shark = pos

    return ans

# 입력
n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    for j in range(n):
        if board[i][j] == 9:
            shark_pos = (i, j)
            break

print(simulation(n, shark_pos, board))