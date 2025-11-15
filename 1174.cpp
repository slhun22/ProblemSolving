#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<long long> v;

void func(long long n) {
	int end = n % 10;
	for (int i = 0; i < end; i++) {
		long long next = n * 10 + i;
		v.push_back(next);
		func(next);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		func(i);
	}

	if (N > v.size())
		cout << -1;
	else {
		sort(v.begin(), v.end());
		cout << v[N - 1];
	}
}