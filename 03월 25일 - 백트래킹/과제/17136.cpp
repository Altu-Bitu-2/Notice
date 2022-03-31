#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 10;
const int INF = 26;

vector<vector<int>> paper(SIZE, vector<int>(SIZE));
vector<int> paper_cnt = {0, 5, 5, 5, 5, 5}; //인덱스 = 색종이 크기

bool promising(int row, int col, int paper_size) {
    for (int i = row; i < row + paper_size; i++) { //색종이 크기 만큼 돌면서 모두 1인지 확인
        for (int j = col; j < col + paper_size; j++) {
            if (paper[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void fill_paper(int row, int col, int paper_size, int fill_value) {
    for (int i = row; i < row + paper_size; i++) {
        for (int j = col; j < col + paper_size; j++) {
            paper[i][j] = fill_value;
        }
    }
}

int backtracking(int idx, int count) { //row: 행, col: 열, count: 색종이 개수
    int ans = INF;

    if (idx == SIZE * SIZE) { //색종이 다 붙임
        return min(ans, count);
    }
    int row = idx / SIZE;
    int col = idx % SIZE;

    if (!paper[row][col]) { //0이라면 -> 색종이 안 붙이므로 넘어감
        return backtracking(idx + 1, count);
    }
    if (ans <= count) { //기존 정답이 더 작으므로 count 값 답 가능성 x
        return INF;
    }

    for (int i = 5; i >= 1; i--) { //5 ~ 1까지 색종이 다 붙여보기
        if (row + i > SIZE || col + i > SIZE || !paper_cnt[i]) {
            continue;
        }
        if (promising(row, col, i)) {
            paper_cnt[i]--;
            fill_paper(row, col, i, 0);
            ans = min(ans, backtracking(idx + 1, count + 1));
            paper_cnt[i]++;
            fill_paper(row, col, i, 1);
        }
    }
    return ans;
}

/**
 * 5x5 색종이부터 1x1 색종이까지 모두 붙여보기
 * -> 필요한 색종이의 "최소" 개수이므로 가장 크기가 큰 5x5부터 시작
 *
 * [가지치기]
 * - 탐색을 하다 아직 색종이를 다 붙이지 않았는데, 개수가 현재 저장된 정답보다 크다면 탐색 종료
 */

int main() {
    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> paper[i][j];
        }
    }

    //연산
    int ans = backtracking(0, 0);

    //출력
    cout << (ans == INF ? -1 : ans); //간단한 출력에선 삼항연산자 사용해도 가독성 좋음
    return 0;
}
