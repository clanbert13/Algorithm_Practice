/*
239p 8.7 원주율 외우기

문제

(주의: 이 문제는 TopCoder 의 번역 문제입니다.)

가끔 TV 에 보면 원주율을 몇만 자리까지 줄줄 외우는 신동들이 등장하곤 합니다. 
이들이 이 수를 외우기 위해 사용하는 방법 중 하나로, 숫자를 몇 자리 이상 끊어 외우는 것이 있습니다. 
이들은 숫자를 세 자리에서 다섯 자리까지로 끊어서 외우는데, 가능하면 55555 나 123 같이 외우기 쉬운 조각들이 많이 등장하는 방법을 택하곤 합니다.

이 때, 각 조각들의 난이도는 다음과 같이 정해집니다:

모든 숫자가 같을 때 (예: 333, 5555) 난이도: 1
숫자가 1씩 단조 증가하거나 단조 감소할 때 (예: 23456, 3210) 난이도: 2
두 개의 숫자가 번갈아 가며 출현할 때 (예: 323, 54545) 난이도: 4
숫자가 등차 수열을 이룰 때 (예: 147, 8642) 난이도: 5
그 외의 경우 난이도: 10
원주율의 일부가 입력으로 주어질 때, 난이도의 합을 최소화하도록 숫자들을 3자리에서 5자리까지 끊어 읽고 싶습니다. 최소의 난이도를 계산하는 프로그램을 작성하세요.

입력

입력의 첫 줄에는 테스트 케이스의 수 C (<= 50) 가 주어집니다. 각 테스트 케이스는 8글자 이상 10000글자 이하의 숫자로 주어집니다.

출력

각 테스트 케이스마다 한 줄에 최소의 난이도를 출력합니다.

예제 입력
5 
12341234 
11111222 
12122222 
22222222 
12673939 
예제 출력
4
2
5
2
14
*/

/*
자를 수 있는 숫자는 3 ~ 5 자리
=> 앞에서 4자리 뒤에서 3자리를 잘라서 7자리수 부터 연산 시작 하는 경우 = 앞 3자리, 뒤 4자리로 7자리부터 연산 시작
=> 메모이제이션 적용 가능

점화식
CalcDifficulty(시작) = min(classify(3 | 4 | 5) + CalcDifficulty(시작 + 3 | 4 | 5))
classify : 난이도 측정 함수
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> s;
int cache[100002];

// const int INF = numeric_limits<int>::max();    // 썼다가 오버플로 났다..    classify(index, i) + CalcDifficulty(index + i) 이 문제를 일으킬 수 있음!
const int INF = 987654321;

int classify(int index, int check){
// 공차
  int diff = s[index + 1] - s[index];

  // 등차수열인지 확인
  bool isAP = true; 
  for (int i = 0; i < check - 1; ++i) 
    if (s[index + i + 1] - s[index + i] != diff) {
      isAP = false;
      break;
    }
  

  if (isAP) { // 등차 수열인가?
    if (diff == 0) return 1;        // 등차가 0 (모두 같은 수)  
    if (abs(diff) == 1) return 2;   // 1씩 증가 & 감소
    return 5;                       // 그외
  }

  // 번갈아 가며 나오는가?
  bool isAlt = true;
  for (int i = 0; i < check - 2; ++i) 
    if (s[index + i] != s[index + i + 2]) {
      isAlt = false;
      break;
    }
  
  if (isAlt) return 4;

  // 해당 없음
  return 10;
}

int CalcDifficulty(int index){
  if (index == s.size()) return 0;    // 수열 탐색 완료 

  int& result = cache[index];
  if(result != -1) return result; // 이미 계산된 결과

  result = INF;

  // 수열을 3 ~ 5까지 나눠서 최소 난이도를 구한다.
  for(int i = 3; i <= 5; i++)
    if(index + i <= s.size()) result = min(result, classify(index, i) + CalcDifficulty(index + i));
  
  return result;
}

int main(){
  vector<int> f_result;
  int C;

  cin >> C;

  for(int i = 0; i < C; i++){
    string input;
    
    cin >> input;
    
    for(char c : input) s.push_back(c - '0');

    // 캐시 초기화
    memset(cache, -1, sizeof(cache));

    f_result.push_back(CalcDifficulty(0));

    s.clear();  // 입력된 수열 초기화
  }

  for(int i : f_result)
    cout << i << '\n';
  
  return 0;
}
