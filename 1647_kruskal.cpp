#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct way {
	int a;
	int b;
	int c;

	bool operator< (const way& other) const {
		return c < other.c;
	}
};

int p[100001];
int rnk[100001];
vector<way> ways;

int find(int n) {
	if (n == p[n])
		return n;
	return p[n] = find(p[n]);
}

void uni(int input_a, int input_b) {
	int a = find(input_a);
	int b = find(input_b);

	if (a == b)
		return;

	if (rnk[a] < rnk[b]) p[a] = p[b];
	else if (rnk[a] > rnk[b]) p[b] = p[a];
	else {
		rnk[a]++;
		p[b] = p[a];
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, a, b, c, N, M;
	cin >> N >> M;

	for (i = 0; i < M; i++) {
		cin >> a >> b >> c;
		ways.push_back({ a, b, c});
	}

	for (i = 1; i <= N; i++)
		p[i] = i;

	sort(ways.begin(), ways.end());
	int cnt = 0, sum = 0;
	for (way w : ways) {
		int pa = find(w.a);
		int pb = find(w.b);
		if (pa == pb)
			continue;

		uni(pa, pb);
		cnt++;

		if (cnt == N - 1)
			break;
		else
			sum += w.c;
	}

	cout << sum;
}