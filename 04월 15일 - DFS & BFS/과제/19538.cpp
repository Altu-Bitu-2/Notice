#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {
    vector<int> rest(n + 1, 0); //각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q;

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0;
        q.push(init[i]);
    }

    //루머 믿어야 하는 주변인 수 초기화
    for (int i = 1; i <= n; i++) {
        rest[i] = (people[i].size() + 1) / 2;
    }

    while (!q.empty()) {
        int curr = q.front(); //현재 사람
        int t = ans[curr]; //루머 믿은 시간
        q.pop();

        for (int i = 0; i < people[curr].size(); i++) {
            int next = people[curr][i];
            if (ans[next] > -1) { //이미 루머를 믿는 다면
                continue;
            }
            rest[next]--;
            if (!rest[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1;
                q.push(next);
            }
        }
    }
    return ans;
}

/**
 * [루머]
 *
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크 배열을 루머를 믿는 시간을 저장하는 배열로 대체함
 *    ans[i] = -1 일 경우, i는 루머를 믿지 않는다
 *    ans[i] = t인 경우, i는 t분 부터 루머를 믿기 시작함
 * 각자가 루머를 믿기 위해 주변인의 절반 이상이 루머를 믿어야 하므로, 각 사람이 루머를 믿기까지 루머를 믿는 주변인 몇명이 남았는지를 리스트에 기록한다.
 * 남은 사람이 0인 순간, 해당 사람은 루머를 믿기 시작
 */

int main() {
    int n, m, input;

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    vector<vector<int>> people(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        while (true) {
            cin >> input;
            if (!input) {
                break;
            }
            people[i].push_back(input);
        }
    }

    //최초 유포자 입력
    cin >> m;
    vector<int> init(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> init[i];
    }

    //연산
    vector<int> ans = bfs(people, init, n);

    //출력
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}