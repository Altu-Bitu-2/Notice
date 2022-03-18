import sys
from collections import Counter
input = sys.stdin.readline

"""
 [팰린드롬 만들기] - 단순 구현 문제
 팰린드롬 문자열은 part1(part3의 대칭) + part2(최대 1글자) + part3(part1의 대칭)으로 이루어진다.
 1. 팰린드롬 문자열을 만들기 위해, 각 알파벳이 몇 개씩 존재하는지 리스트에 저장한다.
 2. 사전순으로 앞선 팰린드롬 수를 만들어야 하므로, 'A'부터 시작해서 part1을 문자의 개수에 맞춰 더해나간다.
 3. 만약 알파벳의 개수가 홀수인 경우, part2에 할당하고, 이미 part2에 문자가 있는 경우엔 팰린드롬을 만들 수 없다.
"""

def make_palindrome(text):
    # 각 알파벳의 수를 가지고 팰린드롬 문자열을 리턴하는 함수
    # 만들 수 없으면 "I'm Sorry Hansoo" 리턴
    part1 = ""
    part2 = ""

    # Counter(text): 각 문자가 몇개씩 들어있는지 dictionary 형태로 돌려줌
    # .items() : key와 value를 짝 지어서 돌려줌
    # sorted - 사전적으로 가장 앞서는 문자열을 만들기 위해 정렬
    alphabets = sorted(Counter(text).items())

    for key, value in alphabets:
        if value % 2 == 1:
            # 만약 가운데 글자가 있다면 더 이상 불가능
            if (len(part2) == 1):
                # 주의! 문자열에 '가 들어있기 때문에, ""로 감싸주어야 합니다.
                return "I'm Sorry Hansoo"
            # 비어있다면, 할당
            part2 = key
        
        part1 += key * (value//2)
    
    return part1 + part2 + part1[::-1]

# 입력
text = input().rstrip()

# 연산 + 출력
print(make_palindrome(text))