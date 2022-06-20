#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

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

int kruskal(int n, int idx, vector<tp> &edge) {
    int cnt = 0, sum = 0;
    for (int i = idx; i < edge.size(); i++) {
        int dist = get<0>(edge[i]);
        int x = get<1>(edge[i]);
        int y = get<2>(edge[i]);
        if (!unionNodes(x, y)) {
            continue;
        }
        sum += dist;
        cnt++;
        if (cnt == n - 1) {
            return sum;
        }
    }
    return 0; //mst를 만들 수 없음
}

/**
 * [MST 게임]
 *
 * MST 알고리즘을 여러 번 실행해도 될까?
 * 1. 크루스칼 알고리즘의 시간 복잡도는 O(ElogE)
 *    이는 오직 간선을 정렬하는 연산의 시간 복잡도!
 *    즉, 모든 간선을 한 번 정렬해서 저장해두면 이후 몇 번의 알고리즘을 수행하여도 연산 시간에 큰 영향이 없음
 * 2. 간선 재사용을 위해 우선순위 큐가 아닌 벡터에 저장하고 크루스칼 알고리즘 k번 실행
 * 3. 매번 크루스칼을 수행할 때마다 제일 먼저 추가한 간선을 제외함
 *    -> 첫번째 간선은 모든 점이 분리된 상태에서 들어오기 때문에 무조건 사용하게 되어 있고, 이는 사용한 간선 중 가장 짧은 간선
 *    -> 제외될 간선은 배열의 첫번째 간선부터 순차적 제외
 * 4. 만약 한 번 MST를 만들 수 없다는게 확인됐다면 이후에도 MST를 만들 수 없으므로 flag 변수로 불필요한 연산 절약
 */
int main() {
    int n, m, k, x, y;

    cin >> n >> m >> k;
    vector<tp> edge;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        edge.push_back({i, x, y});
    }

    bool flag = false;
    for (int i = 0; i < k; i++) {
        if (flag) { //더이상 mst를 만들 수 없음
            cout << 0 << ' ';
            continue;
        }
        parent.assign(n + 1, -1); //초기화
        int ans = kruskal(n, i, edge);
        if (ans == 0) {
            flag = true;
        }
        cout << ans << ' ';
    }
    return 0;
}