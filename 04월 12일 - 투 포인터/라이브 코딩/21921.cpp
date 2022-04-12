//
// Created by BaeSuA on 2022-04-12.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

//슬라이딩 윈도우로 최대 방문자 수(first)를 구하고, 그 기간의 개수(second)를 리턴
ci maxVisitor(int n, int x, vector<int> &visitor) {
    //윈도우 초기화
    int section_visitor = 0; //방문자 수 합
    for (int i = 0; i < x; i++) { //첫날부터 x일 동안의 방문자 수
        section_visitor += visitor[i];
    }

    int ans = section_visitor; //최대 방문자 수
    int cnt = 1; //최대 방문자 수의 기간의 개수
    for (int i = x; i < n; i++) { //슬라이딩, i: 윈도우에 새롭게 추가되는 영역
        section_visitor -= visitor[i - x]; //이번 윈도우에서 제외되는 값
        section_visitor += visitor[i]; //이번 윈도우에서 추가되는 값
        if (section_visitor > ans) { //최대 방문자 수가 갱신된다면
            ans = section_visitor;
            cnt = 1; //기간의 개수 1로 초기화
        } else if (section_visitor == ans) { //현재 최대 방문자 수와 같다면
            cnt++;
        }
    }
    return {ans, cnt};
}


int main() {
    int n, x;

    //입력
    cin >> n >> x;
    vector<int> visitor(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> visitor[i];
    }

    //연산
    ci ans = maxVisitor(n, x, visitor);

    //출력
    if (!ans.first) { //최대 방문자 수가 0명 이라면
        cout << "SAD\n";
        return 0;
    }
    cout << ans.first << '\n' << ans.second;
    return 0;
}