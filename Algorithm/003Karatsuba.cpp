
// //256자리 숫자 a * b를 a1 * 10^128 + a0 형식으로 나누어 곱한다
// //( a1 * b1 * 10^256 ) + ( a0 * b0 ) + { (a0 * b1) * 10^128 + (a1 * b0) * 10^128 }
// // ( a1 * b1 * 10^256 ) + ( a0 * b0 ) + 10^128 * {( a0 + b1 ) * ( a1 + b0 )}
// // a0 * b0 == z0, a1 * b1 == z1, ( a0 + b1 ) * ( a1 + b0 ) == z2, 따라서 이 문제는 ( z1 * 10^256 ) + [ { z2 - ( z1 + z0 ) } * 10^128 ] + z0 이다

// #include<vector>
// #include<algorithm>
// #include<iostream>

// using namespace std;

// //벡터 자릿수 올림 함수
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


// //각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.
// vector<int> Multiply(const vector<int>& a, const vector<int>& b)
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

// void AddTo(vector<int>& a, const vector<int>& b, int k)
// {
//    if (a.size() < b.size() + k)
//        a.resize(b.size() + k);

//    a.push_back(0);

//    for (int i = a.size(); i < a.size(); i++) a[i] = 0;

//    for (int i = 0; i < b.size(); i++) a[i + k] += b[i];

//    normalize(a);
// }

// void SubFrom(vector<int>& a, const vector<int>& b)
// {
//    for (int i = 0; i < b.size(); i++)
//        a[i] -= b[i];
//    normalize(a);
// }

// vector<int> Karatsuba(vector<int>& a, vector<int>& b) {
// 	int al, bl;	//벡테 a와 b의 길이를 저장하는 변수
// 	al = a.size();
// 	bl = b.size();

// 	if (al == 0 || bl == 0) return vector<int>();   //두 수중 하나가 없다면 그냥 반환
// 	if (bl > al)return Karatsuba(b, a); //긴 쪽이 a를 맞는다.
// 	if (al <= 50) return Multiply(a, b);    //자리수가 일정 이하일때 간단한 연산 실행

//    int half = al / 2;

//    vector<int> a0(a.begin(), a.begin() + half);
//    vector<int> a1(a.begin() + half, a.end());

//    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));    //절반은 a기준, a의 크기보다 b가 작을수도 있으므로 bn과의 최소값을 비교한다
//    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

//    vector<int> z0 = Karatsuba(a0, b0);     // a0 * b0 == z0
//    vector<int> z1 = Karatsuba(a1, b1);     // a1 * b1 == z1
   
//    AddTo(a0, a1, 0);
//    AddTo(b0, b1, 0);
//    vector<int> z2 = Karatsuba(a0, b0);     //( a0 + b1 ) * ( a1 + b0 ) == z2
//    SubFrom(z2, z0);
//    SubFrom(z2, z1);

//    vector<int> ret(z2.size() + half * 2, 0);
//    AddTo(ret, z0, 0);
//    AddTo(ret, z1, half);
//    AddTo(ret, z2, half + half);
   
//    return ret;
// }

// int main() {
//    vector<int> v0;
//    vector<int> v1;

 
//    v0.push_back(1);
//    v0.push_back(2);
//    v0.push_back(3);

//    v1.push_back(3);
//    v1.push_back(2);
//    v1.push_back(1);
 
//    //123 * 321 = 39438
//    vector<int> v2 = Karatsuba(v0, v1);

//    for (int i = v2.size() - 1; i >= 0; i--)
//        cout << v2[i];

// 	return 0;
// }