#include<iostream>
#include<queue>
using namespace std;
int main() {
    pair<int, int> toy[25000];//joy price
    priority_queue<pair<float, int>>pq;//ratio idx
    int ans[3];
    int i, N, j, p, total = 0;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> j >> p;
        toy[i] = make_pair(j, p);
        pq.push(make_pair((float)j / p, i));
    }
    for (i = 0; i < 3; i++) {
        auto top = pq.top();
        ans[i] = top.second + 1;
        total += toy[top.second].second;
        pq.pop();
    }
    cout << total << "\n";
    for (i = 0; i < 3; i++)
        cout << ans[i] << "\n";
}