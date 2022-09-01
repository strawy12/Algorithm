<div align="center">

  # Progammers

</div> <br><br>

## 바로 가기
[🔠🔢 숫자 문자열과 영단어](https://github.com/strawy12/Algorithm/blob/main/Programmers/README.md#-%EC%88%AB%EC%9E%90-%EB%AC%B8%EC%9E%90%EC%97%B4%EA%B3%BC-%EC%98%81%EB%8B%A8%EC%96%B4)

<br><br>

## 알고리즘 노트
### 🔠🔢 숫자 문자열과 영단어<br>
<a href="https://school.programmers.co.kr/learn/courses/30/lessons/81301">문제 보기</a><br>
<a href="https://github.com/strawy12/Algorithm/blob/main/Programmers/%EC%88%AB%EC%9E%90%20%EB%AC%B8%EC%9E%90%EC%97%B4%EA%B3%BC%20%EC%98%81%EB%8B%A8%EC%96%B4.cpp">코드 보기</a>
<br>
🕑걸린 시간 : 1시간 이상

  #### 문제 분석
  이 문제는 문자열 안에 있는 숫자 영단어를 실제 숫자로 변환해줘야하는 문제이다.
  <br>
  ex) "one23four" -> 1234, "zero82eight" -> 0828
  
  
  #### 알고리즘 설계
  우선 나는 처음으론 문자열을 전부 검색하여 숫자가 아닌 부분은 어떤 영단어인지 확인하여 변환해주는 if문 위주로 푸는 방식을 택했고 
  변환한 값이 자릿수까지 맞춰질 수 있게 위치에 따라 10ⁿ을 곱하여 정수형으로 변환해주었다.
  그렇게 나온 코드는 처참했다.<br><br>
   <img src="https://user-images.githubusercontent.com/77821550/187939585-f4504265-8490-4f09-93e2-592315de3b76.png"  width="400" height="250"/>

  약 100줄이 되는 코드가 나오게 되었다. <br><br>
  
  #### 개선한 코드
  위와같은 코드를 작성한 이후 다른 방법을 여러가지 고민해보고 참고해보고 검색해본 결과 이러한 코드가 나오게 됐다<br><br>
   <img src="https://user-images.githubusercontent.com/77821550/187940139-d780f8c5-1e88-466e-9ac6-ef8b04464adf.png"  width="400" height="280"/>

 이 알고리즘은 위와 비슷한 구조로 되어있지만 좀 더 간단히 되어있다.
 <br>
 
 우선 첫번째로 가장 크게 달라진 점은 변환시킬 영단어를 미리 배열에 선언 해 놓는 방식이다.
 이렇게 된다면 0번째 index에는 "zero"가 들어가고 9번째 index에는 "nine"이 들어 가 있어 영단어를 변환하는 데 있어 좀 더 간편해졌다.<br><br>
 ![image](https://user-images.githubusercontent.com/77821550/187941201-30bc0213-8b4e-4ade-a0b5-5ec8e8a86098.png)<br><br>

 두번째로는 찾는 방식을 반복문으로 간편하게 변경했다.
 이 부분을 보시면 <br><br>
 ![image](https://user-images.githubusercontent.com/77821550/187942164-0f5724bf-37a4-4b97-b9de-def5a58b0610.png)
<br><br>
string 맴버함수인 find()를 활용했다.
이 함수는 문자열.find("찾고자하는 문자열") 이렇게 사용하게 된다면 찾고자하는 값이 문자열 안에 있다면 그 위치(index)를 반환하는 함수이다.
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
 
 
