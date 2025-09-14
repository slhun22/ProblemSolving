#include<iostream>
#include<unordered_map>
using namespace std;

long long N, P, Q;
unordered_map<long long, long long> m;

long long dfs(long long n) {
	if (n == 0)
		return 1;
	if (m.find(n) != m.end())
		return m[n];

	return m[n] = dfs(n / P) + dfs(n / Q);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> P >> Q;
	cout << dfs(N);
}