#include<iostream>
#include<vector>
using namespace std;

vector<int> e[1001];
bool visited[1001];

void dfs(int n) {
	visited[n] = true;
	for (auto iter : e[n]) {
		if(!visited[iter])
			dfs(iter);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int M, N, i, a, b, cnt = 0;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}