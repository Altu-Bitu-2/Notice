//
// Created by BaeSuA on 2022-03-04.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr; //수열

//버블 정렬
//n = 5 -> 4+3+2+1 = 10
void bubbleSort(int n) {
    int cnt = 0; //연산 횟수

    for (int i = 0; i < n - 1; i++) { //마지막 원소는 자동으로 정렬되므로 n-1까지 반복
        //0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0 ~ 1 까지 정렬
        for (int j = 0; j < n - i - 1; j++) { //i는 이미 정렬된 수의 개수와 같으므로 이를 제외하고 비교
            if (arr[j] > arr[j + 1]) { //왼쪽이 더 크다면
                //swap 함수 구현
                //(python3) arr[j], arr[j+1] = arr[j+1], arr[j] 로 구현 가능!
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
                swap(arr[j], arr[j + 1]); //두 원소 바꾸기
            }
            cnt++;
        }
    }
    //cout << "기본 버블 정렬 count: " << cnt << '\n';
}

//향상된 버블 정렬
//n = 5 -> 4+3+2+1 = 10 ?
void bubbleSortAdv(int n) {
    int cnt = 0; //연산 횟수

    for (int i = 0; i < n - 1; i++) { //마지막 원소는 자동으로 정렬되므로 n-1까지 반복
        bool isSwap = false; //두 원소 바뀌었는지 확인
        //0 ~ n-1까지 정렬 -> 0 ~ n-2까지 정렬 -> ... -> 0 ~ 1 까지 정렬
        for (int j = 0; j < n - i - 1; j++) { //i는 이미 정렬된 수의 개수와 같으므로 이를 제외하고 비교
            if (arr[j] > arr[j + 1]) { //왼쪽이 더 크다면
                isSwap = true;
                swap(arr[j], arr[j + 1]); //두 원소 바꾸기
            }
            cnt++;
        }
        if (!isSwap) { //한 번도 바뀐 적이 없다면
            break; //아래 더 이상 연산이 없다면 바로 return 하는 것이 좋음
        }
    }
    //cout << "향상된 버블 정렬 count: " << cnt << '\n';
}

int main() {
    int n;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //연산
    //bubbleSort(n);
    bubbleSortAdv(n);
    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}