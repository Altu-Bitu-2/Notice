import sys
input = sys.stdin.readline

"""
 [좋다]

 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 4. left와 right의 초기화 주의 -> 음수가 존재하므로, 지금 검사하는 수 보다 큰 수도 포함될 수 있음
"""

# 좋은 수의 개수를 세는 함수(투 포인터)
def count_good_numbers(n, nums):
    count = 0

    for i in range(n):
        p1 = 0
        p2 = n - 1

        while p1 < p2:
            if p1 == i:
                p1 += 1
                continue
            if p2 == i:
                p2 -= 1
                continue

            if nums[p1] + nums[p2] == nums[i]:
                count += 1
                break
            if nums[p1] + nums[p2] < nums[i]:
                p1 += 1
            else:
                p2 -= 1

    return count

# 입력
n = int(input())
nums = list(map(int, input().split()))
nums.sort() # 오름차순 정렬

# 연산 + 출력
print(count_good_numbers(n, nums))