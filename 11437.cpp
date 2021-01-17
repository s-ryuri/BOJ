#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> adj[50001];
	pair<int, int> check[50001];
	queue<int> q;
	int N, M,a,b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	check[1] = { 1,-1 };
	q.push(1);
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (check[nxt].second == 0) {
				check[nxt] = { check[cur].first + 1,cur };
				q.push(nxt);
			}
		}
	}
	cin >> M;
	while (M--) {
		cin >> a >> b;
		while (check[a].first != check[b].first) {
			if (check[a].first > check[b].first) a = check[a].second;
			else if (check[a].first < check[b].first) b = check[b].second;
		}
		while (a != b) {
			a = check[a].second;
			b = check[b].second;
		}
		cout << a << "\n";
	}
}
