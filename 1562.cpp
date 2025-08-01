#include<iostream>
#include<vector>
#define MOD 1000000000

using namespace std;
int N;
vector<vector<vector<int>>> dp(10, vector<vector<int>>(100, vector<int>(1 << 10, -1)));
//대가리 숫자, 수의 길이, 현재 0~9 마킹 상태
//이와 같이 값이 아닌 특정 "상태"에 대한 dp값을 저장해야할 때는 비트로 상태를 나타낸다. 0000010110 = 1, 2, 4를 포함하고 있다는 뜻

int func(int head, int idx, int visit) {
	if (idx == N)
		return visit == (1 << 10) - 1;
	
	if (dp[head][idx][visit] != -1)
		return dp[head][idx][visit];

	int result = 0;
	if (head > 0)
		result = (result + func(head - 1, idx + 1, visit | (1 << head - 1))) % MOD;
	if (head < 9)
		result = (result + func(head + 1, idx + 1, visit | (1 << head + 1))) % MOD;

	return dp[head][idx][visit] = result;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	int sum = 0;
	for (int i = 1; i < 10; i++)
		sum = (sum + func(i, 1, 1 << i)) % MOD;

	cout << sum;
}