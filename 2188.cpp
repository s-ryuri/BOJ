#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 203
using namespace std;

vector<int> adj[MAX];
bool check[MAX];
int d[MAX];

bool dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (check[nxt]) continue;
		check[nxt] = true;
		if (d[nxt] == 0 || dfs(d[nxt]) ){
			d[nxt] = cur;
				return true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M,S,num,cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> S;
		for (int j = 0; j < S; j++) {
			cin >> num;
			adj[i].push_back(num);
		}
	}
	for (int i = 1; i <= N; i++) {
		fill(check, check + MAX, false);
		if (dfs(i)) cnt++;
	}
	cout << cnt;
}
