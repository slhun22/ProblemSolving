#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int yong[100000];
int start;
int N;

pair<int ,int> BinarySearch(int num, int s, int e) {
	if (e - s < 3) {
		int min = 2147000000;
		int sum, index;
		int init = max(start, s - 1);
		int last = std::min(N - 1, e + 1);
		for (int i = init; i <= last; i++) {
			sum = abs(num + yong[i]);
			if (min > sum) {
				min = sum;
				index = i;
			}			
		}
		return make_pair(index, min);
	}
	else {
		int mid = (s + e) / 2;
		if (yong[mid] < -num) {
			return BinarySearch(num, mid + 1, e);
		}
		else if (yong[mid] > -num) {
			return BinarySearch(num, s, mid - 1);
		}
		else if (yong[mid] == -num) {
			return make_pair(mid, 0);
		}
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int i, j, flag = 1;
	cin >> N;
	start = N;

	for (i = 0; i < N; i++) {
		cin >> yong[i];
		if (flag && yong[i] > 0) {
			flag = 0;
			start = i;
		}
	}

	if (start == 0) { //전부 양수
		cout << yong[0] << " " << yong[1];
	}
	else if (start == N) { //전부 음수
		cout << yong[N - 2] << " " << yong[N - 1];
	}
	else {
		int sum, min = 2147000000, minusIndex, plusIndex;
		if (start > 1) {
			min = (yong[start - 2] + yong[start - 1]) * -1;
			minusIndex = start - 2;
			plusIndex = start - 1;
		}
		if (start < N - 1) {
			sum = yong[start] + yong[start + 1];
			if (min > sum) {
				min = sum;
				minusIndex = start;
				plusIndex = start + 1;
			}			
		}
		for (i = 0; i < start; i++) {
			pair<int, int> minData = BinarySearch(yong[i], start, N - 1);
			if (min > minData.second) {
				min = minData.second;
				plusIndex = minData.first;
				minusIndex = i;
			}
		}
		cout << yong[minusIndex] << " " << yong[plusIndex];
	}
}