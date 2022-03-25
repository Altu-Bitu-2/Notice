#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 15;

int n, ans;
vector<int> check(SIZE);

bool promising(int num) {
    int idx = 0;
    while (idx < num) { //이미 놓여있는 모든 퀸에 대해
        // abs(check[num] - check[idx]) : 두 퀸의 행 차이
        // num - idx : 두 퀸의 열 차이 (idx < num이므로  항상 양수)
        // 따라서 두 퀸의 행 차이와 열 차이가 같으면 두 퀸을 잇는 선의 기울기의 절댓값이 1이 되므로, 같은 대각선에 위치한다는 뜻
        if (check[num] == check[idx] || abs(check[num] - check[idx]) == (num - idx)) { //같은 행, 같은 대각선 체크
            return false;
        }
        idx++;
    }
    return true;
}

void backtracking(int cnt) {
    if (cnt == n) { //기저 조건
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        check[cnt] = i; //i행 cnt열에 퀸 배치
        if (promising(cnt)) {
            backtracking(cnt + 1);
        }
    }
}

/**
 * [백트래킹 풀이]
 *
 * 가지치기 시 유망성 검사하는 부분의 시간복잡도 O(n)
 *
 * 시간 약 4360ms
 *
 * 해설 : https://myunji.tistory.com/201
 */

int main() {
    //입력
    cin >> n;

    //연산
    backtracking(0);

    //출력
    cout << ans << '\n';
    return 0;
}