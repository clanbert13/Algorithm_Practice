////must be execute in 1s, low then 64MB
////test case C <=50,  student n ( 2 <= n <= 10), friend pair m (0 <= m <= n (n - 1) / 2)
///*
//input
//
//3
//2 1
//0 1
//4 6
//0 1 1 2 2 3 3 0 0 2 1 3
//6 10
//0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
//
//output
//1
//3
//4
//*/
//#include <cstdio>
//#include<algorithm>
//
//using namespace std;
//
//int n;
//bool areFriends[10][10] = { false };		//friends == 1, not friends == -1
//
////taken[i] = student[i] has pair == 1 else -1
//int countPair(bool taken[10]) {
//	int first = -1;
//
//	for (int i = 0; i < n; i++) {
//		if (!taken[i]) {
//			first = i;
//			break;
//		}
//	}
//
//	//all student pair found 
//	if (first == -1) return 1;
//
//	int res = 0;
//	for (int pairWith = first + 1; pairWith <= n; pairWith++) {
//		if (!taken[pairWith] && areFriends[first][pairWith]) {
//			taken[first] = taken[pairWith] = true;
//			res += countPair(taken);
//			taken[first] = taken[pairWith] = false;
//		}
//	}
//	return res;
//}
//
//
//int main()
//{
//	int C, m, a, b;
//	int result[50];
//
//	scanf_s("%d", &C);
//
//	bool temp[10] = {false};
//
//	for (int i = 0; i < C; i++) {
//		scanf_s("%d %d", &n, &m);
//		for (int j = 0; j < m; j++) {
//			scanf_s("%d %d", &a, &b);
//			if (a > b)swap(a, b);
//			areFriends[a][b] = true;
//		}
//		result[i] = countPair(temp);
//
//		for (int n=0; n < 10; n++)
//			for (int m=0; m < 10; m++)areFriends[n][m] = false;
//	}
//	for (int i = 0; i < C; i++) printf("\n%d", result[i]);
//
//	return 0;
//}
