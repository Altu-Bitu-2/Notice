#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬 + DP
vector<int> topologicalSort(int n, vector<int> &t, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = t[i];
        if (!indegree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            dp[next_node] = max(dp[next_node], dp[node] + t[next_node]);

            indegree[next_node]--;
            if (!indegree[next_node]) {
                q.push(next_node);
            }
        }
    }
    return dp;
}

/**
 * [게임 개발]
 *
 * - ACM Craft (1005) 와 동일한 문제
 * - 최소 시간 = 건물을 동시에 지을 수 있는 건 최대한 동시에 지어야 최소 시간이 걸리므로 그 전 정점 중 가장 오래 걸리는 시간을 선택
 */

int main() {
    int n, input;

    //입력
    cin >> n;
    vector<int> t(n + 1, 0); //건물을 짓는데 걸리는 시간
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        while (cin >> input) {
            if (input == -1) {
                break;
            }
            graph[input].push_back(i);
            indegree[i]++;
        }
    }

    //연산
    vector<int> ans = topologicalSort(n, t, indegree, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}