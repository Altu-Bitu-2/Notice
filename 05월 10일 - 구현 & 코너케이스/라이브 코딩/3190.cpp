//
// Created by BaeSuA on 2022-05-10.
//

#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) {
    //우, 상, 좌, 하
    int dr[4] = {0, -1, 0, 1};
    int dc[4] = {1, 0, -1, 0};

    //뱀 초기화
    deque<ci> snake; //뱀 위치 정보
    snake.push_front({0, 0});
    board[0][0] = 1;

    int t = 0, head_dir = 0; //시간
    while (true) {
        t++;
        //뱀의 머리가 위치하게 될 칸
        int nr = snake.front().first + dr[head_dir];
        int nc = snake.front().second + dc[head_dir];

        //게임 종료 조건: 벽에 부딪히거나, 자기자신의 몸에 부딪힘
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1) {
            break;
        }
        if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리를 지움
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        //뱀이 몸 길이를 늘려서 머리를 다음 칸에 위치시킴
        snake.push_front({nr, nc});
        board[nr][nc] = 1;

        //이번에 방향을 변환하는지 확인
        if (cmd[t] == 'L') { //왼쪽 회전
            head_dir = (head_dir + 1) % 4;
        } else if (cmd[t] == 'D') { //오른쪽 회전
            head_dir = (head_dir + 3) % 4;
        }
    }
    return t;
}

int main() {
    int n, k, row, col, l, x;
    char c;

    //입력
    cin >> n >> k;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        cin >> row >> col;
        board[row - 1][col - 1] = 2; //사과 표시
    }
    cin >> l;
    map<int, char> cmd;
    for (int i = 0; i < l; i++) { //회전 정보
        cin >> x >> c;
        cmd[x] = c;
    }

    //연산 & 출력
    cout << playGame(n, board, cmd);
    return 0;
}