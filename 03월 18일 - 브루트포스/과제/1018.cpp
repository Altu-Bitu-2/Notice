#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 64; //체스판 칸 개수

//(x, y)에서 시작하는 8*8 체스판을 만드는데 필요한 최소 카운트 리턴
//검정으로 시작하는 체스판을 기준으로 계산(b_count) -> 절반(32) 이상이면 흰색으로 시작하는 체스판 카운트(64 - b_count) 리턴
int chessChange(int row, int col, vector<vector<char>> &board) {
    int b_cnt = 0; //B로 시작하는 체스판 만들기 위한 카운트

    for (int i = 0; i < 8; i++) { //행 변화값
        for (int j = 0; j < 8; j++) { //열 변화값
            if ((i + j) % 2 == 0 && board[row + i][col + j] != 'B') {
                b_cnt++;
            } else if ((i + j) % 2 && board[row + i][col + j] != 'W') {
                b_cnt++;
            }

        }
    }

    //최솟값 리턴
    if (b_cnt > SIZE / 2) {
        return SIZE - b_cnt;
    }
    return b_cnt;
}

/**
 * [체스판 다시 칠하기]
 * - 나올 수 있는 체스판의 경우: 2가지
 * - (0, 0)이 검정인 경우, 흰색인 경우
 * - 검정으로 시작하는 체스판의 경우, 인덱스 i+j가 짝수일 때 'B'임을 이용
 *
 * 1.  (0, 0) 인덱스부터 차례로 8*8 체스판 만들 때 바꿔야 하는 칸 수를 계산하고, 그 중 최솟값 구하기
 *
 * 보드 크기 <= 2,500
 * 한 위치에 대한 체스판 비교 연산 = 64번
 * 총 연산 수 = 2,500 * 64 < 1억 -> 브루트 포스 가능
 */

int main() {
    int n, m;
    int ans = SIZE + 1; //정답은 체스판 칸 개수 + 1 로 초기화

    //입력
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m)); //행: n, 열: m
    for (int i = 0; i < n; i++) { //보드 입력
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int cnt = chessChange(i, j, board); //시작인덱스가 (i,j)인 체스판 만드는 최솟값
            ans = min(ans, cnt); //최솟값 갱신
        }
    }

    //출력
    cout << ans << '\n';
    return 0;
}