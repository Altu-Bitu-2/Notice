import sys
input = sys.stdin.readline

"""
[공약수]
최대공약수: gcd, 최소공배수: lcm

gcd * lcm = A * B이고,
A = gcd * a, B = gcd * b로 나타낼 수 있다. (이때, a와 b는 서로소)
따라서 gcd * lcm = A * B = gcd * gcd * a * b,
lcm / gcd = a * b

A+B의 최소 -> a+b의 최소 -> a, b의 차가 최소가 되도록
"""
def calc_gcd(a, b):
    # a > b일 때, a와 b의 최대공약수를 리턴
    if b == 0:
        return a
    return calc_gcd(b, a % b)

gcd, lcm = map(int, input().split())

ab = lcm // gcd
root_ab = ab ** (1/2)

# root(ab)부터 1까지
for i in range(int(root_ab), 0, -1):
    if ab % i > 0:
        continue
    
    a = i
    b = ab // i

    # a와 b가 서로소인지 확인 - a는 항상 b보다 작다
    if calc_gcd(b, a) == 1:
        break

print(a * gcd, b * gcd)