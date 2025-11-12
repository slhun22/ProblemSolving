#include<iostream>
using namespace std;

int N, ans = -2140000000;
char a[23];//Â¦¼ö¿¡ ±âÈ£

int calc(int a, int b, char op) {
	if (op == '+')
		return a + b;
	else if (op == '*')
		return a * b;
	else if (op == '-')
		return a - b;
	else
		return 0;
}

void dfs(int idx, int res, char op) {
	if (idx > N) {
		ans = max(ans, res);
		return;
	}

	dfs(idx + 2, calc(res, a[idx] - '0', op), a[idx + 1]);
	if (idx < N - 1) {
		int first = calc(a[idx] - '0', a[idx + 2] - '0', a[idx + 1]);
		dfs(idx + 4, calc(res, first, op), a[idx + 3]);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin >> N >> s;
	for (int i = 1; i <= N; i++)
		a[i] = s[i - 1];

	dfs(1, 0, '+');
	cout << ans;
}