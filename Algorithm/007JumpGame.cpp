/*
215p 8.1 문제: 외발 뛰기

문제:
n * n 크기의 격자에 1부터 9까지의 정수를 쓴 게임판이 있습니다.
이때 게임의 목적은 게임판의 왼쪽위 칸에서 시작해서 게임판의 맨 오른쪽 아래칸에 도착하는 것입니다.
이때 각 칸에 적혀 있는 수만큼 아래쪽이나 오른쪽으로 이동할 수 있으며, 중간에 게임판 밖으로 벗어나면 안됩니다.
문제는 게임판이 주어졌을 때 시작점에서 끝점으로 도달하는 방법이 존재하는지 확인하는 것입니다.

예제 입력:

예제 입력:
7

2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 2
3 3 1 2 3 4 1
1 5 2 9 4 7 0

2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 2
3 3 1 2 3 4 1
1 5 2 9 4 7 0

1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1
1 1 1 1 1 1 1c
1 1 1 1 1 1 1
1 1 1 1 1 1 2
1 1 1 1 1 2 0


예제 출력:
1

0

0

*/

#include <iostream>
#include <cstring>

int n, board[100][100];

// 재귀호출만 사용한 풀이 (비효율적)
bool jump(int y, int x){
  // 기저 사례: 게임판 밖
  if(y >= n || x >= n) return false;
  // 기저 사례: 도착점
  if(y == n - 1 && x == n - 1) return true;
  int jumpSize = board[y][x];
  return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

// 메모이제이션을 사용한 풀이
int cache[100][100]; // 메모이제이션을 위한 캐시 (-1: 미방문, 0: 불가능, 1: 가능)
// 반환형을 bool에서 int로 변경 (캐시 활용을 위해)
int jump2(int y, int x) {
    // 기저 사례: 게임판 밖
    if (y >= n || x >= n) return 0;

    // 기저 사례: 도착점
    if (y == n - 1 && x == n - 1) return 1;

    // 메모이제이션: 이미 계산한 적이 있다면 캐시값 반환
    int& ret = cache[y][x];
    if (ret != -1) return ret;

    int jumpSize = board[y][x];
    
    // 점프 크기가 0이면 더 이상 진행 불가 (무한 루프 방지)
    // 문제 조건이 1~9라면 필요 없지만, 안전장치로 추가
    if (jumpSize == 0) return ret = 0; 

    // 재귀 호출 및 결과 저장
    // 아래로 가거나(OR) 오른쪽으로 가서 하나라도 성공하면 1
    return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));
}


int main()
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      std::cin >> board[i][j];
  
  //std::cout << jump(0, 0) << "\n";

  // 캐시 초기화 (-1로 채움)
  memset(cache, -1, sizeof(cache));
  std::cout << jump2(0, 0) << "\n";

  return 0;
}