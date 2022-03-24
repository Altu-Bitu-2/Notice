import sys
from itertools import combinations
input = sys.stdin.readline

"""
[암호 만들기]

알파벳은 최대 15개 -> 브루트포스 가능
가능한 모든 조합 만들어서, 검사 통과하면 출력
"""
vowels = ['a', 'e', 'i', 'o', 'u']  # 모음 저장

def is_valid(cypher):
    count = 0   # 모음 수
    for i in cypher:
        if i in vowels:
            count += 1

    # 모음 한개 이상, 자음 2개 이상
    return count >= 1 and len(cypher) - count >= 2

# 입력
n, m = map(int, input().split())
alphabets = list(input().split())

alphabets.sort()    # 오름차순 암호를 만들기 위해 정렬

# 반복문을 돌리기 위해서 굳이 list로 감싸지 않아도 됨, iterator형은 반복문을 바로 돌릴 수 있음
for cypher in combinations(alphabets, n):
    if is_valid(cypher):    # 유효한 암호일 경우
        print(''.join(cypher))