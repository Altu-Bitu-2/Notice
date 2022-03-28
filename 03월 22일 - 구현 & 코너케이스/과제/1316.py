import sys
input = sys.stdin.readline

"""
[그룹 단어 체커] - 단순 구현 문제

- 이미 등장한 알파벳 저장할 set() 선언 (탐색 O(1))
- 처음 등장하는 알파벳은 set에 추가하고, 무리에서 떨어졌는데 이미 등장한 알파벳이면 그룹 단어가 아니다.

"""

def is_group_word(word):
    checked = set()
    prev = None

    for c in word:
        if c == prev:
            continue
        
        if c in checked:
            return False

        checked.add(c)
        prev = c

    return True


# 입력
n = int(input())

# 입력 + 연산
count = 0

for _ in range(n):
    word = input().rstrip()
    if is_group_word(word):
        count += 1

# 출력
print(count)