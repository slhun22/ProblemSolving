#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int ,int>> graph[10001]; //cost v
priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;
bool visited[10001] = { false, true, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int E, V, cnt = 1, sum = 0, a, b, c;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
		graph[b].push_back(make_pair(c, a));
	}
	for (auto edge : graph[1]) {
		pq.push(edge);
	}
	while (cnt < V) {
		auto p = pq.top();
		pq.pop();
		if (!visited[p.second]) {
			visited[p.second] = true;
			cnt++;
			sum += p.first;
			for (auto e : graph[p.second]) {
				if(!visited[e.second])
					pq.push(e);
			}
		}
	}
	cout << sum;
}