#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[32001];
int indeg[32001] = { 0, };
int N;
void we_sort();
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int M,A,B;
	cin >> N >> M;
	while (M--) {
		cin >> A >> B;
		adj[A].push_back(B);
		indeg[B]++;
	}
	we_sort();
}
void we_sort() {
	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= N; i++)
		if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			indeg[nxt]--;
			if (indeg[nxt] == 0) q.push(nxt);
		}
	}
	for (int i = 0; i < N; i++) cout << result[i] << ' ';
}
