import sys
input = sys.stdin.readline

"""
 [컨베이어 벨트 위의 로봇 문제] - python3로 제출 시 시간초과, pypy3로 제출해주세요.
 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감

 [문제 풀이]
 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근

 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
"""

def simulation(n, k, belt):
    size = 2 * n
    robots = [False] * size                 # 로봇의 존재 여부를 저장
    
    up_idx = 0  # 로봇을 올리는 위치
    down_idx = n-1  # 로봇을 내리는 위치

    step = 0
    count = 0   # 내구도가 0인 칸의 수

    while True:
        step += 1

        # 1. 회전
        up_idx = (up_idx - 1) % size    
        down_idx = (down_idx - 1) % size
        
        robots[down_idx] = False    # 로봇 내리기

        prev_idx = down_idx
        idx = down_idx - 1
        
        # 2. 로봇 이동
        while idx != up_idx:
            if robots[idx] and not robots[prev_idx] and belt[prev_idx] > 0:
                robots[idx] = False
                robots[prev_idx] = True
                belt[prev_idx] -= 1
                if belt[prev_idx] == 0:
                    count += 1
            prev_idx = idx
            idx = (idx - 1) % size

        # 내리는 위치에 로봇이 옮겨졌다면 바로 내리기
        robots[down_idx] = False

        # 3. 로봇 올리기
        if belt[up_idx] > 0:
            robots[up_idx] = True
            belt[up_idx] -= 1
            if belt[up_idx] == 0:
                count += 1

        if count >= k:
            break

    return step

# 입력
n, k = map(int, input().split())
belt = list(map(int, input().split()))  # 벨트의 내구도를 저장

# 연산 + 출력
print(simulation(n, k, belt))