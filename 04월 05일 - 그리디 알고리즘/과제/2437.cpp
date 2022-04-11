#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findUnmeasurable(vector<int> &weight) {
    int sum = 0;

    for (int i = 0; i < weight.size(); i++) {
        if (sum + 1 < weight[i]) {
            return sum + 1;
        }
        sum += weight[i];
    }
    return sum + 1;
}

/**
 * [저울]
 *
 * 작은 값부터 측정 가능한지 파악해야 하므로, 오름차순으로 정렬한다.
 * 현재 0부터 scope까지 모든 무게를 빠짐없이 측정가능하다고 했을 때, 새로운 무게는 scope + 1보다 작거나 같아야 한다.
 * ex) 현재 1~5까지 측정 가능한데, 다음 값이 7인 경우 -> 6은 측정 불가
 *
 * 만약 이 조건을 만족할 경우, 측정 가능한 범위는 [1, scope + 새로운 무게]로 갱신된다.
 * 모든 저울을 살펴봤는데도 비어있는 값이 없으면, scope + 1 리턴
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    //정렬
    sort(weight.begin(), weight.end());

    //연산 & 출력
    cout << findUnmeasurable(weight);
    return 0;
}