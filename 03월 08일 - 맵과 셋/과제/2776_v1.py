import sys
input = sys.stdin.readline

# ver1) 셋을 이용한 풀이입니다.
    

t = int(input())

for _ in range(t):
    # 입력
    n = int(input())
    note1 = set(map(int, input().split()))
    m = int(input())
    note2 = list(map(int, input().split()))

    # note2에 있는 숫자를 하나씩 꺼내 note1에 있는지 비교합니다.
    for num in note2:
        if num in note1:
            print(1)
        else:
            print(0)