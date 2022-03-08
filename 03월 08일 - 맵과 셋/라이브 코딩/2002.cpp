//
// Created by BaeSuA on 2022-03-08.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

//몇 개의 차가 추월했는지 구하는 함수
int jumpCar(int n, vector<string> &out_car, map<string, int> &m) {
    int ans = 0; //몇 개의 차가 추월했는지
    for (int i = 0; i < n; i++) { //나온 차 순서대로 검사
        for (int j = i + 1; j < n; j++) { //나온 차 기준으로 뒤에 차들 검사
            if (m[out_car[i]] > m[out_car[j]]) { //나보다 늦게 나온 차가 먼저 들어온 차였다면 -> 추월
                //cout << m[out_car[j]] << ' ';
                ans++;
                break; //추월을 했는지 안 했는지만 보는 것이기 때문에 바로 break
            }
        }
    }
    return ans;
}

int main() {
    int n; //차의 개수
    string car;
    map<string, int> m;

    //입력
    cin >> n;
    vector<string> out_car(n, ""); //나온 차
    for (int i = 1; i <= n; i++) { //들어오는 차
        cin >> car;
        m[car] = i; //들어가는 순서 저장
    }
    for (int i = 0; i < n; i++) {
        cin >> out_car[i];
    }
    //연산 & 출력
    cout << jumpCar(n, out_car, m);
    return 0;
}