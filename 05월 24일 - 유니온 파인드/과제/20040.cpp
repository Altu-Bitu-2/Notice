#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) {
        return false;
    }
    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() {
    int n, m, x, y;

    //입력
    cin >> n >> m;
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클이 생성됨
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}