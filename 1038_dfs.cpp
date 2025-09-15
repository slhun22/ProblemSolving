#include<iostream>
#include<cmath>
using namespace std;

int idx = -1, N;
long long ans = -1;
bool finished = false;
bool used[11];

void dfs(int digit, long long num, int before) {
	if (finished)
		return;
	if (digit == 0) {
		if (before != -1) {
			idx++;
			if (idx == N) {
				ans = num;
				finished = true;
			}
		}
		return;
	}
	
	int start = 0;
	if (!used[digit]) {
		used[digit] = true;
		start = -1;
	}

	for (int i = start; i < 10; i++) {
		long long plus = (i == -1) ? 0 : i * pow(10, digit - 1);
		if (before == -1 || i < before)
			dfs(digit - 1, num + plus, i);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	dfs(10, 0, -1);
	cout << ans;
}