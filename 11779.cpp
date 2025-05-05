#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define MAX 2140000000
using namespace std;

priority_queue<pair<int ,int>, vector<pair<int ,int>>, greater<pair<int ,int>>> pq; //dist v
stack<int> st;
int trace[1001];
int cnt = 0;

void tracing(int v) {
	cnt++;
	st.push(v);
	if (trace[v] == v)
		return;
	tracing(trace[v]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j, n, m, s, e, cost, start, end;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<int> dist(n + 1, MAX);

	for (i = 0; i < m; i++) {
		cin >> s >> e >> cost;
		adj[s].push_back({e, cost});
	}
	cin >> start >> end;
	dist[start] = 0;
	trace[start] = start;
	pq.push({ 0, start });
	while (!pq.empty()) {
		const int v = pq.top().second;
		const int cost = pq.top().first;
		pq.pop();
		if (cost > dist[v])
			continue;

		for (auto iter : adj[v]) {
			const int adjV = iter.first;
			const int adjCost = iter.second;
			if (dist[adjV] > cost + adjCost) {
				dist[adjV] = cost + adjCost;
				trace[adjV] = v;
				pq.push({ dist[adjV], adjV });
			}				
		}
	}
	tracing(end);
	cout << dist[end] << "\n" << cnt << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}