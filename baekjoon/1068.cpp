// /*
// 트리 
 
// 시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
// 2 초	128 MB	81194	25787	19136	30.927%
// 문제
// 트리에서 리프 노드란, 자식의 개수가 0인 노드를 말한다.

// 트리가 주어졌을 때, 노드 하나를 지울 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오. 노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.

// 예를 들어, 다음과 같은 트리가 있다고 하자.



// 현재 리프 노드의 개수는 3개이다. (초록색 색칠된 노드) 이때, 1번을 지우면, 다음과 같이 변한다. 검정색으로 색칠된 노드가 트리에서 제거된 노드이다.



// 이제 리프 노드의 개수는 1개이다.

// 입력
// 첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.

// 출력
// 첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.

// 예제 입력 1 
// 5
// -1 0 0 1 1
// 2
// 예제 출력 1 
// 2
// 예제 입력 2 
// 5
// -1 0 0 1 1
// 1
// 예제 출력 2 
// 1
// 예제 입력 3 
// 5
// -1 0 0 1 1
// 0
// 예제 출력 3 
// 0
// 예제 입력 4 
// 9
// -1 0 0 2 2 4 4 6 6
// 4
// 예제 출력 4 
// 2
// */
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// bool deleted[50];
// vector<int> graph[50];
// int answer = 0;
// int n;

// void bfs(int start) {
// 	queue<int> q;
// 	q.push(start);
// 		while (!q.empty()) {
// 			int cur = q.front();
// 			q.pop();
// 			deleted[cur] = true;
// 			for (int i = 0; i < graph[cur].size(); i++) {
// 				int next = graph[cur][i];
// 				if (deleted[next])
// 					continue;
// 				q.push(next);
			
// 			}
// 		}


// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
	
	
// 	cin >> n;
// 	int start = 0;
// 	for (int i = 0; i < n; i++) {
// 		int num;
// 		cin >> num;
// 		if (num == -1) {
// 			start = i;
// 			continue;
// 		}
// 		graph[num].push_back(i);
// 	}
// 	int delete_num;
// 	cin >> delete_num;
// 	bfs(delete_num);

// 	for (int i = 0; i < n; i++) {
// 		//
// 		if(!deleted[i]){
// 			int j=-1;
// 			for (j = 0; j < graph[i].size(); j++) {
// 				if (!deleted[graph[i][j]])
// 					break;
// 			}
// 			if (j == graph[i].size())
// 				answer++;
// 		}
// 	}
// 	cout << answer;
// 	return 0;
// }