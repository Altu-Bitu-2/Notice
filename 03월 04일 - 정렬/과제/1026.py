import sys
input = sys.stdin.readline

n = int(input())
arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

# 문제에서 B를 재배열하지 말라고 했지만, 어차피 합을 출력하기 때문에 재배열을 해서 짝을 맞추면 됩니다.
# A와 B를 각각 오름차순과 내림차순으로 배열해서 짝을 지어야 최솟값이 됩니다.
# (혹은 A를 내림차순, B를 오름차순으로 정렬해도 결과는 같습니다.)
arr1.sort()             # 오름차순
arr2.sort(reverse=True) # 내림차순

answer = 0
for i in range(n):
    answer += arr1[i]*arr2[i]

print(answer)