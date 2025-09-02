#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int p[100000];
int rnk[100000];
vector<pair<int, int>> v[3];
vector<pair<int, pair<int, int>>> e;

int find(int n) {
	if (p[n] == n)
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

	if (rnk[pa] < rnk[pb])
		p[pa] = pb;
	else
		p[pb] = pa;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N, i, j, x, y, z;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> x >> y >> z;
		v[0].push_back({ x, i });
		v[1].push_back({ y, i });
		v[2].push_back({ z, i });
	}

	for (i = 0; i < 3; i++)
		sort(v[i].begin(), v[i].end());

	for (i = 0; i < N - 1; i++)
		for(j = 0 ; j < 3; j++)
			e.push_back({ abs(v[j][i].first - v[j][i + 1].first), {v[j][i].second, v[j][i + 1].second} });

	for (i = 0; i < N; i++)
		p[i] = i;

	long long sum = 0;
	int cnt = 0;
	sort(e.begin(), e.end());
	for (auto& [cost, nodes] : e) {
		int a = nodes.first;
		int b = nodes.second;

		if (find(a) == find(b))
			continue;

		uni(a, b);
		sum += cost;
		if (++cnt == N - 1)
			break;
	}

	cout << sum;
} 