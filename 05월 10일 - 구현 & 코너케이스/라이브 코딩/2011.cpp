//
// Created by BaeSuA on 2022-05-10.
//

#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6; //모듈러 상수 선언

int cntPassword(int n, string &s) {
    vector<int> dp(n + 1, 0);
    if (s[0] == '0') { //첫 시작이 '0'인 경우 -> 암호 만들 수 없음
        return 0;
    }

    //입력 문자열과 dp 배열의 인덱스를 맞추기 위해서 앞에 공백 문자 더하기
    s = ' ' + s;
    //첫 번째 문자의 암호 해석 경우의 수 1로 초기화. dp[0]은 더미 인덱스.
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] == '0' && (s[i - 1] < '1' || s[i - 1] > '2')) { //30, 40 이런 경우 암호 해독 불가
            return 0;
        }
        if (s[i] != '0') { //한 글자 암호 해석 가능
            dp[i] += dp[i - 1]; //dp[i-1]에서 이어서 암호 해석
        }
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
            dp[i] += dp[i - 2]; //dp[i-2]에서 이어서 암호 해석
        }
        dp[i] %= MOD;
    }
    return dp[n];
}

int main() {
    string s;

    //입력
    cin >> s;

    //연산 & 출력
    cout << cntPassword(s.length(), s);
    return 0;
}