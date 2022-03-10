import sys
input = sys.stdin.readline

# 연산의 편리함을 위해, 모든 시간은 초로 바꾸어 연산합니다.
MIN = 60
HOUR = 60 * MIN
DAY = 24 * HOUR

h, m, s = map(int, input().split())
q = int(input())

time = h*HOUR + m*MIN + s

def print_time(t):
    h = t // HOUR
    t %= HOUR
    m = t // MIN
    t %= MIN
    s = t

    print(h, m, s)

def change_time(c):
    # 현재시간(t)에 c초를 더하는 함수

    # 전역 변수를 바꾸고 싶을 때는 global 키워드를 사용합니다.
    # 만약 사용하지 않으면? 값을 참조하는건 괜찮지만, 변수에 값을 새로 할당하게 되면 함수 내에서 지역 변수가 선언됩니다. 지역변수는 함수가 종료되면서 사라지므로, 전역변수는 바뀌지 않습니다.
    global time
    # 하루가 넘어가거나, 초가 음수가 되었을 수도 있으니 모듈러 연산을 합니다.
    # python의 %와 cpp의 %는 조금 다르게 작동하니까 유의!!
    # ex. (python3) (-4) % 10 -> 6  /  (c++) (-4) % 10 -> 4
    time = (time + c) % DAY

for _ in range(q):
    # 한 줄에 몇개의 입력이 들어올지 모르는 상황이므로 리스트로 입력을 받습니다.
    query = list(map(int, input().split()))

    if query[0] == 1:
        change_time(query[1])
    elif query[0] == 2:
        # 시계를 뒤로 돌려야 하므로, 음수로 바꾸어 함수에 전달합니다.
        change_time(-query[1])
    else:
        print_time(time)