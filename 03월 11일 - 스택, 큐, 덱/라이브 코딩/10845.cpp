//
// Created by BaeSuA on 2022-03-11.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e4 + 1; //1번 인덱스부터 값이 들어감

vector<int> queue_vec(SIZE);
int front_pointer = 0, rear_pointer = 0;

//큐가 꽉 찼는지 검사 -> 직접 구현 시, 런타임에러 방지
bool full() {
    return (rear_pointer + 1) % SIZE == front_pointer;
}

//push: 삽입
void push(int x) {
    rear_pointer = (rear_pointer + 1) % SIZE;
    queue_vec[rear_pointer] = x;
}

//pop: 왼쪽 값 삭제
void pop() {
    front_pointer = (front_pointer + 1) % SIZE;
}

//size: 큐 사이즈
int size() {
    int tmp = rear_pointer - front_pointer;
    if (tmp < 0) {
        tmp += SIZE;
    }
    return tmp;
}

//empty: 비어있는지 확인
bool empty() {
    return rear_pointer == front_pointer;
}

//front: 앞 원소 반환
int front() {
    return queue_vec[(front_pointer + 1) % SIZE];
}

//back: 뒤 원소 반환
int back() {
    return queue_vec[rear_pointer];
}

int main() {
    int n, x;
    string cmd;
    queue<int> q;

    //입력
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            //if (!full()) { //라이브러리 사용 시 필요 x
            q.push(x);
            //}
            continue;
        }
        if (cmd == "pop") {
            if (q.empty()) { //큐가 비어있다면
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
                q.pop(); //앞에 원소 삭제
            }
            continue;
        }
        if (cmd == "size") {
            cout << q.size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << q.empty() << '\n';
            continue;
        }
        if (cmd == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
            }
            continue;
        }
        if (cmd == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << '\n';
            }
        }
    }

    //큐의 순회
//    while (!q.empty()) {
//        cout << q.front() << ' ';
//        q.pop(); //앞에 원소 삭제
//    }
    return 0;
}