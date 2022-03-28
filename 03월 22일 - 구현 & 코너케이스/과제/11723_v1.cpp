#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, num;
    string cmd;
    vector<bool> s(SIZE, false);

    cin >> m;
    while (m--) {
        cin >> cmd;
        if (cmd == "all") {
            s.assign(SIZE, true);
            continue;
        }
        if (cmd == "empty") {
            s.assign(SIZE, false);
            continue;
        }

        cin >> num;
        if (cmd == "add") {
            s[num] = true;
            continue;
        }
        if (cmd == "remove") {
            s[num] = false;
            continue;
        }
        if (cmd == "check") {
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        if (cmd == "toggle") {
            s[num] = !s[num];
            continue;
        }
    }
    return 0;
}