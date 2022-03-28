#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int num) {
    vector<int> pattern = {num};

    int temp = num;
    while (num != (temp * num) % 10) {
        temp *= num;
        temp %= 10;
        pattern.push_back(temp);
    }
    return pattern;
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;

    //0 ~ 9까지 일의 자리 패턴 미리 구하기
    vector<vector<int>> last_digit(10, vector<int>(0));
    vector<int> pattern_size(10, 1);
    for (int i = 0; i < 10; i++) {
        last_digit[i] = findPattern(i);
        pattern_size[i] = last_digit[i].size();
    }

    //입력
    cin >> t;
    while (t--) {
        cin >> a >> b;
        a %= 10;

        if (a == 0) {
            cout << "10\n";
            continue;
        }
        //인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n';
    }
    return 0;
}