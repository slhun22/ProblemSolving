#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

int candy[30001];
map<int, pair<int ,int>> vwmap;
int dp[3000] = {};

int par[30001];
int depth[30001];
vector<int> friends[30001];
bool visited[30001];

int FindParent(int target) {
	if (target == par[target])
		return target;
	
	return par[target] = FindParent(par[target]);
}

void Union(int a, int b) {
	int x = FindParent(a);
	int y = FindParent(b);
	if (x != y) {
		if (depth[x] == depth[y])
			depth[x]++;
		
		if (depth[x] > depth[y])
			par[y] = x;
		else
			par[x] = y;
	}
}

void DFS(int target) {
	visited[target] = true;
	for (auto f : friends[target]) {
		if (!visited[f]) {
			Union(target, f);
			DFS(f);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, K, i, j, a, b;
	cin >> N >> M >> K;
	for (i = 1; i <= N; i++) {
		cin >> candy[i];
		par[i] = i;
	}

	for (i = 0; i < M; i++) {
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (i = 1; i <= N; i++) {
		if (!visited[i])
			DFS(i);
	}

	//--------------------------------

	for (i = 1; i <= N; i++) {
		vwmap[par[i]].first += candy[i];
		vwmap[par[i]].second++;
	}

	for (auto const& vw : vwmap) {
		int v = vw.second.first;
		int w = vw.second.second;
		for (j = K - 1; j >= w; j--)
			dp[j] = max(dp[j - w] + v, dp[j]);
	}

	cout << dp[K - 1];
}