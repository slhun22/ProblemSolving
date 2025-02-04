#include <iostream>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int i, j, N, big = -1, before = -1, current, least = -1;
	bool impossible;
	long long S, sum, max;
	int seq[100000];
	int cache[100001];
	cin >> N >> S;

	for (i = 0; i < N; i++)
		cin >> seq[i];

	cache[0] = 0;
	for (i = 1; i <= N; i++) //Fill Cache
		cache[i] = cache[i - 1] + seq[i - 1];

	current = N;
	while (before != current) {
		before = current;
		impossible = false;
		if (current <= least)
			impossible = true;
		else {
			max = -1;
			for (i = 0; i < N - current + 1; i++) {
				sum = cache[i + current] - cache[i];
				if (max < sum)
					max = sum;
			}
			if (S <= max) {
				big = current;
				current /= 2;
			}
			else {
				impossible = true;
			}
		}	

		if (impossible) {
			if (big == -1) {
				current = -1;
				break;
			}
			else {
				least = current;
				current = (big + current) / 2;
			}
		}
	}

	cout << current + 1;
}