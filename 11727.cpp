#include<iostream>
#include<vector>
#define MOD 10007
using namespace std;

vector<vector<int>> comb;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j, n, a, b, temp, ans = 0;

	comb.emplace_back(vector<int>());//dummy
	comb.emplace_back(vector<int>(2, 1));
	for(i = 2; i <= 1000; i++) {
		comb.emplace_back(vector<int>(i + 1, 1));
		for (j = 1; j < i; j++)
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
	}

	cin >> n;
	a = n;
	b = 0;
	while(a >= b) {
		temp = comb[a][b];
		for (i = 0; i < b; i++)
			temp = (temp * 2) % MOD;

		ans = (ans + temp) % MOD;
		a--;
		b++;
	}

	cout << ans;
}