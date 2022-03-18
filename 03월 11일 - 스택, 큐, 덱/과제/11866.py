import sys
from collections import deque
input = sys.stdin.readline

n, k = map(int, input().split())

# 1부터 n까지 deque에 넣어줍니다.
que = deque(range(1, n+1))
ans = []    # 정답 저장할 리스트

# que의 크기가 0이 될 때까지 반복
while len(que) != 0:
    # for _ in range(k-1):
    #     que.append(que.popleft())

    # .roate(n) : 양수면 n만큼 오른쪽으로 회전, 음수면 n만큼 왼쪽으로 회전하는 메소드
    que.rotate(-(k-1))
    # k번째 수는 pop한 뒤 정답 리스트에 추가합니다.
    ans.append(que.popleft())

# join메소드는 광장히 유용합니다. iterable 객체에 담긴 string들을 사이에 ', '로 이어 리턴하는 함수입니다.
# 그러기에 앞서, 정답 배열에는 정수형이 들어 있으므로, str()을 통해 문자열로 바꾸어야 합니다.
print('<'+', '.join(map(str, ans))+'>')