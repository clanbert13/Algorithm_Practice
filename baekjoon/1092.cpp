// /*
// 배
 
// 시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
// 2 초	128 MB	39906	11028	7780	26.394%
// 문제
// 지민이는 항구에서 일한다. 그리고 화물을 배에 실어야 한다. 모든 화물은 박스에 안에 넣어져 있다. 항구에는 크레인이 N대 있고, 1분에 박스를 하나씩 배에 실을 수 있다. 모든 크레인은 동시에 움직인다.

// 각 크레인은 무게 제한이 있다. 이 무게 제한보다 무거운 박스는 크레인으로 움직일 수 없다. 모든 박스를 배로 옮기는데 드는 시간의 최솟값을 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 각 크레인의 무게 제한이 주어진다. 이 값은 1,000,000보다 작거나 같다. 셋째 줄에는 박스의 수 M이 주어진다. M은 10,000보다 작거나 같은 자연수이다. 넷째 줄에는 각 박스의 무게가 주어진다. 이 값도 1,000,000보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 모든 박스를 배로 옮기는데 드는 시간의 최솟값을 출력한다. 만약 모든 박스를 배로 옮길 수 없으면 -1을 출력한다.

// 예제 입력 1 
// 3
// 6 8 9
// 5
// 2 5 2 4 7
// 예제 출력 1 
// 2
// 예제 입력 2 
// 2
// 19 20
// 7
// 14 12 16 19 16 1 5
// 예제 출력 2 
// 4
// 예제 입력 3 
// 4
// 23 32 25 28
// 10
// 5 27 10 16 24 20 2 32 18 7
// 예제 출력 3 
// 3
// 예제 입력 4 
// 10
// 11 17 5 2 20 7 5 5 20 7
// 5
// 18 18 15 15 17
// 예제 출력 4 
// 2
// */

// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// vector<int> crane, box;
// int avail[10000];

// int main() {
// 	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// 	int c, num, val;
// 	cin >> c;
// 	for (int i = 0; i < c; i++) {
// 		cin >> val;
// 		crane.push_back(val);
// 	}
// 	sort(crane.begin(),crane.end());
// 	cin >> num;
// 	for (int i = 0; i < num; i++) {
// 		cin >> val;
// 		box.push_back(val);
// 	}
// 	sort(box.begin(), box.end());
// 	if (crane[c - 1] < box[num - 1]) {
// 		cout << -1;
// 		return 0;
// 	}
// 	int idx = 0;
// 	for (int i = 0; i < num; i++) {
// 		if (crane[idx] >= box[i]) 	avail[idx]++;		
// 		else {
// 			idx++;
// 			i--;
// 		}
// 	}
// 	int cnt = 0, t = 0;
// 	while (1) {
// 		for (int i = c - 1; i >= 0; i--) {
// 			for (int j = i; j >= 0; j--) {
// 				if (avail[j]) {
// 					avail[j]--;
// 					cnt++;
// 					break;
// 				}
// 			}
// 			if (cnt == num) break;
// 		}
// 		t++;
// 		if (cnt == num) break;
// 	}
// 	cout << t;
// 	return 0;
// }