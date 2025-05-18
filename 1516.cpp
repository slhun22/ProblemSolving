#include<iostream>
#include<queue>
using namespace std;

vector<int> pointing[501];
int cost[501];
int ans[501];
int indeg[501];
queue<int> q;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, i, temp;
	cin >> N;

	for (i = 1; i <= N; i++) {
		cin >> cost[i];
		while (true) {
			cin >> temp;
			if (temp == -1)
				break;

			pointing[temp].push_back(i);
			indeg[i]++;
		}
	}

	for (i = 1; i <= N; i++) {
		if (indeg[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		ans[front] += cost[front];

		for (auto iter : pointing[front]) {
			indeg[iter]--;
			if(ans[iter] < ans[front])
				ans[iter] = ans[front];
			if (indeg[iter] == 0)
				q.push(iter);
		}
	}

	for (i = 1; i <= N; i++)
		cout << ans[i] << "\n";
}