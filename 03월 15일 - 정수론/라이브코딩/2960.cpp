#include <iostream>
#include <vector>

using namespace std;

// 에라토스테네스의 체를 활용해 소수를 찾는 함수
int findPrime(int n, int k) {
    vector<bool> is_prime(n + 1, true);
    // 0과 1은 소수가 아니므로 false
    is_prime[0] = is_prime[1] = false;

    int cnt = 0;    // 현재까지 지워진 수의 개수를 기록
    // 소수도 지워야하므로, i <=n 까지!
    for (int i = 2; i <= n; i++) {
        // i가 소수인지 판단
        // 1. i가 소수아니라면 == i가 이미 지워졌다면
        if (!is_prime[i]) {
            continue;
        }
        // 2. i가 소수라면, i의 배수를 순서대로 방문하기
        // 이 문제에서는 i부터 지워야 하므로 j = i
        for (int j=i; j<= n; j +=i) {
            // 이미 표기된 수라면 넘어가기
            if (!is_prime[j]) {
                continue;
            }
            // cout << cnt+1 << "번째 지워지는 수 " << j << '\n'; // 디버깅용
            is_prime[j] = false;

            // cnt를 +1한 후, k와 같은지 비교하고, 같다면 j를 리턴한다.
            if (++cnt == k) {
                return j;
            }
        }
    }
    return -1;
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;
    // 연산 + 출력
    cout << findPrime(n, k);
    return 0;
}