#include <iostream>
using namespace std;
#define MAX 1000000000
using ll = long long;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N,K;
	cin >> N >> K;
	ll d[202][202] = { 0 ,};
	for (ll i = 1; i <= 200; i++) {
		d[i][1] = 1;
		d[i][2] = i + 1;
		d[0][i] = 1;
	}
	for (int i = 1; i <= 200; i++) {
		for (int k = 3; k <= 200; k++) {
			for (int j = 0; j <= i; j++) {
				d[i][k] += d[i - j][k-1] % MAX;
				d[i][k] %= MAX;
			}
		}
	}
	cout << d[N][K];
}
