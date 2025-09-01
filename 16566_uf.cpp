#include<iostream>
using namespace std;

int p[4000001];

int find(int n) {
	if (p[n] == n)
		return n;
	return p[n] = find(p[n]);
}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	p[pa] = pb;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, K, n, i;
	cin >> N >> M >> K;
	for (i = 0; i < M; i++) {
		cin >> n;
		p[n] = n;
	}

	for (i = N; i > 0; i--) {
		if (p[i] == i)
			n = i;
		else
			p[i] = n;
	}

	for (i = 0; i < K; i++) {
		cin >> n;
		int p = find(n + 1);
		cout << p << "\n";
		uni(p, p + 1);
	}
}