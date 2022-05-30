import sys
input = sys.stdin.readline

"""
 [화살표 연산자]

 1. n이 1보다 큰 홀수인 경우 -> ERROR
 2. n이 1인데 x가 음수인 경우 -> while문 조건 항상 참 -> INFINITE
 3. n이 1인데 x가 양수인 경우 or x가 0보다 작거나 같은 경우 -> while문에 진입 못함 -> 0
 4. n이 0인데 x가 양수인 경우 -> while문 조건 항상 참 -> INFINITE
 5. 나머지 경우엔 (x-1)를 n//2로 나눈 몫을 출력
    - 연산했을 때 1 이상이 남을 때까지만 출력을 할 수 있으므로
"""

def solution(x, n):
    if n > 1 and n % 2:
        return "ERROR"
    if n == 1 and x < 0:
        return "INFINITE"
    if n == 1 or x <= 0:
        return 0
    if n == 0:
        return "INFINITE"
    return (x - 1) // (n // 2)

# 입력
x, n = map(int, input().split())

# 연산 & 출력
print(solution(x, n))