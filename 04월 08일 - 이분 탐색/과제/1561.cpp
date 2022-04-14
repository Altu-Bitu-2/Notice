#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll finalChildren(ll t, vector<int> &rides) {
    ll child = 0;
    for (int i = 1; i < rides.size(); i++) {
        child += (t / rides[i] + 1);
    }
    return child;
}

ll lowerSearch(ll left, ll right, ll target, vector<int> &rides) {
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll child = finalChildren(mid, rides);

        if (child >= target) { //줄의 마지막 아이보다 더 뒤에 있는 아이라면
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int findRides(int n, int m, vector<int> &rides) {
    ll t = lowerSearch(0, (ll) rides[1] * n, n, rides);
    ll child = finalChildren(t, rides);
    for (int i = m; i >= 1; i--) {
        if (t % rides[i] == 0) { //아이가 탐
            if (child-- == n) {
                return i;
            }
        }
    }
}

/**
 * [놀이 공원]
 *
 * n번째 아이가 놀이기구를 타는 시간을 구한 후, 해당 시간에 놀이기구를 타는 아이들을 모두 검사하며 n번째 아이가 타는 놀이기구의 번호를 구한다!
 *
 * 1. n번째 아이가 놀이기구를 타는 시간이 언제인지 parametric search 통해 구함
 *    - 이때, 각 시간 별 놀이기구 타는 아이의 마지막 번호 구하는 공식은 다음과 같음
 *      f(t) = (모든 i(놀이 기구)에 대해서) t/num[i] + n(시간 0일때 놀이기구 타는 아이 수)
 *
 *    - left: 놀이기구 타는 시간의 최소 = 0
 *    - right: 놀이기구 타는 시간의 최대 = 1번 놀이기구 운행 시간 x n (타이트하게 잡으면 최소 운행 시간 x n 이지만 편의상 이렇게 설정)
 *
 *    - n번째 아이가 놀이기구를 타는 첫 시간을 구해야 하므로 lower bound
 *
 * 2. n번째 아이가 놀이기구를 타는 시간을 구했다면, 그 시간에 마지막으로 놀이기구를 타는 아이부터 시작해서
 *    놀이기구를 m부터 탐색하면서 n번째 아이가 몇 번 놀이기구 타는지 구하면 됨!
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> rides(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> rides[i];
    }

    if (n <= m) { //아이의 수가 놀이기구 수보다 적다면
        cout << n;
        return 0;
    }

    //연산 & 출력
    cout << findRides(n, m, rides);
    return 0;
}