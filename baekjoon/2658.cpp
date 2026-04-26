// /*
// 직각이등변삼각형찾기
 
// 시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
// 1 초	128 MB	2822	527	365	23.966%
// 문제
// 가로 10줄, 세로 10줄에 1 또는 0이 적혀진 배열이 있다. 이러한 배열 안에 있는 숫자 1들이 만드는 모양이 한 개의 직각이등변삼각형인지 아닌지 알아내는 프로그램을 작성하시오.

// 직각이등변삼각형의 적어도 한 변은 수평선 또는 수직선이다. 단, 직각이등변삼각형의 내부도 1로 채워져 있어야 한다. 입력된 모양은 삼각형이 아닐 수 있다.

// 입력
// 입력은 10줄로 이루어지며 각 줄은 첫 칸부터 공백없이 10개의 0또는 1로 이루어진다.

// 출력
// 입력된 모양이 직각이등변 삼각형을 이루는 경우에는 세 꼭짓점의 위치를 출력하고, 그렇지 않은 경우에는 0을 출력한다. 각 꼭짓점의 위치를 한 줄에 두 개의 수로 출력한다. 두 수는 하나의 빈 공백을 두고 출력한다. 첫째 수는 그 꼭짓점이 위에서부터 몇 번째 줄에 있는가 나타내며, 두 번째 수는 왼쪽부터 몇 번째 칸에 있는가를 나타내야 한다. 꼭짓점을 출력할때는 첫째 수가 작은 것부터, 첫째 수가 같을 경우 두 번째 수가 작은 것부터 출력한다.

// 예제 입력 1 
// 0000000000
// 0000001000
// 0000011000
// 0000111000
// 0001111000
// 0000111000
// 0000011000
// 0000001000
// 0000000000
// 0000000000
// 예제 출력 1 
// 2 7
// 5 4
// 8 7
// */

// #include <iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <cstring>
// #include <set>
// #include <map>
// #include <cmath>
// #include <utility>
// #include <list>
// #include <unordered_set>
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> pii;

// int arr[10][10];
// pii ans[3];

// void rotate() {
// 	int tmp[10][10];
// 	for (int i = 0; i < 10; i++)
// 		for (int j = 0; j < 10; j++)
// 			tmp[i][j] = arr[i][j];
// 	for (int i = 0; i < 10; i++)
// 		for (int j = 0; j < 10; j++)
// 			arr[i][j] = tmp[9 - j][i];
// }	

// void rotate_point(int n) {
// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < 3; j++) {
// 			int y = ans[j].first, x = ans[j].second;
// 			ans[j].first = 9 - x;
// 			ans[j].second = y;
// 		}
// 	}
// }

// void print(int arr[][10]) {
// 	for (int i = 0; i < 10; i++) {
// 		for (int j = 0; j < 10; j++)
// 			cout << arr[i][j];
// 		cout << '\n';
// 	}
// 	cout << '\n';
// }

// bool evaluate1() {
// 	//�� ������ ã��
// 	int y = -1, x = -1;
// 	for (int i = 0; i < 10; i++) {
// 		for (int j = 0; j < 10; j++)
// 			if (arr[i][j] == 1) {
// 				y = i, x = j;
// 				break;
// 			}
// 		if (y != -1) break;
// 	}
// 	if (y == -1) return false;

// 	ans[0] = { y, x };
// 	//�� �������������� �����ﰢ���� �����
// 	int tmp[10][10];
// 	memset(tmp, 0, sizeof(tmp));
// 	for (int i = 0; i+y < 10; i++) {
// 		if (arr[i + y][x] == 1) {
// 			if (x - i < 0 || x + i >= 10) return false;
// 			ans[1] = { y + i, x - i };
// 			ans[2] = { y + i, x + i };
// 			for (int j = x - i; j <= x + i; j++) {
// 				tmp[i + y][j] = 1;
// 			}
// 		}
// 	}

// 	for (int i = 0; i < 10; i++)
// 		for (int j = 0; j < 10; j++)
// 			if (tmp[i][j] != arr[i][j])
// 				return false;

// 	return true;
// }

// bool evaluate2() {
// 	int y = -1, x = -1;
// 	for (int i = 0; i < 10; i++) {
// 		for (int j = 0; j < 10; j++)
// 			if (arr[i][j] == 1) {
// 				y = i, x = j;
// 				break;
// 			}
// 		if (y != -1) break;
// 	}
// 	if (y == -1) return false;

// 	ans[0] = { y, x };

// 	int tmp[10][10];
// 	memset(tmp, 0, sizeof(tmp));
// 	for (int i = 0; i + y < 10; i++) {
// 		if (arr[i + y][x] == 1) {
// 			if (x + i >= 10) return false;
// 			ans[1] = { y + i, x };
// 			ans[2] = { y + i, x + i };
// 			for (int j = x; j <= x + i; j++) {
// 				tmp[i + y][j] = 1;
// 			}
// 		}
// 	}

// 	for (int i = 0; i < 10; i++)
// 		for (int j = 0; j < 10; j++)
// 			if (tmp[i][j] != arr[i][j])
// 				return false;

// 	return true;
// }

// int main() {
// //	ios::sync_with_stdio(false);
// //	cin.tie(0), cout.tie(0);
// 	for (int i = 0; i < 10; i++)
// 		for (int j = 0; j < 10; j++)
// 			scanf("%1d", &arr[i][j]);

// 	for (int i = 0; i < 4; i++) {
// 		rotate();
// 		if (evaluate1()) {
// 			rotate_point(i + 1);
// 			sort(ans, ans + 3);
// 			for (int j = 0; j < 3; j++)
// 				cout << ans[j].first + 1 << ' ' << ans[j].second + 1<< '\n';
// 			return 0;
// 		}
// 		if (evaluate2()) {
// 			rotate_point(i + 1);
// 			sort(ans, ans + 3);
// 			for (int j = 0; j < 3; j++)
// 				cout << ans[j].first + 1 << ' ' << ans[j].second + 1 << '\n';
// 			return 0;
// 		}
// 	}
// 	cout << 0 << '\n';
// }