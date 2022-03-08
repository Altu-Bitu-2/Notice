#include <iostream>
#include <vector>

using namespace std;
typedef pair<string, int> si; //string, int 쌍을 si로 쓸 것임을 정의
const int MAX_SIZE = 3; //버킷 크기

//버킷
vector<vector<si>> bucket;

//해시 함수
int hashFunc(string str) {
    int key = 0;
    for (int i = 0; i < str.size(); i++) {
        key += (str[i] - 'a') * i;
    }
    return key % MAX_SIZE;
}

//버킷의 상태를 출력
void printHash() {
    for (int i = 0; i < MAX_SIZE; i++) { //i번째 버킷
        cout << "[ " << i << " ] -> ";
        for (int j = 0; j < bucket[i].size(); j++) { //i번째 버킷에 있는 모든 데이터 출력
            cout << "( " << bucket[i][j].first << ' ' << bucket[i][j].second << " ) ";
        }
        cout << '\n';
    }
}

//학생 이름으로 점수 찾기
int findScore(string name) {
    int key = hashFunc(name); //key 값 구하기
    for (int i = 0; i < bucket[key].size(); i++) { //해당하는 버킷에서 일치하는 데이터 찾기
        if (bucket[key][i].first == name) { //데이터 찾음
            return bucket[key][i].second;
        }
    }
    return -1; //일치하는 데이터가 없음
}

/**
 * (해시 함수 예시)
 * key가 영어 소문자로만 이루어진 문자열 str일 때,
 * 모든 i (0 <= i < str.size())에 대해 ‘(str[i] – ‘a’) * i’를 더한 값을
 * bucket의 크기로 나눈 나머지
 */

int main() {
    //입력
    vector<si> student;
    student.emplace_back("lee", 42);
    student.emplace_back("lim", 100);
    student.emplace_back("bae", 50);
    student.emplace_back("park", 88);

    //연산
    bucket.assign(MAX_SIZE, vector<si>(0));
    for (int i = 0; i < student.size(); i++) {
        int key = hashFunc(student[i].first); //해시 함수를 통해 int형의 key값으로 변환
        bucket[key].push_back(student[i]);
    }
    printHash();

    string target = "bae";
    int score = findScore(target); //타겟 있는지 찾기 (find)

    //출력
    if (score == -1)
        cout << "No Such Data\n";
    else
        cout << "Score of " << target << " : " << score << '\n';
}