#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //친구 관계가 모두 다른 사용자로 들어왔을 때의 정점 최댓값

vector<int> parent(MAX + 1, -1);
map<string, int> people;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) {
        return;
    }
    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    } else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

/**
 * [친구 네트워크]
 *
 * 1. weighted union find -> 루트 정점에 친구의 수(집합 원소 수) 저장
 * 2. 친구 네트워크에 몇 명 있는지 구하기 -> 루트 정점의 parent값 접근
 *
 * !주의! 정점이 문자열로 들어오므로 map을 활용해 string을 int로 매핑
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, f;
    string a, b;

    //입력
    cin >> t;
    while (t--) {
        int idx = 1; //정점과 매핑할 수
        parent.assign(MAX + 1, -1);

        cin >> f;
        while (f--) {
            cin >> a >> b;
            if (!people[a]) {
                people[a] = idx++;
            }
            if (!people[b]) {
                people[b] = idx++;
            }

            //연산
            int x = people[a], y = people[b];
            unionInput(x, y);

            //출력
            cout << -parent[findParent(x)] << '\n';
        }
    }
    return 0;
}