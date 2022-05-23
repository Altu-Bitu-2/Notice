#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
    if (node == erase_node) {
        return 0;
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < tree[node].size(); i++) {
        cnt += eraseLeafCnt(tree[node][i], erase_node);
    }
    return cnt;
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node;

    //입력
    cin >> n;
    tree.assign(n, vector<int>(0));
    for (int i = 0; i < n; i++) {
        cin >> par;
        if (par == -1) {
            root = i;
            continue;
        }
        tree[par].push_back(i);
    }
    cin >> erase_node;

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}