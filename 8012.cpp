#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 30001
#define PMAX 20
vector<int> v[MAX];
int d[MAX] = { 0, };
int arr[MAX][PMAX + 1];

void bfs() {
	queue<int> q;
	q.push(1);
	d[1] = 1;
	arr[1][0] = -1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int nxt = v[cur][i];
			if (d[nxt] == 0) {
				arr[nxt][0] = cur;
				d[nxt] = d[cur] + 1;
				q.push(nxt);
			}
		}
	}
}
void getP(int n) {
	for (int j = 1; (1<<j) < n; j++) {
		for (int i = 1; i <= n; i++) {
			if(arr[i][j-1] != 0)
				arr[i][j] = arr[arr[i][j - 1]][j - 1];
		}
	}
}

int LCA(int a, int b) {
	if (d[a] < d[b]) swap(a, b);

	if (d[a] != d[b]) {
		for (int j = PMAX; j >= 0; j--) {
			if (d[a] - (1 << j) >= d[b]) {
				a = arr[a][j];
			}
		}
	}

	if (a == b) return a;
	else {
		for (int j = PMAX; j >= 0; j--) {
			if (d[a] - (1 << j) >= 0 && arr[a][j] != arr[b][j]) {
				a = arr[a][j];
				b = arr[b][j];
			}
		}
	}
	return arr[a][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b,m,sum = 0;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs();
	getP(n);
	cin >> m;
	vector<int> vv(m);
	for (auto& x : vv) cin >> x;
	
	for (int i = 0; i < m - 1; i++) sum += d[vv[i]] + d[vv[i + 1]] - 2 * d[LCA(vv[i], vv[i + 1])];
	cout << sum;
}
