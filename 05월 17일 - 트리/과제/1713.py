import sys
input = sys.stdin.readline

SIZE = 100

"""
 [후보 추천하기]

 1. 비어있는 사진틀이 없는 경우, 가장 추천수가 작은 학생 중 게시 시간이 오래된 학생을 삭제
 2. 후보 학생을 바로 찾기 위해 본 풀이는 딕셔너리 컨테이너를 사용해 구현

 !주의! 게시 시간 정보 저장 시, 후보로 올라간 가장 첫 시간을 저장. 이미 후보에 있는데 게시 시간이 갱신되지 않도록 주의.
"""

n = int(input())
k = int(input())
arr = list(map(int, input().split()))

number = [0]*(SIZE + 1)
candidate = dict()

for idx, student in enumerate(arr):
    # 이미 사진이 올라와 있는 경우
    if student in candidate:
        candidate[student][0] += 1
    else:
        if len(candidate) == n:
            # 추천 횟수가 가장 적은 학생 찾기
            students = sorted(candidate.keys(), key=lambda x:candidate[x])
            candidate.pop(students[0])
        candidate[student] = [1, idx]

print(*sorted(candidate.keys()))