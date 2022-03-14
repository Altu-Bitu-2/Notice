import sys
input = sys.stdin.readline

def count_substring(string, n):
    # 주의! substring = {} 이와 같이 정의를 하면, set이 아닌 dictionary로 정의됩니다.
    substring = set()
    # i 길이의 부분문자열을
    for i in range(1, n+1):
        # j 인덱스부터 시작해서 / i를 빼주지 않으면, string[i:i+j]에서 인덱스 에러가 납니다.
        for j in range(n-i+1):
            substring.add(string[j:j+i])

    return len(substring)

# .rstrip()을 통해 '\n' 제거
s = input().rstrip()

print(count_substring(s, len(s)))