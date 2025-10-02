#include<iostream>
using namespace std;

int maxseg[200001];
int minseg[200001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, N, M, a, b, temp;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> temp;
		minseg[N + i] = temp;
		maxseg[N + i] = temp;
	}
	
	for (i = N - 1; i >= 1; i--) {
		minseg[i] = min(minseg[i * 2], minseg[i * 2 + 1]);
		maxseg[i] = max(maxseg[i * 2], maxseg[i * 2 + 1]);
	}		

	for (i = 0; i < M; i++) {
		cin >> a >> b;
		a += N - 1;
		b += N - 1;
		int minv = 1000000001;
		int maxv = 0;
		while (a <= b) {
			if (a % 2) {
				minv = min(minv, minseg[a]);
				maxv = max(maxv, maxseg[a]);
				a++;
			}

			if (!(b % 2)) {
				minv = min(minv, minseg[b]);
				maxv = max(maxv, maxseg[b]);
				b--;
			}

			a /= 2;
			b /= 2;
		}

		cout << minv << " " << maxv << "\n";
	}
}