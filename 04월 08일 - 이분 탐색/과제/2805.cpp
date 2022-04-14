#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {
    ll sum = 0;
    for (int i = 0; i < tree.size(); i++) {
        if (height >= tree[i]) {
            return sum;
        }
        sum += (tree[i] - height);
    }
    return sum;
}

int upperSearch(int left, int right, int target, vector<int> &tree) {
    while (left <= right) {
        int mid = (left + right) / 2;
        ll tree_cnt = cntTree(mid, tree);

        if (tree_cnt >= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left - 1;
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    vector<int> tree(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end(), greater<>());

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);
    return 0;
}