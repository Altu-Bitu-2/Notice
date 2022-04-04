#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10;

vector<int> dp(MAX + 1);

//top-down 방식 dp 채우기
int numberOfCasesTop(int n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (dp[n]) {
        return dp[n];
    }
    for (int i = 1; i <= 3; i++) {
        dp[n] += numberOfCasesTop(n - i);
    }
    return dp[n];
}

/**
 * [top-down 접근]
 * n부터 시작해서 -1, -2, -3한 수의 경우의 수 먼저 구함
 * 0미만일 경우 합으로 나타낼 수 없는 경우이므로 0 리턴
 * 이미 dp[n] 값이 있을 경우, 바로 리턴
 */

int main() {
    int t, n;

    //입력
    cin >> t;
    while (t--) {
        cin >> n;

        //연산 & 출력
        cout << numberOfCasesTop(n) << '\n';
    }
    return 0;
}