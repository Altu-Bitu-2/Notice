import sys
input = sys.stdin.readline

"""
 [top-down 접근]
 n부터 시작해서 -1, -2, -3한 수의 경우의 수 먼저 구함
 0미만일 경우 합으로 나타낼 수 없는 경우이므로 0 리턴
 이미 dp[n] 값이 있을 경우, 바로 리턴
"""

MAX_N = 10
dp_top = [0] * (MAX_N + 1)

def number_of_cases_top(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    
    if dp_top[n]:
        return dp_top[n]
    
    for i in range(1, 4):
        dp_top[n] += number_of_cases_top(n-i)

    return dp_top[n]

# 입력
t = int(input())

# 입력 + 연산 + 출력
for _ in range(t):
    n = int(input())
    print(number_of_cases_top(n))