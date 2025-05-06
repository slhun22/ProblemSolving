#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

bitset<4000001> b;
vector<int> cumulsum;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i,j,N, l, r, sum, cnt = 0;
	cin >> N;
	b.set(1);
	for (i = 2; i <= N; i++) {
		if (b[i]) continue;
		for (j = i * 2; j <= N; j += i)
			b.set(j);
	}
	cumulsum.push_back(0);
	for (i = 2; i <= N; i++) {
		if (!b[i])
			cumulsum.push_back(cumulsum.back() + i);
	}
	l = r = 1;
	int size = cumulsum.size();		
	while (size) {
		sum = cumulsum[r] - cumulsum[l - 1];
		if (sum <= N) {
			if (sum == N) cnt++;
			if (r + 1 < size) r++;
			else break;
		}
		else {
			if (l + 1 < size) l++;
			else break;
		}
	}
	cout << cnt;
}