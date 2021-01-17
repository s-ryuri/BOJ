#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {
		seq.resize(n + 1);
		int log = ceil(log2(n));
		ll t = (1LL << (log + 1));
		tree.resize(t);
	}
	void init(int node, int s, int e) {
		ll mid = (s + e) / 2;
		if (s == e) tree[node] = seq[s];
		else {
			init(node * 2, s, mid);
			init(node * 2 + 1, mid + 1, e);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	ll query(int node, int s, int e, ll i, ll j) {
		ll mid = (s + e) / 2;
		if (i > e || j < s) return 0;
		if (i <= s && e <= j) return tree[node];
		return query(node * 2, s, mid, i, j) + query(node * 2 + 1, mid + 1, e, i, j);
	}
	void update(int node, int s, int e, ll i, ll u) {
		ll mid = (s + e) / 2;
		if (i < s || i > e) return;
		tree[node] += u;
		if (s != e) { 
			update(node * 2, s, mid, i, u);
			update(node * 2 + 1, mid + 1, e, i, u);
		}
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	ll a, b, c;
	cin >> N >> M >> K;
	Segment se(N);
	for (int i = 1; i <= N; i++) cin >> se.seq[i];
	se.init(1, 1, N);
	int aa = M + K;
	while (aa--) {
		cin >> a >> b >> c;
		if (a == 1) {
			se.update(1, 1, N, b, c - se.seq[b]);
			se.seq[b] = c;
		}
		else cout << se.query(1, 1, N, b, c) << "\n";
	}
}
