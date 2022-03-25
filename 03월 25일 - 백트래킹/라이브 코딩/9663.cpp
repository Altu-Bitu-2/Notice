//
// Created by BaeSuA on 2022-03-25.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 15;

int n, ans;
vector<bool> check_col(SIZE);
vector<bool> check_left(SIZE * 2);
vector<bool> check_right(SIZE * 2);

void backtracking(int row) { //row: 행
    if (row == n) { //n개의 퀸이 모두 놓임 (기저 조건)
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) { //i: 열
        //세로, 좌하향 대각선, 우하향 대각선 모두에 퀸이 없을 경우 -> 퀸 배치
        if (!check_col[i] && !check_left[row + i] && !check_right[row - i + n]) {
            //(row, i)에 퀸 배치 -> 그에 따른 열, 좌하향 대각선, 우하향 대각선 체크해줌
            check_col[i] = true;
            check_left[row + i] = true;
            check_right[row - i + n] = true;
            backtracking(row + 1); //다음 행 호출
            //재탐색이 가능하도록 원래 상태로 돌려주어야 함
            check_col[i] = false;
            check_left[row + i] = false;
            check_right[row - i + n] = false;
        }
    }

}

/**
 * [백트래킹 풀이]
 *
 * 가지치기 시 유망성 검사하는 부분의 시간복잡도 O(1)
 *
 * 시간 약 1680ms
 *
 * !주의! 파이썬 사용 시 python3 말고 pypy3로 제출해야 시간초과 안남
 */

int main() {
    //입력
    cin >> n;

    //연산
    backtracking(0);

    //출력
    cout << ans;
    return 0;
}