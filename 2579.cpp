#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, N, st[301], cache[301][2] = { 0, };//seq jump
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> st[i];
	cache[1][0] = st[1];
	cache[1][1] = st[1];
	for (i = 2; i <= N; i++) {
		cache[i][0] = cache[i - 1][1]+ st[i];
		cache[i][1] = max(cache[i - 2][0], cache[i - 2][1]) + st[i];
	}
	cout << max(cache[N][0], cache[N][1]);
}