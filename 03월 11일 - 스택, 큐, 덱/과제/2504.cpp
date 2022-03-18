#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int calc(string s) {
    stack<char> st;
    map<char, int> num; //괄호 값
    map<char, char> bracket; //괄호 쌍

    //괄호 쌍과 값 저장
    bracket[')'] = '(';
    bracket[']'] = '[';
    num['('] = 2;
    num['['] = 3;

    int ans = 0, temp = 1;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case '(': case '[': //여는 괄호일 경우
                st.push(s[i]);
                temp *= num[s[i]];
                break;
            case ')': case ']': //닫는 괄호일 경우
                if (st.empty() || st.top() != bracket[s[i]]) {
                    return 0;
                }
                if (s[i - 1] == bracket[s[i]]) {
                    ans += temp;
                }
                temp /= num[bracket[s[i]]]; //이미 값을 더한 경우이므로 나누기
                st.pop();
                break;
        }
    }
    if (st.empty()) { //올바른 괄호라면
        return ans;
    }
    return 0;
}

/**
 * "분배법칙"을 활용!
 * ex. ([]([])): 2 x (3 + 2 x 3) == 2 x 3 + 2 x 2 x 3
 * =>                               (   [ ]     (   [   ]   )   )
 * =>                   임시변수값:  2   6 2     4  12   4   2   1
 * =>                        정답:        +6           +12        = 18
 *
 * 따라서, 우선 여는 괄호가 나오면 괄호의 값을 곱해줌
 * 닫는 괄호는, 이전 문자가 여는 괄호일 경우 지금까지 곱한 값을 더해줌 (값이 중복으로 더해지는 것을 방지하기 위해 이전 문자가 여는 괄호인지 꼭 체크!)
 *            한 괄호에 대한 연산이 끝났으므로 (곱하기 연산) 다시 괄호 값을 나눠줘서 연산 진행
 */

int main() {
    string s;

    //입력
    cin >> s;
    //연산 & 출력
    cout << calc(s);
    return 0;
} 