import sys
from itertools import combinations
input = sys.stdin.readline

"""
[ 블랙잭 ] - 단순 구현
카드가 최대 100장이므로,
C(100, 3) < 100*100*100 = 1,000,000 -> 브루트포스 충분히 가능

ver1. 3중 for문 이용해서 구현
+) 코드의 효율성을 높이기 위해, 카드를 사전에 정렬하여 M을 넘어가는 순간 반복 종료

ver2. itertools.combinations 이용하여 모든 조합을 구해서 구현
"""

def play_blackjack(n, m, cards):
    cards.sort()    # 오름차순 정렬
    answer = 0

    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                temp = cards[i] + cards[j] + cards[k]
                # cards 리스트가 오름차순 정렬되어 있으므로 k를 키우는 건 의미 없음
                if (temp > m):
                    break
                answer = max(answer, temp)  # 최댓값 갱신
    return answer

def play_blackjack_with_combinations(n, m, cards):
    combi = combinations(cards, 3)   # cards에서 3개로 이루어진 모든 조합 구하기
    arr = list(map(lambda x:sum(x), combi)) # 모든 조합에 대해 합 구하기
    arr.sort()  # 오름차순 정렬

    answer = 0
    for total in arr:
        # 합이 m을 넘어가면 바로 종료
        if total > m:
            break
        answer = total
    
    return answer


# 입력
n, m = map(int, input().split())
cards = list(map(int, input().split()))

print(play_blackjack(n, m, cards))
# print(play_blackjack_with_combinations(n, m, cards))