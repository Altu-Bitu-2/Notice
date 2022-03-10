import sys
input = sys.stdin.readline
# 리스트 표현식이 익숙하지 않다면, 과제 소스코드과 함께 올라온 링크를 참고해주세요.
# 문제에 주어진 a번째와 b번째는 1부터 시작이므로, 인덱스를 맞춰주기 위해 인덱스 1부터 숫자를 채워 넣습니다.
arr = [i for i in range(0, 21)]

def reverse_card(left, right):
    # [left, right] 닫힌 구간에 포함된 카드를 뒤집는다.
    # 슬라이싱에서 항상 왼쪽은 포함, 오른쪽은 포함되지 않는다고 생각하면 됩니다.
    # 슬라이싱 세번째 요소는 step이에요. 몇 칸씩 건너 뛸건지를 써주면 되고, 아무것도 쓰지 않으면 default로 1칸이 됩니다.
    arr[left:right+1] = arr[right:left-1:-1]

    # 혹은... 순서를 뒤집어 주는 reversed 함수를 쓸 수도 있어요.
    # arr[left:right+1] = reversed(arr[left:right+1])
    return

for _ in range(10):
    a, b = map(int, input().split())
    reverse_card(a, b)

# print()는 end와 sep 값을 지정해서 출력을 원하는 대로 할 수 있어요.
# end는 출력 끝에 덧붙는 문자(열), sep은 여러개를 출력할 때 구분해주는 구분자
# default 값은 end='\n', sep = ' '
for i in arr[1:]:
    print(i, end=' ')