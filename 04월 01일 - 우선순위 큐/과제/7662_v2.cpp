#include <iostream>
#include <set>

using namespace std;

/**
 * set 풀이
 *
 * set은 중복값이 제거되기 때문에 multiset을 이용하여 저장해야 함
 * multiset 또한 값을 넣으면 정렬이 바로 되기 때문에 이후의 정렬 과정이 따로 필요 없음
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k, n;
    char cmd;

    cin >> t;
    while (t--) {
        multiset<int> ms; //중복 저장
        cin >> k;
        while (k--) {
            //입력
            cin >> cmd >> n;

            //연산
            switch (cmd) {
                case 'I': //I 연산
                    ms.insert(n);
                    break;
                case 'D': //D 연산
                    if (ms.empty()) { //ms가 비어있다면 연산 무시
                        break;
                    }
                    if (n == 1) { //최댓값 삭제
                        ms.erase(--ms.end());
                    }
                    if (n == -1) { //최솟값 삭제
                        ms.erase(ms.begin());
                    }
                    break;
            }
        }

        //출력
        if (ms.empty())
            cout << "EMPTY\n";
        else
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    }
}