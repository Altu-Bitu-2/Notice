import sys
sys.setrecursionlimit(10**6)

"""
 [호텔 방 배정]

 - 방을 배정할 때마다 이번에 배정한 방의 다음 방을 집합의 루트 정점으로 만들어 바로 접근할 수 있도록 설정
 - parent를 벡터(혹은 배열)로 사용하면 전체 방 개수(k)의 최대가 10^12이기 때문에 메모리 초과
 -> 따라서 필요한 방의 parent정보만 저장하기 위해 map을 사용해야 함.

 (참고) 백준의 10775와 매우 유사한 문제
"""

parent = dict()

def find_parent(x):
    if x not in parent:
        parent[x] = x + 1   # 다음에 이 방이 호출 될 경우 다음 방을 알려줌
        return x    # 현재는 비었으니까 바로 리턴
    parent[x] = find_parent(parent[x])
    return parent[x]

def solution(k, room_number):
    answer = []
    
    for i in room_number:
        answer.append(find_parent(i))
    
    return answer

# 디버깅을 위한 메인 코드 - 프로그래머스에는 제출 X
if __name__ == "__main__":
    k = 10
    room_number = [1, 3, 4, 1, 3, 1]
    result = solution(k, room_number)
    print(*result)