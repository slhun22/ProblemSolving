#include<iostream>
using namespace std;

int field[500][500];
int dp[500][500];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n;

int func(int r, int c) {
	if (dp[r][c] != 0)
		return dp[r][c];

	int maxv = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		if (nr < 0 || nr >= n || nc < 0 || nc >= n)
			continue;

		if (field[r][c] < field[nr][nc])
			maxv = max(maxv, func(nr, nc));
	}

	return dp[r][c] = maxv + 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> field[i][j];

	int ans = -1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
				ans = max(ans, func(i, j));

	cout << ans;
}