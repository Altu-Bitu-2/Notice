import sys
input = sys.stdin.readline

"""
 [회전 초밥]

 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
"""

def choose_sushi(n, d, k, c, belt):
    sushi = [0]*(d+1)   # 각 인덱스의 초밥 개수

    # 쿠폰으로 먹게 되는 초밥
    sushi[c] = 1
    count = 1

    # 윈도우 초기화
    for i in range(k):
        if sushi[belt[i]] == 0:
            count += 1
        sushi[belt[i]] += 1

    ans = count

    # 슬라이딩 윈도우
    for idx in range(k, n+k):
        sushi[belt[idx - k]] -= 1
        if sushi[belt[idx - k]] == 0:
            count -= 1
        
        if sushi[belt[idx % n]] == 0:
            count += 1
        sushi[belt[idx % n]] += 1
        
        ans = max(ans, count)

    return ans

# 입력
n, d, k, c = map(int, input().split())
belt = [int(input()) for _ in range(n)]
# 연산 + 출력
print(choose_sushi(n, d, k, c, belt))