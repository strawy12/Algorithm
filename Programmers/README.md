<div align="center">

  # Progammers
[나가기](https://github.com/strawy12/Algorithm)
</div> <br><br>

## 바로 가기
[📂 폴더가기](https://github.com/strawy12/Algorithm/tree/main/Programmers)
<br><br>

[🔠🔢 숫자 문자열과 영단어](https://github.com/strawy12/Algorithm/blob/main/Programmers/README.md#-%EC%88%AB%EC%9E%90-%EB%AC%B8%EC%9E%90%EC%97%B4%EA%B3%BC-%EC%98%81%EB%8B%A8%EC%96%B4) <br>
[🔓신규 아이디 추천](https://github.com/strawy12/Algorithm/blob/main/Programmers/README.md#%EC%8B%A0%EA%B7%9C-%EC%95%84%EC%9D%B4%EB%94%94-%EC%B6%94%EC%B2%9C)

<br><br>

## 알고리즘 노트
### 🔠🔢 숫자 문자열과 영단어
 [돌아가기](https://github.com/strawy12/Algorithm/blob/main/Programmers/README.md#progammers)
 <br> <br> 
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/81301">문제 보기</a><br>
<a href="https://github.com/strawy12/Algorithm/blob/main/Programmers/%EC%88%AB%EC%9E%90%20%EB%AC%B8%EC%9E%90%EC%97%B4%EA%B3%BC%20%EC%98%81%EB%8B%A8%EC%96%B4.cpp">코드 보기</a>
<br>
🕑**걸린 시간** : 1시간 이상

  #### 문제 분석
  이 문제는 문자열 안에 있는 **숫자 영단어**를 실제 **숫자**로 **변환**해줘야하는 문제이다.
  <br>
  `ex) "one23four" -> 1234, "zero82eight" -> 0828`
  
  
  #### 알고리즘 설계
  우선 나는 처음으론 **문자열을 전부 검색하여** 숫자가 아닌 부분은 어떤 영단어인지 확인하여 변환해주는 **if문 위주**로 푸는 방식을 택했고 
  변환한 값이 **자릿수**까지 맞춰질 수 있게 위치에 따라 **10ⁿ을 곱하여** 정수형으로 변환해주었다.
  그렇게 나온 코드는 처참했다.<br><br>
   <img src="https://user-images.githubusercontent.com/77821550/187939585-f4504265-8490-4f09-93e2-592315de3b76.png"  width="440" height="250"/>

  약 100줄이 되는 [코드](https://github.com/strawy12/Algorithm/blob/c88be9c2aed826842abbe96b3b2055fe800ee5cb/Programmers/%EC%88%AB%EC%9E%90%20%EB%AC%B8%EC%9E%90%EC%97%B4%EA%B3%BC%20%EC%98%81%EB%8B%A8%EC%96%B4.cpp#L7)가 나오게 되었다. <br>
  코드를 보시면 바로 알 수 있겠지만 **매우 길고 가독성도 떨어지고** 새로운 변환단어가 나오게된다면 **유지보수**하기에도 **큰 어려움**이 생길 수 있다.
  <br>
  
  #### 개선한 코드
  위와같은 코드를 작성한 이후 다른 방법을 여러가지 고민해보고 참고해보고 검색해본 결과 이러한 [코드](https://github.com/strawy12/Algorithm/blob/c88be9c2aed826842abbe96b3b2055fe800ee5cb/Programmers/%EC%88%AB%EC%9E%90%20%EB%AC%B8%EC%9E%90%EC%97%B4%EA%B3%BC%20%EC%98%81%EB%8B%A8%EC%96%B4.cpp#L104)가 나오게 됐다<br><br>
  
```cpp
int solution(string s) {
	int answer = 0;
	string nums[10] = { 
		"zero","one","two","three","four",
		"five","six","seven","eight", "nine" };

	for (int i = 0; i < 10; i++)
	{
		size_t nPos = s.find(nums[i]);

		if (nPos != string::npos)
		{
			s = s.replace(nPos, nums[i].length(), to_string(i));
			i--;
		}
	}
	
	answer = stoi(s);
	return answer;
}
```

 이 알고리즘은 위와 **비슷한 구조**로 되어있지만 좀 더 **간단히** 되어있다.<br>
 우선 첫번째로 가장 크게 달라진 점은 변환시킬 **영단어를 미리 배열에 선언** 해 놓는 방식이다.<br>
 이렇게 된다면 **0번째 index에는 "zero"가** 들어가고 **9번째 index에는 "nine"이** 들어 가 있어 영단어를 변환하는 데 있어 좀 더 간편해졌다.
 <br><br>
 
 ![image](https://user-images.githubusercontent.com/77821550/187941201-30bc0213-8b4e-4ade-a0b5-5ec8e8a86098.png)
 > 인덱스 번호에 따른 단어들
 
 <br><br>

 두번째로는 찾는 방식을 **siwtch**에서 string 맴버함수인 **find()**를 활용하여 더욱 간편하게 변경했다.<br>
```cpp
size_t nPos = s.find(nums[i]);

if (nPos != string::npos)
{
	s = s.replace(nPos, nums[i].length(), to_string(i));
}
```
<br>
이 **find()** 함수는 `문자열.find("찾고자하는 문자열");` <br>
이렇게 사용하게 된다면 **찾고자하는 값**이 문자열 안에 있다면 그 **위치(index)를 반환**하는 함수이다.
그리고 만약 문자열에 **없다면** **string::npos 의 값을 반환**한다고 한다.
<br><br>

그 후 string의 맴버함수인 **replace()** 를 활용하여 **문자열을 변경**해줬다.
```cpp
s = s.replace(nPos, nums[i].length(), to_string(i));
```
이 함수는 다음과 같이 사용할 수 있다. `문자열.replace(시작위치, 길이, 변경할 값)` <br>
설명하자면 **시작위치**에서부터 **길이만큼**의 **값**이 변경할 값으로 **대체** 된다.
<br><br>

그래서 **find**를 통해 영단어를 **찾고** 그 위치에 숫자를 **replace**를 사용해 **변경**해줬다.

#### 개선된 코드 - 2
위 방식과 **로직은 비슷**하지만 **새로운 문법**으로 푼 방법을 가져와봤다.<br>

```cpp
int solution(string s) {
	int answer = 0;
	string nums[10] = {
		"zero","one","two","three","four",
		"five","six","seven","eight", "nine" };

	for (int i = 0; i < 10; i++)
	{
		s = regex_replace(s, regex(nums[i]), to_string(i));
	}

	answer = stoi(s);
	return answer;
}
```
<br>

여기서 가장 유심있게 봐야하는 부분은 이 부분이다. `regex_replace(s, regex(nums[i]), to_string(i))`

이 방식은 이렇게 사용된다. `regex_replace(문자열, regex("변경할 부분"), "대체 값")` <br>
**replace** 방식과 **비슷**한 함수지만 좀 더 **직관적**이고 찾을 문자열이 있는지 일일히 확인 안 해도 되니까 **좀 더 편리**할 거 같다.


<br><br>

#### 새롭게 알게된 점, 느낀점
**알게된 점**: ***string.replace(), string.find(), string::npos, regex_replace***에 대해 새로 자세히 알게 되었다.
**느낀점**: 문제 푸는 데 있어서 가독성도 매우 중요하고, 문법도 많이 중요하다는 사실을 알았다.

**문법 정리 바로가기**
[string.replace()]()
[string.find() & string::npos]()
[regex_replace()]()
<br><br>
 
 ### 🔓신규 아이디 추천 
 [돌아가기](https://github.com/strawy12/Algorithm/blob/main/Programmers/README.md#progammers)
 <br> <br> 
 
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/72410">문제 보기</a><br>
<a href="https://github.com/strawy12/Algorithm/blob/main/Programmers/%EC%8B%A0%EA%B7%9C%20%EC%95%84%EC%9D%B4%EB%94%94%20%EC%B6%94%EC%B2%9C.cpp">코드 보기</a>
<br>
🕑**걸린 시간** : 2시간 이상

  #### 문제 분석
  이 문제는 사용자가 **신규 아이디**를 만들 때 **조건에 맞지 않는 아이디**를 작성한다면 조건에 맞으면서 작성한 아이디와 **가장 유사한 아이디**를 **추천**하는 알고리즘을 만드는 것이다.<br>
 
 `ex) "...!@BaT#*..y.abcdefghijklm" -> bat.y.abcdefghi`
  
  #### 알고리즘 설계
  이 문제는 총 7가지의 조건이 있다.<br>
  
  ```
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
  ```
<br>
이러한 조건에 나는 다음과 같은 방식으로 알고리즘을 풀었다.

1. 문자열 안에 있는 **모든 문자를 탐색**한다.
2. 문자 탐색 중 **필요한 연산**이 있으면** 즉각 처리** 했다. `ex) 대문자 -> 소문자, ".." -> "."`
3. 모든 탐색이 **끝**난 후 **조건문**으로 나머지 조건들을 **작성**했다.

이렇게 작성하니 이런 [코드](https://github.com/strawy12/Algorithm/blob/main/Programmers/%EC%8B%A0%EA%B7%9C%20%EC%95%84%EC%9D%B4%EB%94%94%20%EC%B6%94%EC%B2%9C.cpp)가 완성되었다.<br>
> 보여주고 싶지 않은 코드니 보시고싶다면 링크를 타고 봐주시길 바랍니다.

이 코드의 **문제점**은 조건 별로 함수나 위치를 나누지 않고 **뒤죽박죽으로 작성**했다보니 **가독성**이 매우 **떨어진다**. 또한 **조건 유효성 검사**도 **위치**가 **제각각**이라 추후 **유지 보수에 큰 어려움**을 느낄것으로 보인다.
  
  #### 개선된 코드
  ※ 여기서 개선된 코드는 내가 혼자 생각한것이 아닌 다른 분이 푸신 것을 참고하여 작성했습니다.<br>
  [해당 코드 바로가기](https://github.com/strawy12/Algorithm/blob/964c57905bcb20772b1a824dc1cc730578728fdb/Programmers/%EC%8B%A0%EA%B7%9C%20%EC%95%84%EC%9D%B4%EB%94%94%20%EC%B6%94%EC%B2%9C.cpp#L81)
  
  가장 먼저 **개선**해야겠다고 생각되었던 부분은 **가독성 부분**이다.<br>
  그래서 **조건**을 **차례대로** 차근차근 풀어보기로 했다.<br>
  
  1. **모든 대문자를 대응되는 소문자로 치환** <br>
  이 부분은 **transform** 이라는 함수를 활용하여 쉽게 풀었다
  ```cpp
  transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);
  ```
  <br><br>
  
  2. **특정 문자들을 제외한 모든 문자를 제거** <br>
  이 부분은 **for문**으로 문자열을 차례대로 **순회**하면서 **if문**으로 조건을 걸어줬다.
  
  ```cpp
for (char& c : new_id)
{
	if (('a' <= c && c <= 'z') || // a - z 인지 체크
    	('0' <= c && c <= '9') || // 0 - 9 인지 체크
    	(strchr("-_.", c)))       // -, _, . 인지 체크
  	 {
		temp += c; // 해당 글자가 맞다면 값을 넣어주고 아니면 넣지 않아서 필터링 해준다
  	 }
}
```
<br><br>

 3. **마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환** <br>
  이 부분은 **for문**으로 문자열을 순회를 하며 <br>
  **temp 변수에 한 문자씩 += 연산을 하다가 temp의 마지막 글자가 마침표(.)이고 현재 넣을 글자가 마침표(.)라면 넣지 않게** 설계를 했다.
  
  ```cpp
for (char& c : new_id) 
{
	// 비어있지 않은 상태에서 바로 전의 값이 . 인데 현재값도 . 이면 예외처리
	if (!temp.empty() && temp.back() == '.' && c == '.') continue;
	temp += c;
}
```
<br><br>

4. **마침표(.)가 처음이나 끝에 위치한다면 제거합니다.**
이는 간단한 조건식으로 해결했다.

```cpp
if (temp.front() == '.') temp.erase(temp.begin());
if (temp.back() == '.') temp.erase(temp.end() - 1);
```
<br><br>

5. **빈 문자열이라면, new_id에 "a"를 대입합니다.**  <br>
이는 **empty라는** 함수를 활용해서 해결했다. 

```cpp
if (temp.empty()) temp = "a";
```
<br><br>

6. **길이가 16자 이상이면 15자 이상의 문자들은 삭제합니다.**  <br>
> 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다. <br>
이는 **substr이라는** 함수를 활용해서 해결했다.

```cpp
if (temp.size() >= 16) temp = temp.substr(0, 15);
if (temp.back() == '.') temp.erase(temp.end() - 1);
```
<br><br>


7. **글자수가 3 이하면 맨 끝 문자 반복**  <br>
이는 **while문을** 활용해서 해결했습니다.

```cpp
while (temp.size() < 3)
{
	temp += temp.back();
}
```
<br><br>

##### 새롭게 알게된 점, 느낀점
새로 알게 된 점: transform(), tolower(), toupper(), substr(), strchr() 에 대한 함수를 알았다.
느낀점: 코드를 짤 때 무작정 짜지말고 가독성 좋게 짜보도록 노력하는게 좋을거같다. 그리고 아직 내가 모르는 함수가 많이 존재하는 거 같다.
<br><br>
  
### ❗신고 결과 받기
[돌아가기](https://github.com/strawy12/Algorithm/blob/main/Programmers/README.md#progammers)
 <br> <br> 
 
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/92334">문제 보기</a><br>
<a href="https://github.com/strawy12/Algorithm/blob/main/Programmers/%EC%8B%A0%EA%B3%A0%EA%B2%B0%EA%B3%BC%EB%B0%9B%EA%B8%B0.cpp">코드 보기</a>
<br>
🕑**걸린 시간** : 3시간 이상
