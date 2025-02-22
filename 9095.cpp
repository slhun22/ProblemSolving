#include<iostream>
#include<vector>
using namespace std;

struct Comb {
	int one;
	int two;
	int three;

	Comb operator+(const Comb& x) {
		return { one + x.one, two + x.two, three + x.three };
	}

	bool Okay(int j) {
		if (j == 2)
			return one == 0;
		else if (j == 3)
			return one == 0 && two == 0;
		return true;
	}
};

int f[11] = { 1, };
vector<Comb> cache[11];

int GetCnt(Comb c) {
	return f[c.one + c.two + c.three] / (f[c.one] * f[c.two] * f[c.three]);
}

int main() {
	int i, j, T, N, cnt;
	Comb base[4] = { {0,0,0}, { 1,0,0 },{0,1,0},{0,0,1} };
	for (i = 1; i <= 10; i++)
		f[i] = f[i - 1] * i;
	cache[1].push_back(base[1]);
	cache[2].push_back(base[2]);
	cache[3].push_back(base[3]);

	for (i = 2; i <= 10; i++) {
		for (j = 1; j <= 3; j++) {
			if (i - j > 0) {
				for (Comb& iter : cache[i - j]) {
					if(iter.Okay(j))
						cache[i].push_back(base[j] + iter);
				}
			}
		}
	}
	cin >> T;
	while (T-- > 0) {
		cin >> N;
		cnt = 0;
		for (auto& comb : cache[N])
			cnt += GetCnt(comb);
		cout << cnt << "\n";
	}
}