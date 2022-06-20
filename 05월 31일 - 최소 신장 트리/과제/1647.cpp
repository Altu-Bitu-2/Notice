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

int kruskal(int n, vector<tp> &edge) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < edge.size(); i++) {
        int w = get<0>(edge[i]);
        int u = get<1>(edge[i]);
        int v = get<2>(edge[i]);
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
 * [도시 분할 계획]
 *
 * 마을을 두개로 분리하고, 각 집끼리 이동할 수 있는 최소한의 도로만 남기는 문제
 * 즉, 2개의 최소신장트리를 만들어야 하는 문제
 * -> 하나의 최소신장트리를 만들고, 그 중 가장 유지비가 큰 도로를 삭제
 * -> 크루스칼 알고리즘에서 가장 마지막에 삭제되는 도로가 유지비가 가장 큼
 * -> 크루스칼 알고리즘에서 간선을 n-2개만 선택하여 그 합을 구하여 해결
 */
int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;
    vector<tp> edge;
    parent.assign(n + 1, -1);
    while (m--) {
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }

    //연산
    sort(edge.begin(), edge.end());

    //연산&출력
    cout << kruskal(n - 1, edge);
    return 0;
}