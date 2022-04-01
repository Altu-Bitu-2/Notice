#include <iostream>
#include <vector>

using namespace std;

// heap이 비어있는지 확인
bool isEmpty(vector<int> &heap) {
    return heap.size() == 1;
}

// heap에 x 삽입
void push(vector<int> &heap, int x) {

    // 0. 현재 힙의 크기 = 새로 push 할 데이터의 초기 인덱스
    int idx = heap.size();
    // 1. 힙의 마지막 자리에 x 삽입
    heap.push_back(x);

    // 부모노드와 비교하면서 바꿀 수 있을 때까지...
    while (idx > 1 && heap[idx] > heap[idx / 2]) {
        swap(heap[idx], heap[idx / 2]); // 부모노드와 swap
        idx /= 2; // 현재 x가 위치한 인덱스
    }
    return;
}

// heap에서 값을 제거하고, 그 값을 리턴합
int pop(vector<int> &heap) {
    // 우선 루트노드 값을 복사
    int item = heap[1];
    // 루트노트에 가장 뒤에 있는 값을 옮겨준다.
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();    // 데이터 제거

    int size = heap.size(); // 힙의 크기
    int parent = 1, child = 2;

    // 자식노드가 존재하는 동안 비교 진행
    while (child < size) {
        // 오른쪽 자식 노드가 존재한다면, 둘 중에 큰 쪽을 선택
        if (child + 1 < size && heap[child + 1] > heap[child]) {
            child += 1;
        }

        // 부모노드가 자식노드보다 값이 작은 경우 swap
        if (heap[parent] < heap[child]) {
            swap(heap[parent], heap[child]);
            parent = child;
            child = parent * 2;
        } else {    // 자식보다 부모노드가 큰 상황이므로 더 이상 swap은 필요 없음
            break;
        }
    }
    return item;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    // 입력
    cin >> n;

    // heap 초기화
    vector<int> heap_vec;
    heap_vec.push_back(0);

    while (n--) {
        cin >> x;
        if (x == 0) {
            // 비었다면 0 출력
            if (isEmpty(heap_vec)) {
                cout << "0\n";
            } else { // 가장 큰 값 출력하고 제거
                cout << pop(heap_vec) << '\n';
            }
        } else {
            // 최대 힙에 x를 삽입
            push(heap_vec, x);
        }
    }
    return 0;
}