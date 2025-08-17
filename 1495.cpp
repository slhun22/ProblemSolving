#include<iostream>

using namespace std;

int N, M, v[50], dp[50][1001], maxv = -1;

void func(int idx, int sum) {
	if (idx == N) {
		if(0 <= sum && sum <= M && sum > maxv)
			maxv = sum;
		return;
	}
	if (dp[idx][sum])
		return;

	dp[idx][sum] = 1;
	int up = sum + v[idx];
	int down = sum - v[idx];
	if (up <= M) func(idx + 1, up);
	if (down >= 0) func(idx + 1, down);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, S;
	cin >> N >> S >> M;
	for (i = 0; i < N; i++)
		cin >> v[i];

	func(0, S);
	cout << maxv;
}