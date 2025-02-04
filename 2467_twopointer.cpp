#include <iostream>
#include <cmath>
using namespace std;

int yong[100000];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, N, s, e, x, y, sum, min = 2147000000;
	cin >> N;
	s = 0;
	e = N - 1;
	for (i = 0; i < N; i++)
		cin >> yong[i];
	while (s < e) {
		sum = yong[s] + yong[e];
		if (min > abs(sum)) {
			min = abs(sum);
			x = s;
			y = e;
			if (sum == 0) break;
		}
		if (sum > 0) e--;
		else s++;
	}
	cout << yong[x] << " " << yong[y];
}