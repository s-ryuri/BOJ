#include <iostream>
using namespace std;
long long d[92][3] = { 0, };
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N;
	long long sum = 0;
	cin >> N;
	d[1][1] = 1;
	for (int i = 2; i <= 90; i++) {
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	for (int i = 0; i <= 1; i++) sum += d[N][i];
	cout << sum;
}

//연속된 수를 다룰 때는 이차원배열을 이용한다.
