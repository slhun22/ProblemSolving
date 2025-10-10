#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<>> pq; //head∏¶ ≥÷¿Ω

struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, i, a, b, L;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);

		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), cmp());

	cin >> L;

	int ans = -1;
	for (auto& it : v) {
		int h = it.first;
		int t = it.second;
		pq.push(h);

		int border = t - L;
		while (!pq.empty() && pq.top() < border)
			pq.pop();

		ans = max(ans, static_cast<int>(pq.size()));
	}

	cout << ans;
}