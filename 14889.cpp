#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int minresult = 1e7;
vector<int> v1;
vector<int> v2;
int board[22][22];

void back(int k) {
	if (k == N + 1) {
		if (v1.size() == (N / 2) && v2.size() == (N / 2)) {
			int sum1 = 0;
			int sum2 = 0;
			
			for (int i = 0; i < (N / 2); i++) {
				for (int j = i+1; j < (N / 2); j++) {
					int a = v1[i];
					int b = v1[j];
					sum1 += (board[a][b] + board[b][a]);

					int aa = v2[i];
					int bb = v2[j];
					sum2 += (board[aa][bb] + board[bb][aa]);
					
				}
			}
			minresult = min(minresult, abs(sum1 - sum2));
		}
		return;
	}
	v1.push_back(k);
	back(k+1);
	v1.pop_back();

	v2.push_back(k);
	back(k + 1);
	v2.pop_back();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	back(1);
	cout << minresult;
}
