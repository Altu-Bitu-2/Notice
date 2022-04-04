import sys
input = sys.stdin.readline

"""
 dp[i] = 주어진 동전 종류를 사용해서 i원을 만드는 경우의 수

 dp[0] = 1 을 넣고 시작 (0원을 만드는 경우의 수 1로 생각)
 각 동전마다 해당 동전부터 만들어야 하는 금액(m)까지 돌리면서 해당 동전을 사용하기 전 금액의 경우의 수와 현재 경우의 수를 더함
 !주의! 이때, 해당 동전 사용하기 전 금액의 경우의 수가 0이면 금액을 만들 수 없는 경우이므로 더하면 안됨
"""

MAX = 10**4

def count(n, m, coin):
    dp = [0] * (m+1)
    dp[0] = 1

    for c in coin:
        for idx in range(c, m+1):
            dp[idx] += dp[idx - c]

    return dp[m]

# 입력
t = int(input())

for _ in range(t):
    # 입력
    n = int(input())
    coin = list(map(int, input().split()))
    m = int(input())
    # 연산 + 출력
    print(count(n, m, coin))