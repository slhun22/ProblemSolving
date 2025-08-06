#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[4][4000];
vector<int> v[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, p, q;
    cin >> n;

    for (i = 0; i < n; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> arr[j][i];

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j) {
            v[0].push_back(arr[0][i] + arr[1][j]);
            v[1].push_back(arr[2][i] + arr[3][j]);
        }

    sort(v[0].begin(), v[0].end()); //오름차순
    sort(v[1].begin(), v[1].end(), greater<int>()); //내림차순

    long long cnt = 0;
    p = q = 0;
    while (p < v[0].size() && q < v[1].size()) {
        int sum = v[0][p] + v[1][q];

        if (sum == 0) {
            long long cnt_p = 1, cnt_q = 1;
            while (p + 1 < v[0].size() && v[0][p] == v[0][p + 1]) {
                cnt_p++;
                p++;
            }
            while (q + 1 < v[1].size() && v[1][q] == v[1][q + 1]) {
                cnt_q++;
                q++;
            }

            cnt += cnt_p * cnt_q;
            p++;
            q++;
        }
        else if (sum < 0) ++p;
        else ++q;
    }

    cout << cnt;
}