//
// Created by BaeSuA on 2022-04-12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e9 + 1;

//서로 다른 위치에서 시작해서 서로를 향해 가까워지는 투 포인터
//두 용액의 합 중 0에 제일 가까운 용액의 쌍 리턴
ci findLiquid(int left, int right, vector<int> &liquid) {
    ci ans = {0, 0};
    int min_diff = INF;

    //left는 항상 right의 왼쪽에 있어야 함 (서로 달라야 하므로)
    while (left < right) {
        int mix = liquid[left] + liquid[right]; //두 용액을 혼합
        if (mix == 0) { //그 값이 0이라면 이보다 더 0에 가까워질 수는 없기 때문에 바로 리턴
            return {liquid[left], liquid[right]};
        }
        if (abs(mix) < min_diff) { //0에 가까운 값을 갱신할 수 있는지 확인
            min_diff = abs(mix);
            ans = {liquid[left], liquid[right]};
        }
        if (mix > 0) { //0보다 크다면 더 작은 값을 만들어야 함 -> right 이동
            right--;
        } else { //0보다 작다면 더 큰 값을 만들어야 함 -> left 이동
            left++;
        }
    }
    return ans;
}


int main() {
    int n;

    //입력
    cin >> n;
    vector<int> liquid(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    //연산
    sort(liquid.begin(), liquid.end());
    ci ans = findLiquid(0, n - 1, liquid);

    //출력
    cout << ans.first << ' ' << ans.second;
    return 0;
}