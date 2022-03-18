import sys
input = sys.stdin.readline

"""
 "분배법칙"을 활용!
 ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 =>                               (   [ ]     (   [   ]   )   )
 =>                   임시변수값:  2   6 2     4  12   4   2   1
 =>                        정답:        +6           +12        = 18

 따라서, 우선 여는 괄호가 나오면 괄호의 값을 곱해줌
 닫는 괄호는, 이전 문자가 여는 괄호일 경우 지금까지 곱한 값을 더해줌 (값이 중복으로 더해지는 것을 방지하기 위해 이전 문자가 여는 괄호인지 꼭 체크!)
            한 괄호에 대한 연산이 끝났으므로 (곱하기 연산) 다시 괄호 값을 나눠줘서 연산 진행
"""

def calc(text):
    bracket = dict()    # 괄호 쌍 저장
    bracket[')'] = '('
    bracket[']'] = '['
    value = dict()      # 괄호 값 저장
    value['('] = 2
    value['['] = 3

    stack = []
    answer = 0
    weight = 1  # 누적값 -> 밖을 감싸고 있는 괄호들의 곱
    prev = None     # 직전 괄호

    for i in text:
        if i == '(' or i =='[':
            # 여는 괄호 시 곱하기
            weight *= value[i]
            stack.append(i)
        else:
            if len(stack) == 0 or stack[-1] != bracket[i]:  # 올바르지 않은 괄호
                return 0
            if prev == bracket[i]:      # (), [] 형태가 있다면, 현재까지 누적된 값을 더해줌
                answer += weight
            
            # 괄호가 닫혔으므로, 누적값 나누기
            weight //= value[bracket[i]]
            stack.pop()
        prev = i

    # 올바른 괄호라면
    if len(stack) == 0:
        return answer
    
    return 0

# 입력
s = input().rstrip()
# 연산 + 출력
print(calc(s))