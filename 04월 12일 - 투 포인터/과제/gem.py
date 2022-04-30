"""
 [보석 쇼핑]

 1. dictionary를 활용해 보석의 종류 구함 (중복 x)
 2. 같은 위치에서 시작해서 같은 방향으로 이동하면서 모든 종류 포함하는 구간의 최소값 찾아감 (투 포인터)
    - 이때, 구간 안에 보석 종류의 존재 여부를 dictionary를 통해서 관리
"""

def solution(gems):
    size = len(gems)
    answer = [1, size]
    
    # 보석의 개수를 기록할 딕셔너리
    gem_dict = dict()
    for i in gems:
        gem_dict[i] = 0 # 우선은 0으로 기록

    total = len(gem_dict) # 전체 보석의 종류 수
    
    left = 0
    right = 0
    # 초기 구간 설정
    gem_dict[gems[left]] += 1
    count = 1   # 현재 구매한 보석의 종류 수
    
    while left <= right and right < size:
        if count == total:  # 모든 종류의 보석이 있음 -> 구간 짧게
            if right - left < answer[1] - answer[0]:
                answer = [left + 1, right + 1]

            gem_dict[gems[left]] -= 1
            if gem_dict[gems[left]] == 0:
                count -= 1  # 종류 수 갱신
            left += 1

        elif count < total:    # 모든 종류의 보석이 있는게 아니라면
            right += 1  # 구간을 길게하기 위해 right 이동
            if right == size:   # 인덱스 에러 방지
                break
            if gem_dict[gems[right]] == 0:
                count += 1  # 종류 수 갱신
            gem_dict[gems[right]] += 1

    return answer


# 테스트용 메인함수
# (IDE에서 테스트하실 수 있도록 제공하지만, 가능하면 프로그래머스에서 디버깅하는 연습을 하셨으면 좋겠습니다.)
if __name__ == "__main__":
    gems = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]
    ans = solution(gems)
    print(*ans)