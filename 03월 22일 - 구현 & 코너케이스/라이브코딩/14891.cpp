#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
/*
 * 톱니바퀴 문제
 *
 * 문제에 나와있는대로 구현
 * -> 맞닿은 극이 "다를 경우" 우선 해당 톱니 회전 후, 맞닿은 톱니 반대 방향으로 회전
 * -> 이때 맞닿은 극을 확인하는 경우는 회전 후가 아닌 회전 전!!
 *
 * 톱니바퀴의 상태를 저장할 컨테이너 -> 덱
 *
 * 1. 각 톱니바퀴가 회전할 방향을 결정
 *      - 방향을 저장하는 벡터
 * 2. 결정된 방향으로 회전!
 * */


using namespace std;

const int R = 2;    // 맞닿는 오른쪽 톱니 인덱스
const int L = 6;    // 맞닿는 왼쪽 톱니 인덱스

deque<int> wheel[5];    // 톱니바퀴의 상태를 저장 - deque 5개 선언 (index 1~4까지 사용)
vector<int> rotation(5, 0); // 방향 저장 1: 시계, -1: 반시계 0: 회전 없음

void decideRotation(int num, int rot) {
    // 이미 회전한 경우
    if (rotation[num] != 0) {
        return;
    }
    // num 톱니바퀴를 rot 방향으로 회전
    rotation[num] = rot;

    // 오른쪽 바퀴가 회전하는 경우
    if (num < 4 && wheel[num][R] != wheel[num + 1][L]) {
        decideRotation(num + 1, -rot);
    }
    // 왼쪽 바퀴가 회전하는 경우
    if (num > 1 && wheel[num][L] != wheel[num-1][R]){
        decideRotation(num-1, -rot);
    }
}

void rotate(){
    // rotation의 회전정보를 확인하고 톱니바퀴를 회전시킴
    for (int i=1; i<=4; i++){
        // 시계방향으로 회전하는 경우
        // ex 10101111 -> 11010111
        if (rotation[i] == 1) {
            int temp = wheel[i].back();
            wheel[i].pop_back();
            wheel[i].push_front(temp);
        } else if (rotation[i] == -1) { // 반시계 방향으로 회전하는 경우
            int temp = wheel[i].front();
            wheel[i].pop_front();
            wheel[i].push_back(temp);
        }
    }
    return;
}

int calcScore(){
    int answer = 0;
    for (int i=1; i<=4; i++) {
        answer += pow(2, i-1) * wheel[i][0];
    }
    return answer;
}

int main() {
    string temp;
    for (int i = 1; i <= 4; i++) {
        cin >> temp;
        // 톱니바퀴 상태를 저장
        for (int j = 0; j < 8; j++) {
            wheel[i].push_back(temp[j] - '0'); // '1', '0'
        }
    }

    int n, num, rot;
    cin >> n;

    while (n--) {
        cin >> num >> rot;
        // 회전 정보를 초기화
        rotation.assign(5, 0);
        // 회전 방향 결정
        decideRotation(num, rot);
        // 회전하기
        rotate();
    }

    // 점수 계산하기 + 출력
    cout << calcScore();
    return 0;
}