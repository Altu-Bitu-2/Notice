#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    // 입력
    cin >> n;

    // heap 초기화
    priority_queue<int> max_heap;

    while (n--) {
        cin >> x;
        if (x == 0) {
            // 비었다면 0 출력
            if (max_heap.empty()) {
                cout << "0\n";
            } else { // 가장 큰 값 출력하고 제거
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        } else {
            // 최대 힙에 x를 삽입
            max_heap.push(x);
        }
    }
    return 0;
}