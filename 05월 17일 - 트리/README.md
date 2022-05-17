# 트리

[메인으로 돌아가기](https://github.com/Altu-Bitu-2/Notice)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/1991" target="_blank">1991</a>|<a href="https://www.acmicpc.net/problem/1991" target="_blank">트리 순회</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/>|[바로가기]()|트리|
|<a href="https://www.acmicpc.net/problem/4803" target="_blank">4803</a>|<a href="https://www.acmicpc.net/problem/4803" target="_blank">트리</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()|트리|
|<a href="https://www.acmicpc.net/problem/24545" target="_blank">24545</a>|<a href="https://www.acmicpc.net/problem/24545" target="_blank">Y</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/16.svg"/>|[바로가기]()|트리|



## ✏️ 과제
### 마감기한
~ 5 / 23 (월) 낮 12:00 - 코드 리뷰 O </br>
~ 5 / 24 (월) 밤 11:59 - 코드 리뷰 X </br>
~ 5 / 24 (화) 밤 11:59 - 추가 제출 </br>

### 필수

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://programmers.co.kr/learn/courses/30/lessons/92342" target="_blank">2022 KAKAO BLIND RECRUITMENT</a>|<a href="https://programmers.co.kr/learn/courses/30/lessons/92342" target="_blank">양궁대회</a>|Level 2|[C++]()<br/>[Python3]()|트리|
|<a href="https://www.acmicpc.net/problem/1713" target="_blank">1713</a>|<a href="https://www.acmicpc.net/problem/1713" target="_blank">후보 추천하기</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>|[C++]()<br/>[Python3]()|트리|

---

### 선택

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/5639" target="_blank">5639</a>|<a href="https://www.acmicpc.net/problem/5639" target="_blank">이진 검색 트리</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[C++]()<br/>[Python3]()|그래프, 그래프 탐색|
|<a href="https://www.acmicpc.net/problem/1967" target="_blank">1967</a>|<a href="https://www.acmicpc.net/problem/1967" target="_blank">트리의 지름</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[C++]()<br/>[Python3]()|그래프, 그래프 탐색|
|<a href="https://www.acmicpc.net/problem/1068" target="_blank">1068</a>|<a href="https://www.acmicpc.net/problem/1068" target="_blank">트리</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[C++]()<br/>[Python3]()|그래프, 그래프 탐색|
|<a href="https://www.acmicpc.net/problem/15681" target="_blank">15681</a>|<a href="https://www.acmicpc.net/problem/15681" target="_blank">트리와 쿼리</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[C++]()<br/>[Python3]()|그래프, 그래프 탐색|
|<a href="https://www.acmicpc.net/problem/17471" target="_blank">17471</a>|<a href="https://www.acmicpc.net/problem/17471" target="_blank">게리맨더링</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[C++]()<br/>[Python3]()|그래프, 그래프 탐색|



---

### 힌트
<details>
<summary>양궁대회</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;
  n의 범위가 매우 작아요! 라이언이 주어진 화살로 과녁을 맞추는 모든 경우를 다뤄볼 수 있겠어요. 각 과녁에 대해 라이언이 이기는 경우와 그렇지 않은 경우를 생각해볼까요? 마지막으로, 차이가 동점인 경우 낮은 점수를 더 많이 맞힌 경우를 선택하는 부분을 잘 처리해야 해요. 탐색에 따라 단순 갱신해줘선 안돼요. 따로 조건 처리를 해볼까요?
</div>
</details>

<details>
<summary>후보 추천하기</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;
  후보를 저장하는 컨테이너로 무엇을 사용하면 좋을까요? 후보를 바로 찾아서 연산할 수 있는 컨테이너면 좋겠네요. 후보가 모두 꽉 찼을 경우와 게시 시간을 다루는 부분을 잘 고려해야 해요. 그리고 비어있는 사진틀이 있을 수도 있어요.
</div>
</details>

<details>
<summary>이진 검색 트리</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;
  BST를 직접 만들어 볼까요? BST에 정점을 추가하는 것도 map을 다룰 때 배웠었어요. 그런 다음, 후위 순회한 결과를 출력하는 건 쉽겠네요! 피피티에도 코드가 나와있어요.
</div>
</details>

<details>
<summary>트리의 지름</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;
  지름을 이루는 두 정점을 동시에 찾을 순 없어요. 임의의 모든 정점에서 가장 멀리 있는 정점들은 어떤걸까요? 그 정점들엔 어떤 공통점이 있나요? 지름의 길이를 구하려면 자식->부모 방향으로 거슬러 올라가야 할 수도 있겠어요. 그림에 힌트가 아주 많아요!
</div>
</details>

<details>
<summary>트리</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;
  리프 노드의 수를 구하는 건 튜터링 시간에도 다뤘어요! (PPT 자료에 코드도 있어요.) 그런데 정점을 지울 때, 항상 리프 노드의 개수가 감소하기만 할까요? 증가하는 경우도 있지 않을까요?
</div>
</details>

<details>
<summary>트리와 쿼리</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;
  매번 특정 정점을 루트로 하는 서브 트리의 정점 수를 구하기엔 시간이 너무 오래 걸려요. 모든 서브 트리의 정점 수를 어딘가 '저장'해둘 수는 없을까요? 문제가 기네요. 그만큼 힌트도 많이 있습니다! (PPT에도 있구요)
</div>
</details>

<details>
<summary>게리맨더링</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;
  n의 범위가 매우 작아요! 뭐든 해봐도 좋겠어요. 일단 구역을 나누는 모든 경우의 수를 구해볼까요? 비트마스킹, 조합, 백트래킹 무엇을 써도 좋아요. 그런 다음 해당 구역이 조건을 만족하는지 확인해서 최솟값을 갱신하면 되겠네요!
</div>
</details>



---

### 코드리뷰 가이드

🔗 [링크]()
