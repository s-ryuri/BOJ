#include <iostream>
using namespace std;

string board[70];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j <  y + n; j++) {
			if (board[x][y] != board[i][j]) return false;
		}
	}
	return true;
}
void solve(int x, int y, int n) {
	if (check(x, y, n)) {
		cout << board[x][y];
		return;
	}
	cout << "(";
	int m = n / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			solve(x + i * m, y + j * m, m);
	cout << ")";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> board[i];
	solve(0, 0, N);
}
