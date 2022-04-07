#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

ll getCost(priority_queue<ll, vector<ll>, greater<>> &pq) {
    ll ans = 0;

    while (pq.size() > 1) {
        ll card1 = pq.top();
        pq.pop();
        ll card2 = pq.top();
        pq.pop();
        ans += card1 + card2;
        pq.push(card1 + card2);
    }
    return ans;
}

/**
 * [파일 합치기 3]
 *
 * - 파일을 전부 합치기 위해서는 어차피 하나로 만들어야 한다!
 * - 이 때, 여러번 더해지는 값은 작을 수록 좋다
 * - 따라서, 현재 가장 작은 파일 2개를 합쳐야 비용을 최소화 할 수 있다.
 * -> 최소 힙으로 구현
 *
 * !주의! 파일의 개수는 최대 1,000,000 이고 각 크기의 최대는 10,000이므로
 *       정답의 최댓값이 10^10으로 int 범위를 넘기 때문에 long long 써야 함
 */

int main() {
    int t, k, file;

    //입력
    cin >> t;
    while (t--) {
        priority_queue<ll, vector<ll>, greater<>> pq; //최소힙

        //입력
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> file;
            pq.push(file);
        }

        //연산 & 출력
        cout << getCost(pq) << '\n';
    }
    return 0;
}