#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator() (const pair<int ,int>& a, const pair<int, int>& b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, N, s, e, cnt = 0, last = -1;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> s >> e;
		pq.push(make_pair(s, e));
	}
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (last <= p.first) {
			cnt++;
			last = p.second;
		}
	}
	cout << cnt;
}