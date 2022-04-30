import sys
input = sys.stdin.readline

"""
[단지 번호 붙이기] - dfs

- 단순 탐색
- (주의) 단지 내 집의 수를 "오름차순"으로 출력

- 이 풀이에서는 방문체크 배열을 따로 사용하지 않고, 처음 지도에 표기를 1 -> 0으로 바꾸어 중복으로 탐색하지 않도록 함
"""
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def dfs_recursion(r, c, matrix):
    if not (0 <= r < n and 0 <= c < n): # 인덱스 에러 방지
        return 0
    if not matrix[r][c]:    # 집이 있는지 (이미 방문 했는지) 확인
        return 0

    matrix[r][c] = 0    # 방문 표시
    count = 1   # 자기 자신
    
    # 상하좌우로 연결된 집을 모두 더함
    for x in range(4):
        count += dfs_recursion(r + dr[x], c + dc[x], matrix)

    return count

# 입력
n = int(input())
matrix = [list(map(int, input().rstrip())) for _ in range(n)]

apartment = []  # 단지 수 저장할 리스트

for i in range(n):
    for j in range(n):
        if not matrix[i][j]:
            continue
        apartment.append(dfs_recursion(i, j, matrix))

apartment.sort()    # 정렬

# 출력
print(len(apartment))
print(*apartment, sep='\n')