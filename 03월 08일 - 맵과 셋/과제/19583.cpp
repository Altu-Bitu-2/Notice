#include <iostream>
#include <map>

using namespace std;

/**
 * 개강총회가 시작하기 전에 입장한 학회원을 먼저 map 에 삽입
 * 개강총회를 끝내고 나서부터 스트리밍을 끝낼 때까지의 시간대의 채팅 기록을 보고 퇴장 여부 확인
 * -> 이때, 한 사람이 채팅 여러개 남겼을 수 있으므로 이미 확인한 사람 체크하는 게 중요 (map 의 value 값 활용해서 체크)
 * 시간은 문자열로 받아서 처리 (대소관계 숫자와 동일)
 */

int main() {
    //로컬에서 편하게 확인하기 위해 파일로 입력을 받아서 사용!
    //이때 파일 읽어오기가 제대로 안된다면 다음 블로그 포스팅 참고
    //링크: https://blog.naver.com/PostView.nhn?blogId=strike0115&logNo=221519898666&from=search&redirect=Log&widgetTypeCall=true&directAccess=false
    //freopen("input.txt", "r", stdin);

    string s, e, q, t, name;
    map<string, bool> m;
    int ans = 0; //출석 확인된 학회원 인원 수

    //입력 & 연산
    cin >> s >> e >> q;
    while (cin >> t >> name) { //입력이 있을 때 동안 반복
        if (t <= s) { //개강총회 시작하기 전 입장 시간대
            m[name] = true; //우선 저장
        } else if (t >= e && t <= q) { //개강총회 끝 ~ 스트리밍 끝 시간대
            if (m[name]) { //출석 확인
                ans++;
                m[name] = false; //같은 사람 여러번 출석 되면 안되므로 체크
            }
        }
    }
    //출력
    cout << ans << '\n';
    return 0;
}