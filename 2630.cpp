#include <iostream>
using namespace std;

int result[2];
int board[140][140];

bool check(int n, int m, int num) {
	for (int i = n;i<n + num; i++) {
		for (int j = m; j < m + num; j++) {
			if (board[n][m] != board[i][j]) return false; // 다른거
		}
	}
	return true;
}
void solve(int n, int m, int num) {
	if (check(n, m, num)) {
		result[board[n][m]]++;
		return;
	}
	int k = num / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			solve(n + i * k, m + j * k, k);
		
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> board[i][j];
	solve(0, 0, N);

	cout << result[0] << "\n" << result[1];
}
