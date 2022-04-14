import sys
from itertools import permutations
input = sys.stdin.readline

"""
[야구]

1. 가능한 모든 배치를 구한다.
    - 이때, 4번 타자는 항상 1번 선수(0번 인덱스)여야 함을 주의
2. 구한 배치에 대해 점수를 계산
    - out이 3번을 기록하여 이닝이 바뀔 때, 이전에 베이스에 있던 선수들을 비워주어야 함
    - 선수 인덱스를 갱신하는 과정에서 인덱스 에러가 나지 않도록 모듈러 연산 해주기
"""

# 구한 순서에 대해 점수를 계산
def calc_score(order, result):
    player = 0
    score = 0

    # result의 한 행이 inning이 되고, 
    for inning in result:
        out = 0
        base1 = base2 = base3 = 0
        while out < 3:
            p = inning[order[player]] # 이번 타자의 포인트
            if p == 0:
                out += 1
            elif p == 1:
                score += base3
                base3 = base2
                base2 = base1
                base1 = 1
            elif p == 2:
                score += base3 + base2
                base3 = base1
                base2 = 1
                base1 = 0
            elif p == 3:
                score += base3 + base2 + base1
                base3 = 1
                base2 = base1 = 0
            else:
                score += base3 + base2 + base1 + 1
                base3 = base2 = base1 = 0
            # 다음 타자로 바꿔 줌
            player = (player + 1) % 9                        

    return score


# 입력
n = int(input())
result = [list(map(int, input().split())) for _ in range(n)]    # 각 이닝별 득점결과
answer = 0


# 가능한 모든 배치를 구하되, 1번타자(0번 인덱스)는 고정되어 있음을 주의
for order in permutations(range(1, 9), 8):
    order = list(order)
    order.insert(3, 0)
    # 최댓값 갱신
    answer = max(answer, calc_score(order, result))

print(answer)