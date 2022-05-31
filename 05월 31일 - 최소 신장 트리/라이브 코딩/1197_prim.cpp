#include <iostream>
#include <queue>

using namespace std;

const int INF = 1e6 + 1;
typedef pair<int, int> ci;

int prim(int v, int start, vector<vector<ci>> &graph) {
    int sum = 0;  //간선 비용의 합
    vector<bool> visited(v + 1, false);  //정점 방문 여부 (다익스트라와 달리 프림에선 필요!)
    vector<int> dist(v + 1, INF);  //각 정점까지의 비용 (없어도 상관없으나, 사용하면 메모리를 좀 더 아낄 수 있음)
    priority_queue<ci, vector<ci>, greater<>> pq;

    //초기화
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto[curr_w, curr] = pq.top();
        pq.pop();

        if (visited[curr]) { //이미 확인했던 정점
            continue;
        }
        visited[curr] = true;  //방문 처리
        sum += curr_w;  //MST 간선 가중치 총 합에 더해줌

        for (auto[next_w, next]: graph[curr]) {
            if (!visited[next] && dist[next] > next_w) { //미방문 정점이면서 더 짧은 가중치가 등장한 경우
                dist[next] = next_w;
                pq.push({next_w, next});
            }
        }
    }
    return sum;
}

int main() {
    int v, e, a, b, c;
    // 입력
    cin >> v >> e;
    vector<vector<ci>> graph(v + 1, vector<ci>(0));

    while (e--) { //무방향 그래프
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    //연산 & 출력
    cout << prim(v, 1, graph);
    return 0;
}