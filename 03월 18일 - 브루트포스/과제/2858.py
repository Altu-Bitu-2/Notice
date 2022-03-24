import sys
input = sys.stdin.readline

"""
[기숙사 바닥 문제]
 빨간 타일: 테두리를 채움, 갈색 타일: 나머지
 문제 입력에 만족하는 방의 크기 l, w (l > w)를 출력하는 문제
 
 [풀이]
 기숙사 바닥의 넓이는 타일의 개수의 총합인 r + b
 w(너비)가 1인 사각형부터 검사, 테두리의 타일 수가 r개와 같다면 정답
 테두리 개수 = (l + w) * 2 - 4(겹치는 부분)
 입력 범위는 최대 r + b = 2,005,000 이므로 접근 가능!
"""

# 바닥의 높이와 넓이를 구해서 리턴하는 함수
def get_size(r, b):
    area = r + b

    # l > w 이므로, w를 작은 것 부터 탐색해서 정답이 되는 경우 리턴
    for w in range(1, r+b+1):
        if area % w != 0:
            continue
        l = area // w
        if r == (l + w) * 2 - 4:
            return l, w


r, b = map(int, input().split())
print(*get_size(r, b))  # 인자에 *를 붙이면, 뒤의 객체를 풀어서 하나씩 넣어준다.

# 즉, 아래의 코드와 같다
# l, w = get_size(a, b)
# print(l, w)