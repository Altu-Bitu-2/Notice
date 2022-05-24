//
// Created by BaeSuA on 2022-05-24.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int friendshipCost(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) { //루트 정점이라면
            //루트 정점의 parent 값에 친구비가 음수로 저장되어 있으므로 다시 -연산을 해서 더해줌
            sum -= parent[i];
        }
    }
    return sum;
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

    if (xp == yp) { //이미 같은 집합에 있는 경우
        return;
    }
    if (parent[xp] > parent[yp]) { //루트 xp의 값이 더 크다면 -> xp의 친구비가 더 적은 경우
        parent[yp] = xp;
    } else { //새로운 루트 yp
        parent[xp] = yp;
    }
}

int main() {
    int n, m, k, v, w, cost;

    //입력
    cin >> n >> m >> k;
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> cost;
        parent[i] = -cost; //루트 정점에 필요한 친구비(음수)를 저장
    }
    while (m--) {
        cin >> v >> w;
        //유니온
        unionInput(v, w);
    }

    //연산
    int ans = friendshipCost(n);

    //출력
    cout << (ans <= k ? to_string(ans) : "Oh no"); //삼항 연산자 사용 시 자료형 맞춰야 함
    return 0;
}