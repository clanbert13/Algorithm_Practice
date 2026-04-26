// /*
// 1의 개수 세기
 
// 시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
// 1 초	128 MB	13202	5313	4240	42.763%
// 문제
// 두 자연수 A, B가 주어졌을 때, A ≤ x ≤ B를 만족하는 모든 x에 대해 x를 이진수로 표현했을 때 1의 개수의 합을 구하는 프로그램을 작성하시오.

// 즉, f(x) = x를 이진수로 표현 했을 때 1의 개수라고 정의하고, 아래 식의 결과를 구하자.

//  
// \[\sum_{x=A}^{B}{f(x)}\] 

// 입력
// 첫 줄에 두 자연수 A, B가 주어진다. (1 ≤ A ≤ B ≤ 1016)

// 출력
// 1의 개수를 세어 출력한다.

// 예제 입력 1 
// 2 12
// 예제 출력 1 
// 21
// */

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
 
// ll a, b;
// ll d[55];
 
// ll go(ll x, ll i = 54) {
//     ll ans = x & 1;
//     for (; i > 0; i--) {
//         if (x & (1LL << i)) {
//             ans += d[i - 1] + (x - (1LL << i) + 1);
//             x -= 1LL << i;
//         }
//     }
//     return ans;
// }
 
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
 
//     d[0] = 1;
//     for (ll i = 1; i < 55; i++) {
//         d[i] = d[i - 1] * 2 + (1LL << i);
//     }
//     cin >> a >> b;
//     cout << go(b) - go(a - 1);
// }