<div align = "center">

# Algorithm Tip

알고리즘을 공부하면서 배운 팁이나 문법들을 정리하는 README입니다.

<br><br>
</div>


## 바로가기
 [string](https://github.com/strawy12/Algorithm/edit/main/%EA%B8%B0%ED%83%80/Tip_README.md#string) 
 
 <br><br>
 ## string
이 곳은 string 클래스 관련 문법들을 모아둔 곳입니다.
 <br><br>
### Replace(int, int, string)
※ 현재 이 매개변수 타입은 제가 사용한 해당 함수의 오버로딩중 하나이며 이며 다른 오버로딩된 함수들도 존재합니다 
<br>

#### 첫 사용처
첫 사용은 [숫자 문자열과 영단어](https://github.com/strawy12/Algorithm/blob/main/Programmers/README.md#-%EC%88%AB%EC%9E%90-%EB%AC%B8%EC%9E%90%EC%97%B4%EA%B3%BC-%EC%98%81%EB%8B%A8%EC%96%B4) 에서 사용했습니다.<br><br>

![image](https://user-images.githubusercontent.com/77821550/187948771-630fcc9e-7ba5-438a-99e8-ddcbe9af5e6f.png)
<br> <br>
위 사진처럼 변경하고자 하는 문자열에 .replace(int, int, string) 를 한다면 사용이 가능한데 첫번째 매개변수부터 설명하겠습니다.
<br>
첫번째 매개변수는 내가 변경하고싶은 부분의 시작 위치(index)를 넣어야합니다.
<br>
두번째 매개변수는 시작위치부터 몇 글자만큼을 변경할건지 값을 넣어야합니다.
<br>
마지막은 최종으로 변경할 문자열을 넣으면 함수를 사용합니다.
<br><br>
예시를 보여드리겠습니다. 첨부한 사진처럼 "abcdefg" 라는 문자열이 있습니다.<br>
 <img src="https://user-images.githubusercontent.com/77821550/188314182-d075a6cd-4894-4c9b-a7c3-adbd1517576b.png"  width="600" height="150"/>
 <br> <br>
 이것을 이제 "abxyzfg" 로 변경하겠습니다. 그러기 위해서는 먼저 변경 시작점을 찾아야합니다. <br>
그림을 보면 바로 알 수 있는데 c의 값이 들어가있는 2가 시작점이 됩니다. <br>
그리고 나서는 길이를 적어야하는데 xyz 세글자이기 때문에 3이 들어가게 됩니다. <br>
마지막으로는 변경할 문자열이니 "xyz"를 넣으면 됩니다.<br><br>

이를 사진으로 표현하면 이렇게 됩니다. <br>
<img src="https://user-images.githubusercontent.com/77821550/188314615-dafb22c4-ddb6-42ee-beb2-8d349eb0d1b1.png"  width="600" height="250"/> <br> <br>
이를 코드로 표현하면 <br>

```
string str = "abcdefg";

str = str.replace(2,3,"xyz");
``` 
이렇게 됩니다.




