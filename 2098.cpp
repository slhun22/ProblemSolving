#include<iostream>
#define INF 2140000000
using namespace std;

int cost[16][16];
int dp[1 << 16][16];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, st, N;
	cin >> N;
	int FULL = 1 << N;
	for (i = 0; i < FULL; i++)
		for (j = 0; j < 16; j++)
			dp[i][j] = INF;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> cost[i][j];

	dp[1][0] = 0;
	for (st = 1; st < FULL; st++) {
		for (i = 0; i < N; i++) { //from
			if (dp[st][i] == INF)
				continue;

			for (j = 0; j < N; j++) { //to
				if (cost[i][j] && !(st & (1 << j)))
					dp[st | (1 << j)][j] = min(dp[st | (1 << j)][j], dp[st][i] + cost[i][j]); 
			}
		}
	}

	int mincost = INF;
	for (i = 0; i < N; i++) {
		if(cost[i][0])
			mincost = min(mincost, dp[FULL - 1][i] + cost[i][0]);
	}
	cout << mincost;
}