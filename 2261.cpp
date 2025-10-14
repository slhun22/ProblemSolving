#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2140000000
using namespace std;

vector<pair<int, int>> v;

struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
};

int dist(pair<int, int>& a, pair<int, int>& b) {
	int xdiff = b.first - a.first;
	int ydiff = b.second - a.second;
	return xdiff * xdiff + ydiff * ydiff;
}

int mindist(int first, int last) {
	int size = last - first + 1;
	if (size == 1)
		return INF;
	if (size == 2)
		return dist(v[first], v[last]);

	int mid = (first + last) / 2;
	int minv = min(mindist(first, mid), mindist(mid + 1, last));

	vector<pair<int, int>> able;
	able.reserve(size);
	int div = (v[mid].first + v[mid + 1].first) / 2;
	for (int i = first; i <= last; i++) {
		int diff = v[i].first - div;
		if (diff * diff < minv)
			able.push_back(v[i]);
	}

	sort(able.begin(), able.end(), cmp());
	int len = able.size();
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			int diff = able[j].second - able[i].second;
			if (diff * diff >= minv)
				break;

			minv = min(minv, dist(able[i], able[j]));
		}
	}

	return minv;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, i, a, b;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}

	sort(v.begin(), v.end());
	cout << mindist(0, v.size() - 1);
}