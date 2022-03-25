#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * permutation 이용한 조합 풀이 (브루트 포스) (0ms)
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<bool> is_in_num(n + 1, false); //1 ~ n까지의 수에 대한 조합정보(true / false)

    //연산
    for (int i = 1; i <= m; i++) { //m개의 원소 true로 셋팅
        is_in_num[i] = true;
    }

    do {
        for (int i = 1; i <= n; i++) {
            if (is_in_num[i]) { //true라면 사용이므로 출력
                cout << i << ' ';
            }
        }
        cout << '\n';
    } while (prev_permutation(is_in_num.begin() + 1, is_in_num.end())); //인덱스 1부터 사용

    return 0;
}