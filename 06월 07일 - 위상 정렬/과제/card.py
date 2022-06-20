from itertools import permutations
from collections import deque

SIZE = 4
CNT = 6

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

"""
 [카드 짝 맞추기]

 아이디어
 1. 범위가 크지 않음
 2. 존재하는 모든 카드의 종류는 6개, 카드 2장이 한 쌍을 이룬다.
 3. 뒤집을 카드 순서를 정하는 모든 경우의 수는 6!(카드 순서) * 2^6(2개의 카드 중 어떤 카드를 먼저 뒤집을지) -> 브루트포스 가능
 4. 이번에 목표로 하는 카드에 대해 현재 커서에서 목표 카드까지 가는 최단 경로를 구하며 이동 횟수 전부 구하고 최솟값 갱신

 구현
 1. 존재하는 모든 카드의 위치를 저장하며 카드의 개수 세기 (find_cards)
 2. 가능한 모든 카드의 순서(permutations)와 각 카드를 뒤집을 순서(bitmask)를 결정
    ex) seq = {3, 1, 2}, bit = 011 일 때
        3번, 1번, 2번 카드의 순서로 뒤집는다.
        3번 카드는 1번째 카드부터, 1번 카드는 0번째 카드부터, 2번 카드는 1번째 카드부터 뒤집는다.
        bit의 011이 앞에서부터 각각 1, 2, 3번 카드와 대응함
 3. 현재 카드 순서와 각 카드를 뒤집는 순서에 대한 커서 이동 횟수 계산 (match_card)
    현재 커서 위치와 목표 카드 위치에 대해 bfs 함수 실행
    컨트롤 입력을 고려해야 하기 때문에 4방향에 대한 방향 이동에 추가로 컨트롤 입력도 처리한다.(ctrl)
 4. 매 조합에 따라 board가 갱신되므로 board를 복사한 tmp 사용
 공식 풀이 : https://tech.kakao.com/2021/01/25/2021-kakao-recruitment-round-1/
"""

# 컨트롤로 이동하는 좌표를 리턴하는 함수
def ctrl(row, col, dir, tmp):
    while True:
        row += dr[dir]
        col += dc[dir]
        # 해당 방향에 카드가 하나도 없다면 그 방향의 가장 마지막 칸으로 이동
        if not (0 <= row < SIZE) or not(0 <= col < SIZE):
            return (row - dr[dir], col - dc[dir])
        # 누른 키 방향에 있는 가장 가까운 카드
        if tmp[row][col]:
            return (row, col)

# 현재 커서에서 목표 카드로 이동하는 가장 적은 비용을 리턴하는 함수
def bfs(r1, c1, r2, c2, tmp):
    # 첫 시작 위치에 카드가 있는 경우
    if r1 == r2 and c1 == c2:
        return 1

    visited = [[0]*SIZE for _ in range(SIZE)]
    que = deque()
    # 반드시 엔터를 누르게 될 것. 엔터를 미리 눌렀다 가정하고 1로 표시
    visited[r1][c1] = 1
    que.append((r1, c1))

    while que:
        row, col = que.popleft()
        dist = visited[row][col]
        
        # 컨트롤 입력 이동
        for i in range(4):
            nr, nc = ctrl(row, col, i, tmp)
            if not visited[nr][nc]:                
                visited[nr][nc] = dist + 1
                # 목표 카드에 도달했다면
                if nr == r2 and nc == c2:
                    return dist + 1
                que.append((nr, nc))

        # 방향키 입력 이동
        for i in range(4):
            nr, nc = row + dr[i], col + dc[i]
            if (0 <= nr < SIZE) and (0 <= nc < SIZE) and not visited[nr][nc]:
                # 목표 카드에 도달했다면
                if nr == r2 and nc == c2:
                    return dist + 1
                visited[nr][nc] = dist + 1
                que.append((nr, nc))

    
    # 목표 카드에 도달하지 못함 (실제로는 일어나지 않는 일)
    return -1

# 조합에 대해 카드를 매칭하는 함수
def match_card(bit, num, r, c, seq, cards, board, answer):
    tmp = []
    for line in board:
        tmp.append(line[:])

    ans = 0
    for i in range(num):
        curr = seq[i]   # 이번에 매칭할 캐릭터

        if not cards[curr]:
            continue

        now = 0 # 해당 캐릭터의 0번째 카드부터 선택한다고 가정
        
        # 만약 해당 위치의 비트가 1을 표시했다면 1번째 카드부터 선택
        if bit & (1 << i): 
            now = 1

        for _ in range(2):
            nr, nc = cards[curr][now]    # 이번에 매칭할 카드 위치
            ans += bfs(r, c, nr, nc, tmp)   # 현재 커서에서 목표 카드까지 이동하는 비용

            # 기존 최솟값보다 큰 경우 -> 더 이상의 탐색 불필요
            if ans >= answer:
                return answer

            # 카드 삭제 + 커서 이동
            tmp[nr][nc] = 0
            r, c = nr, nc
            now = 1 - now   # 다음에 매칭할 카드 인덱스
    
    return ans

# 존재하는 모든 카드의 위치를 리턴하는 함수
def find_cards(board):
    cards_pos = [list() for _ in range(CNT + 1)]   # 최대 카드 수
    cnt = 0
    for i in range(SIZE):
        for j in range(SIZE):
            if not board[i][j]:
                continue
            cnt = max(cnt, board[i][j])
            cards_pos[board[i][j]].append((i, j))
    return cards_pos, cnt

def solution(board, r, c):
    answer = 10**9
    cards, card_cnt = find_cards(board)    # 존재하는 모든 카드의 위치
    
    # 가능한 모든 순서에 대해
    for seq in permutations(range(1, card_cnt+1), card_cnt):
        for bit in range(1 << card_cnt):
            answer = match_card(bit, card_cnt, r, c, seq, cards, board, answer)
    return answer

if __name__ == "__main__":
    board = [[1, 0, 0, 3],
             [2, 0, 0, 0],
             [0, 0, 0, 2],
             [3, 0, 1, 0]]
    print(solution(board, 1, 0))