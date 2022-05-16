import sys
from collections import deque
input = sys.stdin.readline

"""
 [문제 설명] - 단순 구현 문제
 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가

 K년이 지난 후 상도의 땅에 살아있는 나무의 개수

 [문제 풀이]
 a: 로봇(S2D2)가 겨울에 주는 양분의 양
 land: 땅의 현재 양분 상태
 tree[i][j]: 해당 영역에 존재하는 나이와 개수를 튜플로 묶어서 덱에 저장
 - 새로운 나무가 번식하기 때문에, 나이에 대한 오름차순을 유지하기 위해서는 앞에서의 삽입이 필요

"""

# 봄을 거쳐 나이를 먹은 나무들에 의해 새롭게 태어나게 되는 나무의 수를 계산
def breeding(breeding_src):
    dr = [-1, -1, -1, 0, 0, 1, 1, 1]
    dc = [-1, 0, 1, -1, 1, -1, 0, 1]

    breeding_cnt = [[0]*n for _ in range(n)]

    for r in range(n):
        for c in range(n):
            if breeding_src[r][c] == 0:
                continue
            for i in range(8):
                nr = r+dr[i]
                nc = c+dc[i]
                if 0 <= nr < n and 0 <= nc < n:
                    breeding_cnt[nr][nc] += breeding_src[r][c]

    return breeding_cnt

# 봄과 여름을 묶어서 진행
def spring_summer():
    breeding_src = [[0]*n for _ in range(n)]    # 나이가 5의 배수가 되어 가을에 번식을 하는 나무의 수를 각 영역에 저장

    for i in range(n):
        for j in range(n):
            next_year = deque()
            dead = 0

            while tree[i][j]:
                age, cnt = tree[i][j].popleft()
                # 해당 나이의 모든 나무에게 양분을 줄 수 없는 경우
                if land[i][j] < age * cnt:
                    dead = cnt - land[i][j] // age
                    cnt = land[i][j] // age # 살 수 있는 최대 수

                if cnt > 0:
                    land[i][j] -= age * cnt
                    next_year.append((age+1, cnt))

                    if (age + 1) % 5 == 0:
                        breeding_src[i][j] += cnt

                # 죽은 나무가 생기면 그 이후의 나무는 모두 죽게 된다.
                if dead > 0:
                    land[i][j] += (age // 2) * dead # 여름에 양분이 됨
                    break
            
            # 여름 -> 죽은 나무들이 양분이 됨
            while tree[i][j]:
                age, dead = tree[i][j].popleft()
                land[i][j] += (age // 2) * dead

            tree[i][j] = next_year

    return breeding_src

def autumn_winter(breeding_src):
    # 봄에 나이를 먹은 나무들의 번식 결과
    breeding_cnt = breeding(breeding_src)

    for i in range(n):
        for j in range(n):
            # 가을 - 번식
            if breeding_cnt[i][j]:
                tree[i][j].appendleft((1, breeding_cnt[i][j]))
            # 겨울 - 로봇에 의해 양분 추가
            land[i][j] += winter_list[i][j]
    return


# 입력
n, m, k = map(int, input().split())
winter_list = [list(map(int, input().split())) for _ in range(n)]

land = [[5]*n for _ in range(n)]
tree = [[deque() for _ in range(n)] for _ in range(n)]  # -> 만약 여기서 [deque()] * n으로 하면 어떻게 될까요?

for _ in range(m):
    x, y, z = map(int, input().split())
    tree[x-1][y-1].append((z, 1))


# k년 동안 시뮬레이션
for _ in range(k):
    breeding_src = spring_summer()
    autumn_winter(breeding_src)

ans = 0

# 남아 있는 나무 수 카운트
for line in tree:
    for area in line:
        for _, cnt in area:
            ans += cnt

print(ans)