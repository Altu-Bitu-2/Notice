import sys
from itertools import permutations
input = sys.stdin.readline

"""
 [숫자 야구]
 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수

 [풀이]
 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 질문 n의 범위는 최대 100
 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
"""

def count_strike_ball(s1, s2):
    # a가 답이라고 가정하고, b에 대한 스트라이크와 볼 수를 세서 리턴한다.
    strike = 0
    ball = 0
    for i in range(3):
        if s2[i] == s1[i]:  # 위치와 숫자가 모두 맞으면
            strike += 1
        elif s2[i] in s1:   # 숫자는 있지만 위치가 다르면
            ball += 1

    return (strike, ball)

# 반복문으로 직접 경우의 수 구하는 함수
def play_game(questions):

    answer = 0

    for i in range(123, 987 + 1):
        s1 = str(i)
        # 0은 포함되지 않음
        if '0' in s1:
            continue
        # 같은 수를 중복해서 사용할 수 없음
        if s1[0] == s1[1] or s1[0] == s1[2] or s1[1] == s1[2]:
            continue

        answer += 1 # 정답 후보 +1
    
        for s2, count in questions:
            if count_strike_ball(s1, s2) != count:
                answer -= 1     # 조건을 만족하지 않기 때문에, 후보에서 제외하고 break
                break

    return answer

# permutation 이용해서 경우의 수 구하는 함수
def play_game_with_permutations(questions):
    digits = [str(i) for i in range(1, 10)]
    
    answer = 0

    for s1 in permutations(digits, 3):
        answer += 1
        for s2, count in questions:
            if count_strike_ball(s1, s2) != count:
                answer -= 1
                break

    return answer

# 입력
n = int(input())
# 세자리 수는 string, 스트라이크와 볼 수는 int형으로 tuple로 묶어서 저장
initialize_input = lambda x: (x[0], (int(x[1]), int(x[2])))
questions = [initialize_input(input().split()) for _ in range(n)]

# 연산 + 출력
print(play_game_with_permutations(questions))