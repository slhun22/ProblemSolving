#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int getcnt(long long bit, int length) {
	int cnt = 0;
	for (int i = 0; i < length; i++)
		cnt += (bit >> i) & 1;
	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j, N, M;
	long long g[10];
	string s;
	cin >> N >> M;

	for (i = 0; i < N; i++) {
		cin >> s >> s;
		for (j = 0; j < M; j++)
			g[i] = (g[i] << 1) | (s[j] == 'Y');
	}

	pair<int, int> ans = { 0, -1 };
	for (i = 0; i < (1 << N); i++) {
		long long song = 0;
		for (j = 0; j < N; j++)
			if (i & (1 << j))
				song |= g[j];

		int scnt = getcnt(song, M);
		int gcnt = getcnt(i, N);
		if (ans.first < scnt)
			ans = { scnt, gcnt };
		else if (ans.first == scnt && ans.second > gcnt)
			ans.second = gcnt;
	}

	cout << ans.second;
}