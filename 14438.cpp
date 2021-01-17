#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Segment {
	vector<int> tree;
	vector<int> seq;
	Segment(int n) {
		seq.resize(n + 1);
		int log = ceil(log2(n));
		int t = (1 << (log + 1));
		tree.resize(t);
	}

	int init(int node, int s, int e) {
		if (s == e) return tree[node] = seq[s];
		int mid = (s + e) / 2;
		return tree[node] = min(init(node * 2, s, mid), init(node * 2 + 1, mid + 1, e));
	}
	int query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 1e9;
		if (i <= s && e <= j) return tree[node];
		int mid = (s + e) / 2;
		return min(query(node * 2, s, mid, i, j), query(node * 2 + 1, mid + 1, e, i, j));
	}

	int update(int node, int s, int e, int i, int u) {
		int mid = (s + e) / 2;
		if (i < s || i > e) return tree[node];
		if (s == e) return tree[node] = u;
		return tree[node] = min(update(node * 2, s, mid, i, u), update(node * 2 + 1, mid + 1, e, i, u));
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, a, b, c;
	cin >> N;
	Segment se(N);
	for (int i = 1; i <= N; i++) cin >> se.seq[i];
	
	se.init(1, 1, N);
	cin >> M;
	while (M--) {
		cin >> a >> b >> c;
		if (a == 1) se.update(1, 1, N, b, c);
		else cout << se.query(1, 1, N, b, c) << "\n";
	}
}
