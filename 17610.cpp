#include<iostream>
#include<vector>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int K, S = 0, chu[13] = {}, loop[13] = {}, sum, i, cnt = 0;
	cin >> K;
	for (i = 0; i < K; i++) {
		cin >> chu[i];
		S += chu[i];
	}
	vector<bool> cache(S + 1);
	for (loop[0] = -1; loop[0] < 2; loop[0]++)
		for (loop[1] = -1; loop[1] < 2; loop[1]++)
			for (loop[2] = -1; loop[2] < 2; loop[2]++)
				for (loop[3] = -1; loop[3] < 2; loop[3]++)
					for (loop[4] = -1; loop[4] < 2; loop[4]++)
						for (loop[5] = -1; loop[5] < 2; loop[5]++)
							for (loop[6] = -1; loop[6] < 2; loop[6]++)
								for (loop[7] = -1; loop[7] < 2; loop[7]++)
									for (loop[8] = -1; loop[8] < 2; loop[8]++)
										for (loop[9] = -1; loop[9] < 2; loop[9]++)
											for (loop[10] = -1; loop[10] < 2; loop[10]++)
												for (loop[11] = -1; loop[11] < 2; loop[11]++)
													for (loop[12] = -1; loop[12] < 2; loop[12]++) {
														sum = 0;
														for (i = 0; i < K; i++)
															sum += chu[i] * loop[i];		
														if (sum > 0) {
															cache[sum] = true;
														}													
													}
	for (i = 1; i <= S; i++)
		if (!cache[i])
			cnt++;
	cout << cnt;
}