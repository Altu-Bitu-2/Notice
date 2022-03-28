#include <iostream>
#include <cmath>

using namespace std;

typedef pair<int, int> ci;

/**
 * [요요 시뮬레이션] - 단순 구현 문제
 * 체중(weight): 일일 에너지 섭취량(energy_in) - 일일 에너지 소비량(energy_out) (일일 기초 대사량(b) + 일일 활동 대사량(a))
 * if |일일 에너지 섭취량(energy_in) - 일일 에너지 소비량(energy_out)| > 기초 대사량 변화 역치(T)
 * -> 일일 기초 대사량(b) += [(일일 에너지 섭취량(energy_in) - 일일 에너지 소비량(energy_out)) / 2]
 * -> !주의! 이때 일일 기초 대사량에서 더해지는 값이 Floor 함수 적용이므로 음수일 때 값처리 주의해야 함
 */

//기초대사량 변화하는 경우 처리 함수
ci diet(int period, int initial_weight, int energy_in, int a, int I0, int T) {
    int b = I0;
    int weight = initial_weight;
    while (period--) {
        int energy_out = b + a;
        weight += (energy_in - energy_out);

        if (abs(energy_in - energy_out) > T) { //기초대사량 변화
            b += floor((double) (energy_in - energy_out) / 2); //c++에서 음수를 나누면 소수점은 그냥 버려지므로 내림함수 적용
        }
        if (weight <= 0 || b <= 0) {
            return ci(0, 0);
        }
    }
    return ci(weight, b);
}

int main() {
    int initial_weight, I0, T, period, energy_in, a;

    //입력
    cin >> initial_weight >> I0 >> T;
    cin >> period >> energy_in >> a;

    //일일 기초 대사량의 변화를 고려하지 않는 경우
    int weight = initial_weight + (energy_in - (I0 + a)) * period;
    if (weight <= 0) {
        cout << "Danger Diet\n";
    }
    else {
        cout << weight << ' ' << I0 << '\n';
    }

    //일일 기초 대사량의 변화를 고려하는 경우
    ci result = diet(period, initial_weight, energy_in, a, I0, T);
    if (!result.first || !result.second) {
        cout << "Danger Diet\n";
    }
    else {
        string ans = "NO";
        if (I0 - result.second > 0) {
            ans = "YOYO";
        }
        cout << result.first << ' ' << result.second << ' ' << ans << '\n';
    }
    return 0;
}