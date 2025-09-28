#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sumA[1000][1000];
int sumB[1000][1000];
vector<int> A, B;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T, n, m, i, j;
	cin >> T >> n;
	for (i = 0; i < n; i++) {
		cin >> sumA[i][i];
		A.push_back(sumA[i][i]);
	}

	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> sumB[i][i];
		B.push_back(sumB[i][i]);
	}

	for (i = 1; i < n; i++) //간격
		for (j = 0; j + i < n; j++) {
			sumA[j][j + i] = sumA[j][j + i - 1] + sumA[j + i][j + i];
			A.push_back(sumA[j][j + i]);
		}


	for (i = 1; i < m; i++) //간격
		for (j = 0; j + i < m; j++) {
			sumB[j][j + i] = sumB[j][j + i - 1] + sumB[j + i][j + i];
			B.push_back(sumB[j][j + i]);
		}

	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());

	int p, q;
	p = q = 0;
	long long cnt = 0;
	while (p < A.size() && q < B.size()) {
		int a = A[p];
		int b = B[q];

		if (a + b > T)
			q++;
		else if (a + b < T)
			p++;
		else {
			long long cntA = 0, cntB = 0;

			while (p < A.size() && A[p] == a) {
				cntA++;
				p++;
			}
			while (q < B.size() && B[q] == b) {
				cntB++;
				q++;
			}

			cnt += cntA * cntB;
		}
	}

	cout << cnt;
}