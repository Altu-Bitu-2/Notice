import sys
input = sys.stdin.readline

"""
[골드바흐의 추측]
1. 에라토스테네스의 체를 활용하여 최댓값까지의 소수를 미리 탐색한다.
2. 가능한 소수의 차이가 커야 하므로, 작은 수부터 탐색하다가 골드바흐의 추측을 만족하면 바로 종료한다.
"""

MAX = 1000000

def find_prime():
    # 소수인지 여부를 판단해서 리스트 형태로 돌려주는 함수
    is_prime = [True] * (MAX + 1)

    root_MAX = MAX**(1/2)
    
    for i in range(2, int(root_MAX)+1):
        # i가 소수라면
        if is_prime[i]:
            for j in range(i*i, MAX, i):
                is_prime[j] = False
    
    # 소수가 아닌 것들을 표기
    # 이 문제에서는 홀수인 소수만을 취급하므로 2도 제외
    is_prime[0] = is_prime[1] = is_prime[2] = False

    return is_prime  

# 소수를 찾는 과정은 한번만 한다. -> 반복문 밖에서 함수 호출
is_prime = find_prime()

while True:
    n = int(input())
    if n == 0:
        break
    
    # 3부터 n//2까지 홀수만 검사
    # n//2 + 1 이상에서의 탐색은 필요 없음.
    for i in range(3, n//2 + 1, 2):
        # i와 n-i가 둘 다 소수이면 더해서 n이 되는 두 소수를 찾은 것이므로 종료
        if is_prime[i] and is_prime[n-i]:
            print(n, '=', i, '+', n-i)
            break
    # for-else문: for문이 break에 의해 종료되지 않고, 반복문이 끝까지 돌아 정상 종료된 경우 else문으로 들어갑니다.
    else:
        print("Goldbach's conjecture is wrong.")