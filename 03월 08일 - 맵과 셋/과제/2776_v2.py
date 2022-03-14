import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

# ver2) 아직 배우지는 않았지만, 후반부에 배울 이분탐색을 이용한 풀이입니다.
# O(n)의 시간복잡도를 갖는 선형탐색(linear search)는 달리, 이분탐색(binary search)는 O(logn)의 시간 복잡도를 갖습니다. 

t = int(input())

for _ in range(t):
    # 입력
    n = int(input())
    note1 = list(map(int, input().split()))
    m = int(input())
    note2 = list(map(int, input().split()))

    note1.sort() # 이분탐색을 하기 위해서 정렬

    # note2에 있는 숫자를 하나씩 꺼내 note1에 있는지 확인합니다.
    for num in note2:
        # bisect_left 함수는 정렬된 리스트에서 새로운 값이 들어갈 수 있는 첫번째 인덱스를 리턴합니다.
        # bisect_right 함수는 정렬된 리스트에서 새로운 값이 들어갈 수 있는 마지막 인덱스를 리턴합니다.
        # 만약 num이 note1에 포함되어 있지 않다면, 둘의 결과 값은 같게 됩니다.
        if bisect_left(note1, num) == bisect_right(note1, num):
            print(0)
        else:
            print(1)