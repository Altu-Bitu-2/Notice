#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int> &belt) {
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;
    sushi[c]++;

    //윈도우 초기화
    for (int i = 0; i < k; i++) {
        if (!sushi[belt[i]]) {
            section_sushi++;
        }
        sushi[belt[i]]++;
    }

    int ans = section_sushi;
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--;
        if (!sushi[belt[i - k]]) {
            section_sushi--;
        }
        if (!sushi[belt[i % n]]) {
            section_sushi++;
        }
        sushi[belt[i % n]]++;
        ans = max(ans, section_sushi);
    }
    return ans;
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);
    return 0;
}