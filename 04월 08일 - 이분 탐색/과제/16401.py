import sys
input = sys.stdin.readline

"""
 [과자 나눠주기]

 n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?

 left: 과자 길이의 최솟값 -> 1
 right: 과자 길이의 최댓값
"""

# 내림차순 정렬된 snacks 리스트에서 length 길이의 과자를 몇개 만들 수 있는지 개수를 세어 리턴하는 함수
def split_snack(length, snacks):
    count = 0
    for l in snacks:
        if l < length:
            return count
        count += l // length

    return count

def binary_search(m, snacks):
    left = 1
    right = snacks[0]
    while left <= right:
        mid = (left + right) // 2
        if split_snack(mid, snacks) >= m:
            left = mid + 1
        else:
            right = mid - 1
    return left - 1

m, n = map(int, input().split())
snacks = list(map(int, input().split()))
snacks.sort(reverse=True)   # 내림차순 정렬

print(binary_search(m, snacks))