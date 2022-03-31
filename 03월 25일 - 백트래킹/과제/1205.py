import sys
input = sys.stdin.readline

"""
[등수 구하기]

1. n = 0일 때, 고려
2. 등수는 p보다 작지만, 랭킹 리스트에 들어가지 못하는 경우 고려

.find(value): value가 있는 첫번째 인덱스를 리턴, 없으면 에러 발생
입력된 점수를 기존 리스트에 넣고 인덱스 구하기 -> 해당 점수의 첫번째 인덱스 리턴
.count(value): 리스트에서 value의 수를 세어 리턴, 없으면 에러 발생
전체 점수 중 동점자의 수 구하기 -> 첫번째 등수(인덱스 + 1) + 동점자 수 - 1 
                                = 첫번째 인덱스 + 동점자 수 
                                = 해당 점수의 마지막 등수

마지막 등수가 p를 넘지 않으면, 첫번째 인덱스로 구한 등수가 정답
"""

# 입력
n, new_score, p = map(int, input().split())

if n == 0:
    answer = 1
else:
    # 입력
    scores = list(map(int, input().split()))
    
    # 해당 점수의 가장 상위 등수 구하기
    scores.append(new_score)
    scores.sort(reverse=True)
    first_idx = scores.index(new_score)

    # 동점자가 몇 명 있는지 구하기
    same_score = scores.count(new_score)

    if first_idx + same_score <= p:
        answer = first_idx + 1
    else: # 이미 스코어 보드가 다 찬 경우
        answer = -1

print(answer)