#include<iostream>
#define MOD 1000000007
using namespace std;

int field[1000][1000];
int cache[1000][1000] = {};

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int i, j, k, M, N;
	long long sum = 0;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> field[i][j];
			if (i == 0)
				cache[i][j] = field[i][j];
		}
	}
	for (i = 1; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (field[i][j] == 1) {
				for (k = -1; k < 2; k++) {
					if (j + k >= 0 && j + k < M) {
						cache[i][j] += cache[i - 1][j + k] % MOD;
						cache[i][j] %= MOD;
					}
				}
			}
		}
	}
	for (j = 0; j < M; j++) {
		sum += cache[i - 1][j];
		sum %= MOD;
	}
	cout << sum;
}