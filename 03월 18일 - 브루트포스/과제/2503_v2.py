import sys
from itertools import permutations
input = sys.stdin.readline

"""
 [숫자 야구]
 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수

 [풀이]
 들어오는 모든 질문에 대해, 영수의 답과 일치하지 숫자만 남긴다.
 끝까지 남아 있는 숫자가 가능한 답의 경우의 수가 된다.
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

def count_answer(questions):
    digits = [str(i) for i in range(1, 10)]
    numbers = set(permutations(digits, 3))
    
    for s1, count in questions:
        temp = set()    # 주의! 여기서 temp.clear()를 쓰면 numbers가 가 같이 비워지게 됩니다.
        for s2 in numbers:
            if count_strike_ball(s1, s2) == count:
                temp.add(s2)
        numbers = temp

    return len(numbers)

# 입력
n = int(input())
# 세자리 수는 string, 스트라이크와 볼 수는 int형으로 tuple로 묶어서 저장
initialize_input = lambda x: (x[0], (int(x[1]), int(x[2])))
questions = [initialize_input(input().split()) for _ in range(n)]

# 연산 + 출력
print(count_answer(questions))