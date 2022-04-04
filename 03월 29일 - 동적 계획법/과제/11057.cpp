#include <iostream>
#include <vector>

using namespace std;
const int MOD = 10007;

//길이 N에서 일의 자리 수가 0 ~ 9인 오르막 수 모두 더하는 함수
int sumLastCnt(vector<int> &arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans += arr[i];
        ans %= MOD;
    }
    return ans;
}

int upNumberCnt(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(10, 1));

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 10; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }
    return sumLastCnt(dp[n]);
}

/**
 * dp[i][j] = 수의 길이가 i이고, 일의 자리 수가 j인 오르막 수의 개수
 *
 * -> (j보다 작은 수 or j와 같은 수) + j를 하면 오르막 수가 됨
 * -> j보다 작은 수로 끝나는 길이 i - 1 인 오르막 수 개수 + j로 끝나는 길이 i - 1 인 오르막 수 개수
 * -> j보다 작은 수로 끝나고 길이가 i - 1 인 오르막 수의 접근은 길이 i인 오르막 수에서 마지막 수를 j로 대체하는 것으로 해결 가능
 * => dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
 *
 * dp 배열 채운 후, 길이가 n이고 일의 자리 수가 0 ~ 9인 오르막 수 개수 모두 더하면 됨!
 *
 * ex. 길이가 2인 오르막 수의 개수를 구해야 한다면
 *      0  1  2  3  4  5  6  7  8  9
 *  -------------------------------
 *  1 : 1  1  1  1  1  1  1  1  1  1
 *  2 : 1  2  3  4  5  6  7  8  9  10
 *  -> 2행의 값을 모두 더해서 출력!
 *
 *  해당 풀이는 연산 편하게 하기 위해 미리 dp 값 1로 초기화
 *  !주의! 마지막에 길이 n인 오르막 수 모두 더할 때도 모듈러 연산 해야함
 */

int main() {
    int n;

    //입력
    cin >> n;

    //연산 & 출력
    cout << upNumberCnt(n);
    return 0;
}