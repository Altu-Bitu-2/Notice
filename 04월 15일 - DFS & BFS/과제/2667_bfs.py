import sys
from collections import deque
input = sys.stdin.readline

"""
[단지 번호 붙이기] - bfs

- 단순 탐색
- (주의) 단지 내 집의 수를 "오름차순"으로 출력

- 이 풀이에서는 방문체크 배열을 따로 사용하지 않고, 처음 지도에 표기를 1 -> 0으로 바꾸어 중복으로 탐색하지 않도록 함
"""

def bfs(i, j, n, matrix):
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    que = deque()
    que.append((i, j))
    count = 1

    while que:
        r, c = que.popleft()
        for x in range(4):
            new_r = r + dr[x]
            new_c = c + dc[x]
            # 새 좌표가 범위에 맞지 않거나, matrix에 0으로 표기되어 있으면 건너 뜀
            if not (0 <= new_r < n and 0 <= new_c < n) or not matrix[new_r][new_c]:
                continue
            matrix[new_r][new_c] = 0
            que.append((new_r, new_c))
            count += 1

    return count

# 입력
n = int(input())
matrix = [list(map(int, input().rstrip())) for _ in range(n)]

apartment = []  # 단지 수 저장할 리스트

for i in range(n):
    for j in range(n):
        if not matrix[i][j]:
            continue
        matrix[i][j] = 0
        apartment.append(bfs(i, j, n, matrix))

apartment.sort()    # 정렬

# 출력
print(len(apartment))
print(*apartment, sep='\n')