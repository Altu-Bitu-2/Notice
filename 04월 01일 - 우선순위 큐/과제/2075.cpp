#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 정렬이랑 반대

    cin >> n;
    int size = n * n;
    while (size--) {
        //입력
        cin >> input;

        //연산
        if (pq.size() < n) { //우선순위 큐의 크기가 N보다 작다면 그냥 투입
            pq.push(input);
        }
        else if (pq.top() < input) { //우선순위 큐의 크기가 N 이상이라면 root 노드보다 input이 클 때만 갱신
            pq.pop();
            pq.push(input);
        }
    }

    //출력
    cout << pq.top();
}
