//
// Created by BaeSuA on 2022-05-03.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7; //최대 n-1개의 간선을 지나므로 n * (가중치 최대값)

void floydWarshall(int n, vector<vector<int>> &graph) {
    for (int k = 1; k <= n; k++) { //중간 정점
        for (int i = 1; i <= n; i++) { //출발 정점
            for (int j = 1; j <= n; j++) { //도착 정점
                //중간에 k를 거쳐서 i에서 j로 갈 때의 비용
                int cost = graph[i][k] + graph[k][j];
                //더 짧은 경로 선택
                graph[i][j] = min(graph[i][j], cost);
            }
        }
    }
}

int main() {
    int n, m, a, b, c;

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) { //자기 자신과의 거리
        graph[i][i] = 0;
    }
    while (m--) {
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c); //비용 여러개일 수 있으므로 최솟값으로
    }

    //연산
    floydWarshall(n, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
        }
        cout << '\n';
    }
    return 0;
}