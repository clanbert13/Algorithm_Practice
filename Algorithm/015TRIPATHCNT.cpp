// /*
// 254p 삼각형 위의 최대 경로 개수 세기

// 문제

// 9
// 5 7
// 1 3 2
// 3 5 5 6
// 위 형태와 같이 삼각형 모양으로 배치된 자연수들이 있습니다. 
// 맨 위의 숫자에서 시작해, 한 번에 한 칸씩 아래로 내려가 맨 아래 줄로 내려가는 경로를 만들려고 합니다. 
// 경로는 아래 줄로 내려갈 때마다 바로 아래 숫자, 혹은 오른쪽 아래 숫자로 내려갈 수 있습니다.

// 이 때 숫자의 합이 가장 큰 경로는 하나가 아니라 여러 개일 수 있습니다. 
// 예를 들어 위 삼각형에서는 {9, 7, 2, 6}과 {9, 7, 3, 5}의 합이 모두 최대인 24이고, {9, 7, 3, 5}는 두 번 등장하거든요.

// 삼각형이 주어질 때 최대 경로의 수를 세는 프로그램을 작성하세요.

// 입력

// 입력의 첫 줄에는 테스트 케이스의 수 C(C <= 50)가 주어집니다. 각 테스트 케이스의 첫 줄에는 삼각형의 크기 n(2 <= n <= 100)이 주어지고, 그 후 n줄에는 각 1개~n개의 숫자로 삼각형 각 가로줄에 있는 숫자가 왼쪽부터 주어집니다. 각 숫자는 1 이상 100000 이하의 자연수입니다.

// 출력

// 각 테스트 케이스마다 한 줄에 최대 경로의 수를 출력합니다.
// 경로의 수는 230 이하라고 가정해도 좋습니다.

// 예제 입력
// 2
// 4
// 1
// 1 1 
// 1 1 1 
// 1 1 1 1 
// 4
// 9
// 5 7
// 1 3 2
// 3 5 5 6

// 예제 출력
// 8
// 3

// */


// #include <iostream>
// #include <vector>
// #include <cstring>

// #define MAX_NUMBER 100000

// using namespace std;

// int C, n, triangle[100][100];
// int cache[100][100];
// int countCache[100][100];

// int path2(int y, int x) {
//   // 기저 사례: 삼각형의 맨 아래에 도달한 경우
//   if (y == n - 1)
//     return triangle[y][x];

//   // 메모이제이션
//   int& ret = cache[y][x];
//   if (ret != -1)
//     return ret;

//     // 왼쪽 아래 경로의 최대 합
//     int leftSum = path2(y + 1, x);
//     // 오른쪽 아래 경로의 최대 합
//     int rightSum = path2(y + 1, x + 1);

//     // 더 큰 값을 선택하고, 어느 쪽을 선택했는지 기록(next_step)
//     if (leftSum >= rightSum) 
//       ret = triangle[y][x] + leftSum;
//     else 
//       ret = triangle[y][x] + rightSum;
    
//     return ret;
// }

// int countPath(int y, int x) {
//   // 기저 사례: 삼각형의 맨 아래에 도달한 경우
//   if (y == n - 1) return 1;

//   //메모이제이션
//   int& ret = countCache[y][x];
//   if (ret != -1) return ret;

//   ret = 0;
  
//   int leftSum = path2(y + 1, x);  // 왼쪽 길의 개수
//   int rightSum = path2(y + 1, x + 1); // 오른쪽 길의 개수

//   if (leftSum >= rightSum) ret += countPath(y + 1, x);  // 왼쪽 길의 개수를 더함
//   if (rightSum >= leftSum) ret += countPath(y + 1, x + 1);  // 오른쪽 길의 개수를 더함

//   return ret;
// }

// int main(){
//   cin >> C;

//   for(int c = 0; c < C; c++) {
//     cin >> n;

//     for(int i = 0; i < n; i++) 
//       for(int j = 0; j <= i; j++) 
//         cin >> triangle[i][j];

//     memset(cache, -1, sizeof(cache));
//     memset(countCache, -1, sizeof(cache));

//     cout << countPath(0, 0) << '\n';
//   }

//   return 0;
// } 