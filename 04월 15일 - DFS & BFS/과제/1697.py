import sys
from collections import deque
input = sys.stdin.readline

"""
[숨바꼭질]

 x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
"""
SIZE = 10**5

def bfs(n, k):
    time = [-1] * (SIZE + 1)
    que = deque()
    que.append(n)
    time[n] = 0

    while que:
        curr = que.popleft()
        if curr == k:
            return time[curr]
        
        for next in (curr * 2, curr + 1, curr - 1):
            if next < 0 or next > SIZE or time[next] > -1:
                continue
            time[next] = time[curr] + 1
            que.append(next)

# 입력
n, k = map(int, input().split())
# 연산 + 출력
print(bfs(n, k))