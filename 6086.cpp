#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 55
using namespace std;
int flow[MAX][MAX];
int capacity[MAX][MAX];
int N;
vector<int> adj[MAX];

inline int ctoi(char a) {
	if (a <= 'Z') return a - 'A';
	return a - 'a' + 26;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i <N; i++) {
		char a, b;
		int c,aa,bb;
		cin >> a >> b >> c;
		aa = ctoi(a); bb = ctoi(b);
		capacity[aa][bb] = capacity[bb][aa] += c;
		adj[aa].push_back(bb);
		adj[bb].push_back(aa); //원래는 단방향인데 역방향도 고려해줘야됨
	}
	int sum = 0, S = ctoi('A'), E = ctoi('Z');

	while (1) {
		int dist[MAX];
		fill(dist, dist + MAX, -1);
		queue<int> q;
		q.push(S);
		while (!q.empty() && dist[E] == -1) {
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur]) {
				if (capacity[cur][nxt] - flow[cur][nxt] > 0 && dist[nxt] == -1) {
					q.push(nxt);
					dist[nxt] = cur;
					if (nxt == E) break;
				}
			}
		}

		if (dist[E] == -1) break;

		int water = 2100000000;
		for (int i = E; i != S; i = dist[i]) {
			water = min(water, capacity[dist[i]][i] - flow[dist[i]][i]);
		}
		for (int i = E; i != S; i = dist[i]) {
			flow[dist[i]][i] += water;
			flow[i][dist[i]] -= water;
		}

		sum += water;
	}
	cout << sum;
}
