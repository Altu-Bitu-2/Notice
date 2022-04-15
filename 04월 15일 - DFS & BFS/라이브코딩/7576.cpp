#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

int bfs(int n, int m, int cnt, vector<vector<int>> &matrix, queue<ci> &que) {
    // 상, 하, 좌, 우
    int dr[] = {-1, +1, 0, 0};
    int dc[] = {0, 0, -1, +1};

    int t = 0;  // 현재 시간 기록

    while (!que.empty()) {
        auto[r, c] = que.front();   // r = que.front().first; c = que.front().second;
        que.pop();
        t = matrix[r][c];
        for (int i = 0; i < 4; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            // (중요) 새로운 좌표가 범위 안에 있는지 확인한 뒤에 접근해야 한다.
            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && matrix[new_r][new_c] == 0) {
                que.push({new_r, new_c});
                matrix[new_r][new_c] = t + 1;   // 인접해있던 익은 토마토의 다음날에 익는다.
                cnt--;  // 익지 않은 토마토의 수를 줄여줌
            }
        }
    }
    // 다 익었다면, 걸린 시간 출력
    return (cnt == 0 ? t - 1 : -1);
}

int main() {
    int n, m;
    // 입력
    cin >> m >> n;  // 행렬 반대로 되어 있니 주의!
    vector<vector<int>> matrix(n, vector<int>(m, 0));   // 각 토마토의 정보를 저장할 2차원 벡터
    queue<ci> que;  // 탐색을 하기 위해 사용할 큐

    int cnt = 0;    // 익지 않은 토마토 수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) { // 이미 익은 토마토의 좌표를 큐에 삽입 -> 탐색의 시작점
                que.push({i, j});
            } else if (matrix[i][j] == 0) { // 익지 않은 토마토의 개수 카운트
                cnt++;
            }
        }
    }
    // 연산 + 출력
    cout << bfs(n, m, cnt, matrix, que);
    return 0;
}