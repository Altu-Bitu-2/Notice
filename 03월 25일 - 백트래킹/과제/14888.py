import sys
sys.stdin.readline

"""
[연산자 끼워넣기]
연산자를 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
"""

MAX = 10**9

add = lambda x, y: x + y
sub = lambda x, y: x - y
multiply = lambda x, y: x * y

# C++14 방식에 맞추어 나누기 함수 작성
def division(x, y):
    if x < 0:
        return - (-x // y)
    return x // y

# 인덱스에 맞는 연산을 하기 위해 함수를 리스트에 저장
functions = [add, sub, multiply, division]

# cnt: 수 인덱스, value: 현재까지 연산 결과
def backtracking(cnt, value):
    global max_value, min_value
    if cnt == n:    # 연산이 모두 완료 되었다면
        max_value = max(max_value, value)
        min_value = min(min_value, value)
        return

    for i in range(4):
        if operator[i] > 0:
            operator[i] -= 1
            backtracking(cnt + 1, functions[i](value, numbers[cnt]))    # i번째 함수에 value와 numbers[cnt]를 인자로 넘겨주어 계산함
            operator[i] += 1
    return

# 입력
n = int(input())
numbers = list(map(int, input().split()))
operator = list(map(int, input().split()))

max_value = -MAX   # 현재까지 최대값 기록
min_value = MAX    # 현재까지 최솟값 기록

# 연산
backtracking(1, numbers[0])
# 출력
print(max_value, min_value, sep='\n')