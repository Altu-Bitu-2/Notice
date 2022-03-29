//
// Created by BaeSuA on 2022-03-29.
//

#include <iostream>
#include <vector>

using namespace std;

struct info {
    int w, v;
};

int knapsack1(int n, int k, vector<info> &product) {
    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= n; i++) { //i: 물품
        for (int j = k; j >= product[i].w; j--) { //j: 최대 배낭 무게
            //i번째 물품을 배낭에 넣은 경우와 안 넣은 경우 중 최댓값 저장
            dp[j] = max(dp[j - product[i].w] + product[i].v, dp[j]);
        }
    }
    return dp[k];
}

int knapsack2(int n, int k, vector<info> &product) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) { //i: 현재 넣으려는 물품
        //j: 최대 배낭 무게
        for (int j = 0; j < product[i].w; j++) { //어차피 최대 배낭 무게가 물품 무게보다 작아서 물품을 배낭에 못넣음
            dp[i][j] = dp[i - 1][j]; //그 전의 값 그대로 사용
        }
        for (int j = product[i].w; j <= k; j++) {
            //배낭에 넣은 경우와 안 넣은 경우 중 최댓값 저장
            dp[i][j] = max(dp[i - 1][j - product[i].w] + product[i].v, dp[i - 1][j]);
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;

    //입력
    cin >> n >> k;
    vector<info> product(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> product[i].w >> product[i].v;
    }

    //연산 & 출력
    cout << knapsack1(n, k, product);
    return 0;
}