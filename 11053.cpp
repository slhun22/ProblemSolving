#include<iostream>
using namespace std;

int N;
int seq[1001];
int cache[1001] = { 0, };

int GetLength(int idx) {
	if (idx == N)
		return 1;
	if (cache[idx]) {
		return cache[idx];
	}
	int max = 0;
	for (int i = idx + 1; i <= N; i++) {
		if (seq[idx] < seq[i]) {
			int length = GetLength(i);
			if (max < length)
				max = length;
		}
	}
	return cache[idx] = max + 1;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, max = -1;
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> seq[i];
	for (i = 1; i <= N; i++) {
		int length = GetLength(i);
		if (max < length)
			max = length;
	}
	cout << max;
}