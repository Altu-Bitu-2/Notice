import sys
from collections import deque
input = sys.stdin.readline

"""
[숫자 할리갈리 게임] - 시뮬레이션 문제
- 언어별 추가시간이 없으므로, pypy3으로 제출
- 카드 덱과 그라운드의 카드를 관리하기 위해 덱 사용
1. 차례가 되면, 상단 카드를 그라운드에 놓는다.
2. 누군가의 카드 덱이 비는 즉시 게임 종료
3. 종을 치면, 상대방의 그라운드 카드를 뒤집어서 카드 더미의 밑에 넣는다.
"""
def move_cards(card, ground):
    # index 에러 방지 -1 제거
    ground.popleft()

    # deque.extendleft(arr): arr에 있는 값을 하나씩 빼서 왼쪽에 삽입한다.
    card.extendleft(ground)
    ground.clear()

    ground.append(-1) # 인덱스 방지 -1 다시 추가
    return

def play_game(cards, ground):
    player = 0

    ground[0].append(-1)    # index 에러 방지
    ground[1].append(-1)

    for _ in range(m):
        ground[player].append(cards[player].pop())

        if len(cards[player]) == 0:
            return 1 - player

        player = 1 - player     # 다음 플레이어

        if ground[0][-1] == 5 or ground[1][-1] == 5:
            hit = 0     # 도도
        elif ground[0][-1] + ground[1][-1] == 5:
            hit = 1     # 수연
        else:
            continue

        move_cards(cards[hit], ground[1 - hit])
        move_cards(cards[hit], ground[hit])

    if len(cards[0]) > len(cards[1]):
        return 0
    elif len(cards[0]) < len(cards[1]):
        return 1
    else:
        return 2

n, m = map(int, input().split())

cards = [deque() for _ in range(2)]
ground = [deque() for _ in range(2)]
name = ["do", "su", "dosu"]     # 출력할 이름

for _ in range(n):
    a, b = map(int, input().split())
    cards[0].append(a)
    cards[1].append(b)

print(name[play_game(cards, ground)]) 