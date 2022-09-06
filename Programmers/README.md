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
  
```
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
```
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
```
s = s.replace(nPos, nums[i].length(), to_string(i));
```
이 함수는 다음과 같이 사용할 수 있다. `문자열.replace(시작위치, 길이, 변경할 값)` <br>
설명하자면 **시작위치**에서부터 **길이만큼**의 **값**이 변경할 값으로 **대체** 된다.
<br><br>

그래서 **find**를 통해 영단어를 **찾고** 그 위치에 숫자를 **replace**를 사용해 **변경**해줬다.

#### 개선된 코드 - 2
위 방식과 **로직은 비슷**하지만 **새로운 문법**으로 푼 방법을 가져와봤다.<br>

```
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


  이렇게 작성하니 이런 [코드](https://github.com/strawy12/Algorithm/blob/main/Programmers/%EC%8B%A0%EA%B7%9C%20%EC%95%84%EC%9D%B4%EB%94%94%20%EC%B6%94%EC%B2%9C.cpp)가 완성되었다.<br>
  <img src="https://user-images.githubusercontent.com/77821550/188318266-e7027520-5f4d-4191-8667-a8dd5f064353.png"  width="450" height="450"/>
  <br>
  이 코드의 문제는 조건 별로 함수나 위치를 나누지 않고 뒤죽박죽으로 작성했다보니 가독성이 매우 떨어진다. 또한 조건 유효성 검사도 위치가 제각각이라 추후 유지 보수에 큰 어려움을 느낄것으로 보인다.
  
  #### 개선된 코드
  ※ 여기서 개선된 코드는 내가 혼자 생각한것이 아닌 다른 분이 푸신 것을 참고하여 작성했습니다.<br>
  [해당 코드 바로가기](https://github.com/strawy12/Algorithm/blob/964c57905bcb20772b1a824dc1cc730578728fdb/Programmers/%EC%8B%A0%EA%B7%9C%20%EC%95%84%EC%9D%B4%EB%94%94%20%EC%B6%94%EC%B2%9C.cpp#L81)
  
  해당코드의 스크린샷입니다.<br>
  ![image](https://user-images.githubusercontent.com/77821550/188319811-9d62dcd4-ad50-4a5d-be51-718adb529c91.png)

이 구조는 우선 for문을 위에 보단 더 많이 사용하긴 하지만 조건별로 절차적으로 변환되는 가독성 놓은 코드로 바꼈다.
이 중 가장 인상 깊은 부분은 strchr 함수인데 이 함수는 매개변수로 string, string 타입의 값이 들어가는데 앞에서부터 찾고자한 문자열, 찾을 문자열인데 <br>
예시를 든다면 만약 "123456" 이라는 문자열에 3이라는 글자가 있는지 확인해보고싶을 때 strchr("3", "123456") 을 한다면 존재하는지 확인 해볼 수 있다. <br>
<br>
이 코드의 가장 치명적인 단점은 for문을 여러번 해서 엄청 긴 글자가 들어온다면 많이 시간이 걸릴 순 있다. 그래도 가독성이 좋아 이렇게 개선을 하였다
<br><br>
##### 새롭게 알게된 점, 느낀점
우선 strchr 라는 문자열 검색 함수를 새롭게 알게되었고 tolower, toupper 로 대 > 소문자, 소 > 대문자로 변경할 수 있다는 점을 알았다<br>
마지막으로 코드를 짤 때 무작정 짜지말고 가독성 좋게 짜보도록 노력해야할거같다

  
