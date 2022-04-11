import sys
input = sys.stdin.readline

"""
[저울]

- 작은 값부터 측정 가능한지 파악해야 하므로, 오름차순으로 정렬한다.
- 현재 0부터 scope까지 모든 무게를 빠짐없이 측정가능하다고 했을 때, 새로운 무게는 scope + 1보다 작거나 같아야 한다.
- ex) 현재 1~5까지 측정 가능한데, 다음 값이 7인 경우 -> 6은 측정 불가

- 만약 이 조건을 만족할 경우, 측정 가능한 범위는 [1, scope + 새로운 무게]로 갱신된다.
- 모든 저울을 살펴봤는데도 비어있는 값이 없으면, scope + 1 리턴
"""

def find_unmeasurable(weight):
    weight.sort()   # 작은 무게부터 봐야 하므로 정렬
    scope = 0

    for w in weight:
        if scope + 1 < w:
            return scope + 1
        scope += w            

    return scope + 1

n = int(input())
weight = list(map(int, input().split()))

print(find_unmeasurable(weight))