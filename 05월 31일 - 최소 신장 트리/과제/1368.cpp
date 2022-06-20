#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 + 1;

int prim(int size, int start, vector<vector<int>> &graph) {
    int sum = 0;
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<bool> visited(size, false); //논 방문 여부
    vector<int> dist(size, INF); //각 논까지의 비용

    //초기화
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;
        sum += cost;

        for (int i = 0; i < size; i++) {
            if (!visited[i] && graph[cur][i] < dist[i]) {
                dist[i] = graph[cur][i];
                pq.push({graph[cur][i], i});
            }
        }
    }
    return sum;
}

/**
 * [물대기]
 *
 * 각 논들 사이의 간선도 고려하고, 우물을 파는 경우도 고려? -> 복잡
 * 논에 추가로 모든 우물과 연결되는 수원이 있다고 가정!
 * ->직접 논에 우물을 파는 경우는 수원과 각 논 사이의 간선 가중치라고 할 수 있음
 * 
 * 0 2 2 2 5
 * 2 0 3 3 4
 * 2 3 0 4 4
 * 2 3 4 0 3
 * 5 4 4 3 0
 * 
 * 인덱스 0 ~ n-1은 논, 인덱스 n은 수원
 * 1개 이상의 논은 반드시 직접 우물을 파야 하므로 수원(n)에서 시작하는 프림 알고리즘
 */
int main() {
    int n, w;

    //입력
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) { //수원으로부터 물을 끌어오는 비용
        cin >> w;
        graph[i][n] = graph[n][i] = w;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j]; //논들 사이에서 물을 끌어오는 비용
        }
    }

    //연산 & 출력
    cout << prim(n + 1, n, graph); //수원에서 시작하는 프림 알고리즘
    return 0;
}