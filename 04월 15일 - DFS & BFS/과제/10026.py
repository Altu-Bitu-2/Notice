import sys
from collections import deque
input = sys.stdin.readline

"""
[적록색약]

그림의 색을 기준으로 구역을 나누는 문제
1. 적록색약이 아닌 사람 기준으로 구역을 나눈다.
2. 그림의 초록을 모두 빨강으로 바꾼 후, 적록색약인 사람 기준으로 구역을 나눈다.
"""

def bfs(i, j, picture, visited):
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    que = deque()
    que.append((i, j))
    visited[i][j] = True

    while que:
        r, c = que.popleft()
        for x in range(4):
            new_r = r + dr[x]
            new_c = c + dc[x]
            # 새 좌표가 범위에 맞지 않거나, 이미 방문했으면 건너 뜀
            if not (0 <= new_r < n and 0 <= new_c < n) or visited[new_r][new_c]:
                continue
            if picture[new_r][new_c] != picture[r][c]:
                continue
            visited[new_r][new_c] = True
            que.append((new_r, new_c))

    return

def count_area(n, picture):
    visited = [[False]*n for _ in range(n)]
    area = 0

    for i in range(n):
        for j in range(n):
            if visited[i][j]:
                continue
            
            area += 1
            bfs(i, j, picture, visited)
    
    return area

def green_to_red(n, picture):
    for i in range(n):
        for j in range(n):
            if picture[i][j] == 'G':
                picture[i][j] = 'R'
    
    return picture

# 입력
n = int(input())
picture = [list(input().rstrip()) for _ in range(n)]
ans = []

ans.append(count_area(n, picture))
picture = green_to_red(n, picture)
ans.append(count_area(n, picture))

print(*ans)