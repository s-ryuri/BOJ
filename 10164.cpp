#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int N, M, K,r=0,c=0,num = 1;
	bool a = false;
	long long d[17][17] = { 0, };
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			d[i][j] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (num == K) {
				r = i;
				c = j;
				a = true;
				break;
			}
			num++;
		}
		if (a)break;
	}
	if (K == 0) {
		for (int i = 1; i < N; i++) {
			for (int j = 1; j < M; j++) {
				d[i][j] = d[i - 1][j] + d[i][j - 1];
			}
		}
		cout << d[N - 1][M - 1];	
	}
	else {
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				d[i][j] = d[i - 1][j] + d[i][j - 1];
		long long temp = d[r][c];
		d[r][c] = 1;
		for (int i = r + 1; i < N; i++)
			for (int j = c + 1; j < M; j++)
				d[i][j] = d[i - 1][j] + d[i][j - 1];
		cout << temp * d[N - 1][M - 1];
	}
}
