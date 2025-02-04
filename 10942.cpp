#include<iostream>

using namespace std;

int dp[2001][2001] = { 0, };
int seq[2001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j, N, Q, S, E;
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> seq[i];
	for (i = 1; i <= N; i++)
		dp[i][i] = 1;
	for (i = 1; i < N; i++)
		if (seq[i] == seq[i + 1])
			dp[i][i + 1] = 1;
	for (i = N; i >= 1; i--)
		for (j = i + 2; j <= N; j++)
			if (dp[i + 1][j - 1] && seq[i] == seq[j])
				dp[i][j] = 1;
	cin >> Q;
	for (i = 0; i < Q; i++) {
		cin >> S >> E;
		cout << dp[S][E] << "\n";
	}
}