// /*
// 215p 8.1 문제: 외발 뛰기

// 문제:
// n * n 크기의 격자에 1부터 9까지의 정수를 쓴 게임판이 있습니다.
// 이때 게임의 목적은 게임판의 왼쪽위 칸에서 시작해서 게임판의 맨 오른쪽 아래칸에 도착하는 것입니다.
// 이때 각 칸에 적혀 있는 수만큼 아래쪽이나 오른쪽으로 이동할 수 있으며, 중간에 게임판 밖으로 벗어나면 안됩니다.
// 문제는 게임판이 주어졌을 때 시작점에서 끝점으로 도달하는 방법이 존재하는지 확인하는 것입니다.

// 예제 입력:

// 예제 입력:
// 7

// 2 5 1 6 1 4 1
// 6 1 1 2 2 9 3
// 7 2 3 2 1 3 1
// 1 1 3 1 7 1 2
// 4 1 2 3 4 1 2
// 3 3 1 2 3 4 1
// 1 5 2 9 4 7 0

// 2 5 1 6 1 4 1
// 6 1 1 2 2 9 3
// 7 2 3 2 1 3 1
// 1 1 3 1 7 1 2
// 4 1 2 3 4 1 2
// 3 3 1 2 3 4 1
// 1 5 2 9 4 7 0

// 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1
// 1 1 1 1 1 1 1c
// 1 1 1 1 1 1 1
// 1 1 1 1 1 1 2
// 1 1 1 1 1 2 0


// 예제 출력:
// 1

// 0

// 0

// */


// // // 재귀호출만 사용한 풀이 (비효율적)
// // bool jump(int y, int x){
// //   // 기저 사례: 게임판 밖
// //   if(y >= n || x >= n) return false;
// //   // 기저 사례: 도착점
// //   if(y == n - 1 && x == n - 1) return true;
// //   int jumpSize = board[y][x];
// //   return jump(y + jumpSize, x) || jump(y, x + jumpSize);
// // }
// #include <iostream>
// #include <cstring>

// using namespace std;

// int n, board[100][100];
// int cache[100][100]; 

// int jump2(int y, int x) {
//   if (y >= n || x >= n) return 0;
//   if (y == n - 1 && x == n - 1) return 1;

//   int& ret = cache[y][x];
//   if (ret != -1) return ret;

//   int jumpSize = board[y][x];
//   if (jumpSize == 0) return ret = 0; 

//   return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
// }

// int main()
// {
//   int C;
//   cin >> C;

//   while(C--) {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//       for (int j = 0; j < n; j++)
//         cin >> board[i][j];

//     memset(cache, -1, sizeof(cache));
    
//     if (jump2(0, 0) == 1) 
//       cout << "YES" << "\n";
//     else 
//       cout << "NO" << "\n";
// }

//   return 0;
// }