import sys
sys.setrecursionlimit(10**6)

"""
 Ver1. 트리를 직접 작성하는 방식 - 백준에 제출 시에는 시간초과가 나는 소스코드입니다. 다만 트리를 직접 구현한 코드를 한번 참고하시면 좋을거 같아서 업로드 합니다.

 맵과 셋 PPT 중 BST 노드 삽입 과정 참고

 [이진 검색 트리]

 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 4. 완성한 트리를 후위 순회
"""

class node_info:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def make_tree(node, data):
    if node == None:    # 이번 노드가 들어가게 될 위치
        node = node_info(data)
    elif node.data > data:
        node.left = make_tree(node.left, data)
    elif node.data < data:
        node.right = make_tree(node.right, data)

    return node

# 후위 순회
def postorder(node):
    if node == None:
        return
    
    postorder(node.left)
    postorder(node.right)
    print(node.data)

root = None

# 입력 & 연산
for i in sys.stdin:
    root = make_tree(root, int(i))

postorder(root)