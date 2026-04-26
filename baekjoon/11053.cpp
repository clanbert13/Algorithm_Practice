// /*
// 가장 긴 증가하는 부분 수열 성공
 
// 시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
// 1 초	256 MB	214063	88535	58677	39.133%
// 문제
// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

// 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

// 입력
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

// 출력
// 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

// 예제 입력 1 
// 6
// 10 20 10 30 20 50
// 예제 출력 1 
// 4
// */
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

//     // ���� ���: �̹� ����� ���� �ִٸ� ���� �ٷ� ��ȯ
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

//   // cache �ʱ�ȭ
//   memset(cache, -1, sizeof(cache));

//   int maxLen = 0;
//   for (int i = 0; i < N; i++) 
//     maxLen = max(maxLen, LIS(i));
  
//   cout << maxLen;
//   return 0;
// }