#include<iostream>
#include<algorithm>
using namespace std;

int c[51];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, K, j;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		c[i] = i < (N / 2);

	for (int i = 0; i < K; i++) {
		for (j = 0; j < N - 1; j++) {
			if (c[j] == 1 && c[j + 1] == 0) {
				swap(c[j], c[j + 1]);
				break;
			}
		}

		if (j == N - 1) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i < N; i++)
		cout << (char)('A' + c[i]);
}