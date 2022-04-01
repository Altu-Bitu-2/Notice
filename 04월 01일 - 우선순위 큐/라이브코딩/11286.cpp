#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(const int &x1, const int &x2) {
        // 1. 절댓값이 작으면 우선순위
        // 2. 값이 작으면 우선순위
        if (abs(x2) != abs(x1)) {
            return abs(x2) < abs(x1);
        }
        return x2 < x1;
    }
};

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    // 입력
    cin >> n;
    // 우선순위 큐 선언
    priority_queue<int, vector<int>, cmp> pq;

    while (n--) {
        cin >> x;
        // 출력 + 삭제
        if (x == 0) {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {    // 삽입
            pq.push(x);
        }
    }
    return 0;
}