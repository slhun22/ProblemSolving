#include<iostream>
#include<queue>
using namespace std;

vector<pair<int, int>> adj[100001];
bool visited[100001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;//w-v

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, i, a, b, c;
	cin >> N >> M;

	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	pq.push({0, 1});
	int sum = 0, maxcost = -1, cnt = 0;
	while (cnt < N) {
		int v = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (visited[v])
			continue;
		visited[v] = true;
		cnt++;
		sum += cost;
		if (maxcost < cost)
			maxcost = cost;

		for (auto e : adj[v])
			if (!visited[e.first])
				pq.push({ e.second, e.first });
	}

	cout << sum - maxcost;
}