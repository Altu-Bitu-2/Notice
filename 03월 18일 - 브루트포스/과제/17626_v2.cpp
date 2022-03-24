#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, num_size;
vector<int> square_num;

bool isPossible(int cnt, int sum, int m) { //cnt: 고른 개수, sum: 지금까지 합, m: 골라야 하는 개수
    bool check = false; //m개의 제곱수 합 표현 가능한지

    if (cnt == m) { //다 골랐다면
        if (sum == n) { //제곱수 합이 n과 같다면
            return true;
        }
        return false;
    }
    for (int i = num_size - 1; i >= 0; i--) {
        if (sum + square_num[i] <= n) {
            check = isPossible(cnt + 1, sum + square_num[i], m);
            if (check) { //m개의 제곱수의 합 표현 가능
                return true;
            }
        }
    }
    return check;
}

/**
 * [Four Squares] - 백트래킹 풀이 (8ms)
 * 자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
 * 미리 최댓값까지의 제곱수를 구해놓고, 1개 ~ 3개까지의 제곱수 합으로 표현이 가능한지 검사
 * 이때, 제곱수가 큰 수부터 검사해서 더한 값이 n 넘어가면 가지치기
 *
 * 1. 1 ~ 3개의 조합으로 불가능한 경우, 답은 무조건 4가 된다 -> 4개의 합은 시도해보지 않아도 된다.
 */

int main() {
    //입력
    cin >> n;

    //연산
    for (int i = 1; i <= sqrt(n); i++) { //미리 루트 n 까지의 제곱수 저장
        square_num.push_back(i * i);
    }
    num_size = square_num.size(); //제곱수 개수

    //3개의 조합까지만 구함
    int ans = 4; //우선 4로 초기화
    for (int i = 1; i <= 3; i++) {
        if (isPossible(0, 0, i)) { //정답 생기면
            ans = i;
            break;
        }
    }

    //출력
    cout << ans;
    return 0;
}