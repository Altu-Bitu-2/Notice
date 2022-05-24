# 유니온 파인드 (Union Find)

[메인으로 돌아가기](https://github.com/Altu-Bitu-2/Notice)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/1717" target="_blank">1717</a>|<a href="https://www.acmicpc.net/problem/1717" target="_blank">집합의 표현</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/4803" target="_blank">4803</a>|<a href="https://www.acmicpc.net/problem/4803" target="_blank">트리</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/16562" target="_blank">16562</a>|<a href="https://www.acmicpc.net/problem/16562" target="_blank">친구비</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>|[바로가기]()| &nbsp; |


## ✏️ 과제
### 마감기한
~ 5 / 30 (월) 낮 12:00 - 코드 리뷰 O </br>
~ 5 / 30 (월) 밤 11:59 - 코드 리뷰 X </br>
~ 5 / 31 (화) 밤 11:59 - 추가 제출 </br>

### 필수

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/12100" target="_blank">12100</a>|<a href="https://www.acmicpc.net/problem/12100" target="_blank">2048 (Easy)</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>|[C++]()<br/>[Python3]()||
|<a href="https://www.acmicpc.net/problem/16114" target="_blank">16114</a>|<a href="https://www.acmicpc.net/problem/16114" target="_blank">화살표 연산자</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[C++]()<br/>[Python3]()| &nbsp; |


---

### 선택

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/20040" target="_blank">20040</a>|<a href="https://www.acmicpc.net/problem/20040" target="_blank">사이클 게임</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[C++]()<br/>[Python3]()||
|<a href="https://programmers.co.kr/learn/courses/30/lessons/64063" target="_blank">2019 카카오 개발자 겨울 인턴십</a>|<a href="https://programmers.co.kr/learn/courses/30/lessons/64063" target="_blank">호텔 방 배정</a>|Level 4|[C++]()<br/>[Python3]()||
|<a href="https://www.acmicpc.net/problem/1043" target="_blank">1043</a>|<a href="https://www.acmicpc.net/problem/1043" target="_blank">거짓말</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/>|[C++]()<br/>[Python3]()||
|<a href="https://www.acmicpc.net/problem/4195" target="_blank">4195</a>|<a href="https://www.acmicpc.net/problem/4195" target="_blank">친구 네트워크</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/>|[C++]()<br/>[Python3]()||
|<a href="https://www.acmicpc.net/problem/20303" target="_blank">20303</a>|<a href="https://www.acmicpc.net/problem/20303" target="_blank">할로윈의 양아치</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/>|[C++]()<br/>[Python3]()|&nbsp;|



---

### 힌트

<details>
<summary>2048 (Easy)</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;가능한 모든 경우를 탐색해도 상, 하, 좌, 우 4가지 경우에 깊이는 최대 5까지 밖에 안 빠지네요! 시간은 충분해요. 블록을 이동 시키는 부분을 잘 구현해야겠어요. 잘 풀리지 않는다면, 두 수가 같지 않은 경우와 근접한 칸이 아니라 서로 떨어져 있는데 같은 수인 경우를 잘 처리했는지 확인해 볼까요?
</div>
</details>

<details>
<summary>화살표 연산자</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;간단해 보이지만 몇 가지 코너 케이스를 주의해야 해요. INFINITE, ERROR, 0이 나오는 경우를 잘 정리해 볼까요? x 자체가 양수와 음수일 수도 있지만, n의 개수에 따라 부호가 바뀔 수도 있죠.
</div>
</details>

<details>
<summary>사이클 게임</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;사이클이 발생하는 순간을 파악하려면 매번 사이클 발생 여부를 체크해야겠네요. 이걸 빠르게 계산하려면 어떤 방법을 써야 할까요?
</div>
</details>

<details>
<summary>호텔 방 배정</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;배정하는 방에 곧바로 접근할 수 있는 방법은 없을까요? 배정하는 방들은 모두 순서대로 연결되어 있어요. 그런데 여기까지만 해결하면 효율성에서 점수를 얻을 수 없어요! 문제의 입력 범위를 다시 살펴볼까요? 입력으로 들어올 수 있는 방 번호의 범위가 크네요.
</div>
</details>

<details>
<summary>거짓말</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;같은 파티에 속한 사람들은 하나의 집합에 속해 있다고 할 수 있겠네요. 진실을 말할 수 없는 경우는 그 집합이 어떤 상태일 때 일까요? 라이브 코딩에서 다룬 4803번에서 힌트를 구할 수 있어요! 한 사람이 여러 파티에 참여할 수 있다는 걸 잊으면 안돼요.
</div>
</details>

<details>
<summary>친구 네트워크</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;그래프의 정점이 문자열으로 들어오네요! 바로 쓰기엔 어려우니 정수로 바꾸어 사용해야겠어요. 어떤 컨테이너를 활용하면 좋을까요?
</div>
</details>

<details>
<summary>할로윈의 양아치</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;우선 아이들의 무리와 각 무리의 사탕의 수를 구해야 해요! 이는 집합으로 나누고, 각 집합의 원소 개수와 원소들의 합을 구하는 것과 같죠. 튜터링 때 다룬 가장 효율적인 유니온 파인드를 활용해 볼 수 있겠어요. 그리고 구한 아이들의 무리를 잘 선택해서 k명 미만의 아이로 가장 많은 사탕을 뺏는 건 예전에 다룬 알고리즘을 활용할 수 있어요. 마치 무게가 정해진 배낭에 사탕을 최대한 많이 챙기는 것과 같지 않나요..?
</div>
</details>


---

### 코드리뷰 가이드

🔗 [링크]()
