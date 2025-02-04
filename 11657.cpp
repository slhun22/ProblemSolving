#include <iostream>
#include <vector>
#include <tuple>
#define INF 10000000000
//1과 연결되지 않은 여러 정점들끼리 마이너스 cycle을 형성하고 있다면 -1로 처리하면 안되므로 거리 갱신은 무조건 1이 닿은 적 있는 노드에서만 실행해야됨!!

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