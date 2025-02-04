#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
int unf[1001];
vector<tuple<int, int, int>> e;

int Find(int myV)
{
	if (unf[myV] != myV)
	{
		int x = Find(unf[myV]);
		unf[myV] = x;
		return x;
	}
	else
		return myV;
}

void Union(int v1, int v2)
{
	unf[Find(v2)] = Find(v1);
}


bool compare(tuple<int, int, int> a, tuple<int, int, int> b)
{
	int valueA = get<2>(a);
	int valueB = get<2>(b);

	return valueA < valueB;
}

int Kruskal()
{
	int result = 0;
	for (auto& iter : e)
	{
		int a, b, c;
		tie(a, b, c) = iter;
		if (Find(a) != Find(b))
		{
			Union(a, b);
			result += c;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, a, b , c;
	cin >> N >> M;

	for (i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		e.push_back(tie(a, b, c));
	}
	for (i = 1; i <= N; i++)
		unf[i] = i;

	sort(e.begin(), e.end(), compare);

	cout << Kruskal();
}
