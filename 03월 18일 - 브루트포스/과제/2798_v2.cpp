#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//재귀함수 사용시 함수를 계속 호출하므로 전역변수로 관리하는 것이 더 효율적
int n, m;
vector<int> card;

//백트래킹 풀이
//카드를 중복으로 고르는 걸 방지하기 위해 t 매개변수를 활용해서 그 전에 고른 카드 번호 이후부터 고르도록
int selectCard(int cnt, int t, int sum) { //cnt: 카드 개수, t: 현재 카드 번호, sum: 카드 합
    int ans = 0;
    if (sum > m) { //합이 m을 넘는다면
        return 0;
    }
    if (cnt == 3) { //3장의 카드를 골랐다면
        return sum;
    }
    for (int i = t; i < n; i++) {
        ans = max(ans, selectCard(cnt + 1, i + 1, sum + card[i]));
    }
    return ans;
}

int main() {
    //입력
    cin >> n >> m;
    card.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    //연산 & 출력
    sort(card.begin(), card.end());
    cout << selectCard(0, 0, 0);
    return 0;
}