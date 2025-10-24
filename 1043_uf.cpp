#include<iostream>
#include<vector>
using namespace std;

int p[51];
int rnk[51];
vector<int> party[51];

int find(int n) {
	if (n == p[n])
		return n;
	return p[n] = find(p[n]);
}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb)
		return;

	if (rnk[pa] == rnk[pb])
		rnk[pa]++;

	if (rnk[pa] > rnk[pb])
		p[pb] = pa;
	else
		p[pa] = pb;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int M, N, R, temp, before = -1;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		p[i] = i;

	cin >> R;
	for (int i = 0; i < R; i++) {
		cin >> temp;
		if (before != -1)
			uni(before, temp);
		before = temp;
	}
	int know_parent = find(before);

	for (int i = 1; i <= M; i++) {
		cin >> R;
		before = -1;
		for (int j = 0; j < R; j++) {
			cin >> temp;
			party[i].push_back(temp);
			if (before != -1)
				uni(before, temp);
			before = temp;
		}
	}

	int ans = 0;
	for (int i = 1; i <= M; i++) {
		int hasKnows = false;
		for (auto person : party[i]) {
			if (find(person) == find(know_parent)) {
				hasKnows = true;
				break;
			}
		}

		if (!hasKnows)
			ans++;
	}

	cout << ans;
}