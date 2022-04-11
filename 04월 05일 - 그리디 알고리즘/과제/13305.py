import sys
input = sys.stdin.readline

"""
[주유소]

최대한 가격이 싼 곳에서 많은 기름을 넣어야 한다.
따라서 첫번째 도시부터 현재까지 가장 싼 가격을 저장하고, 이동에 필요한만큼만 기름을 채운다.
이렇게 하면 지금까지 지나 온 도시 중 가장 싼 곳에서 최대한 많이 살 수 있다.
"""

def calc_min_cost(n, road, price):
    cost = 0
    min_price = price[0]
    dist = 0

    for city in range(n - 1):
        cost += min_price * road[city]
        if price[city + 1] < min_price:
            min_price = price[city + 1]

    return cost

# 입력
n = int(input())
road = list(map(int, input().split()))
price = list(map(int, input().split()))

# 연산 + 출력
print(calc_min_cost(n, road, price))