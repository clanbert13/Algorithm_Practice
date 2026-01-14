// /*
// 쿼드 뒤집기
// 그림의 모든 픽셀이 검은&흰 색일경우 이 그림의 압축결과는 b&w가 된다.
// 모든 픽셀이 같은 색이 아니라면 그림을 가로 세로 2등분하여 압축한다. 압축 결과는 x(왼쪽 위 부분의 압축 결과)(오른쪽 위 부분의 압축 결과)

// 입력
// 첫줄에 테스트 케이스 C<=50이 주어집니다. 그후 C줄에 하나씩 쿼드 트리로 압축한 그림이 주어집니다.
// 모든 문자열의 길이는 1,000 이하이며 원본 그림의 크기는 2^20 * 2^20 을 넘지 않습니다.

// 출력
// 각 테스트 케이스당 한 줄에 주어진 그림을 상하로 뒤집은 결과를 쿼드 트리 압축해서 출력합니다.

// 예제 입력
// 4
// w
// xbwwb
// xbwxwbbwb
// xxwwwbxwxwbbbwwxxxwwbbbwwwwbb
// 예제 출력
// w
// xwbbw
// xxbwwbbbw
// xxwbxwwxbbwwbwbxwbwwxwwwxbbwb
// */
// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// string img; 
// int iter_pos; 

// string Reverse()
// {
//   iter_pos++; 
//   char head = img[iter_pos]; 

//   if (head != 'x') return string(1, head);

//   string upL = Reverse();
//   string upR = Reverse();
//   string dwL = Reverse();
//   string dwR = Reverse();

//   return string("x" + dwL + dwR + upL + upR);
// }

// int main(void)
// {
//   int C;
//   cin >> C;

//   for (int i = 0; i < C; i++) {
//     cin >> img;

//     iter_pos = -1; 
//     cout << Reverse() << '\n';
//   }

//   return 0;
// }