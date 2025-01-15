#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> pointing[32001];
int indeg[32001] = { 0, };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, N, M, x, y;
	queue<int> q;
	cin >> N >> M;

	for (i = 0; i < M; i++) {
		cin >> x >> y;
		pointing[x].push_back(y);
		indeg[y]++;
	}

	for (i = 1; i <= N; i++) {
		if (indeg[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int curr = q.front();
		cout << curr << " ";
		q.pop();
		for (auto child : pointing[curr])
			if (--indeg[child] == 0)
				q.push(child);
	}
}