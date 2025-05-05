#include<iostream>
#define INF 8100000
using namespace std;

int adj[801][801];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, E, i, j, k, first, second, a, b, c;
	cin >> N >> E;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			if (i != j)
				adj[i][j] = INF;

	for (i = 0; i < E; i++) {
		cin >> a >> b >> c;
		adj[a][b] = c;
		adj[b][a] = c;
	}
	cin >> first >> second;

	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++) 
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	int mindist = min(adj[1][first] + adj[first][second] + adj[second][N], adj[1][second] + adj[second][first] + adj[first][N]);
	if (mindist >= INF)
		mindist = -1;

	cout << mindist;
}