#include<iostream>
using namespace std;

int parent[500000];
int ranks[500000] = {};

int Find(int v) {
	if (parent[v] == v)
		return v;
	return parent[v] = Find(parent[v]);
}

bool Union(int v1, int v2) {
	int root1 = Find(v1);
	int root2 = Find(v2);
	if (root1 == root2) {
		return false;
	}
	else {
		if (ranks[root1] == ranks[root2]) {
			ranks[root1]++;
			parent[root2] = root1;
		}
		else if (ranks[root1] > ranks[root2])
			parent[root2] = root1;
		else
			parent[root1] = root2;
	}	
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, i, j, a, b;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		if (!Union(a, b)) {
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;
}