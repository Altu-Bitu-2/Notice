#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;
const int INF = 5e6; //최대 n-1개의 간선을 지나게 됨 -> n * (가중치 최대값)

vector<int> bellmanFord(int start, int n, vector<tp> &edges) {
    vector<int> dist(n + 1, 0); //(추가 제출 시) 0으로 초기화한 이유 꼭 적어주세요!

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < edges.size(); j++) {
            int s = get<0>(edges[j]);
            int d = get<1>(edges[j]);
            int w = get<2>(edges[j]);

            if (dist[s] == INF) {
                continue;
            }
            int weight = dist[s] + w;
            if (weight < dist[d]) {
                dist[d] = weight;
                flag = false;
                if (i == n) {
                    return {INF + 1}; //음의 사이클이 생겼음을 INF+1로 나타냄
                }
            }
        }
        if (flag) {
            break;
        }
    }
    return dist;
}

/**
 * [웜홀]
 *
 * 벨만-포드 문제
 *
 * 시간이 되돌아가서 출발 지점에 도착하는 경우 = 음의 사이클이 생긴 경우
 *
 * 특별히 시작점이 주어지지 않았으므로, 벨만-포드를 특정 정점에서 시작하는 경우만 돌릴 시 해당 정점에서 닿을 수 없는 음의 사이클의 존재를 판단할 수 없음
 * 그러나, 모든 정점에서 벨만-포드 연산을 하게 되면 O(n^2*E)의 시간 복잡도가 걸려서 효율적이지 않음
 * => 모든 정점에 도달할 수 있는 임의의 가짜 정점을 만들어서 시작점을 0으로 하는 한 번의 벨만-포드 연산으로 그래프 전체에 대한 음의 사이클 존재 여부 판단!
 * => 이때, 가짜 정점 0에서 모든 정점으로의 거리가 0인 간선이 있다고 가정하여 dist배열을 0으로 초기화
 */

int main() {
    int tc, n, m, w, s, e, t;

    //입력
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> w;
        vector<tp> edges; //간선의 수
        while (m--) { //도로 -> 무방향
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        while (w--) { //웜홀 -> 방향
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        //연산
        vector<int> dist = bellmanFord(0, n, edges);

        //출력
        if (dist[0] == INF + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}