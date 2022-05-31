#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;
typedef tuple<double, int, int> tp;
typedef pair<double, double> ci;
vector<int> parent;

// Find 연산
int findParent(int x) {
    if (parent[x] < 0) { //값이 음수면 루트 정점
        return x;
    }
    return parent[x] = findParent(parent[x]); //그래프 압축하며 루트 정점 찾기
}

// union 연산
bool unionNodes(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if (px == py) {
        return false;
    }

    if (parent[px] < parent[py]) { //새로운 루트 px
        parent[px] += parent[py];
        parent[py] = px;
    } else { //새로운 루트 py
        parent[py] += parent[px];
        parent[px] = py;
    }
    return true;
}

double kruskal(int n, vector<tp> &edge) {
    double sum = 0;
    int cnt = 0;

    for (auto[w, n1, n2]: edge) {
        if (!unionNodes(n1, n2)) { //사이클이 생기는 경우
            continue;
        }
        sum += w;
        cnt++;
        if (cnt == n - 1) { //간선 다 찾은 경우
            return sum;
        }
    }

    return sum;
}

int main() {
    int n;
    double x, y;

    // 입력
    cin >> n;
    parent.assign(n, -1);
    vector<tp> edge;  // 간선 배열
    vector<ci> star;    // 각 별의 위치

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = 0; j < i; j++) {
            //임의의 두 별에 대한 거리(간선) 모두 구하기
            double dx = x - star[j].first;
            double dy = y - star[j].second;
            edge.push_back({sqrt(dx * dx + dy * dy), i, j});
        }
        star.push_back({x, y});
    }
    sort(edge.begin(), edge.end());

    //연산 & 출력
    cout << fixed;  // 고정된 소수점 자리로 출력할 것을 선언
    cout.precision(2);  // 소수점 2번째자리로 정확도를 설정
    cout << kruskal(n, edge);
    return 0;
}