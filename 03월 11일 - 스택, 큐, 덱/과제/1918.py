import sys
input = sys.stdin.readline

"""
[중위 표기식 -> 후위 표기식]
 1. 피연산자는 스택에 넣지 않고 바로 답에 추가한다.
 2. '('는 무조건 스택에 넣는다.
 3. 항상 스택의 top 에 있는 연산자 우선순위가 제일 높아야 한다. (연산자 우선순위: *,/ > +,-)
 4. 따라서 스택의 top 에 있는 값이 현재 연산자의 우선순위와 같거나 더 높다면 스택에서 값을 꺼내 답에 추가한다.
 5. 4번 과정을 끝마치면, 스택에 현재 연산자를 넣는다.
 6. ')'가 들어오면 '('값이 스택의 top이 될 때까지 스택에서 값을 꺼내서 답에 추가한다.
 7. (!주의!) 주어진 문자열에 대한 검사가 모두 끝나면 스택에 남아있는 연산자를 모두 답에 추가한다.
"""

# 연산자 우선 순위
priority = dict()
priority['*'] = priority['/'] = 2   # 우선 순위 가장 높음
priority['+'] = priority['-'] = 1   
priority['('] = priority[')'] = 0   # 우선 순위 없음
priority["bottom"] = -1     # 스택의 가장 밑 부분을 표기하기 위해 사용 (인덱스 에러 방지) - 우선 순위 가장 낮음


# 중위 표기식 -> 후위 표기식
def infix_to_postfix(string):
    # 쌓아두기
    stack = ["bottom"]     # stack이 비어있을 때 stack[-1]를 호출할 경우 인덱스 에러가 난다. 이를 방지하기 위해 미리 bottom을 삽입
    answer = ""

    for i in string:
        #  i가 피연산자라면
        if i not in priority:
            answer += i
        elif i == '(':
            stack.append(i)
        elif i == ')':
            while stack[-1] != '(':    # '('가 나올 때까지 답에 연산자 추가
                answer += stack.pop()
            stack.pop()     # '(' 제거

        # '+', '-', '*', '/' 의 경우
        else:
            # 현재 연산자의 우선순위와 같거나 더 높다면 스택에서 값을 꺼내 답에 추가
            while priority[i] <= priority[stack[-1]]:
                answer += stack.pop()
            stack.append(i)

    while (len(stack) > 1):
        answer += stack.pop()

    return answer


s = input().rstrip()
print(infix_to_postfix(s))