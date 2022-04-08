//
// Created by BaeSuA on 2022-04-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//lower bound
int lowerBound(int left, int right, int target, vector<int> &arr) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값
        //중간값이 target보다 크다면 target이 왼쪽에 있음
        //중간값이 target과 같다면 왼쪽에 target과 같은 값이 더 있을 수 있음
        if (arr[mid] >= target) {
            right = mid - 1;
        } else { //중간값이 target보다 작다면 target은 오른쪽에 있음
            left = mid + 1;
        }
    }
    /**
     * left를 리턴하는 이유
     * break 직전 left와 right는 같은 곳을 가리킴
     * 이 상태에서 mid가 가리키는 값은 target 미만이기 때문에 left 포인터가 이동하고 break
     * 이 때의 left 값은 target이 되는 첫 지점이므로 lower bound!
     */
    return left;
}

//upper bound
int upperBound(int left, int right, int target, vector<int> &arr) {
    while (left <= right) { //left가 right를 넘어가면 break
        int mid = (left + right) / 2; //중간값
        //중간값이 target보다 작다면 target이 오른쪽에 있음
        //중간값이 target과 같다면 오른쪽에 target과 같은 값이 더 있을 수 있음
        if (arr[mid] <= target) {
            left = mid + 1;
        } else { //중간값이 target보다 크다면 target이 왼쪽에 있음
            right = mid - 1;
        }
    }
    /**
     * left를 리턴하는 이유
     * left가 움직일 때는 arr[mid]가 target 이하일 때
     * arr[mid] == target 일 때, 계속 left = mid + 1이 되다가 left가 target을 초과하는 순간 옴
     * 그 때의 left 값이 upper bound!
     */
    return left;
}

int main() {
    //입출력 속도 향상
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, input;

    //입력
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //정렬!! - 이분 탐색을 하기 위해선 반드시 정렬을 해야함
    sort(arr.begin(), arr.end());

    //입력
    cin >> m;
    while (m--) {
        cin >> input;

        //연산 & 출력
        cout << upperBound(0, n - 1, input, arr) - lowerBound(0, n - 1, input, arr) << ' ';
        //cout << upper_bound(arr.begin(), arr.end(), input) - lower_bound(arr.begin(), arr.end(), input) << ' ';
    }
    return 0;
}