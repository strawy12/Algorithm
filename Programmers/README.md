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

 이 알고리즘은 위와 **비슷한 구조**로 되어있지만 좀 더 **간단히** 되어있다.
 <br>
 
 우선 첫번째로 가장 크게 달라진 점은 변환시킬 **영단어를 미리 배열에 선언** 해 놓는 방식이다.<br>
 이렇게 된다면 **0번째 index에는 "zero"**가 들어가고 **9번째 index에는 "nine"**이 들어 가 있어 영단어를 변환하는 데 있어 좀 더 간편해졌다.<br><br>
 ![image](https://user-images.githubusercontent.com/77821550/187941201-30bc0213-8b4e-4ade-a0b5-5ec8e8a86098.png)<br><br>

 두번째로는 찾는 방식을 **siwtch**에서 string 맴버함수인 **find()**를 활용하여 더욱 간편하게 변경했다.<br>
```
    size_t nPos = s.find(nums[i]);

		if (nPos != string::npos)
		{
			s = s.replace(nPos, nums[i].length(), to_string(i));
			i--;
		}
```
<br>
이 **find()** 함수는 `문자열.find("찾고자하는 문자열");` <br>
이렇게 사용하게 된다면 찾고자하는 값이 문자열 안에 있다면 그 위치(index)를 반환하는 함수이다.
그리고 만약 문자열에 없다면 string::npos 의 값을 반환한다고 한다.

그래서 배열 안에 있는 값 하나하나 순회하면서 그 값이 문자열 안에 있는지 체크하고 있다.
<br><br>

마지막으로는 이 방식을 통해 값을 변환해줬다.<br><br>
![image](https://user-images.githubusercontent.com/77821550/187948771-630fcc9e-7ba5-438a-99e8-ddcbe9af5e6f.png)<br><br>
간단하게 소개하자면 
string의 맴버함수인 replace는 문자열.replace(시작위치, 길이, 변경할 값) 이렇게 사용하면 시작위치에서부터 길이만큼의 값이 변경할 값으로 대체 된다.
그래서 문자열에 영단어가 감지 된 경우는 그 감지된 위치를 알 수 있으니 그 정보를 활용하여 변환시켰다.
그리고 i--는 중복 검색이 불가능 하여 다시 한번 똑같은 단어를 검색해보게 작성한 부분이다.
<br><br>

#### 새롭게 알게된 점, 느낀점
string의 다양한 함수들을 활용하니 100줄짜리 코드도 20줄 코드로 변경할 수 있다는 점이 너무 좋았고<br>
string.replace(), string.find(), string::npos 에 대해 자세히 알게 되었다
 
 
 ### 🔓신규 아이디 추천 
 [돌아가기](https://github.com/strawy12/Algorithm/blob/main/Programmers/README.md#progammers)
 <br> <br> 
 
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/72410">문제 보기</a><br>
<a href="https://github.com/strawy12/Algorithm/blob/main/Programmers/%EC%8B%A0%EA%B7%9C%20%EC%95%84%EC%9D%B4%EB%94%94%20%EC%B6%94%EC%B2%9C.cpp">코드 보기</a>
<br>
🕑걸린 시간 : 2시간 이상

  #### 문제 분석
  이 문제는 사용자가 신규 아이디를 만들 때 조건에 맞지 않는 아이디를 작성한다면 조건에 맞으면서 작성한 아이디와 가장 유사한 아이디를 추천하는 알고리즘을 만드는 것이다.<br>
 
  ex) "...!@BaT#*..y.abcdefghijklm" -> bat.y.abcdefghi
  
  #### 알고리즘 설계
  이 문제는 총 7가지의 조건이 있는데 그 중 특정 글자를 제외한 모든 글자는 제외를 하니 변환할 문자열을 한 글자씩 순차적으로 탐색을 하고 temp변수를 하나 만들어 특정 글자면 += 연산을 해주고 아니라면 더하는 연산을 하지 않는 방식의 구조를 짠 다음 특정 글자의 조건이 있는 경우를 if문으로 하나하나 작성해 완성한다. <br>
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

  
