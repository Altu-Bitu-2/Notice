#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

void greenToRed(int n, vector<vector<char>> &board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G') {
                board[i][j] = 'R';
            }
        }
    }
}

void bfs(int n, int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &board) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q;

    //큐 초기화
    q.push({r, c});
    visited[r][c] = true;
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) {
                continue;
            }
            if (board[nr][nc] != board[cr][cc]) {
                continue;
            }
            q.push({nr, nc});
            visited[nr][nc] = true;
        }
    }
}

int countArea(int n, vector<vector<char>> &board) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) {
                continue;
            }
            bfs(n, i, j, visited, board);
            area++;
        }
    }
    return area;
}

/**
 * [적록색약]
 *
 * 그림의 색을 기준으로 구역을 나누는 문제
 * 1. 적록색약이 아닌 사람 기준으로 구역을 나눈다.
 * 2. 그림의 초록을 모두 빨강으로 바꾼 후, 적록색약인 사람 기준으로 구역을 나눈다.
 */

int main() {
    int n;
    string s;

    //입력
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, ' '));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            board[i][j] = s[j];
        }
    }

    //연산 & 출력
    cout << countArea(n, board) << ' ';
    greenToRed(n, board);
    cout << countArea(n, board);
    return 0;
}