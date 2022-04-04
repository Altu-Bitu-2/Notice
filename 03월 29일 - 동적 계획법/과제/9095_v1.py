import sys
input = sys.stdin.readline

"""
 [bottom-up 접근]
 각 수를 인덱스로 써서 정수 10까지 1, 2, 3의 합으로 나타내는 방법의 수를 저장하자!

 우선 3까지 1, 2, 3의 합으로 나타내는 방법의 수 초기화 함
 해당 인덱스에서 -1, -2, -3 한 인덱스에 +1, +2, +3을 해줬다고 생각하면 됨

 -> dp[n] = dp[n - 1] + dp[n - 2] + dp[n - 3] (n >= 3)

 해당 풀이는 인덱스 관리를 편하게 하기 위해 0을 더미 인덱스로 줘서 인덱스 3부터 연산
"""

MAX_N = 10

def number_of_all_cases():
    dp = [0] * (MAX_N + 1)
    dp[0] = dp[1] = 1
    dp[2] = 2

    for i in range(3, MAX_N + 1):
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

    return dp

# 사전 연산
dp = number_of_all_cases()   # 10까지 모든 경우의 수를 미리 구해 둠

# 입력
t = int(input())

# 입력 + 출력
for _ in range(t):
    n = int(input())
    print(dp[n])