import sys
from math import floor  # round 함수를 대체할 floor(내림)함수
from collections import Counter
input = sys.stdin.readline

"""
[통계학]
1. 산술 평균 계산 시 반올림에 주의
    - python의 round 함수는 사사오입 원칙을 따릅니다.
    - 즉, 반올림 할 숫자가 5이면 앞자리를 짝수로 만들도록 올림/내림합니다.
    - 따라서, 우리가 원하는 출력을 하기 위해서는 round 함수를 쓰면 안됩니다.
2. n은 홀수 이므로 중앙값은 항상 (n/2)번째 인덱스
3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값
4. 최빈값이 유일한 경우 고려
"""

# Counter 없이 직접 최빈값 찾는 함수
def find_mode(n, arr):
    # 정렬된 리스트에서 최빈값을 찾아 반환하고, 만약 최빈값이 여러개라면 두번째로 작은 값을 반환하는 함수
    count = [] # [정수의 값, 정수의 개수]으로 구성된 리스트

    current_idx = 0 # 현재 인덱스를 저장하는 변수
    count.append([arr[0], 1])   # 첫번째 값을 미리 입력하여 for문에서 index 에러 방지
    # 주의! 이때 튜플을 사용하면, 값을 업데이트 할 수 없음

    for i in range(1, n):
        # 만약 직전 값과 같은 값이라면
        if arr[i] == arr[i-1]:
            # 개수 + 1
            count[current_idx][1] += 1
        else:
            # 그렇지 않다면, 새로운 값을 count리스트에 추가
            count.append([arr[i], 1])
            current_idx += 1

    # 만약 값이 한 종류라면, 바로 리턴 -> 아래에서 인덱스 에러 방지
    if current_idx == 0:
        return arr[0]

    # 정렬
    # 1. 개수에 대해 내림차순
    # 2. 값에 대해 오름차순
    count.sort(key=lambda x:(-x[1], x[0]))

    # 최빈값이 여러개인지 확인
    if count[0][1] == count[1][1]:
        return count[1][0]
    
    return count[0][0]

# collections.Counter 사용해서 최빈값 찾는 함수
def find_mode_with_counter(arr):
    # Counter(arr) : arr에 있는 각 요소가 몇개인지 딕셔너리 형태로 돌려준다.
    # .most_common(n): 가장 많은 상위 n 개를 리스트에 담아 돌려준다.
    # 이때 개수가 같다면 순서는 원본 리스트(arr)에서의 순서에 따른다.
    count = Counter(arr).most_common(2)     # 여기서 arr은 이미 정렬된 상태로 함수에 전달되므로 따로 정렬X

    # 만약 값이 한 종류라면, 바로 리턴 -> 아래에서 인덱스 에러 방지
    if len(count) == 1:
        return count[0][0]

    # 최빈값이 여러개인지 확인
    if count[0][1] == count[1][1]:
        return count[1][0]
    
    return count[0][0]

def print_values(n, arr):
    # 산술평균

    mean = sum(arr) / n
    print(floor(mean + 0.5))    # 0.5를 더해 내림해주면, 우리가 생각한대로 4까지는 내림, 5부터는 올림 연산을 수행하게 됩니다.

    # 중앙값
    print(arr[n//2])

    # 최빈값
    # print(find_mode(n, arr))
    print(find_mode_with_counter(arr))

    # 범위
    print(arr[-1] - arr[0])


n = int(input())
arr = [int(input()) for _ in range(n)]
arr.sort()

print_values(n, arr)