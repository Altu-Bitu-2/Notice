#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long calTip(int n, vector<int> &tips) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int cur_tip = tips[i] - i;
        if (cur_tip < 0) //음수면 팁에 더하지 않는데 처음에 내림차순 정렬했으므로 아예 break
            break;
        ans += cur_tip;
    }
    return ans;
}

/**
 * 강호가 받을 수 있는 팁이 최댓값이 되려면 팁이 많은 사람의 순위가 높아야함
 * !주의! 주어지는 N의 최대 크기가 100,000이고 팁의 최대 크기가 100,000이므로
 *       정답의 최댓값은 10^5 * (10^5+1) / 2로 int 범위를 넘기 때문에 long long 을 써야 함
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> tips(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tips[i];
    }
    //연산
    sort(tips.begin(), tips.end(), greater<>()); //내림차순 정렬
    //출력
    cout << calTip(n, tips) << '\n';
    return 0;
}