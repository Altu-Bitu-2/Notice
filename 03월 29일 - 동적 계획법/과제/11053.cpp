#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 1.
 *
 * 강의자료 점화식
 *
 * 시간 복잡도 O(n^2)
 */
int lis(int n, vector<int> &arr) {
    vector<int> dp(n, 1);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) { //증가하는 관계라면
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]); //최장 길이 갱신
    }
    return ans;
}

/**
 * 2.
 *
 * dp[i] : 증가하는 부분 수열의 길이가 i인 수 중에 가장 작은 수
 * idx : 가장 긴 증가하는 부분 수열의 길이
 *
 * 시간 복잡도 O(nk) (k는 idx의 크기)
 *
 * -> k가 n이 될 수 있으므로 이론상 시간복잡도는 O(n^2)으로 동일하지만,
 *    증가하는 관계일 때 break를 해줌으로써 실제 연산횟수는 더 적어서 1번 함수보다 빠른 풀이
 *
 * 해설 : https://myunji.tistory.com/214
 */
int lisAdv(int n, vector<int> &arr) {
    vector<int> dp(n + 1, 0); //dp[1]을 갱신하기 위해 dp[0] = 0으로 설정
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = idx; j >= 0; j--) {
            if (arr[i] > dp[j]) { //증가하는 관계라면
                dp[j + 1] = arr[i];
                if (j == idx) { //최장 길이 갱신
                    idx++;
                }
                break;
            }
        }
    }
    return idx;
}

/**
 * 3.
 *
 * lisAdv에서 line 36~43의 과정을 이분탐색으로 구현
 *
 * 시간 복잡도 O(nlogk) (k는 dp의 크기)
 * 해설 : https://myunji.tistory.com/270
 */
int lisFinal(int n, vector<int> &arr) {
    vector<int> dp;

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin(); //arr[i] 이상의 값이 처음 나오는 위치
        if (pos == dp.size()) { //arr[i]가 가장 크다면 pos 값이 dp.size()와 같음 -> 최장 길이 갱신
            dp.push_back(arr[i]);
        }
        dp[pos] = arr[i]; //dp[pos]의 값이 arr[i]이상이므로 더 작은 arr[i]로 덮어 씌우기
    }
    return dp.size();
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산 & 출력
    cout << lis(n, arr);
    return 0;
}