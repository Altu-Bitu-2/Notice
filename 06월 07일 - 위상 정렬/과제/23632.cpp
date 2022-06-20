#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

//위상정렬
vector<int> topologicalSort(int t, int n, vector<int> &indegree, matrix &resources, matrix &graph) {
    queue<pair<int, int>> q; //first:진입차수가 0인 건물, second:시간
    vector<bool> check(n + 1, false); //생산 자원 체크 배열
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) {
            q.push({i, 0});
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int curr_t = q.front().second;
        q.pop();

        if (curr_t > t) {
            break;
        }
        result.push_back(x);
        for (int i = 0; i < resources[x].size(); i++) {
            int resource = resources[x][i];
            if (check[resource]) {
                continue;
            }
            check[resource] = true;
            for (int j = 0; j < graph[resource].size(); j++) {
                int building = graph[resource][j];
                indegree[building]--;
                if (!indegree[building]) {
                    q.push({building, curr_t + 1});
                }
            }
        }
    }
    return result;
}

/**
 * [쿠키런 킹덤]
 *
 * 건물마다 필요로 하는 자원의 관계를 그래프로 표현하여 위상정렬을 사용해 제한 시간(t) 이내에 지을 수 있는 건물들을 구함
 * - 그래프 관계: 필요로 하는 자원 -> 건물
 * - 이때, 각 건물마다 생산하는 자원이 여러 개이므로 위상정렬에서 연결된 정점의 진입차수를 감소하는 부분에서 생산하는 자원을 모두 검사해야 함
 * - 위 과정에서 서로 다른 건물끼리 생산하는 자원이 겹칠 수 있으므로, 이미 생산한 자원은 체크를 해줌
 * - 위상정렬하다 제한 시간을 넘으면 종료
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t, cnt, resource, building;

    //입력
    cin >> n >> m >> t;
    vector<int> indegree(n + 1, 0);
    matrix graph(n + 1, vector<int>(0));
    matrix resources(n + 1, vector<int>(0)); //각 건물이 생산하는 자원들
    for (int i = 0; i < m; i++) { //이미 지어진 건물
        cin >> building;
    }
    for (int i = 1; i <= n; i++) { //건물이 생산하는 자원
        cin >> cnt;
        while (cnt--) {
            cin >> resource;
            resources[i].push_back(resource);
        }
    }
    for (int i = 0; i < n - m; i++) { //건물마다 필요한 자원
        cin >> building >> cnt;
        indegree[building] = cnt;
        while (cnt--) {
            cin >> resource;
            graph[resource].push_back(building);
        }
    }

    //연산
    vector<int> result = topologicalSort(t, n, indegree, resources, graph);
    sort(result.begin(), result.end());

    //출력
    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}