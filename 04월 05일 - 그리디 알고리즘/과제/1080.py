import sys
input = sys.stdin.readline

"""
[행렬]
- (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
- A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
- 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 !주의! string은 immutable하므로, 입력을 받고 리스트 등으로 변환해 한 글자씩 나눠주어야 함.
"""

# 부분행렬 뒤집는 함수
def flip_square(row, col, matrix):
    for x in range(row, row+3):
        for y in range(col, col+3):
            matrix[x][y] = 1 - matrix[x][y]
    return

# 두 행렬이 같은지 확인하는 함수
def is_same(n, m, matrix_A, matrix_B):
    for i in range(n):
        for j in range(m):
            if matrix_A[i][j] != matrix_B[i][j]:
                return False
    return True

# 입력
n, m = map(int, input().split())

matrix_A = [list(map(int, list(input().rstrip()))) for _ in range(n)]
matrix_B = [list(map(int, list(input().rstrip()))) for _ in range(n)]

count = 0   # 뒤집는 횟수

for i in range(n-2):
    for j in range(m-2):
        if matrix_A[i][j] != matrix_B[i][j]:
            flip_square(i, j, matrix_A)
            count += 1

# 출력
if is_same(n, m, matrix_A, matrix_B):
    print(count)
else:
    print(-1)