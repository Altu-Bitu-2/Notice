import sys
input = sys.stdin.readline

n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]
# 정렬의 우선순위에 맞춰 람다함수를 작성합니다.
arr.sort(key=lambda x:(x[1], x[0]))

for x, y in arr:
    print(x, y)