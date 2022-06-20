import sys
from collections import deque
input = sys.stdin.readline

"""
 [쿠키런 킹덤]

 건물마다 필요로 하는 자원의 관계를 그래프로 표현하여 위상정렬을 사용해 제한 시간(t) 이내에 지을 수 있는 건물들을 구함
 - 그래프 관계: 필요로 하는 자원 -> 건물
 - 이때, 각 건물마다 생산하는 자원이 여러 개이므로 위상정렬에서 연결된 정점의 진입차수를 감소하는 부분에서 생산하는 자원을 모두 검사해야 함
 - 위 과정에서 서로 다른 건물끼리 생산하는 자원이 겹칠 수 있으므로, 이미 생산한 자원은 체크를 해줌
 - 위상정렬하다 제한 시간을 넘으면 종료
"""

def topological_sort(n, t, pre_built, indegree, products, consumer):
    result = []
    que = deque()
    ready = [False] * (n+1) # i번째 자원이 준비되었는지
    
    for x in pre_built:
        que.append((0, x))

    while que:
        curr_t, x = que.popleft()

        if curr_t > t:
            break

        for i in products[x]:
            if ready[i]:
               continue
            ready[i] = True
            for j in consumer[i]:
                indegree[j] -= 1
                if not indegree[j]:
                    que.append((curr_t + 1, j))
        
        result.append(x)

    return result

# 입력
n, m, t = map(int, input().split())
pre_built = list(map(int, input().split())) # 이미 지어진 건물

indegree = [0] * (n+1)
products = [0]    # products[i]: i번 빌딩이 만들 수 있는 자원
consumer = [list() for _ in range(n+1)]    # consumer[i]: i번 리소스가 필요한 건물

# 건물이 생산하는 자원
for i in range(1, n+1):
    products.append(list(map(int, input().split()[1:])))

# i번 자원이 필요한 건물
for _ in range(n-m):
    line = list(map(int, input().split()))
    indegree[line[0]] = line[1]
    for i in line[2:]:
        consumer[i].append(line[0])

# 연산
ans = topological_sort(n, t, pre_built, indegree, products, consumer)
ans.sort()

# 출력
print(len(ans))
print(*ans)