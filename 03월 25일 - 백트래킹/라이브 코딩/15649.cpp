//
// Created by BaeSuA on 2022-03-25.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

//재귀함수 사용 시, 함수를 계속 호출할 때 매개변수도 생성되므로 전역변수로 선언하는 것이 더 효율적
int n, m;
vector<int> num(SIZE);
vector<bool> check(SIZE + 1);

void backtracking(int cnt) { //cnt: 수열의 인덱스
    if (cnt == m) { //m개의 수열 만든 경우 (기저 조건)
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) { //i: 고르려는 수
        if (!check[i]) { //현재 수열에 해당 수가 없다면 -> 사용 가능
            num[cnt] = i; //사용
            check[i] = true;
            backtracking(cnt + 1); //다음 인덱스 수 호출
            //다시 돌아왔을 때
            check[i] = false; //원래 상태로 돌려놓음
        }
    }
}

int main() {
    //입력
    cin >> n >> m;

    //연산
    backtracking(0);
    return 0;
}