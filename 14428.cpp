#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
vector<int> tree;
vector<int> seq;
int N;

inline int idx(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return seq[a] <= seq[b] ? a : b;
}
inline int init(int node, int s, int e) {
	if (s == e) return tree[node] = s;
	int mid = (s + e) / 2;
	return tree[node] = idx(init(node * 2, s, mid), init(node * 2 + 1, mid + 1, e));
}
inline int query(int node, int s, int e, int i, int j) {
	if (e < i || s > j) return -1;
	if (i <= s && e <= j) return tree[node];
	int mid = (s + e) / 2;
	return idx(query(node * 2, s, mid, i, j), query(node * 2 + 1, mid + 1, e, i, j));
}

inline int update(int node, int s, int e, int i, int u) {
	if (i < s || i > e || s == e) return tree[node];
	int mid = (s + e) / 2;
	return tree[node] = idx(update(node * 2, s, mid, i, u), update(node * 2 + 1, mid + 1, e, i, u));
}

inline void construct(int n) {
	seq.resize(n + 1);
	int log = ceil(log2(n));
	ll t = (1LL << (log + 1));
	tree.resize(t);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M,a, b, c;
	cin >> N;
	construct(N);
	for (int i = 1; i <= N; i++) cin >> seq[i];
	init(1, 1, N);
	cin >> M;
	while (M--) {
		cin >> a >> b >> c;
		if (a == 1) {
			seq[b] = c;
			update(1, 1, N, b, c);
		}
		else cout << query(1, 1, N, b, c) << "\n";
	}
}
