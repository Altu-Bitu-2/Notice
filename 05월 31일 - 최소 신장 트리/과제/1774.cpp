#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;

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

double kruskal(int v, vector<tp> &edge) {
    double sum = 0;
    int cnt = 0;

    for (int i = 0; i < edge.size(); i++) {
        double cost = get<0>(edge[i]);
        int x = get<1>(edge[i]);
        int y = get<2>(edge[i]);

        if (!unionNodes(x, y)) {
            continue;
        }
        sum += cost;
        cnt++;
        if (cnt == v - 1) {
            return sum;
        }
    }
    return 0;
}

/**
 * [우주신과의 교감]
 *
 * 4386번 : 별자리 만들기의 응용 문제
 * 이미 연결된 정점들이 존재한다는 것을 제외하고는 4386번과 동일
 *
 * 1. 임의의 두 별에 대한 거리(간선) 모두 구하기
 * 2. 이미 존재하는 통로들 표시
 *    !주의! 통로의 개수가 m개라면 v-m-1개의 간선만 더 추가하면 될까?
 *          이미 연결된 통로들도 사이클을 이룰 수 있기 때문에 유니온 연산을 하며 사이클 없이 연결된 간선만 세기
 * 3. 이미 연결된 통로의 수를 k개라고 하면 v-k-1개의 간선을 추가로 선택
 */
int main() {
    int n, m, a, b, v = 0;
    double x, y;

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1);
    vector<tp> edge;
    vector<ci> star(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        for (int j = 1; j < i; j++) {
            //임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            edge.push_back({sqrt(dx * dx + dy * dy), i, j});
        }
        star[i] = {x, y};
    }

    //연산
    while (m--) {
        cin >> a >> b;
        if (unionNodes(a, b)) { //이미 연결된 통로
            v++;
        }
    }
    sort(edge.begin(), edge.end());

    //연산 & 출력
    cout << fixed;
    cout.precision(2);
    cout << kruskal(n - v, edge);
    return 0;
}
