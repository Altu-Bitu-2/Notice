#include <vector>
#include <iostream>

using namespace std;

vector<vector<vector<bool>>> board;

//현재 상태가 조건에 만족하는지 (x, y) 중심으로 확인
bool validate(int x, int y, int p, int n) {
    if (p == 0) { //기둥
        if (y == 0) { //바닥 위
            return true;
        }
        if (board[x][y][1] || (x > 0 && board[x - 1][y][1])) { //보의 왼쪽/오른쪽 끝
            return true;
        }
        if (y > 0 && board[x][y - 1][0]) { //기둥 위
            return true;
        }
    } else { //보
        if (y > 0 && board[x][y - 1][0]) { //왼쪽 끝이 기둥 위
            return true;
        }
        if (x < n && y > 0 && board[x + 1][y - 1][0]) { //오른쪽 끝이 기둥 위
            return true;
        }
        if (x > 0 && x < n && board[x - 1][y][1] && board[x + 1][y][1]) { //양쪽 끝이 보와 연결
            return true;
        }
    }
    return false;
}

//(x, y)에 있는 구조물을 삭제할 수 있는지 확인
bool checkRemovable(int x, int y, int n) {
    int dx[3] = {-1, 0, 1};
    int dy[3] = {-1, 0, 1};
    //기둥이 삭제된 경우, 해당 기둥 위에 보가 있었을 수 있으므로 (조건 2-b) 대각선도 확인이 필요
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int nx = x + dx[i];
            int ny = y + dy[j];
            if (nx < 0 || nx > n || ny < 0 || ny > n) {
                continue;
            }
            for (int k = 0; k < 2; k++) {
                if (board[nx][ny][k] && !validate(nx, ny, k, n)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    board.assign(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false))); //현재 설치 현황
    //시뮬레이션
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int p = build_frame[i][2];
        int cmd = build_frame[i][3];
        if (!cmd) { //삭제
            board[x][y][p] = false;
            //삭제할 수 없으면
            if (!checkRemovable(x, y, n)) {
                board[x][y][p] = true;
            }
        } else if (validate(x, y, p, n)) { //설치 가능한 경우
            board[x][y][p] = true;
        }
    }
    //결과
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                if (board[i][j][k]) {
                    answer.push_back({i, j, k});;
                }
            }
        }
    }
    return answer;
}

/**
 * [기둥과 보 설치]
 * 들어오는 입력에 대해 설치 또는 삭제 이후에도 기본 조건에 만족하는지 확인
 *
 * [기본 조건]
 * 1. 기둥
 *     a. 바닥 위
 *     b. 보의 한 쪽 끝
 *     c. 다른 기둥 위
 * 2. 보
 *     a. 한쪽 끝이 기둥 위
 *     b. 양쪽 끝이 보와 연결
 *
 * - 설치: 설치하려는 좌표가 조건을 만족하는지 확인
 * - 삭제: 해당 기둥/보를 삭제했을 시 영향을 받는 인접한 기둥/보가 여전히 조건을 만족하고 있는지 확인
 */
int main() {
    int n = 5;
    vector<vector<int>> build_frame = {{1, 0, 0, 1},
                                       {1, 1, 1, 1},
                                       {2, 1, 0, 1},
                                       {2, 2, 1, 1},
                                       {5, 0, 0, 1},
                                       {5, 1, 0, 1},
                                       {4, 2, 1, 1},
                                       {3, 2, 1, 1}};
    vector<vector<int>> ans = solution(n, build_frame);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}