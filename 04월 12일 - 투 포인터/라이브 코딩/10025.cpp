//
// Created by BaeSuA on 2022-04-12.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e6;

//슬라이딩 윈도우로 얼음들의 최대합 구함
int maxIce(int k, int end_point, vector<int> &position) {
    int section = 2 * k + 1; //윈도우 영역
    int section_ice = 0; //윈도우 내의 얼음 합
    //윈도우 초기화
    for (int i = 0; i < section; i++) {
        if (i > end_point) { //윈도우 영역이 양동이가 존재하는 끝 점보다 클 수도 있음
            break; //종료
        }
        section_ice += position[i];
    }
    int ans = section_ice; //얼음 최대합
    for (int i = section; i <= end_point; i++) { //슬라이딩, i: 윈도우에서 추가되는 값
        section_ice -= position[i - section]; //이번 윈도우에서 제외되는 값
        section_ice += position[i]; //이번 윈도우에서 추가되는 값
        ans = max(ans, section_ice);
    }
    return ans;
}

int main() {
    int n, k, g, x, end_point = 0;

    //입력
    cin >> n >> k;
    vector<int> position(SIZE + 1, 0); //좌표 최댓값 아직 모르므로 SIZE까지 선언
    while (n--) {
        cin >> g >> x;
        position[x] = g;
        end_point = max(end_point, x);
    }

    //연산 & 출력
    cout << maxIce(k, end_point, position);
    return 0;
}