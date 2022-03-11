//
// Created by BaeSuA on 2022-03-11.
//

#include <iostream>
#include <stack>
#include <map>

using namespace std;

//괄호가 균형을 이루었는지 확인하는 함수
bool isBalanced(string &s) {
    stack<char> st;
    map<char, char> m;
    //괄호 짝 미리 저장
    m[']'] = '[';
    m[')'] = '(';

    for (int i = 0; i < s.length(); i++) {
        //(python3) 파이썬은 switch-case문을 지원하지 않으므로, if-else문 사용하면 됨.
        switch (s[i]) {
            case '(': case '[': //여는 괄호
                st.push(s[i]);
                break;
            case ')': case ']': //닫는 괄호
                if (st.empty() || st.top() != m[s[i]]) { //스택 비었거나, 종류 안맞음
                    return false;
                }
                st.pop();
                break;
        }
    }
    return st.empty(); //스택에 원소가 비어있어야 균형 o
}

/**
 * 여는 괄호 -> 스택에 넣기
 * 닫는 괄호 -> 스택에서 빼기
 * => 하는 도중, 스택이 비어있는데 닫는 괄호가 나오거나,
 *    모두 끝났는데 스택에 원소가 남아있다면 균형 x!
 * => 나머지 경우는 모두 균형 o
 */

int main() {
    string s;

    //getline(cin, <문자열 이름>): 공백 포함 입력받기
    while (getline(cin, s)) {
        if (s == ".") {
            break;
        }
        //연산 & 출력
        if (isBalanced(s)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}