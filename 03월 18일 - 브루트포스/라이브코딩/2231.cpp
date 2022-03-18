#include <iostream>

using namespace std;

int findConstructor(int n) {
    // 가장 작은 생성자 리턴
    // 1부터, n까지 분해합을 구해보면서, 분해합이 n인 경우(=생성자)를 찾는다.

    int sum;

    for (int i = 1; i < n; i++) {
        // 반복문 내에서 i를 변경하지 않고, 임시변수 사용
        int temp = i;
        sum = i;    // 해당 수를 더하고

        // 각 자리 수 더하기
        // 216 -> 216 + 6 + 1 + 2
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        // 생성자가 맞으면 바로 리턴
        if (sum == n) {
            return i;
        }
    }
    // 생성자가 없는 경우
    return 0;
}

int main() {
    int n;
    //입력
    cin >> n;
    // 연산 + 출력
    cout << findConstructor(n);
    return 0;
}