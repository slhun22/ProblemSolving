#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N, i;
	double area = 0; //float이면 부동 소수점 한계로 값에 오차가 발생함.
	pair<long long, long long> point[10000]; //int 이면 overflow 남.
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> point[i].first >> point[i].second;
	for (i = 0; i < N - 1; i++)
		area += (point[i].first + point[i + 1].first) * (point[i].second - point[i + 1].second);
	area += (point[N - 1].first + point[0].first) * (point[N - 1].second - point[0].second);
	cout.precision(1);
	cout << fixed << round(abs(area * 5)) / 10;
}