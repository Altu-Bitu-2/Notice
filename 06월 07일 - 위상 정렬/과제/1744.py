import sys
input = sys.stdin.readline

"""
[수 묶기]

1. 양수는 양수끼리, 음수는 음수끼리 곱해야 큰 수를 만들 수 있다.
2. 절댓값이 큰 것끼리 곱해야 더 큰 수를 만들 수 있다.
     ex) 1, 2, 3, 4 => 4 * 1 + 3 * 2 = 10
                    => 4 * 3 + 2 * 1 = 14
3. 1은 곱하는 것보다 더해야 큰 수를 만들 수 있다. (x * 1 = x < x + 1)
"""

def tie_number(arr):
    total = 0
    size = len(arr)
    for i in range(0, size - 1, 2):
        total += arr[i] * arr[i + 1]
    # 하나 남은 수는 그냥 더해줌
    if size % 2:
        total += arr[-1]

    return total

n = int(input())
arr1 = [] # 1보다 큰 수를 저장
arr2 = [] # 1보다 작은 수를 저장
cnt = 0 # 1의 개수를 저장

for _ in range(n):
    x = int(input())
    if x > 1:
        arr1.append(x)
    elif x < 1:
        arr2.append(x)
    else:
        cnt += 1

# 절댓값이 큰 순으로 정렬
arr1.sort(reverse=True)
arr2.sort()

print(cnt + tie_number(arr1) + tie_number(arr2))