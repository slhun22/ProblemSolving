#include <iostream>
#define MAX 1e18
using namespace std;
typedef long long ll;
ll field[1001][1001];
//다익스트라로 푸는 것이 더 빠르긴 하다
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, M, X, a, b, t, i, j, k;
	ll max_time = -1;
	cin >> N >> M >> X;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			field[i][j] = MAX;
		}
	}
	for (i = 1; i <= N; i++) {
		field[i][i] = 0;
	}
	for (i = 0; i < M; i++) {
		cin >> a >> b >> t;
		field[a][b] = t;
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for(k = 1; k <= N; k++) {
				field[j][k] = min(field[j][k], field[j][i] + field[i][k]);
			}
		}
	}
	for (i = 1; i <= N; i++) {
		max_time = max(max_time, field[i][X] + field[X][i]);
	}
	cout << max_time;
}