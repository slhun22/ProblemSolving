#include<iostream>
#include<queue>
using namespace std;

int field[50][50] = {};
bool visited[50][50] = {};
int M, N;

void dfs(int r, int c) {
	visited[r][c] = true;
	if (r - 1 >= 0 && field[r - 1][c] && !visited[r - 1][c])
		dfs(r - 1, c);
	if (r + 1 < M && field[r + 1][c] && !visited[r + 1][c])
		dfs(r + 1, c);
	if (c + 1 < N && field[r][c + 1] && !visited[r][c + 1])
		dfs(r, c + 1);
	if (c - 1 >= 0 && field[r][c - 1] && !visited[r][c - 1])
		dfs(r, c - 1);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T, K, r, c, i, j;
	queue<pair<int,int>> q;
	cin >> T;
	while (T--) {
		int cnt = 0;
		cin >> M >> N >> K;
		for (i = 0; i < M; i++)
			for (j = 0; j < N; j++) {
				field[i][j] = 0;
				visited[i][j] = false;
			}		
		for (i = 0; i < K; i++) {
			cin >> r >> c;
			field[r][c] = 1;
			q.push(make_pair(r, c));
		}	
		while (!q.empty()) {
			auto pos = q.front();
			q.pop();
			if (!visited[pos.first][pos.second]) {
				cnt++;
				dfs(pos.first, pos.second);
			}
		}
		cout << cnt << "\n";
	}
}