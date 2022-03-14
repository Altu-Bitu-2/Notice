import sys
# 로컬에서 코드를 확인하기 위해, 파일로 입력을 전달합니다.
# sys.stdin = open('input.txt 파일경로', 'r') # 이 부분은 백준에 올릴 때는 주석처리합니다.
input = sys.stdin.readline


s, e, q = input().split()
attendance = set()
answer = 0  # 출석 확인된 회원 수

# 이 문제는 파일의 끝 (EOF, End Of File)까지 입력을 받아야 하는 문제 입니다.
# try, except 문을 통해 입력이 들어오지 않는 경우에 대한 예외 처리를 해줍니다.
while (True):
    try:
        time, name = input().rstrip().split()
        # 입장 확인
        if time <= s:
            attendance.add(name)
        # 퇴장 확인
        elif e <= time <= q:
            if name in attendance:
                answer += 1
                attendance.remove(name) # 중복 체크를 방지하기 위해 이름을 제거한다.

    except:
        # 입력이 끝났으므로, 출석 인원 출력
        print(answer)
        break