#include <iostream>
#include <vector>

using namespace std;

// gcd 자체는 최대 1,000,000이므로 int 범위 안에 들어옴
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long gcdSum(int n, vector<int> &v) {
    // 최대 100개의 숫자 -> C(100, 2) = 4,950
    // 입력범위 1,000,000 -> gcd의 최댓값은 1,000,000
    // sum <= 4,950,000,000 -> long long 사용
    long long sum = 0;

    // 가능한 모든 쌍의 최대공약수를 구해서, sum에 더하기
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += gcd(max(v[i], v[j]), min(v[i], v[j]));
        }
    }
    return sum;
}

int main() {
    // 입력
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // 연산 + 출력
        cout << gcdSum(n, arr) << '\n';
    }
}