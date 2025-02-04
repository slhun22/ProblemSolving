#include <iostream>
#include <algorithm>
using namespace std;

long long yong[5000];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int N, i, m, s, e;
	int ans[3];
	long long min = 1e18, sum;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> yong[i];
	sort(yong, yong + N);
	for (m = 0; m < N - 2; m++) {
		s = m + 1;
		e = N - 1;
		while (s < e) {
			sum = yong[m] + yong[s] + yong[e];
			if (min > abs(sum)) {
				min = abs(sum);
				ans[0] = m;
				ans[1] = s;
				ans[2] = e;
			}
			if (sum > 0)
				e--;
			else
				s++;
		}
	}
	cout << yong[ans[0]] << " " << yong[ans[1]] << " " << yong[ans[2]];
}
