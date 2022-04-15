#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> adj_matrix;    // 인접 행렬
vector<bool> visited_recur; // 재귀함수에서 사용할 방문 체크 배열
vector<int> order_recur;    // 재귀함수로 구한 순서 기록

// 재귀함수로 구현한 dfs
void dfsRecur(int n, int curr){
    if (visited_recur[curr]) {  // 이전에 방문했던 정점이라면 종료
        return;
    }
    visited_recur[curr] = true; // 방문 표기
    order_recur.push_back(curr);    // 순서 기록
    for (int next=1; next <=n; next++){
        if (adj_matrix[curr][next]) {   // curr에서 next로 갈 수 있다면
            dfsRecur(n, next);
        }
    }
}

// 반복문으로 구현한 bfs
vector<int> bfs(int n, int v, vector<vector<bool>> &adj_matrix) {
    vector<bool> visited(n + 1, false);   // 방문 체크
    vector<int> order;  // 정답 기록
    queue<int> que;

    que.push(v);    // 우선 시작점부터 큐에 넣고 시작
    visited[v] = true;  // 방문 표기

    // 큐가 빌 때까지
    while (!que.empty()) {
        int curr = que.front();
        order.push_back(curr);
        que.pop();

        // 숫자가 작은 정점부터
        for (int next = 1; next <= n; next++) {
            // 간선이 없거나, 이미 방문했다면
            if (!adj_matrix[curr][next] || visited[next]) {
                continue;
            }
            visited[next] = true;   // 방문 표기
            que.push(next); // 큐에 삽입
        }
    }
    return order;
}

int main() {
    int n, m, v, a, b;
    // 입력
    cin >> n >> m >> v;
    // 초기화
    adj_matrix.assign(n + 1, vector<bool>(n + 1, false));
    visited_recur.assign(n+1, false);

    while (m--) {
        cin >> a >> b;
        // 양방향 간선이므로, 두 방향 모두 표기
        adj_matrix[a][b] = true;
        adj_matrix[b][a] = true;
    }
    // 연산
    dfsRecur(n, v);
    // 출력
    for (auto i: order_recur) {
        cout << i << ' ';
    }
    cout << '\n';
    // 연산 + 출력
    for (auto i: bfs(n, v, adj_matrix)) {
        cout << i << ' ';
    }


    return 0;
}