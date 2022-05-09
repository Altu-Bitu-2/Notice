import sys
input = sys.stdin.readline

INF = 10**9

"""
[마인크래프트]
 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 -> 위치에 관계없이, 높이에 따라 필요한 블록 수와 시간이 결정되기 때문에 해당 높이의 블록이 몇 개 있는지 미리 저장 -> 가능한 높이 당 최대 256번의 연산만으로 계산 가능

 !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
"""

def mine_land(min_height, max_height, b, height, cnt):
    t = 0
    for i in range(min_height, height):
        temp = cnt[i] * (height - i)
        b -= temp
        t += temp

    for i in range(height, max_height + 1):
        temp = cnt[i] * (i - height)
        b += temp
        t += temp * 2

    if b < 0:
        return INF + 1

    return t


# 입력
n, m, b = map(int, input().split())

cnt = [0]*257   # cnt[i] = 높이 i를 가지고 있는 땅의 수
min_height = 256
max_height = 0

for _ in range(n):
    for i in map(int, input().split()):
        cnt[i] += 1
        min_height = min(min_height, i)
        max_height = max(max_height, i)

min_t = INF
height = 0

# 연산
for h in range(min_height, max_height+1):
    t = mine_land(min_height, max_height, b, h, cnt)
    if t <= min_t:
        min_t = t
        height = h

# 출력
print(min_t, height)