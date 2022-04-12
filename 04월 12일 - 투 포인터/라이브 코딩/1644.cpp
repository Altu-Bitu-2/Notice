//
// Created by BaeSuA on 2022-04-12.
//

#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체 = 해당 소수의 배수를 지워나가면서 수가 소수인지 아닌지를 판단
//n이하의 모든 수의 소수 여부 저장
vector<bool> isPrime(int n) {
    vector<bool> is_prime(n + 1, true); //소수 여부 저장

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) { //i가 소수가 아니면 넘어감
            continue;
        }
        for (int j = i * i; j <= n; j += i) {
            is_prime[j] = false; //i의 배수 제거
        }
    }
    return is_prime;
}

//n이하의 모든 소수 구하는 함수
vector<int> primeList(int n, vector<bool> &is_prime) {
    vector<int> prime_list;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) { //i가 소수라면
            prime_list.push_back(i);
        }
    }
    prime_list.push_back(0); //런타임 에러 방지하기 위해 미리 값을 넣어줌
    return prime_list;
}

//같은 위치에서 시작하여 같은 방향으로 이동하는 투 포인터
//소수의 연속합으로 n 만드는 경우의 수 리턴
int cntPrimeSum(int left, int right, int target, vector<int> &prime_list) {
    int sum = prime_list[left]; //초기 구간, 구간에서 소수의 합
    int ans = 0, size = prime_list.size() - 1; //임의로 넣은 마지막 0 제외한 사이즈

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    //right는 항상 size보다 작은 값이어야 함
    while (left <= right && right < size) {
//        if (sum == target) { //구간의 합이 target과 같을 때
//            ans++; //정답 증가
//            sum -= prime_list[left++]; //기존 left구간 제외 후, left 포인터 증가
//            sum += prime_list[++right]; //right 포인터 증가 후, 새로운 right 값 추가
//        } else if (sum < target) { //구간의 합이 target보다 작을 때
//            sum += prime_list[++right]; //right 포인터 증가 후, 새로운 right 값 추가
//        } else { //구간의 합이 target보다 클 경우
//            sum -= prime_list[left++]; //기존 left구간 제외 후, left 포인터 증가
//        }
        if (sum <= target) { //구간의 합이 target보다 작거나 같을 때
            if (sum == target) { //구간의 합이 target과 같다면
                ans++;
            }
            sum += prime_list[++right]; //right 포인터 증가 후, 새로운 right 값 추가
        } else { //구간의 합이 target보다 클 경우
            sum -= prime_list[left++]; //기존 left구간 제외 후, left 포인터 증가
        }
    }
    return ans;
}

int main() {
    int n;

    //입력
    cin >> n;

    //연산
    vector<bool> is_prime = isPrime(n); //n까지 수의 소수 여부 저장 (에라토스테네스의 체)
    vector<int> prime_list = primeList(n, is_prime); //n까지 소수 배열 구함

    //연산 & 출력
    cout << cntPrimeSum(0, 0, n, prime_list);
    return 0;
}