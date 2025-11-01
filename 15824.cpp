#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1000000007
using namespace std;

vector<int> v;
long long mul[300000];

//최소 최대의 pair에 집착하지 말고, 각 값을 최대로 사용하는 조합의 개수, 최소로 사용하는 조합의 개수로 독립적으로 계산해서 최대는 더하고 최소는 빼는 아이디어가 핵심임
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, N,n;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> n;
		v.push_back(n);
	}
	
	long long temp = 1;
	for (i = 0; i < N; i++) {
		mul[i] = temp;
		temp = (temp * 2) % MOD;
	}

	sort(v.begin(), v.end());

	long long sum = 0;
	for (i = 0; i < N; i++) {
		int maxcnt = i;
		int mincnt = N - i - 1;
		sum = (sum + (v[i] * mul[maxcnt]) % MOD) % MOD;
		sum = (sum - (v[i] * mul[mincnt]) % MOD + MOD) % MOD;
	}

	cout << sum;
}