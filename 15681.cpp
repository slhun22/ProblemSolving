#include<iostream>
#include<vector>
using namespace std;

vector<int> adj[100001];
int dp[100001];

int traverse(int root, int parent) {
	int sum = 1;
	for (int v : adj[root]) {
		if (v != parent)
			sum += traverse(v, root);
	}
	return dp[root] = sum;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, R, Q, i, u, v;
	cin >> N >> R >> Q;

	for (i = 1; i < N; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	traverse(R, 0);

	for (i = 0; i < Q; i++) {
		cin >> u;
		cout << dp[u] << "\n";
	}
}