//
// Created by BaeSuA on 2022-03-11.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int SIZE = 1e4; //스택 사이즈

vector<int> stack_vec(SIZE);
int top_pointer = -1; //스택의 현재 위치 가리키는 포인터

//full: 스택이 꽉 찼는지 확인 (직접 구현 시, 런타임 에러 방지용)
bool full() {
    return top_pointer == (SIZE - 1);
}

//push: 삽입
void push(int x) {
    stack_vec[++top_pointer] = x;
}

//pop: 가장 위의 값 삭제
void pop() {
    top_pointer--;
}

//size: 스택 사이즈 반환
int size() {
    return top_pointer + 1;
}

//empty: 비어있으면 1, 아니면 0
bool empty() {
    return top_pointer == -1;
}

//top: 가장 위에 있는 원소 반환 (삭제 x)
int top() {
    return stack_vec[top_pointer];
}

int main() {
    int n, x;
    string cmd; //명령
    stack<int> st;

    //입력
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            //런타임 에러 방지하기 위해, 스택이 꽉 찼는지 검사
            //if (!full()) { //라이브러리 사용시엔 필요 x
            st.push(x);
            //}
            continue;
        }
        if (cmd == "pop") {
            if (st.empty()) { //스택이 비어있다면
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
            continue;
        }
        if (cmd == "size") {
            cout << st.size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << st.empty() << '\n';
            continue;
        }
        if (cmd == "top") {
            if (st.empty()) {
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
            }
        }
    }

    //스택의 순회
//    while (!st.empty()) {
//        cout << st.top() << ' ';
//        st.pop();
//    }
    return 0;
}