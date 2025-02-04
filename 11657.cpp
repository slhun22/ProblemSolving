#include <iostream>
#include <vector>
#include <tuple>
#define INF 10000000000
//1�� ������� ���� ���� �����鳢�� ���̳ʽ� cycle�� �����ϰ� �ִٸ� -1�� ó���ϸ� �ȵǹǷ� �Ÿ� ������ ������ 1�� ���� �� �ִ� ��忡���� �����ؾߵ�!!

using namespace std;

vector<tuple<int, int, int>> edge;
long long dp[501];
int N, M;
bool minusCycle, hasPath;

bool PathFinder()
{
    int i, j, src, dest;
    long long curW, plusW;
    for (i = 0; i < N; i++)
    {
        for (auto iter : edge)
        {
            src = get<0>(iter);
            dest = get<1>(iter);
            curW = dp[src];
            plusW = get<2>(iter);
            if (dp[dest] > curW + plusW && dp[src] != INF)
            {
                dp[dest] = curW + plusW;
                if (i == N - 1)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int i, A, B, C;
    cin >> N >> M;

    for (i = 1; i <= N; i++)
        dp[i] = INF;

    for (i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        edge.push_back(make_tuple(A, B, C));
    }

    dp[1] = 0;

    if (PathFinder())
    {
        for (i = 2; i <= N; i++)
        {
            if (dp[i] == INF)
                cout << -1 << "\n";
            else
                cout << dp[i] << "\n";
        }
    }
    else
        cout << -1;
}