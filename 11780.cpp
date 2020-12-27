#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000010
using namespace std;
int n, m;
int d[102][102] = { 0, };
int nxt[102][102] = { 0, };
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= 101; i++)
		for (int j = 1; j <= 101; j++)
			d[i][j] = MAX;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
		nxt[a][b] = b;
	}
	for (int i = 1; i <= 101; i++)
		for (int j = 1; j <= 101; j++)
			if (i == j) d[i][j] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j]) {
					nxt[i][j] = nxt[i][k];
					d[i][j] = d[i][k] + d[k][j];
				}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == MAX) cout << "0 ";
			else cout << d[i][j] << " ";
		}
		printf("\n");
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == 0 || d[i][j] == MAX) {
				cout << "0\n";
				continue;
			}
			vector<int> p;
			int start = i;
			while (start != j) {
				p.push_back(start);
				start = nxt[start][j];
			}
			p.push_back(j);
			cout << p.size() << " ";
			for (auto& n : p) cout << n << " ";
			cout << "\n";
		}
	}
}
