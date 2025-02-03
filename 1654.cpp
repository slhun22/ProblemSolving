#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int K, N, i, max = -1, cnt;
	ll s = 1, e = -1, m;
	int o[10000];
	cin >> K >> N;
	for (i = 0; i < K; i++) {
		cin >> o[i];
		if (e < o[i])
			e = o[i];
	}
	while (s <= e) {
		m = (s + e) / 2;
		cnt = 0;
		for (i = 0; i < K; i++)
			cnt += o[i] / m;
		if (cnt >= N) {
			s = m + 1;
			max = m;
		}
		else
			e = m - 1;
	}
	cout << max;
}