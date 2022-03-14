#include <iostream>
#include <set>

using namespace std;

//서로 다른 부분 문자열 구하는 함수
int cntDiff(string s) {
    set<string> sub; //중복 없이 부분 문자열 저장
    for (int i = 0; i < s.length(); i++) {
        string temp = "";
        for (int j = i; j < s.length(); j++) {
            temp += s[j]; //i-j 부분 문자열
            sub.insert(temp); //삽입
        }
    }
    return sub.size();
}

/**
 * 중복을 제거해서 저장해주는 컨테이너인 set을 활용해서 풀이 가능
 * 삽입만 하므로 트리 구조 셋(set)이나 해시 구조 셋(unordered_set) 중 무엇을 쓰든 크게 상관 x
 */

int main() {
    string s;

    //입력
    cin >> s;
    //연산 & 출력
    cout << cntDiff(s);
    return 0;
}