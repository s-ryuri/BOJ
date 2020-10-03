#include <iostream>

using namespace std;

long long d[101][10];
long long mod = 1000000000;
long long sum = 0;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i < 10; i++) d[1][i] = 1;
	for (int i = 2; i <= 100; i++) { //N
		for (int j = 0; j <= 9; j++) { //L
			d[i][j] = 0;
			if (j >= 1) d[i][j] += d[i - 1][j - 1];
			if (j <= 8) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}
	for (int i = 0; i <= 9; i++) sum += d[n][i];
	cout << sum % mod;
}
