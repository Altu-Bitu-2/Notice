import sys
import heapq as hq
input = sys.stdin.readline

"""
[절댓값 힙]

- heapq에 절댓값을 우선순위로 전달하기 위해 클래스 생성 후 비교연산자 오버라이딩
"""

class data:
    # 생성자
    def __init__(self, num):
        self.num = num
        
    # < (less than) 연산 오버라이딩
    # self가 next보다 더 작다(=우선순위이다)는 사실을 리턴하도록 작성
    def __lt__(self, next):
        if abs(self.num) != abs(next.num):
            return abs(self.num) < abs(next.num)

        return self.num < next.num

# 입력
n = int(input())
abs_heap = []

for _ in range(n):
    # 입력
    x = int(input())
    if x == 0:  # 삭제
        if abs_heap:
            print(hq.heappop(abs_heap).num)
        else:
            print(0)
    else:   # 삽입
        hq.heappush(abs_heap, data(x))