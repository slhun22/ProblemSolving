#include<iostream>
using namespace std;

int seq[100000];
int score[1000001];
bool chk[1000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, N, num;
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> seq[i];
		chk[seq[i]] = true;
	}

	for (i = 0; i < N; i++) {
		num = seq[i];
		for (j = 2; num * j <= 1000000; j++) { // 1000000/num 회 반복이므로 괜찮은거임
			if (chk[num * j]) {
				score[num]++;
				score[num * j]--;
			}
		}
	}

	for (i = 0; i < N; i++)
		cout << score[seq[i]] << " ";
}