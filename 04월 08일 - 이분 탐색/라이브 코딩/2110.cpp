//
// Created by BaeSuA on 2022-04-08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//가장 인접한 두 공유기 사이의 거리가 dist이도록 공유기를 설치했을 때, 설치된 공유기 개수
int cntRouter(int dist, vector<int> &house) {
    //첫번째 집에 무조건 공유기 설치
    int cnt = 1; //공유기 개수
    int cur = house[0]; //현재 공유기 설치한 집의 거리

    for (int i = 1; i < house.size(); i++) {
        if (house[i] - cur >= dist) { //가장 가까운 집과의 거리가 dist 이상이면
            cnt++; //공유기 설치
            cur = house[i];
        }
    }
    return cnt; //설치된 공유기의 수
}

//c개의 공유기 설치 가능한 최소 인접 거리 중 최댓값 (=upper bound)
int upperSearch(int left, int right, int target, vector<int> &house) {
    while (left <= right) {
        //가장 인접한 두 공유기 사이의 거리가 mid일 때, 공유기 c개를 설치할 수 있는가?
        int mid = (left + right) / 2;
        int installed = cntRouter(mid, house);

        if (installed >= target) { //installed가 target보다 많다면 거리를 늘려서 installed를 줄여야 함
            left = mid + 1;
        } else { //installed가 target보다 적다면 거리를 줄여서 installed를 늘려야 함
            right = mid - 1;
        }
    }
    return left - 1; //upper bound값에서 1을 뺌
}


int main() {
    int n, c;

    //입력
    cin >> n >> c;
    vector<int> house(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    //정렬
    sort(house.begin(), house.end());

    //연산 & 출력
    //공유기 사이의 최단 거리 (left): 1
    //공유기 사이의 최장 거리 (right): 가장 멀리 있는 두 집 사이의 거리 =  house[n-1] - house[0]
    cout << upperSearch(1, house[n - 1] - house[0], c, house);
    return 0;
}