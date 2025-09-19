#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int arr[100001];
pair<int,int> seg[400000];

void build(int node, int l, int r) {
	if (l == r) {
		seg[node] = {arr[l], l};
		return;
	}
	int m = (l + r) / 2;
	build(node * 2, l, m);
	build(node * 2 + 1, m + 1, r);
	if (seg[node * 2] < seg[node * 2 + 1])
		seg[node] = seg[node * 2];
	else
		seg[node] = seg[node * 2 + 1];
}

int get_min() {
	return seg[1].second;
}

void update(int node, int idx, int val, int l, int r) {
	if (l == r) {
		seg[node] = { val, l };
		return;
	}

	int m = (l + r) / 2;
	if (idx <= m)
		update(node * 2, idx, val, l, m);
	else
		update(node * 2 + 1, idx, val, m + 1, r);

	if (seg[node * 2] < seg[node * 2 + 1])
		seg[node] = seg[node * 2];
	else
		seg[node] = seg[node * 2 + 1];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, i;
	cin >> N;
	for (i = 1; i <= N; i++)
		cin >> arr[i];

	build(1, 1, N);

	cin >> M;
	cin.ignore();
	string s;
	for (i = 0; i < M; i++) {
		getline(cin, s);
		if (s[0] == '1') {
			stringstream ss(s.substr(2));
			int idx, val;
			ss >> idx >> val;
			update(1, idx, val, 1, N);
		}
		else if (s[0] == '2')
			cout << get_min() << "\n";
	}
}