#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

//필요 강의실 수를 구하는 함수
int arrayRoom(int n, vector<ci> lec) {
    priority_queue<int, vector<int>, greater<>> pq; //종료 시간을 저장하는 우선순위 큐

    pq.push(-1); //처음 인덱스 에러를 피하기 위해 음수 값 삽입. (첫번째 강의 때 갱신될 값)

    for (int i = 0; i < n; i++) {
        if (lec[i].first >= pq.top()) { //종료시간이 가장 빠른 수업보다 시작시간이 같거나 느리다면 -> 같은 강의실
            pq.pop();
        }
        pq.push(lec[i].second); //기존 강의실 정보 갱신 or 새로운 강의실 정보 저장
    }
    return pq.size();
}

/**
 * [강의실 배정]
 *
 * 강의실 수를 최소로 하기 위해서, 현재 사용하는 강의실 중 가장 빨리 끝나는 강의실에 가장 먼저 시작하는 강의실을 배치해야 한다.
 * 이 문제는 모든 강의를 다 진행해야 하므로, 회의실 배정 문제와는 다르다! 먼저 시작하는 순으로 정렬할 것.
 * 현재 가장 빨리 끝나는 시간을 구하기 위해 최소 힙(우선순위 큐) 사용
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<ci> lec(n, ci(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> lec[i].first >> lec[i].second; //first: 시작시간, second: 종료시간
    }

    //연산
    sort(lec.begin(), lec.end());

    //출력
    cout << arrayRoom(n, lec) << '\n';
    return 0;
}