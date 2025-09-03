#include<iostream>
#include<cstring>
using namespace std;

int field[500][500];
int dp[500][500];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0 ,1 };
int M, N;

int dfs(int r, int c) {
	if (r == M - 1 && c == N - 1)
		return 1;
	if (dp[r][c] != -1)
		return dp[r][c];

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		
		if (nr < 0 || nr >= M || nc < 0 || nc >= N)
			continue;

		if (field[nr][nc] < field[r][c])
				sum += dfs(nr, nc);
	}

	return dp[r][c] = sum;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j;
	cin >> M >> N;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cin >> field[i][j];

	memset(dp, -1, sizeof(dp));
	dfs(0, 0);
	cout << dp[0][0];
}