#include<iostream>
#include<cmath>
using namespace std;

int GCD(int a, int b) {
	int r = a % b;
	if (r)
		return GCD(b, r);
	else
		return b;
}

int main() {
	int R, G, i;
	cin >> R >> G;
	int gcd = GCD(R, G);
	int limit = (int)sqrt(gcd);
	for (i = 1; i <= limit; i++) {
		if (gcd % i == 0) {
			cout << i << " " << R / i << " " << G / i << "\n";
			if(i * i != gcd)
				cout << gcd / i << " " << R / (gcd / i) << " " << G / (gcd / i) << "\n";
		}
	}
}