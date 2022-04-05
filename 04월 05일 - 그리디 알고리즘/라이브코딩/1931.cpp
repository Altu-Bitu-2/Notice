#include <iostream>
#include <vector>
#include <algorithm> // sort 사용

using namespace std;

typedef pair<int, int> ci;

// 진행할 수 있는 회의의 최댓값을 리턴하는 함수
int getMaxCount(int n, vector<ci> &meetings) {
    int count = 0;  // 회의 수
    int prev_end = 0;   // 직전 회의의 끝나는 시간
    for (int i = 0; i < n; i++) {
        auto[ end, start ] = meetings[i];   // C++17부터 지원
                                                // int end = meetings[i].first;
                                                // int start = meetings[i].second;
        // 직전 회의가 끝나는 시간 이후로 시작하는 회의를 선택
        if (start >= prev_end) {
            count++;
            prev_end = end;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<ci> meetings(n, {0, 0});

    // 이후 정렬을 할 때
    // 1. 빨리 끝나는 순서대로
    // 2. 빨리 시작하는 순서대로
    // 따라서 first에 끝나는 시간, second에 시작하는 시간 저장!
    for (int i = 0; i < n; i++) {
        cin >> meetings[i].second >> meetings[i].first;
    }
    // 빨리 끝나는 순서대로, 빨리 시작하는 순서대로 정렬
    sort(meetings.begin(), meetings.end());
    // 연산 + 출력
    cout << getMaxCount(n, meetings);
    return 0;
}