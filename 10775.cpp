#include<iostream>
using namespace std;

int pv[100001];
int parent[100001];

int FindParent(int n) {
	if (parent[n] == n)
		return parent[n];
	return parent[n] = FindParent(parent[n]);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, G, P;
	cin >> G >> P;
	for (i = 1; i <= P; i++)
		cin >> pv[i];
	for(i = 1; i <= G; i++)
		parent[i] = i;
	for (i = 1; i <= P; i++) {
		int par = FindParent(pv[i]);
		if (par) parent[par]--;
		else break;
	}
	cout << i - 1;
}
