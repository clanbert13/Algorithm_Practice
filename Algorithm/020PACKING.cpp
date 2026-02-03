// /*
// 281p 9.2 여행 짐 싸기 

// 문제

// 여행을 떠나기 전날까지 절대 짐을 싸지 않는 버릇이 있는 재훈이는 오늘도 비행기 타기 전날에야 가방을 싸기 위해 자리에 앉았습니다. 
// 비행기 규정상 재훈이는 캐리어를 하나만 가지고 갈 수 있는데, 아무래도 가져가고 싶은 물건들이 캐리어 안에 다 들어가지 않을 것 같습니다. 
// 재훈이는 가져가고 싶은 각 물건들의 부피와 얼마나 필요한지를 나타내는 절박도를 조사해 다음과 같은 목록을 만들었습니다.

// 물건	노트북 컴퓨터	카메라	XBOX365	커피그라인더	아령	백과사전
// 부피	4	2	6	4	2	10
// 절박도	7	10	6	7	5	4
// 캐리어의 용량이 정해져 있기 때문에 가져갈 수 있는 물건들의 부피 합은 캐리어의 용량 w 이하여야 합니다. 
// 이때 절박도를 최대화할 수 있는 물건들의 목록을 계산하는 프로그램을 작성하세요.

// 입력

// 입력의 첫 줄에는 테스트 케이스의 수 C (1≤C≤50)가 주어집니다.
// 각 테스트 케이스의 첫 줄에는 가져가고 싶은 물건의 수 N (1≤N≤100)과 캐리어의 용량 W (1≤W≤1000)가 주어집니다.
// 그 이후 N줄에 순서대로 각 물건의 정보가 주어집니다. 
// 한 물건에 대한 정보는 물건의 이름, 부피, 절박도 순서대로 주어지며, 
// 이름은 공백 없는 알파벳 대소문자 1글자 이상 20글자 이하의 문자열, 부피와 절박도는 1000 이하의 자연수입니다.

// 출력

// 각 테스트 케이스별 출력의 첫 줄에는 가져갈 수 있는 물건들의 최대 절박도 합과 가져갈 물건들의 개수를 출력합니다. 
// 이후 한 줄에 하나씩 각 물건들의 이름을 출력합니다. 
// 만약 절박도를 최대화하는 물건들의 조합이 여럿일 경우 아무 것이나 출력해도 좋습니다.

// 예제 입력
// 2
// 6 10
// laptop 4 7
// camera 2 10
// xbox 6 6
// grinder 4 7
// dumbell 2 5
// encyclopedia 10 4
// 6 17
// laptop 4 7
// camera 2 10
// xbox 6 6
// grinder 4 7
// dumbell 2 5
// encyclopedia 10 4
// 예제 출력
// 24 3
// laptop
// camera
// grinder
// 30 4
// laptop
// camera
// xbox
// grinder
// */

// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n;
// int volume[100], need[100];
// string name[100];
// int cache[1001][100];


// int Pack(int capacity, int item) {
//   if(item == n) return 0; // 기저사례1 : 담을 아이템이 없음

//   int& result = cache[capacity][item];
//   if(result != -1) return result;

//   // 물건을 담지 않는 경우
//   result = Pack(capacity, item + 1);

//   // 물건을 담는 경우
//   if(capacity >= volume[item]) 
//     result = max(result, Pack(capacity - volume[item], item +1) + need[item]);
  
//   return result;
// }
// void Recontruct(int capacity, int item, vector<string>& picked) {
//   if(item == n) return; // 기저사례1: 아이템 모두 선정

//   if(Pack(capacity, item) == Pack(capacity, item + 1)) Recontruct(capacity, item + 1, picked);
//   else {
//     picked.push_back(name[item]);
//     Recontruct(capacity - volume[item],item + 1, picked);
//   }
// }

// int main() {
//   int c;
//   cin >> c;

//   while(c--) {
//     int w;
//     vector<string> picked;
//     cin >> n >> w;
//     for(int i = 0; i < n; i++) 
//       cin >> name[i] >> volume[i] >> need[i];

//     memset(cache, -1, sizeof(cache));
//         Recontruct(w, 0, picked);
//     cout << Pack(w, 0) << ' ' << picked.size() << '\n';
//     for(string i : picked)
//       cout << i << '\n';
//   }

//   return 0;
// }