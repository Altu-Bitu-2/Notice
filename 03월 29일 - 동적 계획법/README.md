# 동적 계획법 (Dynamic Programming)

[메인으로 돌아가기](https://github.com/Altu-Bitu-2/Notice)

## 💻 튜터링

### 라이브 코딩

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/2579" target="_blank">2579</a>|<a href="https://www.acmicpc.net/problem/2579" target="_blank">계단 오르기</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[바로가기](https://github.com/Altu-Bitu-2/Notice/blob/main/03%EC%9B%94%2029%EC%9D%BC%20-%20%EB%8F%99%EC%A0%81%20%EA%B3%84%ED%9A%8D%EB%B2%95/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/2579.cpp)|다이나믹 프로그래밍|
|<a href="https://www.acmicpc.net/problem/12865" target="_blank">12865</a>|<a href="https://www.acmicpc.net/problem/12865" target="_blank">평범한 배낭</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기](https://github.com/Altu-Bitu-2/Notice/blob/main/03%EC%9B%94%2029%EC%9D%BC%20-%20%EB%8F%99%EC%A0%81%20%EA%B3%84%ED%9A%8D%EB%B2%95/%EB%9D%BC%EC%9D%B4%EB%B8%8C%20%EC%BD%94%EB%94%A9/12865.cpp)|다이나믹 프로그래밍|


## ✏️ 과제
### 마감기한
~ 4 / 4 (월) 낮 12:00 - 코드 리뷰 O </br>
~ 4 / 4 (월) 밤 11:59 - 코드 리뷰 X </br>
~ 4 / 5 (화) 밤 11:59 - 추가 제출 </br>


### 선택

|문제 번호|문제 이름|난이도|풀이 링크|분류|
| :-----: | :-----: | :-----: | :-----: | :-----: |
|<a href="https://www.acmicpc.net/problem/11727" target="_blank">11727</a>|<a href="https://www.acmicpc.net/problem/11727" target="_blank">2×n 타일링 2</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/9095" target="_blank">9095</a>|<a href="https://www.acmicpc.net/problem/9095" target="_blank">1, 2, 3 더하기</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/8.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/11053" target="_blank">11053</a>|<a href="https://www.acmicpc.net/problem/11053" target="_blank">가장 긴 증가하는 부분 수열</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/9.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/9084" target="_blank">9084</a>|<a href="https://www.acmicpc.net/problem/9084" target="_blank">동전</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/9251" target="_blank">9251</a>|<a href="https://www.acmicpc.net/problem/9251" target="_blank">LCS</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/11.svg"/>|[바로가기]()||
|<a href="https://www.acmicpc.net/problem/11057" target="_blank">11057</a>|<a href="https://www.acmicpc.net/problem/11057" target="_blank">오르막 수</a>|<img height="25px" width="25px" src="https://static.solved.ac/tier_small/10.svg"/>|[바로가기]()||


---

### 힌트

<details>
<summary>2×n 타일링 2</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;각 너비마다 배치할 수 있는 경우의 수를 저장해 볼까요? 그 전의 타일에서 특정 타일을 이어 붙인다 생각하면 좋을 것 같아요. 이때, 중복으로 경우를 세지 않도록 주의해야겠어요!
</div>
</details>

<details>
<summary>1, 2, 3 더하기</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;수를 1, 2, 3의 합으로 나타낸 다는 건, 이미 1, 2, 3의 합으로 이루어진 수에서 각각 1과 2와 3을 더해서 나타낸다고 생각해도 좋겠어요!
</div>
</details>

<details>
<summary>가장 긴 증가하는 부분 수열</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;각 수마다 가장 긴 증가하는 부분수열을 저장하며 풀면 될 것 같아요. 어렵다면 깃허브에 올라간 강의자료 피피티를 참고해볼까요! 정확히 같은 문제가 소개되어 있어요.
</div>
</details>

<details>
<summary>동전</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;일단 동전의 종류가 주어지는 것이니, 사용 개수에는 제한이 없네요! 동전을 만들 수 없는 경우도 생긴다는 걸 주의해야겠어요.
</div>
</details>

<details>
<summary>LCS</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp; LCS에 대한 설명은 강의자료 피피티를 참고해볼까요! 표를 먼저 채우고, 구현하면 좋을 것 같아요.
</div>
</details>

<details>
<summary>오르막 수</summary>
<div markdown="1">
&nbsp;&nbsp;&nbsp;&nbsp;오르막 수의 일의 자리에 집중해 볼까요. 길이가 N인 오르막 수를 한 번에 만드는 것이 아니라 그 전의 연산을 저장하며 사용해보면 어떨까요?
</div>
</details>

---

### 코드리뷰 가이드

🔗 [링크]()
