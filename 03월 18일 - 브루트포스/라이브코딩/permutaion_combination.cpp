#include <iostream>
#include <algorithm>

using namespace std;

// 순열 출력 실습
void permutation() {
    // 내림차순 출력
    int arr[] = {4, 3, 2, 1};

    do {
        for (int i = 0; i < 4; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    } while (prev_permutation(arr, arr + 4));

    // 오름차순 출력
//    int arr[] = {1, 2, 3, 4};
//    while (next_permutation(arr, arr+4)) {
//        for (int i=0; i<4; i++) {
//            cout << arr[i] << ' ';
//        }
//        cout << '\n';
//    }
}

// next_permutation 이용해서 조합 구하기
void combination() {
    // 0(false)과 1(true)로 이루어진 임시 벡터의 순열을 구해서, 임시벡터가 true인 것만 선택하는 방식!
    int arr[] = {1, 2, 3, 4};
    bool temp[] = {false, false, true, true};   // false = 0, true = 1

    do {
        for (int i = 0; i < 4; i++) {
//            cout << temp[i] << ' ';
            if (temp[i]) {
                cout << arr[i] << ' ';
            }
        }
        cout << '\n';
    } while (next_permutation(temp, temp + 4));
}

int main() {
    permutation();
    combination();
    return 0;
}