#include<iostream>
#define INF 999999990000000LL
using namespace std;

long long dp[500][500];
long long prefix[500];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T-- > 0) {
		int K, temp, i, j, k;
		cin >> K;

		for (i = 0; i < K; i++)
			for (j = 0; j < K; j++)
				dp[i][j] = INF;

		cin >> prefix[0];
		dp[0][0] = 0;
		for (i = 1; i < K; i++) {
			cin >> temp;
			prefix[i] = prefix[i - 1] + temp;
			dp[i][i] = 0;
		}

		for (i = 1; i < K; i++)
			for (j = 0; j + i < K; j++)
				for (k = 0; k < i; k++) {
					auto p = dp[j][j + k];
					auto q = dp[j + k + 1][j + i];
					auto sum = prefix[j + i];
					if (j > 0)
						sum -= prefix[j - 1];

					dp[j][j + i] = min(dp[j][j + i], p + q + sum);
				}	

		cout << dp[0][K - 1] << "\n";
	}
}