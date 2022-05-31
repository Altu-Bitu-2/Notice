#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tp;
vector<int> parent;

// Find 연산
int findParent(int x) {
    if (parent[x] < 0) { //값이 음수면 루트 정점
        return x;
    }
    return parent[x] = findParent(parent[x]); //그래프 압축하며 루트 정점 찾기
}

// union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) {
        return false;
    }

    if (parent[px] < parent[py]) {  //새로운 루트 px
        parent[px] += parent[py];
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

int kruskal(int v, vector<tp> &edge) {
    int sum = 0, cnt = 0;

    for (auto[w, n1, n2]: edge) {
        // w = get<0>(vertex[i]);
        // n1 = get<1>(vertex[i]);
        // n2 = get<2>(vertex[i]);
        if (!unionNodes(n1, n2)) {   // 사이클이 생기는 경우
            continue;
        }
        sum += w;
        cnt++;

        if (cnt == v - 1) {    // 필요한 간선을 모두 찾은 경우
            return sum;
        }
    }
    // MST 못 만든 경우
    return 0;
}

int main() {
    int v, e, a, b, c;
    // 입력
    cin >> v >> e;

    // 초기화
    vector<tp> edge;
    parent.assign(v + 1, -1);

    while (e--) {
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());

    // 연산 & 출력
    cout << kruskal(v, edge);
    return 0;
}