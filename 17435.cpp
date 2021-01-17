#include <iostream>
#include <vector>
using namespace std;
#define MAX 500002
#define PMAX 19

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M;
	cin >> M;
	int arr[MAX][PMAX] = { 0, };
	for (int i = 1; i <= M; i++) cin >> arr[i][0];

	for (int j = 1; j < PMAX; j++) {
		for (int i = 1; i <= M; i++)
			arr[i][j] = arr[arr[i][j - 1]][j - 1];
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int n, x;
		cin >> n >> x;
		for (int j = PMAX; j >= 0; j--) {
			if (n >= 1 << j) {
				n -= 1 << j;
				x = arr[x][j];
			}
		}
		cout << x << '\n';
	}
}
