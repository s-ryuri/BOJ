#include <iostream>
#define MAX 2200
using namespace std;
int board[MAX][MAX];
int result[3];
bool checkboard(int n, int m, int num);
void solve(int x, int y, int n);
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	solve(0, 0, N);
	for (auto& x : result) cout << x << "\n";
}

bool checkboard(int n, int m, int num) {
	for (int i = n; i < n + num; i++) {
		for (int j = m; j < m + num; j++) {
			if (board[n][m] != board[i][j]) return false;
		}
	}
	return true;
}

void solve(int x, int y, int n) {
	if (checkboard(x, y, n)) {
		result[board[x][y] + 1]++;
		return;
	}
	int m = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i * m, y + j * m, m);
		}
	}
}
