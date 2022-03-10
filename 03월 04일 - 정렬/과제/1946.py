import sys
input = sys.stdin.readline

def solve(n, arr):
    arr.sort()
    # key 값이 따로 없이 정렬했으므로, 서류 점수의 오름차순, 그 이후 면접 순위의 오름차순으로 정렬이 되어있다.
    # 따라서 앞에서 부터 탐색하면서 면접 순위에 대한 조건을 만족하는지 확인해야 한다.
    count = 0
    best_rank = n   # 현재까지 면접 순위 중 가장 높은 순위를 기록한다.
    for rank in arr:
        # 이미 서류 점수의 오름차순으로 정렬했으므로, 현재 최고의 면접 순위보다 우수해야 선발할 수 있다.
        if rank[1] < best_rank:
            count += 1
            best_rank = rank[1]

    return count


T = int(input())
for _ in range(T):
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]
    print(solve(n, arr))