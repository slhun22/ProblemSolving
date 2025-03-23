#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> pointing[32001];
int indeg[32001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, N, M, a, b;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		pointing[a].push_back(b);
		indeg[b]++;
	}

	for (i = 1; i <= N; i++)
		if (indeg[i] == 0)
			pq.push(i);

	while (!pq.empty()) {
		int top = pq.top();
		pq.pop();
		cout << top << " ";
		for (auto iter : pointing[top])
			if (--indeg[iter] == 0)
				pq.push(iter);
	}
}