import sys
input = sys.stdin.readline

"""
[큰수 A+B]
 1. 한 자릿수씩 더해서 리스트에 저장
 2. 한 자릿수씩 더할 때, 값이 10을 넘어가는 경우 고려 -> 자릿수 올림
 3. A와 B의 길이가 같지만, 둘의 합의 길이는 다른 경우 고려 -> 마지막 자리에서 올림
 4. A와 B의 길이가 다른 경우 고려 -> 더 긴 길이 처리 주의
"""

def calcPlus(a, b):
    # 항상 a가 b보다 자리수가 크다고 가정
    if len(a) < len(b):
        a, b = b, a

    ans = [0] * (len(a) + 1) # 정답 저장할 배열

    # -1, -2 ... 일의 자리부터 뒤에서 더하기 위해
    for i in range(-1, -len(b)-1, -1):
        ans[i] += int(a[i]) + int(b[i])     # carry(올림) + a + b
        ans[i-1] = ans[i] // 10     # carry가 존재한다면 미리 표기
        ans[i] %= 10

    for i in range(-len(b)-1, -len(a)-1, -1):
        ans[i] += int(a[i])         # carry + a
        ans[i-1] = ans[i] // 10
        ans[i] %= 10

    # 맨 앞자리 0이 출력되지 않도록 int() 적용
    return int(''.join(map(str, ans)))

# 입력
a, b = input().split()
# 연산 + 출력
print(calcPlus(a, b))