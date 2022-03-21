#include <iostream>
#include <cmath>

using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {
        return a;
    }
    return gcdRecursion(b, a % b);
}

/**
 * "두 수의 곱 = 최대 공약수 * 최소 공배수" 라는 점을 활용해서 두 수를 찾음
 *
 * 최대 공약수 * 1, * 2, * 3, ... 을 하면서 자연수 A를 찾음
 * 최소 공배수 / 1, / 2, / 3, ... 을 하면서 자연수 B를 찾음
 * <= (최대 공약수 * x) * (최소 공배수 / x) = 최대 공약수 * 최소 공배수 = 두 수의 곱 이기 때문!
 *
 * 이때, 두 수의 합이 최소가 되어야 함 -> 두 수의 차이가 가장 작음 -> A가 B보다 커지면 탐색 종료
 * B의 값을 구할 때, 정확히 나누어 떨어지는지 판단해야 함!
 *
 * 해당 풀이에선 모든 가능한 경우의 수를 다 구하다 가장 마지막에 구한 것이 답이기에 2436_v1.cpp 보단 비효율적이지만 더 직관적인 풀이기에 제공
 */

int main() {
    int gcd, lcm, ans_a, ans_b;

    //입력
    cin >> gcd >> lcm;

    //연산
    int temp = 0; //두 수를 구하기 위해 활용하는 변수
    while (true) {
        temp++;
        //gcd 엔 temp 를 곱해주고, lcm 엔 temp 를 나눠줌으로써 임의의 A, B 만듦
        int temp_a = gcd * temp;
        int temp_b = lcm / temp;

        if (temp_a > temp_b) {
            break;
        }
        if (lcm % temp || temp_b % gcd) { //두 곱 != lcm * gcd 이거나 공약수가 아니라면
            continue;
        }

        //임의로 정한 A(temp_a)와 B(temp_b)의 최대공약수 값이 원래(gcd)와 같은지 비교
        if (gcdRecursion(temp_b, temp_a) == gcd) {
            ans_a = temp_a;
            ans_b = temp_b;
        }
    }

    //출력
    cout << ans_a << ' ' << ans_b << '\n';
    return 0;
}