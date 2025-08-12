#include<iostream>
using namespace std;

int comb[201][201];
int K;

void func(int n, int r) {
	if (n == 1) {
		if (r == 1) cout << 'a';
		else cout << 'z';
		return;
	}

	int cnt = comb[n - 1][r - 1];
	if (cnt == -1) 
		cnt = 1000000001;

	if (cnt >= K) {
		cout << 'a';
		func(n - 1, r - 1);
	}
	else {
		cout << 'z';
		K -= cnt;
		func(n - 1, r);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, i, j;
	cin >> N >> M >> K;

	for (i = 1; i <= N + M; i++)
		comb[i][0] = comb[i][i] = 1;
	
	for (i = 2; i <= N + M; i++) {
		for (j = 1; j < i; j++) {
			if (comb[i - 1][j - 1] == -1 || comb[i - 1][j] == -1)
				comb[i][j] = -1;
			else {
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
				if (comb[i][j] > 1000000000) {
					comb[i][j] = -1;
				}
			}		
		}
	}

	if (comb[N + M][N] == -1 || comb[N + M][N] >= K)
		func(N + M, N);
	else
		cout << -1;
}