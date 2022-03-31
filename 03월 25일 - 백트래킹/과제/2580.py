import sys
input = sys.stdin.readline

"""
 가지치기 효율: 80ms

 9X9의 스도쿠에서 각 행, 열, 3x3 사각형에 1~9가 존재하는지 체크하는 2차원 배열 활용
 각 2차원 배열의 행: 어느 부분에 대한 체크인지(행, 열, 3x3), 0번 인덱스부터 시작
 각 2차원 배열의 열: 1 ~ 9 숫자 체크

 행과 열은 바로 사용하면 됨
 (ex) check_row[3][2] = true;  //3행에 2라는 숫자가 존재한다는 것
      check_col[8][9] = false; //8열에 9라는 숫자가 존재하지 않는다는 것

 3x3 사각형 (하나를 각 구역이라고 표현)
 -> 행을 3으로 나눈 몫과 열을 3으로 나눈 몫으로 구역 0부터 8까지 다음과 같이 나타낼 수 있음
 (0,0) (0,1) (0,2)
 (1,0) (1,1) (1,2)
 (2,0) (2,1) (2,2)
 -> 1차원 배열 인덱스로 구분하기 위해 각 (행 / 3)값에 3을 곱한 후 (열 / 3)을 더함
 -> 따라서 3x3 사각형의 구간은 (row / 3) * 3 + (col / 3) = 0 ~ 8인 구간으로 나눌 수 있음
"""

SIZE = 9    # 스도쿠 한 행 사이즈
check_row = [[False] * (SIZE + 1) for _ in range(SIZE)]     # 각 행의 숫자 존재 여부 체크
check_col = [[False] * (SIZE + 1) for _ in range(SIZE)]     # 각 열의 숫자 존재 여부 체크
check_3x3 = [[False] * (SIZE + 1) for _ in range(SIZE)]     # 각 3x3 사각형의 숫자 존재 여부 체크

def calc_area(x, y):
    return (x // 3) * 3 + y // 3

def fill_sudoku(cnt):
    if cnt == SIZE * SIZE:
        return True
    
    x, y = cnt // SIZE, cnt % SIZE

    if sudoku[x][y] > 0:    # 이미 숫자가 채워진 칸이라면 다음 칸으로 넘어감
        return fill_sudoku(cnt + 1)

    for i in range(1, SIZE + 1):    # 1~9까지 넣어보기
        if check_row[x][i] or check_col[y][i] or check_3x3[calc_area(x, y)][i]:
            continue

        check_row[x][i] = True
        check_col[y][i] = True
        check_3x3[calc_area(x, y)][i] = True
        sudoku[x][y] = i

        if fill_sudoku(cnt + 1):    # 생각해보기 : 이 부분이 없으면 어떻게 될까요?
            return True

        check_row[x][i] = False
        check_col[y][i] = False
        check_3x3[calc_area(x, y)][i] = False
        sudoku[x][y] = 0

    return False

# 입력
sudoku = [list(map(int, input().split())) for _ in range(SIZE)]

# 스도쿠 상태 표시
for i in range(SIZE):
    for j in range(SIZE):
        if sudoku[i][j] == 0:
            continue
        check_row[i][sudoku[i][j]] = True
        check_col[j][sudoku[i][j]] = True
        check_3x3[calc_area(i, j)][sudoku[i][j]] = True

# 연산
fill_sudoku(0)

# 출력
for line in sudoku:
    print(*line)    # *list -> 리스트의 요소를 하나씩 풀어서 print()에 인자로 넣어줌
                    # print(*[1, 2, 3]) == print(1, 2, 3)