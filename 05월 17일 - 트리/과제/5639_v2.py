import sys
sys.setrecursionlimit(10**6)

"""
 Ver2. 트리를 직접 작성하지 않고, 바로바로 출력하는 풀이

 전위순회 - V L R
 후위순회 - L R V

 1. 전위 순회는 root 노드의 위치는 알 수 있지만 왼쪽, 오른쪽 서브트리의 경계는 알 수 없음
 2. BST의 성질 : 왼쪽 서브트리의 모든 노드 값 < 루트 노드 값 < 오른쪽 서브트리의 모든 노드 값
    -> 처음으로 root 보다 값이 커진다면, 그 위치가 왼쪽, 오른쪽 서브트리의 경계
 3. 재귀함수 호출로 분할 반복하며 출력
"""

def preorder_to_postorder(start, end):
    if start > end:
        return

    curr = preorder[start]

    # 오른쪽 자식이 없는 경우를 미리 확인하여 불필요한 탐색을 줄임
    if preorder[end] <= curr:
        idx = end + 1
    else:
        # 오른쪽 자식이 시작되는 인덱스 찾기
        for i in range(start+1, end+1):
            if preorder[i] > curr:
                idx = i
                break

    preorder_to_postorder(start + 1, idx-1) # 왼쪽 서브 트리
    preorder_to_postorder(idx, end) # 오른쪽 서브 트리
    postorder.append(curr)

# 입력 & 연산
preorder = [int(i) for i in sys.stdin]
postorder = []

preorder_to_postorder(0, len(preorder)-1)
print(*postorder)