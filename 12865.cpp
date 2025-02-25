#include<iostream>
using namespace std;

int cache[101][100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, K, i, j, w, v;
    pair<int, int> obj[101];//<w,v>
	cin >> N >> K;
	for (i = 1; i <= N; i++)
		cin >> obj[i].first >> obj[i].second;

	for (i = 0; i <= K; i++)
		cache[0][i] = 0;

	for (i = 1; i <= N; i++) {
		w = obj[i].first;
		v = obj[i].second;
		for (j = 0; j <= K; j++) {			
			if (j - w >= 0)
				cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - w] + v);
			else
				cache[i][j] = cache[i - 1][j];
		}
	}
	cout << cache[N][K];
}