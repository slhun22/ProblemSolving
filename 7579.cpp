#include<iostream>
using namespace std;

int cache[10001] = {};

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, M, i, j, sum = 0, m[101], c[101];
	cin >> N >> M;
	for (i = 1; i <= N; i++)
		cin >> m[i];
	for (i = 1; i <= N; i++) {
		cin >> c[i];
		sum += c[i];
	}
	for (i = 1; i <= N; i++)
		for (j = sum; j >= c[i]; j--)
			cache[j] = max(cache[j], cache[j - c[i]] + m[i]);
	for (i = 0; i <= sum; i++) {
		if (cache[i] >= M) {
			cout << i;
			break;
		}
	}
}