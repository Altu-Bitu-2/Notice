#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

struct baseball {
    string num;       //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string &s1, string &s2) {
    int strike_cnt = 0; //s1과 s2사이의 strike 개수
    int ball_cnt = 0;   //s1과 s2사이의 ball 개수

    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i]) { //위치+수 정확히 일치 -> 스트라이크
            strike_cnt++;
        } else if (s1.find(s2[i]) != s1.npos) { //위치 다른데 수가 존재 -> 볼
            ball_cnt++;
        }
    }

    return ci(strike_cnt, ball_cnt);
}

int game(int n, vector<baseball> &question) {
    int ans = 0; //정답 개수
    vector<int> is_in_num = {0, 0, 0, 0, 0, 0, 0, 1, 2, 3}; //7부터 9번 인덱스까지 순서 저장

    do {
        bool check = true;
        string s1 = "000"; //정답인지 확인할 수
        for (int i = 1; i <= 9; i++) {
            if (is_in_num[i]) {
                s1[is_in_num[i] - 1] = i + '0'; //각 순서에 따라 숫자 저장
            }
        }
        for (int i = 0; i < n; i++) {
            string s2 = question[i].num; //질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이의 스트라이크와 볼 개수
            if (cnt.first != question[i].strike || cnt.second != question[i].ball) { //하나라도 다르면
                check = false;
                break;
            }
        }
        if (check) {
            ans++;
        }
    } while (next_permutation(is_in_num.begin() + 1, is_in_num.end()));

    return ans;
}

/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이] - 순열 풀이
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지 -> 순열로 구하자 (임시 배열에 순서를 저장)
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 서로 다른 세 자리수 모두 구해서 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */

int main() {
    int n;

    //입력
    cin >> n;

    vector<baseball> question(n);
    for (int i = 0; i < n; i++) {
        cin >> question[i].num >> question[i].strike >> question[i].ball;
    }

    //연산 + 출력
    cout << game(n, question);

    return 0;
} 