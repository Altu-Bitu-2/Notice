//
// Created by BaeSuA on 2022-03-04.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//(python3) 파이썬은 리스트에 문자열과 정수를 동시에 저장할 수 있으니, 그냥 리스트를 사용하면 된다
struct student { //학생들의 정보를 나타내는 구조체
    string name;
    int kor, eng, math;
};

//비교 함수(bad)
bool cmp(const student &a, const student &b) {
    if (a.kor == b.kor) { //국어 점수가 같으면 영어 점수가 증가하는 순서로
        if (a.eng == b.eng) { //국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
            if (a.math == b.math) { //모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로
                return a.name < b.name;
            }
            return a.math > b.math;
        }
        return a.eng < b.eng;
    }
    return a.kor > b.kor; //국어 점수가 감소하는 순서로
}

//비교 함수(good)
//(python3) lambda 함수를 이용해서 보다 편리하게 각 index에 대한 각각의 정렬을 짤 수 있음 (피피티 자료 참고)
bool cmpAdv(const student &a, const student &b) {
    if (a.kor != b.kor) { //1. 국어 점수가 다르다면 감소하는 순서
        return a.kor > b.kor;
    }
    if (a.eng != b.eng) { //2. (국어 점수는 같고) 영어 점수가 다르다면 증가하는 순서
        return a.eng < b.eng;
    }
    if (a.math != b.math) { //3. (국어, 영어 같고) 수학 점수가 다르다면 감소하는 순서
        return a.math > b.math;
    }
    return a.name < b.name; //4. (국어, 영어, 수학 모두 같고) 이름이 사전 순으로 증가하는 순서
}

int main() {
    int n;
    //입력
    cin >> n;
    vector<student> arr(n);
    for (int i = 0; i < n; i++) { //이름, 국어, 영어, 수학 점수
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
    }
    //연산
    sort(arr.begin(), arr.end(), cmpAdv);
    //출력
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << '\n';
    }
    return 0;
}