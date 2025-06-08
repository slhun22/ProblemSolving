#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int f(int i) {
	if (i == 0)
		return 1;
	return i * f(i - 1);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, N, M, cnt = 0;
	cin >> N >> M;
	int fact = f(N - M);
	vector<int> v;
	for (i = 1; i <= N; i++)
		v.push_back(i);
	do {
		if (!(cnt++ % fact)) {
			for (i = 0; i < M; i++)
				cout << v[i] << " ";
			cout << "\n";
		}
	} while (next_permutation(v.begin(), v.end()));
}