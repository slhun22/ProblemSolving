#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>>vertex[20001];
int dist[20001];
bool visited[20001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<pair<int, int>> q;
	int V, E, S, i, j, u, v, w, cur, next, curW, plusW;
	cin >> V >> E >> S;

	for (i = 1; i < 20001; i++)
		dist[i] = 2147300000;

	for (i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair( v, w ));
	}

	////// {->노드번호, w}
	
	dist[S] = 0;
	q.push(make_pair(0, S));
	
	while (!q.empty())
	{
		curW = -q.top().first;
		cur = q.top().second;
		visited[cur] = true;
		q.pop();
		int length = vertex[cur].size();

		for (i = 0; i < length; i++)
		{
			next = vertex[cur][i].first;
			if (visited[next])
				continue;
			plusW = vertex[cur][i].second;

			if (dist[next] > curW + plusW)
			{
				dist[next] = curW + plusW;
				q.push(make_pair(-dist[next], next));
			}
		}
	}	

	for (i = 1; i <= V; i++)
	{
		if (dist[i] == 2147300000)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}