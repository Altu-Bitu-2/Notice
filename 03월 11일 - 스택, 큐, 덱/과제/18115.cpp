#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

deque<int> cardGame(int n, vector<int> &cmd) {
    deque<int> dq;

    for (int i = 1; i <= n; i++) { //놓여 있는 위의 카드부터 검사 1, ..., n
        switch (cmd[i]) {
            case 1:
                dq.push_front(i);
                break;
            case 2: { //!주의! c++에서 switch-case 문에 변수 선언 시 {} 필수!
                int x = dq.front();
                dq.pop_front();
                dq.push_front(i);
                dq.push_front(x);
                break;
            }
            case 3:
                dq.push_back(i);
                break;
        }
    }
}

/**
 * 결과값을 보고 처음 도출 -> 기술을 모두 반대로 쓰자!
 * 1. 제일 위의 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드를 다시 위에 ->
 *    제일 위의 카드 앞에 넣기
 * 2. 위에서 두 번째 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 위에서 두 번째에 넣기 ->
 *    제일 위의 카드 앞에서 두번째에 넣기
 * 3. 제일 밑에 있는 카드 바닥에 내려놓기 ->
 *    바닥에 내려놓은 카드 밑에 넣기 ->
 *    제일 위의 카드 뒤에 넣기
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<int> cmd(n + 1, 0);
    for (int i = 1; i <= n; i++) { //입력
        cin >> cmd[i];
    }

    //연산
    reverse(cmd.begin() + 1, cmd.end()); //가장 위의 카드부터 검사하기 위해 기술 순서도 반대로
    deque<int> dq = cardGame(n, cmd);

    //출력
    while (!dq.empty()) {
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    return 0;
}