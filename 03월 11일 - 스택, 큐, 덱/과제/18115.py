import sys
from collections import deque
input = sys.stdin.readline

"""
 결과값을 보고 처음 도출 -> 기술을 모두 반대로 쓰자!
 1. 제일 위의 카드 바닥에 내려놓기 ->
    바닥에 내려놓은 카드를 다시 위에 ->
    제일 위의 카드 앞에 넣기
 2. 위에서 두 번째 카드 바닥에 내려놓기 ->
    바닥에 내려놓은 카드 위에서 두 번째에 넣기 ->
    제일 위의 카드 앞에서 두번째에 넣기
 3. 제일 밑에 있는 카드 바닥에 내려놓기 ->
    바닥에 내려놓은 카드 밑에 넣기 ->
    제일 위의 카드 뒤에 넣기
"""

# 입력
n = int(input())
cmd = list(map(int, input().split()))

cards = deque()

# 1번부터 n번 카드까지
for i in range(1, n+1):
    op = cmd[-i]    # 기술을 뒤에서부터 쓰기
    if op == 1:
        cards.appendleft(i)
    elif op == 2:
        # cards = [temp, ...]
        temp = cards.popleft()
        cards.appendleft(i) # cards = [i, ...]
        cards.appendleft(temp) # cards = [temp, i, ...]
    else:
        cards.append(i)

# 출력
for i in cards:
    print(i, end=' ')