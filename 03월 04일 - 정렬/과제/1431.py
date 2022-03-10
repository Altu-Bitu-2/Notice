import sys
input = sys.stdin.readline

n = int(input())
arr = [input().rstrip() for _ in range(n)]

def sum_digit(text):
    # 문자열에 포함된 숫자를 전부 더해 반환하는 함수입니다.
    total = 0
    for c in text:
        # 문자열의 메소드 .isdigit()으로 숫자인지 판단할 수 있습니다.
        if c.isdigit():
            total += int(c)
    return total

# 정렬의 우선순위에 맞춰서 람다함수를 작성합니다.
# 첫번째는 문자열의 길이, 두번째가 숫자의 합, 세번째가 사전순 입니다.
arr.sort(key=lambda x:(len(x), sum_digit(x), x))

for i in arr:
    print(i)
# 혹은 print('\n'.join(arr)) 로 한줄에 처리할 수 있습니다.
# .join 메소드는 문자열을 처리할 때 유용하니 알아두세요!