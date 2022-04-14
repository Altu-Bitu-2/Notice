#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
    string ans = "";
    int start = arrow_point;
    do {
        ans += wheel[arrow_point];
        arrow_point = (arrow_point + 1) % n;
    } while (arrow_point != start);
    return ans;
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) {
        int rot = record[i].first;
        char alpha = record[i].second;
        idx = (idx - rot % n + n) % n;
        if (wheel[idx] == alpha) {
            continue;
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) {
            return "!";
        }
        wheel[idx] = alpha;
        is_available[alpha - 'A'] = true;
    }
    return arrowStartWheel(idx, n, wheel);
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k;

    //입력
    cin >> n >> k;
    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second;
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0;
}