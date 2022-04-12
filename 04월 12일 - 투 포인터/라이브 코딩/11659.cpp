//
// Created by BaeSuA on 2022-04-12.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, num, a, b;

    //입력
    cin >> n >> m;
    vector<int> sum(n + 1, 0); //인덱스를 1부터 시작하면 i=0인 경우를 따로 처리할 필요 없음
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum[i] = sum[i - 1] + num; //첫 번째 수부터 i번째 수까지의 누적합
    }

    //입력 & 구간합 구하기
    while (m--) {
        cin >> a >> b;

        //출력
        cout << sum[b] - sum[a - 1] << '\n'; //a ~ b 구간합
    }
    return 0;
}