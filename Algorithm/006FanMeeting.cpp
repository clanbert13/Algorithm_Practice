// // /*
// // 201p 7.6 문제: 팬미팅
// // 멤버들은 오른쪽 멤버에서부터 시작해 한 명씩 왼쪽으로 움직이며 멤버들과 하나씩 포옹
// // 모든 팬들은 동시에 한 명씩 움직인다.
// // 남성 멤버는 남성 팬과 포옹하기 민망하여 포옹 대신 악수를 한다
// // 멤버들과 팬들의 성별이 각각 주어질때 팬미팅이 진행되는 과정에서 모든 멤버가 동시에 포옹을 하는 일이 몇 번이나 있는지 계산하는 프로그램을 작성하시오

// // 입력
// // 첫째 줄에 테스트 케이스의 수 C가 주어진다. (C <= 20)
// // 각 테스트 케이스는 멤버들의 성별과 팬들의 성별을 나타내는 두 줄의 문자열로 구성되어있다.
// // 왼쪽부터 오른쪽 순서대로 성별(M: 남성, F: 여성)이 주어진다.
// // 멤버와 팬의 수는 모두 1 이상 200,000 이하의 정수이며, 멤버의 수는 항상 팬의 수 이하이다.

// // 예제 입력 : 
// // 4
// // FFFMMM
// // MMMFFF
// // FFFFF
// // FFFFFFFFFF
// // FFFFM
// // FFFFFMMMMF
// // MFMFMFFFMMMFMF
// // MMFFFFFMFFFMFFFFFFMFFFMFFFFMFMMFFFFFFF

// // 예제 출력 : 
// // 1
// // 6
// // 2
// // 2
// // */

// // /*
// // 풀이:
// // 단순 모든 경우의 수 연산은 O(N^2)으로 시간 초과가 발생한다.
// // 이를 위해 각 성별을 1과 0으로 치환 후 다항식 곱셈과 이를 단축시킬 카라츠바 알고리즘을 사용한다.
// // 다항식 곱셈의 결과에서 1이 나오면 악수(실패)가 발생한 것이며 0이면 모두 포옹(성공)이 발생한 것으로 판단한다.
// // */

// // #include <iostream>
// // #include <vector>
// // #include <algorithm>

// // using namespace std;

// // void normalize(vector<int>& v)
// // {
// //    v.push_back(0); //벡터의 자리수를 미리 추가한다.

// //    int size = v.size();
// //    for (int i = 0; i < size - 1; i++)
// //    {
// //        if (v[i] < 0) // 계산 결과시 음수일 경우
// //        {
// //            int borrow = (abs(v[i]) + 9) / 10;
// //            v[i + 1] -= borrow;
// //            v[i] += borrow * 10;
// //        }
// //        else
// //        {
// //            v[i + 1] += v[i] / 10;
// //            v[i] %= 10;
// //        }
// //    }
// //    //앞에 남은 0을 제거한다.
// //    while (v.size() > 1 && v.back() == 0)
// //        v.pop_back();
// // }

// // vector<int> KaratsubaMultiply(const vector<int>& a, const vector<int>& b)
// // {
// //    vector<int> v(a.size() + b.size() + 1, 0);  //값이 저장되는 배열
// //    int al = a.size();
// //    int bl = b.size();

// //    for (int i = 0; i < al; i++)
// //        for (int j = 0; j < bl; j++)
// //            v[i + j] += a[i] * b[j];

// //    normalize(v);
// //    return v;
// // }

// // int CountHugs(string members, string fans)
// // {
// //   int hugCount = 0;
// //   // 남성 : M -> 1, 여성 : F -> 0 치환
// //   vector<int> membersInt;
// //   vector<int> fansInt;

// //   for(char c : members){    
// //     if(c == 'M') membersInt.push_back(1);
// //     else membersInt.push_back(0);
// //   }

// //   for(char c : fans){
// //     if(c == 'M') fansInt.push_back(1);
// //     else fansInt.push_back(0);
// //   }

// //   vector<int> result = KaratsubaMultiply(membersInt, fansInt);

// //   // 결과 배열에서 0이 나오는 위치는 포옹(성공)을 의미한다.
// //   for(int i = membersInt.size() - 1; i < fansInt.size(); i++)
// //     if(result[i] == 0)
// //       hugCount++;

// //   return hugCount;
// // }

// // int main()
// // {
// //   int C;
// //   vector<int> result;

// //   cin >> C;
// //   string members, fans;

// //   for(int i = 0; i < C; i++){
// //     cin >> members >> fans;
// //     reverse(members.begin(), members.end());
// //     result.push_back(CountHugs(members, fans));
// //   }

// //   for(int i = 0; i < C; i++)
// //     cout << result[i] << endl;
  
// //   return 0;
// // }

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>

// using namespace std;

// void normalize(vector<int>& num) {
// 	num.push_back(0);

// 	for (int i = 0; i < num.size() - 1; i++) {
// 		if (num[i] < 0) {		
// 			int borrow = (abs(num[i]) + 9) / 10;
// 			num[i + 1] -= borrow;
// 			num[i] += borrow * 10;
// 		}
// 		else {		
// 			num[i + 1] += num[i] / 10;
// 			num[i] %= 10;
// 		}
// 	}
// 	while (num.size() > 1 && num.back() == 0) 
// 		num.pop_back();
// }

// vector<int> multiply(const vector<int> &A, const vector<int> &B) {	
// 	vector<int> num(A.size() + B.size() + 1, 0);

// 	for (int i = 0; i < A.size(); i++) {
// 		for (int j = 0; j < B.size(); j++) {
// 			num[i + j] += (A[i] * B[j]);
// 		}
// 	}

// 	return num;
// }

// void addTo(vector<int>& A, const vector<int>& B, int k) {
// 	A.resize(max(A.size(), B.size() + k));

// 	for (int i = 0; i < B.size(); i++) {
// 		A[i + k] += B[i];
// 	}

// }

// void subFrom(vector<int>& A, const vector<int>& B) {
// 	A.resize(max(A.size(), B.size()) + 1);

// 	for (int i = 0; i < B.size(); i++) {
// 		A[i] -= B[i];
// 	}
// }

// vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
// 	int an = a.size(), bn = b.size();
// 	if (an < bn) return karatsuba(b, a);

// 	if (an == 0 || bn == 0) return vector<int>(); 

// 	if (an <= 50) return multiply(a, b);

// 	int half = an / 2; 

// 	vector<int> a0(a.begin(), a.begin() + half);
// 	vector<int> a1(a.begin() + half, a.end());
// 	vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));
// 	vector<int> b1(b.begin() + min<int>(bn, half), b.end());

// 	vector<int> z2 = karatsuba(a1, b1);
// 	vector<int> z0 = karatsuba(a0, b0);

// 	addTo(a0, a1, 0);	
// 	addTo(b0, b1, 0);	

// 	// z1 = (a0 * b0) - z0 - z2
// 	vector<int> z1 = karatsuba(a0, b0);	
// 	subFrom(z1, z0);	
// 	subFrom(z1, z2);


// 	vector<int> res;
// 	addTo(res, z0, 0);
// 	addTo(res, z1, half);
// 	addTo(res, z2, half * 2);

// 	return res;
// }


// void solve(const string& mems, const string& fans) {
// 	int n = mems.size(), m = fans.size(), cnt = 0;
// 	vector<int> A(n), B(m);

// 	for (int i = 0; i < n; i++) {
// 		A[i] = (mems[i] == 'M') ? 1 : 0;
// 	}
// 	for (int i = 0; i < m; i++) {
// 		B[m - i - 1] = (fans[i] == 'M') ? 1 : 0;
// 	}

// 	vector<int> C = karatsuba(A, B);	

// 	for (int i = n - 1; i < m; i++) {
// 		if (C[i] == 0)
// 			cnt++;
// 	}

// 	cout << cnt << "\n";
// }

// int main() {
// 	int C;

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);

// 	cin >> C;
// 	while (C--) {
// 		string mems, fans;

// 		cin >> mems >> fans;

// 		solve(mems, fans);
// 	}
// 	return 0;
// }