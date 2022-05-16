import sys
input = sys.stdin.readline

"""
 [Java vs C++]

 1. 입력으로 주어진 변수가 C++ 형식에도 맞고, JAVA 형식에도 맞을 수 있음 (ex. name)
 2. "Error!"인 경우 
    2-1. (공통) 알파벳 소문자로 시작하지 않는 변수
    2-2. (Java)
        - 언더바('_')가 등장하는 변수
    2-3. (C++)
        - 언더바('_')가 연속해서 등장하는 변수
        - 대문자가 등장하는 변수

(주의) python에서 string은 immutable한 객체이다 -> 변경이 불가능
ex) 아래 코드를 실행해보세요
    a = "hello"
    a[0] = "H" 
"""

# cpp 형식으로 바꾸는 함수
def to_cpp(word):
    result = ""

    for c in word:
        if c == c.upper():
            result += '_'
        result += c.lower()
    
    return result

# 가능하면 java형식으로 바꾸는 함수
def to_java_if_possible(word_list):
    result = []
    for word in word_list:
        if len(word) == 0 or word != word.lower():
            return "Error!"
        result.append(word.capitalize())

    result[0] = result[0].lower() # 첫 단어는 capitalize하면 안됨
    return ''.join(result)

# 입력
word = input().rstrip()


if (not word[0].isalpha()) or word[0] == word[0].upper(): # 공통 예외에 포함되는 경우
    print("Error!")
elif word.isalpha():    # Java식 변수인 경우
    print(to_cpp(word))
else:   # 나머지 경우 (error || cpp식 변수)
    word_list = word.split('_')
    print(to_java_if_possible(word_list))