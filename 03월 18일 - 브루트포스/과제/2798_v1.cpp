#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//prev_permutation()을 활용한 조합을 이용한 풀이
int blackJackC(int n, int m, vector<int> &card) {
    int ans = 0; //정답

    vector<bool> is_selected(n, false); //고른 카드가 true
    for (int i = 0; i < 3; i++) { //3장 카드 고른 것으로 초기화
        is_selected[i] = true;
    }

    do {
        int sum = 0; //고른 3장의 카드 합 저장
        for (int i = 0; i < n; i++) {
            if (is_selected[i]) {
                sum += card[i];
            }
        }
        //m과 가장 가까운 카드 구하기
        if (sum <= m) {
            ans = max(ans, sum);
        }
    } while (prev_permutation(is_selected.begin(), is_selected.end()));
    return ans;
}

//3중 for문 풀이
int blackJackFor(int n, int m, vector<int> &card) {
    int ans = 0; //정답

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = card[i] + card[j] + card[k];
                if (sum > m) { //m을 넘었다면
                    break; //(생각해보세요) 바로 return ans; 를 하면 어떻게 될까요?
                }
                ans = max(ans, sum);
            }
        }
    }
    return ans;
}

/**
 * [ 블랙잭 ] - 단순 구현
 * 카드가 최대 100장이므로,
 * C(100, 3) < 100*100*100 = 1,000,000 -> 브루트포스 충분히 가능
 *
 * ver1. 3중 for문 이용해서 구현
 * +) 코드의 효율성을 높이기 위해, 카드를 사전에 정렬하여 M을 넘어가는 순간 반복 종료 (이때, 한 반복만 빠져나오는 것 주의!)
 *
 * ver2. prev_permutation()을 활용하여 모든 조합을 구해서 구현
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> card(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    //연산
    //조합 풀이
    int ans = blackJackC(n, m, card);

    //3중 for 문 풀이
    //sort(card.begin(), card.end());
    //int ans = blackJackFor(n, m, card);

    //출력
    cout << ans;
    return 0;
}