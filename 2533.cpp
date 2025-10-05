#include<iostream>
#include<vector>
#include<bitset>
#include<cstring>
using namespace std;

vector<int> adj[1000001];
vector<int> nadj[1000001];
int dp[1000001][2];
bitset<1000001> visit;

int dfs(int root, bool flag) {
	if (dp[root][flag] != -1)
		return dp[root][flag];

	int sum = flag;
	for (int c : nadj[root]) {
		int val = dfs(c, true);
		if (flag)
			val = min(val, dfs(c, false));

		sum += val;
	}

	return dp[root][flag] = sum;
}

void traverse(int root) {
	for (int c : adj[root]) {
		if (!visit[c]) {
			visit[c] = true;
			nadj[root].push_back(c);
			traverse(c);
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	int N, i, a, b;
	cin >> N;
	for (i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	visit[1] = true;
	traverse(1);

	cout << min(dfs(1, true), dfs(1, false));
}