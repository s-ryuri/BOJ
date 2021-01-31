#include <iostream>
#include <algorithm>
#define MAX 1000003

using namespace std;

int dp[MAX];
int past[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	dp[1] = 0;
	fill(past, past + N + 2, -1);
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		past[i] = i - 1;
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2]) {
				dp[i] = dp[i / 2] + 1;
				past[i] = i / 2;
			}
		}
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3]) {
				dp[i] = dp[i / 3] + 1;
				past[i] = i / 3;
			}
		}

	}
	cout << dp[N] << "\n";
	cout << N << " ";
	while (past[N] != -1) {
		cout << past[N] << " ";
		past[N] = past[past[N]];
	}
}
