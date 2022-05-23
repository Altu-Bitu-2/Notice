import sys
input = sys.stdin.readline

"""
 [트리]

 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴

 !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 !주의! 루트 노드가 항상 0이 아님을 주의
"""

#주어진 정점을 지웠을 때의 리프 노드의 수
def erase_leaf_cnt(node, erase_node):
    if node == erase_node:
        return 0
    if not tree[node] or (len(tree[node]) == 1 and tree[node][0] == erase_node):
        return 1
    
    cnt = 0

    for i in range(len(tree[node])):
        cnt += erase_leaf_cnt(tree[node][i], erase_node)
    
    return cnt


# 입력
n = int(input())
tree = [list() for _ in range(n)]

for idx, x in enumerate(input().split()):
    if x == "-1":
        root = idx
    else:
        tree[int(x)].append(idx)

erase_node = int(input())

# 연산 & 출력
print(erase_leaf_cnt(root, erase_node))
