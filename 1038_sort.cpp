#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> v;

void dfs(long long num) {
	v.push_back(num);
	for (int i = 0; i < 10; i++) {
		if (num % 10 > i)
			dfs(num * 10 + i);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 10; i++)
		dfs(i);

	int N;
	cin >> N;
	if (N >= v.size())
		cout << -1;
	else {
		sort(v.begin(), v.end());
		cout << v[N];
	}
}