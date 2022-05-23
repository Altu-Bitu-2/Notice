#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e3;

int n, ans = INF;
vector<bool> is_ward, visited;
vector<int> people;
vector<vector<int>> graph;

//두 선거구의 인구 수 차이 구하는 함수
int calcDiff() {
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        if (is_ward[i]) {
            sum1 += people[i];
        } else {
            sum2 += people[i];
        }
    }
    return abs(sum1 - sum2);
}

//선거구 내의 정점 연결됐는지 탐색하는 dfs 함수
int dfs(int curr, bool state) {
    if (visited[curr]) {
        return 0;
    }
    visited[curr] = true;
    int cnt = 1;
    for (int i = 0; i < graph[curr].size(); i++) {
        if (is_ward[graph[curr][i]] == state) {
            cnt += dfs(graph[curr][i], state);
        }
    }
    return cnt;
}

void backtracking(int cnt, int true_area) {
    if (cnt == n + 1) { //(기저조건) 모든 구역 탐색
        if (true_area == n) {
            return;
        }
        int false_node = 0;
        for (int i = 1; i <= n; i++) {
            if (!is_ward[i]) {
                false_node = i;
                break;
            }
        }
        visited.assign(n + 1, false);
        if (true_area == dfs(1, true) && (n - true_area) == dfs(false_node, false)) {
            ans = min(ans, calcDiff());
        }
        return;
    }
    is_ward[cnt] = true;
    backtracking(cnt + 1, true_area + 1);
    is_ward[cnt] = false;
    backtracking(cnt + 1, true_area);
}

/**
 * [게리맨더링]
 *
 * 1. 구역을 나누는 모든 경우의 수 구하기 - 백트래킹
 * - 두 선거구로 나누는 경우이므로 모든 구역에 대해 true/false로 구분해서 경우의 수 구하기
 * - 이때, 중복 연산 피하기 위해 1번 구역은 true로 고정. (집합끼리 구분할 필요가 없으므로 1번이 false일 때의 경우의 수는 1번이 true일 때와 정확히 일치)
 * 2. 각 경우마다 나눈 두 구역이 조건(구역 내 정점이 모두 연결)을 만족하는지 확인 - dfs
 * - 구역 내 한 정점에서 dfs 탐색을 시작해서 구역 내의 모든 정점을 방문했다면 조건 만족한 것임
 * 3. 두 구역이 조건을 만족한다면 인구 수의 차이 구해서 최솟값 갱신
 */

int main() {
    int cnt, input;

    //입력
    cin >> n;
    people.assign(n + 1, 0);
    graph.assign(n + 1, vector<int>(0)); //인접리스트
    is_ward.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> people[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> cnt;
        while (cnt--) {
            cin >> input;
            graph[i].push_back(input); //양방향 그래프지만, 입력 자체가 양방향으로 들어옴
        }
    }

    //연산
    is_ward[1] = true; //1번 구역 고정
    backtracking(2, 1);

    //출력
    cout << (ans == INF ? -1 : ans);
    return 0;
}