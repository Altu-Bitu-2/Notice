#include <iostream>
#include <map>
#include <string>

using namespace std;

/**
 * 중복없이 정렬이 필요한 경우
 * key(확장자)-value(파일 개수) 쌍이 필요하므로 map 사용
 */

int main() {
    int n;
    string input;
    map<string, int> extension; //key: 확장자, value: 확장자 파일 개수

    //입력 & 연산
    cin >> n;
    while (n--) {
        cin >> input;
        //string.substr(pos, len): 첫 번째 문자의 위치(pos)부터 pos + len 까지의 부분 문자열
        //pos + len 이 문자열보다 길다면 문자열 마지막 문자까지만 리턴하도록 처리
        string ext = input.substr(input.find('.') + 1, input.length()); //.뒤의 부분 문자열 추출
        extension[ext]++; //확장자 개수 추가
    }
    //출력
    for (auto iter = extension.begin(); iter != extension.end(); iter++) {
        cout << iter->first << ' ' << iter->second << '\n';
    }
    return 0;
}