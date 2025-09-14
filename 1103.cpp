#include<iostream>
using namespace std;

int N, M;
int board[50][50];
int dp[50][50];
bool visit[50][50];
bool infinity = false;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dfs(int r, int c) {
	if (infinity)
		return 0;
	if (r < 0 || r >= N || c < 0 || c >= M)
		return 0;
	if (visit[r][c]) {
		infinity = true;
		return 0;
	}
	if (board[r][c] == -1)
		return 0;
	if (dp[r][c])
		return dp[r][c];

	visit[r][c] = true;
	int mul = board[r][c];
	int maxv = -1;
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i] * mul;
		int nc = c + dy[i] * mul;
		int cnt = 1 + dfs(nr, nc);
		maxv = max(maxv, cnt);
	}

	visit[r][c] = false;
	return dp[r][c] = maxv;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j;
	string s;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> s;
		for (j = 0; j < M; j++) {
			if (s[j] == 'H')
				board[i][j] = -1;
			else
				board[i][j] = s[j] - '0';
		}
	}

	dfs(0, 0);
	if (infinity)
		cout << -1;
	else
		cout << dp[0][0];
}