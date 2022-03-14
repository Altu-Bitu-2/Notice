import sys
input = sys.stdin.readline

# key(확장자) - value(파일 개수) 쌍이 필요하므로 dict() 사용

n = int(input())
extension = dict()

for _ in range(n):
    # 입력을 '.'을 기준으로 나누어 리스트에 담고 (.split('.')), 두번째 요소(확장자)를 ext에 저장
    ext = input().rstrip().split('.')[1]
    # key 에러가 나지 않도록 ext가 딕셔너리에 있는지 확인
    if ext in extension:
        extension[ext] += 1
    else:
        extension[ext] = 1

answer = sorted(extension.items())

for key, value in answer:
    print(key, value)