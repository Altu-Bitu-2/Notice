#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings;
vector<int> order(10, 0); //타순
vector<bool> check(10, false);
int n, ans;

//각 루타마다 얻는 점수
int hitScore(int hit, vector<bool> &baseman) {
    int score = 0;
    for (int i = 3; i >= 0; i--) {
        if (!baseman[i]) {
            continue;
        }
        if (i + hit >= 4) {
            score ++;
        } else {
            baseman[i + hit] = true;
        }
        baseman[i] = false;
    }
    if (hit == 4) {
        score++;
    } else {
        baseman[hit] = true; //새로운 선수 도착
    }
    return score;
}

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) {
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10) {
                idx = 1;
            }
            if (state == 0) {
                out++;
            } else {
                score += hitScore(state, baseman);
            }
        }
    }
    return score;
}

//가능한 배치 모두 구하기
void array(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        array(cnt + 1);
        return;
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score);
        return;
    }
    for (int i = 2; i <= 9; i++) {
        if (!check[i]) {
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            array(cnt + 1); //다음 타자
            check[i] = false;
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    //입력
    cin >> n;
    innings.assign(n, vector<int>(10, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> innings[i][j];
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    array(1);

    //출력
    cout << ans;
    return 0;
}