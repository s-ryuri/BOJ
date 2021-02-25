#include<iostream>
#include<vector>
#include <utility>
#include <algorithm>
using namespace std;

bool check[20] = { 0, };
int board[52][52];
int n, m, k;
int minnum = 1e9;
vector<pair<int, int>> chicken, home,subset;

int dist(const pair<int, int>& a, const pair<int, int>& b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void dfs(int startidx, int cnt) {
	if (cnt == m) {
		int sum = 0;
		int d;
		for (int i = 0; i < home.size(); i++) {
			d = 1e7;
			for (int j = 0; j < subset.size(); j++) {
				d = min(d, dist(home[i], subset[j]));
			}
			sum += d;
		}
		minnum = min(minnum, sum);
		return;
	}
	else {
		for (int i = startidx; i < chicken.size(); i++) {
			if (check[i]) continue;
			check[i] = true;
			subset.push_back(chicken[i]);
			dfs(i, cnt + 1);
			check[i] = false;
			subset.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) home.push_back({ i,j });
			if (board[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << minnum;
}
