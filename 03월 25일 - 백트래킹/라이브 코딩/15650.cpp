//
// Created by BaeSuA on 2022-03-25.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);

void backtracking(int cnt, int start) { //cnt: 수열 인덱스, start: 현재 탐색 시작하는 원소 값
    if (cnt == m) { //m개 수 고름 (기저 조건)
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) { //i: 고르려는 수
        num[cnt] = i;
        backtracking(cnt + 1, i + 1);
    }
}

int main() {
    //입력
    cin >> n >> m;

    //연산
    backtracking(0, 1);
    return 0;
}