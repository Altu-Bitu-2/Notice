#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll greedyOil(vector<pair<ll, ll>> &city, int n) {
    ll cur_cost = city[0].second, tot_cost = 0;

    for (int i = 0; i < n; i++) {
        if (city[i].second < cur_cost) { //이 도시의 기름값이 더 저렴하면 교체
            cur_cost = city[i].second;
        }
        tot_cost += (cur_cost * city[i].first); //이동 비용
    }
    return tot_cost;
}

/**
 * [주유소]
 *
 * 최대한 가격이 싼 곳에서 많은 기름을 넣어야 한다.
 * 따라서 첫번째 도시부터 현재까지 가장 싼 가격을 저장하고, 이동에 필요한만큼만 기름을 채운다.
 * 이렇게 하면 지금까지 지나 온 도시 중 가장 싼 곳에서 최대한 많이 살 수 있다.
 *
 * !주의! 도시 사이의 간격이 최대 10^9이고, 리터당 가격이 최대 10^9이므로
 *       가능한 정답의 최댓값은 10^18으로 int 범위 넘어감! -> long long 써야 함
 */

int main() {
    int n;

    //입력
    cin >> n;
    vector<pair<ll, ll>> city(n, {0, 0});
    for (int i = 0; i < n - 1; i++) {
        cin >> city[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> city[i].second;
    }

    //연산 & 출력
    cout << greedyOil(city, n);
    return 0;
}