// /*
// 218p 8.2 문제: 와일드 카드

// 문제: 와일드카드 패턴은 일반적인 파일명과 비슷하지만 특수문자 *와 ?를 포함할 수 있는 문자열이다.
// 패턴을 앞에서 한 글자씩 파일명과 비교해서 모든 글자가 일치했을 때 해당 와일드 카드 패턴이 파일명과 대응된다고 말한다.
// 단 와일드카드 패턴에 포함된 ?는 어떤 글자와도 대응된다고 가정하며, *는 0 글자 이상의 어떤 문자열에도 대응된다고 가정한다.
// 예를 들어 와일드 카드 he?p는 파일명 help와 heap에 대응되지만 helpp에는 대응되지 않는다.
// 또한 와일드 카드 *p*는 파일명 help, papa에도 대응되지만 hello에는 대응되지 않는다.

// 패턴과 함께 파일명의 집합이 주어질 때, 그중 패턴에 대응되는 파일명을 찾아내는 프로그램을 작성해라.

// 시간 및 메모리 제약: 2초, 64MB

// 입력
// 첫줄에는 테스트 케이스의 수 C()1 <= C <= 10)이 주어진다.
// 각 테스트 케이스의 첫 줄에는 와일드카드 패턴 W가 주어진다.
// 그 다음 줄에 파일명의 수 n(1 <= n <= 50)이 주어지고, 그 후 n줄에 하나씩 각 파일명이 주어진다.
// 와일드카드 패턴은 알파벳 대소문자, 숫자와 *?만으로 구성되며, 파일명은 알파벳 대소문자와 숫자만으로 이루어진다.
// 모든 문자열의 길이는 1이상 100이하이며, 공백을 포함하지 않는다.

// 출력
// 각 테스트 케이스마다 주어진 패턴에 대응되는 파일들의 이름을 한 줄에 하나씩 알파벳 순서대로 출력합니다.

// 예제 입력:
// 3
// he?p
// 3
// help
// heap
// helpp
// *p*
// 3
// help
// papa
// hello
// *bb*
// 1
// babbbc

// 예제 출력:
// heap
// help
// help
// papa
// babbbc
// */
// // // ===================== 재귀호출만 사용한 풀이 (비효율적) ====================
// // #include <iostream>
// // #include <string>
// // #include <vector>
// // #include <algorithm>

// // using namespace std;

// // int C;
// // string W;

// // bool WildCardMatch_Exhaustive(const string& w, const string& f){
// //   int pos = 0;
// //   while (pos < w.size() && pos < f.size() && (w[pos] == '?' || w[pos] == f[pos]))
// //     pos++;
  
// //   if (pos == w.size())
// //     return pos == f.size();
  
// //   if (w[pos] == '*')
// //     for (int skip = 0; pos + skip <= f.size(); skip++)
// //       if (WildCardMatch_Exhaustive(w.substr(pos + 1), f.substr(pos + skip)))
// //         return true;
      
// //   return false;
// // }

// // int main(){
// //   cin >> C;

// //   vector<vector<string>> all_results; 

// //   for(int i = 0; i < C; i++){
// //     cin >> W;
// //     int n;
// //     cin >> n;
    
// //     vector<string> matched_files; 
// //     string filename;

// //     for(int j = 0; j < n; j++){
// //       cin >> filename;
// //       if(WildCardMatch_Exhaustive(W, filename))
// //         matched_files.push_back(filename); 
// //     }
    
// //     sort(matched_files.begin(), matched_files.end());
// //     all_results.push_back(matched_files);
// //   }

// //   cout << endl;

// //   for(int i = 0; i < all_results.size(); i++) 
// //       for(const string& file : all_results[i]) 
// //           cout << file << endl;
      
// //   return 0;
// // }


// /*
// *는 "0글자 이상"을 의미
// 패턴이 **a이고 문자열이 ba일때
// 1. 첫 번째 *가 b를 먹었을 때 -> 남은 패턴 **a, 남은 문자열 a
// 2. 첫 번째 *가 아무것도 안 먹었을 때 -> 두 번째 *가 b를 먹음 -> 남은 패턴 *a, 남은 문자열

// 이 과정에서 **"남은 패턴이 *a이고 남은 문자열이 a인 상황"**이 아주 여러 경로를 통해 중복되어 나타난다.

// 이에 따라 메모이제이션을 사용하여 이미 계산된 부분 문제의 결과를 저장하고 재사용하는 방법을 적용할 수 있다.
// */

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring>

// using namespace std;

// int C;
// // (-1: 미방문, 0: 불가능, 1: 가능)
// int cache[101][101]; 
// string W, S;

// bool WildCardMatch(int w, int f) {
//   // 메모이제이션 확인: 이미 답을 구한 적이 있는가?
//   if (cache[w][f] != -1) 
//     return cache[w][f];
  

//   // 비교 로직 (인덱스 사용)
//   int pos = 0;
//   while (w < W.size() && f < S.size() && (W[w] == '?' || W[w] == S[f])) {
//     w++;
//     f++;
//   }

//   // 패턴 끝에 도달했을 때 (더 이상 *가 없음)
//   if (w == W.size()) 
//     return cache[w][f] = (f == S.size()); 
  

//   // *를 만났을 때
//   if (W[w] == '*') 
//     for (int skip = 0; f + skip <= S.size(); skip++) 
//       if (WildCardMatch(w + 1, f + skip)) return cache[w][f] = 1; 

//   return cache[w][f] = 0;
// }

// int main() {
// vector<vector<string>> all_results;

// cin >> C;


// while (C--) {
//   cin >> W;
//   int n;
//   cin >> n;
//   vector<string> matched; 

//   for (int i = 0; i < n; i++) {
//     cin >> S;
    
//     memset(cache, -1, sizeof(cache)); // 캐시 초기화
//     if (WildCardMatch(0, 0)) 
//       matched.push_back(S);
//   }
    
//   sort(matched.begin(), matched.end());
//   all_results.push_back(matched);
// }

// cout << endl;
// for(int i = 0; i < all_results.size(); i++) 
//   for(const string& file : all_results[i]) 
//     cout << file << endl;

// return 0;
// }