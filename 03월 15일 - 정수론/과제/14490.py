import sys
input = sys.stdin.readline

"""
[백대열]
- n과 m의 최대공약수를 찾아서 나눠준다.
"""

def calc_gcd(a, b):
    # a > b일 때, a와 b의 최대공약수를 리턴
    if b == 0:
        return a
    return calc_gcd(b, a % b)

# 입력
n, m = map(int, input().split(':')) # ':' 기준으로 나누기

# 연산 + 출력
gcd = calc_gcd(max(n, m), min(n, m))
# / 로 계산하면 1.0 과 같이 소수점이 표기되므로 주의
print(n // gcd, ':', m // gcd, sep='')