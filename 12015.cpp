#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> res;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, i, n;
	cin >> N;
	cin >> n;
	res.push_back(n);
	for (i = 1; i < N; i++) {
		cin >> n;
		if (res.back() < n)
			res.push_back(n);
		else
			*lower_bound(res.begin(), res.end(), n) = n;
	}

	cout << res.size();
}