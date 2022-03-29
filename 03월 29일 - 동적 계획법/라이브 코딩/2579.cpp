//
// Created by BaeSuA on 2022-03-29.
//

#include <iostream>
#include <vector>

using namespace std;

int maxScore(int n, vector<int> &score) {
    vector<int> dp(n + 1, 0); //dp[i] = i번째 계단을 마지막으로 생각했을 때의 점수 최댓값, 각 계단까지의 최댓값 저장

    if (n == 1) { //인덱스 에러 방지를 위해 n = 1일 경우 바로 리턴
        return score[1];
    }

    dp[1] = score[1]; //1번째 계단은 해당 칸 밟는게 최대
    dp[2] = score[1] + score[2]; //2번째 계단은 1번째와 2번째 밟는게 최대
    for (int i = 3; i <= n; i++) { //i: 현재 마지막 계단
        //2칸 전에서 온 경우(2칸 이동), 3칸 전 + 2칸 이동해서 1칸 전으로 온 경우(1칸 이동) 중 최댓값
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    }
    return dp[n];
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> score(n + 1, 0); //계단 점수
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    //연산 & 출력
    cout << maxScore(n, score);
    return 0;
}