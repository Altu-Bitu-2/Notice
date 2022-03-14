import sys
input = sys.stdin.readline

# 같은 종류의 옷이 각각 몇 벌 있는지만 알면 되는 문제

t = int(input())

for _ in range(t):
    n = int(input())
    # 종류별 수를 저장할 딕셔너리
    closet = dict()

    for _ in range(n):
        # 옷의 종류만 필요하므로 두번째 단어만 저장
        type_of_cloth = input().rstrip().split()[1]
        # key 에러 방지를 위해 딕셔너리에 존재하는지 확인
        if type_of_cloth in closet:
            closet[type_of_cloth] += 1
        else:
            closet[type_of_cloth] = 1

    answer = 1

    # .values() : 딕셔너리에서 value들을 뽑아 iterator 형태로 돌려주는 메소드
    # iterator는 바로 반복문 사용이 가능합니다.
    for value in closet.values():
        # 해당 종류의 옷에서 선택할 수 있는 경우의 수 = 종류의 수 + 안 입기
        answer *= (value+1)
    
    # 아무 것도 입지 않은 경우를 제외하고 출력
    print(answer-1)