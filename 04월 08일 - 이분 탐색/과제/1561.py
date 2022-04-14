import sys
input = sys.stdin.readline

"""
 [놀이 공원]

 n번째 아이가 놀이기구를 타는 시간을 구한 후, 해당 시간에 놀이기구를 타는 아이들을 모두 검사하며 n번째 아이가 타는 놀이기구의 번호를 구한다!

 1. n번째 아이가 놀이기구를 타는 시간이 언제인지 parametric search 통해 구함
    - 이때, 각 시간 별 놀이기구 타는 아이의 마지막 번호 구하는 공식은 다음과 같음
      f(t) = (모든 i(놀이 기구)에 대해서) t/num[i] + n(시간 0일때 놀이기구 타는 아이 수)

    - left: 놀이기구 타는 시간의 최소 = 0
    - right: 놀이기구 타는 시간의 최대 = n(사람 수) * (운행시간)
                                    - 여기서 운행시간은 엄밀히 말하면 주어진 운행시간 중 최솟값으로 계산해야 tight한 범위가 나오지만, 그보다 큰 값을 right로 설정해도 답이 구간 내에 존재하므로 이분탐색으로 충분히 찾을 수 있다. 따라서 이 풀이에서는 첫번째 놀이기구의 운행시간으로 계산하였다.
    - n번째 아이가 놀이기구를 타는 첫 시간을 구해야 하므로 lower bound

 2. n번째 아이가 놀이기구를 타는 시간을 구했다면, 그 시간에 마지막으로 놀이기구를 타는 아이부터 시작해서 놀이기구를 m-1부터 탐색하면서 n번째 아이가 몇 번 놀이기구 타는지 구하면 됨!
"""

def calc_people(time, rides):
    people = 0
    for t in rides:
        people += time // t + 1
    return people

def binary_search(n, rides):
    left = 0
    right = rides[0] * n

    while left <= right:
        mid = (left + right) // 2
        if calc_people(mid, rides) >= n:
            right = mid - 1
        else:
            left = mid + 1

    return left

def find_ride(n, m, rides):
    time = binary_search(n, rides)
    people = calc_people(time, rides)
    for i in range(m - 1, -1, -1):
        if time % rides[i] == 0:
            if people == n:
                return i + 1
            people -= 1

# 입력
n, m = map(int, input().split())
rides = list(map(int, input().split()))
print(find_ride(n, m, rides))