import sys
from collections import deque
input = sys.stdin.readline

"""
[루머]

- 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
- 방문 체크 배열을 루머를 믿는 시간을 저장하는 배열로 대체함
    time[i] = -1 일 경우, i는 루머를 믿지 않는다
    time[i] = t인 경우, i는 t분 부터 루머를 믿기 시작함
- 각자가 루머를 믿기 위해 주변인의 절반 이상이 루머를 믿어야 하므로, 각 사람이 루머를 믿기까지 루머를 믿는 주변인 몇명이 남았는지를 리스트에 기록한다.
- 남은 사람이 0인 순간, 해당 사람은 루머를 믿기 시작
"""

def bfs(n, adj_list, initial_people):
    que = deque()
    time = [-1] * (n+1) # 각 사람이 루머를 믿기 시작한 시간
    rest = [0]  # 각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    for i in initial_people:
        time[i] = 0
        que.append(i)
    
    for i in range(1, n + 1):
        rest.append((len(adj_list[i]) + 1) // 2)

    while que:
        curr = que.popleft()
        for next in adj_list[curr]:
            if time[next] > -1:
                continue
            rest[next] -= 1
            if rest[next] == 0:
                time[next] = time[curr] + 1 # curr이 t분에 루머를 퍼트리므로, next는 t+1분에 주변인의 절반 이상에게서 루머를 듣게 된다.
                que.append(next)
            
    return time


# 입력
n = int(input())
adj_list = [None]

for _ in range(n):
    tmp = list(map(int, input().split()))
    tmp.pop()   # 마지막 0 제거
    adj_list.append(tmp)

m = int(input())
initial_people = list(map(int, input().split()))

# 연산
answer = bfs(n, adj_list, initial_people)
# 출력
print(*answer[1:])