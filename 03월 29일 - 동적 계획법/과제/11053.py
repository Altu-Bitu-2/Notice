import sys
from bisect import bisect_left
input = sys.stdin.readline

def lis(n, arr):
    """
    시간 복잡도 O(n^2)

    강의 자료 점화식 참고
    """
    dp = [1]* (n + 1)

    for i in range(n):
        for j in range(i):
            if arr[i] > arr[j]: # 증가한다면
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)

def lis2(n, arr):
    """
    dp[i] : 증가하는 부분 수열의 길이가 i인 수열에서 마지막에 올 수 있는 가장 작은 수
    idx : 가장 긴 증가하는 부분 수열의 길이

    시간 복잡도 O(nk) (k는 idx의 크기)
    -> k가 n이 될 수 있으므로 이론상 시간복잡도는 O(n^2)으로 동일하지만, 증가하는 관계일 때 break를 해줌으로써 실제 연산횟수는 더 적어서 1번 함수보다 빠른 풀이
    해설 : https://myunji.tistory.com/214
    """
    dp = [0]*(n+1)

    size = 0 # 현재까지의 최장 길이 기록

    for i in range(n):
        if arr[i] > dp[size]:    # 최장 길이 갱신
            size += 1
            dp[size] = arr[i]
            continue

        for j in range(size-1, -1, -1):
            if arr[i] > dp[j]:  # arr[i]를 이어 붙일 수 있다면
                dp[j+1] = arr[i]
                break

    return size

def lis_adv(arr):
    """
    lisAdv에서 line 36~43의 과정을 이분탐색으로 구현
    
    시간 복잡도 O(nlogk) (k는 dp의 크기)
    해설 : https://myunji.tistory.com/270
    """
    dp = list()

    for value in arr:
        idx = bisect_left(dp, value)    # idx: value 이상의 값이 처음 나오는 위치
        if idx == len(dp):  # value가 현재 값 중 가장 크다면 최장 길이 갱신
            dp.append(value)
        else:
            dp[idx] = value  # 그렇지 않다면 idx의 있는 값을 value로 덮어 씌우기

    return len(dp)

# 입력
n = int(input())
arr = list(map(int, input().split()))

# 연산 + 출력
# print(lis(n, arr))
# print(lis2(n, arr))
print(lis_adv(arr))