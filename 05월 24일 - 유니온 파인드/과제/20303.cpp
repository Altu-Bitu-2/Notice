#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

vector<ci> parent;

int knapsack(int n, int k) {
    vector<ci> cnt; //first: 아이들의 수, second: 사탕 개수
    for (int i = 1; i <= n; i++) {
        if (parent[i].first < 0) {
            cnt.push_back({-parent[i].first, parent[i].second});
        }
    }
    vector<int> dp(k, 0); //1부터 k-1까지
    for (int i = 0; i < cnt.size(); i++) {
        for (int j = k - 1; j >= cnt[i].first; j--) {
            dp[j] = max(dp[j], dp[j - cnt[i].first] + cnt[i].second);
        }
    }
    return dp[k - 1];
}

//Find 연산
int findParent(int node) {
    if (parent[node].first < 0) {
        return node;
    }
    return parent[node].first = findParent(parent[node].first);
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) {
        return;
    }
    if (parent[xp].first < parent[yp].first) {
        parent[xp].first += parent[yp].first;
        parent[yp].first = xp;
        parent[xp].second += parent[yp].second;
    } else {
        parent[yp].first += parent[xp].first;
        parent[xp].first = yp;
        parent[yp].second += parent[xp].second;
    }
}

/**
 * [할로윈의 양아치]
 *
 * - weighted union find -> 루트 정점에 아이들의 수(집합 원소 수)와 사탕 개수까지 pair 쌍으로 저장하기
 * - dp(냅색)으로 K명 미만의 아이들에게서 뺏을 수 있는 최대 사탕 수 구하기
 */

int main() {
    int n, m, k, a, b;

    //입력
    cin >> n >> m >> k;
    parent.assign(n + 1, {-1, 0}); //first: 아이들의 수, second: 사탕 개수
    for (int i = 1; i <= n; i++) {
        cin >> parent[i].second;
    }
    while (m--) {
        cin >> a >> b;
        unionInput(a, b);
    }

    //연산 & 출력
    cout << knapsack(n, k);
    return 0;
}