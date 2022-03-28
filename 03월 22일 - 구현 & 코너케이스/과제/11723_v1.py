import sys
input = sys.stdin.readline

"""
[집합] - 단순 구현 문제

ver1. 리스트 사용
set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 리스트를 이용합니다.

1. 크기가 21인 리스트 선언
2. add는 True, remove는 false

"""
SIZE = 21
m = int(input())
s = [False]*SIZE
value = {"all":True, "empty":False}

def update(cmd):
    for i in range(1, 21):
        s[i] = value[cmd]

def check(num):
    if s[num]:
        return 1
    return 0

for _ in range(m):
    cmd = input().split()

    if len(cmd) == 1:
        update(cmd[0])
        continue
    else:
        num = int(cmd[1])

    if cmd[0] == "add":
        s[num] = True
    elif cmd[0] == "remove":
        s[num] = False
    elif cmd[0] == "check":
        print(check(num))
    elif cmd[0] == "toggle":
        s[num] = not s[num]