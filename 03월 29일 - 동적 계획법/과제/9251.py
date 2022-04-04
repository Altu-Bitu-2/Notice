import sys
input = sys.stdin.readline

"""
 LCS (해당 풀이는 "08. 동적계획법.pdf" 참고)

 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
"""

def get_lcs_size(text1, text2):
    size1 = len(text1)
    size2 = len(text2)
    dp = [[0] * (size2 + 1) for _ in range(size1 + 1)]

    for i in range(1, size1 + 1):
        for j in range(1, size2 + 1):
            if text1[i - 1] == text2[j - 1]:    # 두 문자가 같으면
                dp[i][j] = dp[i-1][j-1] + 1
            else: # 두 문자가 다르면
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    
    return dp[size1][size2] # 최종 lcs 길이 리턴


# 입력
text1 = input().rstrip()
text2 = input().rstrip()

# 연산 + 출력
print(get_lcs_size(text1, text2))