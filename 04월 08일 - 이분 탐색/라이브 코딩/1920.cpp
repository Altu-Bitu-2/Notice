//
// Created by BaeSuA on 2022-04-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//이분 탐색
bool binarySearch(int left, int right, int target, vector<int> &arr) {
    while (left <= right) { //left 포인터가 right 포인터보다 뒤에 있으면 break
        int mid = (left + right) / 2; //중간값

        if (arr[mid] == target) { //target을 찾음
            return true;
        }
        if (arr[mid] < target) { //중간값이 target보다 작다면 target이 오른쪽에 있음
            left = mid + 1;
        } else { //중간값이 target보다 크다면 target이 왼쪽에 있음
            right = mid - 1;
        }
    }
    return false; //target을 찾지 못함
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

    //정렬!!!!!!!!!
    //이분 탐색을 하기 위해선 반드시 정렬을 해야함
    sort(arr.begin(), arr.end());

    cin >> m;
    while (m--) {
        cin >> input;

        //연산 & 출력
        cout << binarySearch(0, n - 1, input, arr) << '\n';
        //cout << binary_search(arr.begin(), arr.end(), input) << '\n'; //라이브러리 함수 사용
    }
    return 0;
}