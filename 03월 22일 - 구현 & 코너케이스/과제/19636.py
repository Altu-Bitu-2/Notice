import sys
input = sys.stdin.readline

"""
[요요 시뮬레이션] - 단순 구현 문제
체중(weight): 일일 에너지 섭취량(energy_in) - 일일 에너지 소비량(energy_out) (일일 기초 대사량(b) + 일일 활동 대사량(a))
if |일일 에너지 섭취량(energy_in) - 일일 에너지 소비량(energy_out)| > 기초 대사량 변화 역치(T)
-> 일일 기초 대사량(b) += [(일일 에너지 섭취량(energy_in) - 일일 에너지 소비량(energy_out)) / 2]
-> !주의! 이때 일일 기초 대사량에서 더해지는 값이 Floor 함수 적용이므로 음수일 때 값처리 주의해야 함

기초 대사량(b) 변화를 고려하지 않는 경우는, b == I0이므로 한번에 계산
"""

def diet_simulation(initial_weight, I0, T, period, energy_in, a):
    b = I0
    weight = initial_weight
    for _ in range(period):
        energy_out = a + b  
        weight += energy_in - energy_out

        if abs(energy_in - energy_out) > T:
            b += (energy_in - energy_out) // 2
    
    return weight, b

# 입력
initial_weight, I0, T = map(int, input().split())
period, energy_in, a = map(int, input().split())

# 연산 + 출력

# 기초 대사량 변화 고려하지 않는 경우
weight = initial_weight + (energy_in - (I0 + a)) * period
if weight <= 0:
    print("Danger Diet")
else:
    print(weight, I0)

# 기초 대사량 변화 고려한 경우
weight, b = diet_simulation(initial_weight, I0, T, period, energy_in, a)

if weight <=0 or b <= 0:
    print("Danger Diet")
else:
    if b < I0:
        answer = "YOYO"
    else:
        answer = "NO"
    print(weight, b, answer)