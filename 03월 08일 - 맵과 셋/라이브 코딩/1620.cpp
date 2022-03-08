//
// Created by BaeSuA on 2022-03-08.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    string input;
    map<string, int> pocket_name; //이름이 key, 번호가 value
    map<int, string> pocket_num; //번호가 key, 이름이 value

    //입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        pocket_name[input] = i;
        pocket_num[i] = input;
    }
    while (m--) {
        cin >> input;
        if (isdigit(input[0])) { //숫자 입력이라면
            //string to int
            cout << pocket_num[stoi(input)] << '\n'; //number에 대응하는 value(이름) 출력
        } else { //문자열이라면
            cout << pocket_name[input] << '\n'; //input(이름)에 대응하는 value(번호) 출력
        }
    }
    return 0;
}