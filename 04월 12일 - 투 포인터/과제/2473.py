import sys
input = sys.stdin.readline
INF = 10**9 * 3 + 1

"""
 2470번 : 두 용액 섞기
 2473번 : 세 용액 섞기

 [세 용액]

 1. 하나의 용액을 반드시 사용한다고 가정
 2. 용액 하나 고정
 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용

 pair : 2개의 값 저장
 tuple : 3개의 값 저장

 !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
"""

# 다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
def find_liquid(n, arr):
    min_diff = INF
    ans = []

    for fixed in range(n-2):
        p1 = fixed + 1
        p2 = n - 1

        while p1 < p2:
            mixed = arr[p1] + arr[p2] + arr[fixed]
            if mixed == 0:
                return [arr[fixed], arr[p1], arr[p2]]

            if abs(mixed) < min_diff:
                ans = [arr[fixed], arr[p1], arr[p2]]
                min_diff = abs(mixed)

            if mixed < 0:
                p1 += 1
            else:
                p2 -= 1

    return ans

# 입력
n = int(input())
arr = list(map(int, input().split()))
arr.sort()

# 출력
print(*find_liquid(n, arr))