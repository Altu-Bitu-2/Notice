import sys
input = sys.stdin.readline

"""
[스위치 켜고 끄기]

 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기

 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 스위치 20개씩 출력하는 부분 주의
 인덱스 번호 주의
"""

# 남학생의 스위치 바꾸기
def change_switch_boy(k, n, switch):
    # k-1 부터 -> 인덱스는 0부터니까
    for i in range(k-1, n, k):
        switch[i] = 1 - switch[i]
    return

# 여학생의 스위치 바꾸기
def change_switch_girl(k, n, switch):
    k -= 1  # 인덱스는 0부터
    idx = 0
    # 스위치 범위가 넘어가거나 좌우 대칭이 깨질 때가지
    while k-idx >= 0 and k+idx < n and switch[k-idx] == switch[k+idx]:
        switch[k-idx] = switch[k+idx] = 1 - switch[k+idx]
        idx += 1
    return

# 입력
n = int(input())
switch = list(map(int, input().split()))
k = int(input())

for _ in range(k):
    a, b = map(int, input().split())
    if a == 1:
        change_switch_boy(b, n, switch)
    else:
        change_switch_girl(b, n, switch)

# 출력
for i in range(0, n, 20):
    print(*switch[i:i+20])