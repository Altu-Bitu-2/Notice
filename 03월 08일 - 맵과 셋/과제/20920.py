import sys
input = sys.stdin.readline

n, m = map(int, input().split())

note = dict()

for _ in range(n):
    word = input().rstrip()
    # 길이가 m 미만이면 단어장에 들어가지 않음
    if len(word) < m:
        continue
    
    # key 에러를 방지하기 위해 딕셔너리에 단어가 있는지 확인
    if word in note:
        note[word] += 1
    else:
        note[word] = 1

# .keys() 딕셔너리의 key들을 iterator로 돌려주는 메소드
# 정렬을 위해 리스트에 담아줍니다.
arr = list(note.keys())

# [영단어 우선 순위]
# 1. 자주 나오는 단어일 수록 (딕셔너리의 value 값) - 내림차순
# 2. 해당 단어의 길이가 길수록 - 내림차순
# 3. 알파벳 사전 순으로 - 오름차순
arr.sort(key=lambda x:(-note[x], -len(x), x))

# 출력
for w in arr:
    print(w)