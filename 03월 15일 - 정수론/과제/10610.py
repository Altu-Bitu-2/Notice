import sys
input = sys.stdin.readline

"""
[30]
30의 배수 = 10의 배수 && 3의 배수
1. 10의 배수 -> 입력된 수에 0이 포함되어 있는지 확인
2. 3의 배수 -> 모든 자리수의 합이 3의 배수인지 확인

30의 배수임이 확인 되었으면,
가장 큰 수를 만들기 위해 9부터 0까지 역순으로 나열한다.
"""

def find_number(n):
    digits = list(n)
    digits.sort(reverse=True)   # 가장 큰 수를 만들기 위해 역순으로 정렬

    # 0이 존재하지 않으면, return -1
    if digits[-1] != '0':
        return -1
    
    total = 0   # 3의 배수인지 확인하기 위해 모든 자리수를 더함

    for i in digits:
        total += int(i)

    # 3의 배수임을 확인
    if total % 3 == 0:
        return ''.join(digits)
    else:
        return -1

# 입력
n = input().rstrip()
# 연산 + 출력
print(find_number(n))