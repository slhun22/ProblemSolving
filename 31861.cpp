#include<iostream>
#define MOD 1000000007
using namespace std;

int cache[27][1001];
int N, M;

int dp(int n, int depth) {
	if (cache[n][depth] != -1)
		return cache[n][depth];
	int cnt = 0, sub = N;
	if (N == 0)
		sub++;

	while (n - sub > 0) {
		cnt += dp(n - sub, depth - 1) % MOD;
		cnt %= MOD;
		sub++;
	}
	sub = N;
	while (n + sub < 27) {
		cnt += dp(n + sub, depth - 1) % MOD;
		cnt %= MOD;
		sub++;
	}
	return cache[n][depth] = cnt;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, j, cnt = 0, depth = 1;
	cin >> N >> M;
	for (i = 1; i <= 26; i++)
		for (j = 0; j <= 1000; j++) {
			if (j == 0)
				cache[i][j] = 1;
			else
				cache[i][j] = -1;
		}	
	for (i = 1; i <= 26; i++) {
		cnt += dp(i, M - 1) % MOD;
		cnt %= MOD;
	}
	cout << cnt;
}