#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int N, M, maxnum = -1;
	int board[6][6];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &board[i][j]);

	for (int i = 0; i < (1 << (N * M)); i++) {
		int sum = 0;
		for (int k = 0; k < N; k++) {
			int cur = 0;
			for (int p = 0; p < M; p++) {
				int m = k * M + p;
				if ((i & (1 << m)) == 0) cur = cur * 10 + board[k][p];
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int k = 0; k < M; k++) {
			int cur = 0;
			for (int p = 0; p < N; p++) {
				int m = p * M + k;
				if ((i & (1 << m)) != 0) cur = cur * 10 + board[p][k];
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		maxnum = max(maxnum, sum);
	}
	printf("%d", maxnum);
}
