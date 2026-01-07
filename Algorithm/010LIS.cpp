// /*
// 230p 8.10 예제: 최장 증가 부분 수열
// 정수 수열 S의 부분 수열이란 S에서 0개 이상의 숫자를 지우고 남은 수열들을 말한다.
// 예를 들어 '1 2 4'는 '1 5 2 4 7'의 부분 수열이다.
// 부분 수열에 포함된 숫자들이 순 증가(strictly increasing)하면 이 부분 수열을 증가 부분 수열이라고 부른다.
// 예를 들어 S가 '1 3 4 2 4' 라면 '1 2 4'는 S의 증가 부분 수열이지만 '1 4 4'는 증가 부분 수열이 아니다.
// 주어진 수열에서 얻을 수 있는 증가 부분 수열 중 가장 긴 것을 찾는 문제
// */

// /*
// 백준  11053 : 가장 긴 증가하는 부분 수열
// 문제
// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

// 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

// 입력
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

// 출력
// 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

// 예제 입력 
// 6
// 10 20 10 30 20 50
// 예제 출력
// 4
// */
// // #include <iostream>
// // #include <vector>
// // #include <algorithm>

// // using namespace std;

// // int LIS(vector<int> A, int N){
// //   if(A.empty()) return 0;   // 기저사례 : 빈 배열

// //   int result = 0;
// //   vector<int> B; 
// //   for(int i = 0; i < N - 1; i++){ 
// //     for(int j = i + 1; j < N; j++)
// //       if(A[i]<A[j]) B.push_back(A[j]);
// //     result = max(result, 1 + LIS(B, N));    // 재귀 과정에서 메모리 초과
// //   }
// //   return result;
// // }

// // int main(){
// //   int N;
// //   vector<int> A;
// //   int input;
// //   cin >> N;
// //   for(int i = 0; i < N; i++){
// //     cin >> input;
// //     A.push_back(input);
// //   }

// //   cout<< LIS(A, N);

// //   return 0;
// // }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cstring> 

// using namespace std;

// int N;
// vector<int> A;
// int cache[1000];

// int LIS(int start) {
//     int& ret = cache[start];

//     // 기저 사례: 이미 계산한 적이 있다면 값을 바로 반환
//     if(ret != -1) return ret;

//     ret = 1; 

//     for (int next = start + 1; next < N; ++next) 
//       if (A[start] < A[next]) 
//         ret = max(ret, 1 + LIS(next));

//     return ret;
// }

// int main() {
//   cin >> N;
//   for (int i = 0; i < N; i++) {
//     int input;
//     cin >> input;
//     A.push_back(input);
//   }

//   // cache 초기화
//   memset(cache, -1, sizeof(cache));

//   int maxLen = 0;
//   for (int i = 0; i < N; i++) 
//     maxLen = max(maxLen, LIS(i));
  
//   cout << maxLen;
//   return 0;
// }