#include <iostream>
#include <tuple>
#include <unordered_map>
using namespace std;

int V, E;
int visited[10000];
unordered_map<int, pair<int, int>> e; //v1      v2, cost

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	int i, a, b, c;

	for (i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		e[a] = { b, c };
		e[b] = { a, c };
	}
		
	visited[0] = 1;
	for (i = 0; i < V - 1; i++)
	{
		int min = INT_MAX;
		
	}
}