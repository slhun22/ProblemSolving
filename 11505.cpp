#include<iostream>
#define MOD 1000000007
using namespace std;

long long seg[2000000];
int N;

void update(int idx, int num) {
	int p = N + idx - 1;
	seg[p] = num;
	p /= 2;
	while (p > 0) {
		seg[p] = (seg[p * 2] * seg[p * 2 + 1]) % MOD;
		p /= 2;
	}
}

int get(int a, int b) {
	a += N - 1;
	b += N - 1;
	long long res = 1;
	while (a <= b) {
		if (a % 2 == 1) {
			res = (res * seg[a]) % MOD;
			a++;
		}
		if (b % 2 == 0) {
			res = (res * seg[b]) % MOD;
			b--;
		}
		a /= 2;
		b /= 2;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> seg[N + i];

	for (int i = N - 1; i >= 1; i--)
		seg[i] = (seg[i * 2] * seg[i * 2 + 1]) % MOD;

	int a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else if (a == 2)
			cout << get(b, c) << "\n";
	}
}