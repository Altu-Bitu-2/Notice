#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int x) {
    if (parent[x] < 0) {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

//Union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) {
        return false;
    }
    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py];
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int n, vector<tp> &edges) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        int w = get<0>(edges[i]);
        int u = get<1>(edges[i]);
        int v = get<2>(edges[i]);
        if (!unionNodes(u, v)) {
            continue;
        }
        sum += w;
        cnt++;
        if (cnt == n - 1) {
            return sum;
        }
    }
    return 0;
}

/**
 * [전기가 부족해]
 *
 * 모든 도시에 전기가 공급될 수 있도록 최소 비용으로 도시를 연결하는 문제
 * 이 문제는 k개의 최소신장트리를 만들어야 하지만, 발전기가 있는 도시를 모두 가상의 정점에 연결한다고 생각하면 하나의 큰 트리를 이룸
 *
 * -> 한번의 크루스칼 알고리즘으로 해결 가능
 */
int main() {
    int n, m, k, u, v, w;

    //입력
    cin >> n >> m >> k;
    vector<tp> edge;
    parent.assign(n + 1, -1);
    for (int i = 0; i < k; i++) {
        cin >> u;
        parent[u] = 0; //0번 정점과 연결됐다고 생각
    }
    while (m--) {
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }

    //연산
    sort(edge.begin(), edge.end());

    //연산 & 출력
    cout << kruskal(n - k + 1, edge); //k개의 정점은 이미 연결된 상태이므로 n - k개의 간선만 선택해도 됨
    return 0;
}