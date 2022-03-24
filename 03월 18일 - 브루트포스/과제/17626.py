import sys
from itertools import combinations_with_replacement # 중복선택이 가능한 조합
input = sys.stdin.readline

"""
[Four Squares]
자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
미리 최댓값까지의 제곱수를 구해놓고, 완전탐색

1. 답이 1인 경우, n이 제곱수인지만 확인해서 찾을 수 있다.
2. 2개와 3개 조합으로 불가능한 경우, 답은 무조건 4가 된다 -> 4개의 합은 시도해보지 않아도 된다.

sqrt(50000) = 약 223
전체 연산 수  < 223^2 + 223^3 = 11139296 <1억 -> 브루트포스 가능
"""

MAX = 50000

def find_min_number(n):
    squares = [i*i for i in range(1, int(MAX**(1/2))+1)]

    # 만약 n이 제곱수라면
    if (int(n**(1/2)))**2 == n:
        return 1
    
    # 2, 3
    for num in range(2, 4):
        # combinations_with_replacement() -> 중복조합
        combi = combinations_with_replacement(squares, num)
        sum_list = list(map(lambda x:sum(x), combi))    # 모든 조합의 합 구하기
        if n in sum_list:
            return num
        
    # 1,2,3이 아니라면
    return 4

# 입력
n = int(input())
# 연산 + 출력
print(find_min_number(n))