#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, i;
	cin >> N >> M;
	vector<int> v(N, 1);
	for (i = 0; i < M; i++)
		v[i] = 0;

	do {
		for (i = 0; i < N; i++) {
			if (v[i] == 0)
				cout << i + 1 << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
}