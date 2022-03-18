#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_DIFF = 1000;  // 100 (개인 능력치 최대) * 10 (n/2의 최댓값) = 1000
vector<vector<int>> power;

int sumPower(vector<int> team) {
    // 전달 받은 팀의 능력치 합 구하기
    int sum = 0;    //능력치 합
    int size = team.size();

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            sum += power[team[i]][team[j]] + power[team[j]][team[i]];
        }
    }
//    cout << sum << ' ';   // 디버깅용
    return sum;
}

int calcDiff(int n, vector<bool> &is_teamA) {
    // 2. 전달받은 임시배열을 이용해서 팀을 구분하기

    vector<int> teamA;  // A팀에 속한 사람의 인덱스
    vector<int> teamB;  // B팀에 속한 사람의 인덱스

//    cout << "team A: "; // 디버깅용
    for (int i = 0; i < n; i++) {
        if (is_teamA[i]) {
            teamA.push_back(i);
//            cout << i << ' ';   // 디버깅용
        } else {
            teamB.push_back(i);
        }
    }
//    cout << '\n';   // 디버깅용
    // 차이 구하기
    int diff = sumPower(teamA) - sumPower(teamB);
//    cout << diff << '\n';   // 디버깅용
    return abs(diff);
}

int findMinDiff(int n) {
    // 1. 팀 나누기

    // 조합을 구하기 위해 임시배열 만들기
    vector<bool> is_teamA(n, true);
    for (int i = 0; i < n / 2; i++) {
        is_teamA[i] = false;
    }

    int answer = MAX_DIFF;

    do {
        // 팀이 결정된 상황
        // 팀 간의 능력치 차이를 구하고, 최솟값을 갱신
        answer = min(answer, calcDiff(n, is_teamA));
    } while (next_permutation(is_teamA.begin() + 1, is_teamA.end()));

    return answer;

}

int main() {
    int n;
    // 입력
    cin >> n;
    power.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> power[i][j];
        }
    }
    // 연산 + 출력
    cout << findMinDiff(n);

    return 0;
}