import sys
input = sys.stdin.readline

"""
 [휴게소 세우기]

 M개의 휴게소를 짓고 난 후에 휴게소가 없는 구간의 최댓값의 최솟값은?
 -> 휴게소가 없는 구간의 최댓값이 k(임의의 수)일 때, M개의 휴게소를 지을 수 있는가?

 left: 휴게소가 없는 구간의 최솟값 -> 1
 right: 휴게소가 없는 구간의 최댓값 -> l - 1

 휴게소 구간의 최댓값이 주어졌을 때, 몇 개의 휴게소 짓는지 구하는 방법
 -> 처음 존재하는 휴게소 구간을 최대값으로 나누면 그 몫이 최대 구간이 최대값이 되도록 현재 구간 안에 설치해야 하는 휴게소 개수!
"""

# m개의 휴게소를 추가해서 휴게소 없는 구간이 dist 이하로 만들 수 있는지 확인하는 함수
def calc_rest(dist, n, location):
    count = 0
    for i in range(n-1):
        if location[i + 1] - location[i] > dist:
            count += (location[i + 1] - location[i] - 1) // dist
    
    return count

# 가능한 최댓값을 구하는 형식
def binary_search(n, m, l, location):
    left = 1
    right = l - 1
    while left <= right:
        mid = (left + right) // 2
        if calc_rest(mid, n, location) <= m:
            right = mid - 1
        else:
            left = mid + 1            
    return right + 1

# 입력
n, m, l = map(int, input().split())
location = list(map(int, input().split()))
# 도로의 시작과 끝을 추가하여, 도로 시작 ~ 첫 휴게소, 마지막 휴게소 ~ 도로 끝 구간도 체크할 수 있도록 한다.
location.append(0)
location.append(l)
location.sort() # 인접한 휴게소의 거리를 계산해야 하므로 정렬

print(binary_search(n+2, m, l, location))   # 양 끝값을 추가했으므로 n+2 대입