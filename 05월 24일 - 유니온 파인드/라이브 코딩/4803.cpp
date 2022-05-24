//
// Created by BaeSuA on 2022-05-24.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<bool> cycle;

//결과 출력 함수
void printResult(int tc, int cnt) {
    cout << "Case " << tc << ": ";
    switch (cnt) {
        case 0:
            cout << "No trees.\n";
            break;
        case 1:
            cout << "There is one tree.\n";
            break;
        default:
            cout << "A forest of " << cnt << " trees.\n";
            break;
    }
}

int cntTree(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0 && !cycle[i]) { //루트 정점인데 사이클도 없을 때
            cnt++;
        }
    }
    return cnt;
}

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //값이 음수면 루트 정점
        return node;
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) { //같은 집합에 있다면 -> 사이클 발생
        cycle[xp] = true;
        return;
    }
    if (cycle[xp] || cycle[yp]) { //서로 다른 집합이지만, 하나라도 사이클이 있는 집합이라면
        cycle[xp] = cycle[yp] = true;
    }
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int main() {
    int n, m, a, b, tc = 0;

    //입력
    while (cin >> n >> m) {
        if (n == 0 && m == 0) { //종료 조건
            break;
        }

        //초기화
        tc++;
        parent.assign(n + 1, -1);
        cycle.assign(n + 1, false);

        //입력
        while (m--) {
            cin >> a >> b;
            //유니온
            unionInput(a, b);
        }

        //연산 & 출력
        printResult(tc, cntTree(n));
    }
    return 0;
}