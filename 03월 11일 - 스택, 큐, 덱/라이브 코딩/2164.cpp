//
// Created by BaeSuA on 2022-03-11.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    queue<int> q;

    //입력
    cin >> n;
    //카드 초기화
    for (int i = 1; i <= n; i++) {
        q.push(i); //큐 삽입
    }
    while (q.size() != 1) { //반복문 탈출 조건: 큐에 카드가 1장 남음
        //!주의! 해당 문제의 경우 항상 최소 1개의 카드가 있음이 보장되었기에 empty() 체크 안한 것
        q.pop(); //가장 위 카드 버리기
        q.push(q.front()); //위에 있는 카드 맨 아래로 옮기기
        q.pop(); //옮겼으므로 카드 제거
    }
    //출력
    cout << q.front(); //가장 마지막 남은 카드
    return 0;
}