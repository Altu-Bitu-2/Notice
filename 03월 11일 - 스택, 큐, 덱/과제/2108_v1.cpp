#include <iostream>
#include <vector>
#include <algorithm>    // sort() 사용
#include <numeric>      // accumulate() 사용
#include <cmath>        // floor() || round() 사용

using namespace std;

typedef pair<int, int> ci;  // pair<int, int>에 ci라는 별칭 부여

// 비교함수
bool cmp(const ci &a, const ci &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int findMode(int n, vector<int> &arr) {
    // 정렬된 벡터에서 최빈값을 찾아 반환하고, 만약 최빈값이 여러개라면 두번째로 작은 값을 반환하는 함수
    vector<ci> count;   // 정수의 값와 해당 정수 개수를 pair로 묶어서 저장하는 벡터
                        // first: 값, second: 개수

    int current_idx = 0;    // 현재의 인덱스를 저장하는 변수
    count.push_back({arr[0], 1});   // 첫번째 값을 입력하여 for문에서 index 에러 방지

    for (int i = 1; i < n; i++) {
        // 만약 직전 값과 같은 값이라면
        if (arr[i] == arr[i - 1]) {
            count[current_idx].second++;
        } else {
            // 그렇지 않다면, 새로운 값을 count 벡터에 삽입
            count.push_back({arr[i], 1});
            current_idx++;
        }
    }

    // 만약 값이 한 종류라면, 바로 리턴 -> 아래에서 인덱스 에러 방지
    if (current_idx == 0) {
        return arr[0];
    }

    // 정렬
    // 1. 개수(first)에 대해 내림차순
    // 2. 값(second)에 대해 오름차순
    sort(count.begin(), count.end(), cmp);

    // 최빈 값이 여러개인지 확인
    if (count[0].second == count[1].second) {
        return count[1].first;
    }
    return count[0].first;
}

/**
 * [통계학]
 * 1. 산술 평균 계산 시 실수 자료형 사용, 반올림에 주의
 * 2. n은 홀수 이므로 중앙값은 항상 (n/2)번째 인덱스
 * 3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값
 * 4. 최빈값이 유일한 경우 고려
 */

int main() {
    int n;
    cin >> n;

    // n 최대 500,000 * 입력값 최대 4,000 = 2,000,000,000 <- int 범위 안
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    // 산술평균
    int sum = accumulate(arr.begin(), arr.end(), 0);
    // round() 함수를 사용할 수도 있어요. 다만 -0이 나오지 않도록 조건문을 사용해야 합니다.
    cout << floor((double)sum / n + 0.5) << '\n';

    // 중앙값
    cout << arr[n / 2] << '\n';

    // 최빈값
    cout << findMode(n, arr) << '\n';

    // 범위
    cout << arr[n - 1] - arr[0] << '\n';
}