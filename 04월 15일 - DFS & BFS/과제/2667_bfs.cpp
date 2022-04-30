#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

//단지 내 집 개수 탐색하는 bfs
int bfs(int n, int r, int c, vector<vector<bool>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q;

    //큐 초기화
    q.push({r, c});
    board[r][c] = false;
    int cnt = 1;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || !board[nr][nc]) {
                continue;
            }
            q.push({nr, nc});
            board[nr][nc] = false;
            cnt++;
        }
    }
    return cnt;
}

//단지 수와 단지 내 집 개수 구하는 함수
vector<int> cntComplex(int n, vector<vector<bool>> &board) {
    vector<int> complex;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                int cnt = bfs(n, i, j, board);
                complex.push_back(cnt);
            }
        }
    }
    return complex;
}

/**
 * [단지 번호 붙이기] - bfs
 *
 * 단순 탐색
 * (주의) 단지 내 집의 수를 "오름차순"으로 출력
 *
 * 이 풀이에서는 방문체크 배열을 따로 사용하지 않고, 처음 지도에 표기를 1 -> 0으로 바꾸어 중복으로 탐색하지 않도록 함
 */

int main() {
    int n;
    string s;

    //입력
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    //연산
    vector<int> ans = cntComplex(n, board);
    sort(ans.begin(), ans.end());

    //출력
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}