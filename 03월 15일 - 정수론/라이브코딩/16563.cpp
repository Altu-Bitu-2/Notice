#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5e6;

vector<int> isPrime() {
    // n 이하의 수를 소인수분해하는 경로를 리턴
    vector<int> prime(MAX + 1, 0);
    for (int i = 2; i * i <= MAX; i++) {
        // 소수가 아니면 continue
        if (prime[i] != 0) {
            continue;
        }
        // i가 소수라면
        // i부터 i*(i-1)은 이미 앞선 소수들에 의해 지워졌음.
        for (int j = i * i; j <= MAX; j += i) {
            if (prime[j] == 0) {
                prime[j] = i;
            }
        }
    }
    return prime;
}


int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    // 소수 경로 구하기
    auto prime = isPrime(); // 결론적으로, is_prime[i]에는 i의 가장 작은 소인수가 들어가게 됨

    while (n--) {
        int k;
        cin >> k;

        // prime[k] != 0이면 소수가 아님 -> k가 소수가 될 때까지
        while (prime[k] != 0) {
            cout << prime[k] << ' ';
            k /= prime[k];
        }
        // 마지막 남은 소수 k 출력
        cout << k << '\n';
    }

    return 0;
}