//
// Created by JIYOUNG.P on 2022-03-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * ver2. 아직 배우지는 않았지만, 후반부에 배울 이분탐색을 이용한 풀이입니다.
 * O(n)의 시간복잡도를 갖는 선형탐색(linear search)는 달리, 이분탐색(binary search)는 O(logn)의 시간 복잡도를 갖습니다.
 * */

int main() {
    // 입출력 처리 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int t;
    cin >> t;
    while (t--) {
        int n, m, input;

        // 수첩1에 해당되는 원소들을 vector에 저장
        cin >> n;
        vector<int> note1(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> note1[i];
        }

        // 이분탐색을 하기 위해 정렬
        sort(note1.begin(), note1.end());

        cin >> m;
        while (m--) {
            cin >> input;
            // 이분탐색 라이브러리 함수를 활용해, 원소가 수첩1에 있는지 확인
            // binary_search() -> 이분탐색으로 원소가 있는지를 확인하고, 결과를 리턴하는 함수
            if (binary_search(note1.begin(), note1.end(), input)) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
    return 0;
}