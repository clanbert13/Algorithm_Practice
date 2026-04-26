// /*
// 알 수 없는 번호
 
// 시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
// 2 초	128 MB	4612	361	262	9.404%
// 문제
// 당신은 한 개의 알 수 없는 수를 알아내야만 한다. "이런 젠장"

// 어쨌든 당신은 그 수를 알아내야만 한다. 당신에게 주어지는 정보는 다음과 같다.

// 그 수가 있을 수 있는 범위
// 그 수를 x로 나눈 나머지, 즉 그 수를 qx + y(0 ≤ y < |x|) 꼴로 나타냈을 때 y의 값
// 이때, 당신은 그 수가 무엇인지 추측해야 한다.

// 입력
// 첫 번째 줄에는 수가 있을 수 있는 범위의 양끝 값을 의미하는 두 개의 수가 주어진다.

// 두 번째 줄에는 나누는 수 x와 나머지 y가 주어진다.

// 주어지는 모든 수는 -231 이상 231 - 1 이하의 정수이다.

// 출력
// 첫째 줄에 추측한 수를 출력한다. 만약 정확히 한 개로 추측할 수 없다면 Unknwon Number를 출력한다.

// 예제 입력 1 
// 1 10
// 10 5
// 예제 출력 1 
// 5
// 예제 입력 2 
// 1 10
// 7 2
// 예제 출력 2 
// Unknwon Number
// */
// #include <bits/stdc++.h>
// #define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// using namespace std;

// #define int int64_t
// const int INF = INT_MAX;

// int32_t main() {
// 	fastio;
// 	int l, r, x, y; cin >> l >> r >> x >> y; x = abs(x); //ans = Q * x + y, ans �� [l, r]
// 	if (l > r) swap(l, r);
// 	if (r - l >= 2 * x || !(0 <= y && y < x)) return !(cout << "Unknwon Number" << '\n');
// 	else {
// 		vector<int> v;
// 		int st = l;
// 		if ((l % x + x) % x == y);
// 		else if ((l % x + x) % x <= y) st += y - (l % x + x) % x;
// 		else st += x - (l % x + x) % x + y;
// 		for (int i = st; i <= r; i += x) {
// 			if ((i % x + x) % x == y) v.push_back(i);
// 			if (v.size() > 1) return !(cout << "Unknwon Number" << '\n');
// 		}
// 		if (v.empty()) cout << "Unknwon Number" << '\n';
// 		else cout << v[0] << '\n';
// 	}
// }