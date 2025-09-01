#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int arr[4000000];
set<int> s;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M, K, n, i;
	cin >> N >> M >> K;
	for (i = 0; i < M; i++)
		cin >> arr[i];

	sort(arr, arr + i);
	s = set<int>(arr, arr + i);

	for (i = 0; i < K; i++) {
		cin >> n;
		auto it = s.upper_bound(n);
		cout << *it << "\n";
		s.erase(it);
	}
}