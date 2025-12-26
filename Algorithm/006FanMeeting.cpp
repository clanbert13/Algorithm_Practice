// /*
// 201p 7.6 문제: 팬미팅
// 멤버들은 오른쪽 멤버에서부터 시작해 한 명씩 왼쪽으로 움직이며 멤버들과 하나씩 포옹
// 모든 팬들은 동시에 한 명씩 움직인다.
// 남성 멤버는 남성 팬과 포옹하기 민망하여 포옹 대신 악수를 한다
// 멤버들과 팬들의 성별이 각각 주어질때 팬미팅이 진행되는 과정에서 모든 멤버가 동시에 포옹을 하는 일이 몇 번이나 있는지 계산하는 프로그램을 작성하시오

// 입력
// 첫째 줄에 테스트 케이스의 수 C가 주어진다. (C <= 20)
// 각 테스트 케이스는 멤버들의 성별과 팬들의 성별을 나타내는 두 줄의 문자열로 구성되어있다.
// 왼쪽부터 오른쪽 순서대로 성별(M: 남성, F: 여성)이 주어진다.
// 멤버와 팬의 수는 모두 1 이상 200,000 이하의 정수이며, 멤버의 수는 항상 팬의 수 이하이다.

// 예제 입력 : 
// 4
// FFFMMM
// MMMFFF
// FFFFF
// FFFFFFFFFF
// FFFFM
// FFFFFMMMMF
// MFMFMFFFMMMFMF
// MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF

// 예제 출력 : 
// 1
// 6
// 2
// 2
// */

// /*
// 풀이:
// 단순 모든 경우의 수 연산은 O(N^2)으로 시간 초과가 발생한다.
// 이를 위해 각 성별을 1과 0으로 치환 후 다항식 곱셈과 이를 단축시킬 카라츠바 알고리즘을 사용한다.
// 다항식 곱셈의 결과에서 1이 나오면 악수(실패)가 발생한 것이며 0이면 모두 포옹(성공)이 발생한 것으로 판단한다.
// */

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void normalize(vector<int>& v)
// {
//    v.push_back(0); //벡터의 자리수를 미리 추가한다.

//    int size = v.size();
//    for (int i = 0; i < size - 1; i++)
//    {
//        if (v[i] < 0) // 계산 결과시 음수일 경우
//        {
//            int borrow = (abs(v[i]) + 9) / 10;
//            v[i + 1] -= borrow;
//            v[i] += borrow * 10;
//        }
//        else
//        {
//            v[i + 1] += v[i] / 10;
//            v[i] %= 10;
//        }
//    }
//    //앞에 남은 0을 제거한다.
//    while (v.size() > 1 && v.back() == 0)
//        v.pop_back();
// }

// vector<int> KaratsubaMultiply(const vector<int>& a, const vector<int>& b)
// {
//    vector<int> v(a.size() + b.size() + 1, 0);  //값이 저장되는 배열
//    int al = a.size();
//    int bl = b.size();

//    for (int i = 0; i < al; i++)
//        for (int j = 0; j < bl; j++)
//            v[i + j] += a[i] * b[j];

//    normalize(v);
//    return v;
// }

// int CountHugs(string members, string fans)
// {
//   int hugCount = 0;
//   // 남성 : M -> 1, 여성 : F -> 0 치환
//   vector<int> membersInt;
//   vector<int> fansInt;

//   for(char c : members){    
//     if(c == 'M') membersInt.push_back(1);
//     else membersInt.push_back(0);
//   }

//   for(char c : fans){
//     if(c == 'M') fansInt.push_back(1);
//     else fansInt.push_back(0);
//   }

//   vector<int> result = KaratsubaMultiply(membersInt, fansInt);

//   // 결과 배열에서 0이 나오는 위치는 포옹(성공)을 의미한다.
//   for(int i = membersInt.size() - 1; i < fansInt.size(); i++)
//     if(result[i] == 0)
//       hugCount++;

//   return hugCount;
// }

// int main()
// {
//   int C;
//   vector<int> result;

//   cin >> C;
//   string members, fans;

//   for(int i = 0; i < C; i++){
//     cin >> members >> fans;
//     reverse(members.begin(), members.end());
//     result.push_back(CountHugs(members, fans));
//   }

//   for(int i = 0; i < C; i++)
//     cout << result[i] << endl;
  
//   return 0;
// }