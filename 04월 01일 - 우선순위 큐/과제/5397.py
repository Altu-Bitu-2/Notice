import sys
from collections import deque
input = sys.stdin.readline

"""
 [키로거]

 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함

 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
"""

t = int(input())

for _ in range(t):
    front = deque() # 커서 이전 내용을 저장
    back = deque()  # 커서 이후 내용을 저장

    log = input().rstrip()
    
    for c in log:
        # 현재 커서 앞에 있는 글자를 지운다.
        if c == '-':
            if front:
                front.pop()
        # 커서를 왼쪽으로 이동 -> front의 마지막 원소를 back 앞에 삽입
        elif c == '<':
            if front:
                back.appendleft(front.pop())
        # 커서를 오른쪽으로 이동 -> back의 처음 원소를 front 뒤에 삽입
        elif c == '>':
            if back:
                front.append(back.popleft())
        # 문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 front에 삽입
        else:
            front.append(c)
    
    print(''.join(front)+''.join(back))