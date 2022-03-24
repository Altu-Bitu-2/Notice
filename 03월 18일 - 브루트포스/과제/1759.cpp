#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<char, bool> vowels; //모음 저장 맵

//조합 임시배열로 문자열을 만드는 함수
string charToString(int c, vector<char> &alphabet, vector<bool> &is_in_password) {
    string result = "";
    for (int i = 0; i < c; i++) {
        if (is_in_password[i]) { //연산에 포함된 문자라면 result에 더하기
            result += alphabet[i];
        }
    }
    return result;
}

//암호 만들기 가능한지 확인하는 함수 (최소 모음 1개, 최소 자음 2개)
bool isValid(int l, int c, vector<char> &alphabet, vector<bool> &is_in_password) {
    int cnt_vowels = 0;
    //자음 개수는 암호 전체 길이에서 모음 개수를 빼서 알 수 있음
    for (int i = 0; i < c; i++) {
        if (!is_in_password[i]) { //암호에 속하지 않았다면
            continue;
        }
        if (vowels[alphabet[i]]) { //모음이라면
            cnt_vowels++;
        }
    }
    return (cnt_vowels >= 1) && ((l - cnt_vowels) >= 2);
}

//조합 구하기
vector<string> findPassword(int l, int c, vector<char> &alphabet) {
    vector<string> result;
    vector<bool> is_in_password(c, false);
    for (int i = 0; i < l; i++) { //미리 l개의 true 저장
        is_in_password[i] = true;
    }
    do {
        if (isValid(l, c, alphabet, is_in_password)) { //암호 만들기 가능하다면
            result.push_back(charToString(c, alphabet, is_in_password));
        }
    } while (prev_permutation(is_in_password.begin(), is_in_password.end()));

    return result;
}

/**
 * [암호 만들기]
 * 알파벳은 최대 15개 -> 브루트포스 가능
 * 가능한 모든 조합 만들어서, 검사 통과하면 출력
 */

int main() {
    int l, c;

    //모음 저장
    vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = true;

    //입력
    cin >> l >> c;
    vector<char> alphabet(c, 0);
    for (int i = 0; i < c; i++) {
        cin >> alphabet[i];
    }

    //연산
    sort(alphabet.begin(), alphabet.end()); //오름차순 정렬
    vector<string> result = findPassword(l, c, alphabet);

    //출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}