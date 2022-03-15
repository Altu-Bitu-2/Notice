#include <iostream>

using namespace std;

// O(n) 으로 최대공약수 구하기
int gcdBad(int a, int b) {
    // 최대공약수를 구하는 함수
    // a, b중 더 작은 수를 기준으로 반복문을 돌려서 최대공약수 리턴
    for (int i = min(a, b); i > 0; i--) {
        // 공약수인지 확인
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {
        return a;
    }
    return gcdRecursion(b, a % b);
}

int main() {
    // 입력
    int a, b;
    cin >> a >> b;

    // 최대공약수
    int g = gcdRecursion(max(a, b), min(a, b));
    // 최소공배수
    int l = a * b / g;

    // 출력
    cout << g << '\n' << l << '\n';
    return 0;
}