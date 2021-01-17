#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MOD 1000000007

using ll = long long;

struct Segment {
	vector<ll> tree;
	vector<ll> seq;
	Segment(int n) {	//초기화 함수, 배열의 크기와 트리의 크기를 초기화 해줌
		seq.resize(n + 1);
		int log = ceil(log2(n));
		ll t = (1LL << (log + 1));
		tree.resize(t);
	}

	void init(int node, int s, int e) {
		if (s == e) tree[node] = seq[s];
		else {
			init(node * 2, s, (s + e) / 2);
			init(node * 2 + 1, (s + e) / 2 + 1, e);
			tree[node] = tree[node * 2] + tree[node * 2 + 1];
		}
	}

	ll query(int node, int s, int e, int i, int j) {
		if (e < i || s > j) return 0;
		if (i <= s && e <= j) return tree[node];
		return query(node * 2, s, (s + e) / 2, i, j) + query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
	}

	void update(int node, int s, int e, int i, ll u) {
		if (i < s || i > e) return;
		tree[node] += u;
		if (s != e) {
			update(node * 2, s, (s + e) / 2, i, u);
			update(node * 2 + 1, (s + e) / 2 + 1, e, i, u);
		}
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, Q,a,p,x;
	cin >> N >> Q;
	Segment se(N);
	//for (int i = 1; i <= N; i++) cin >> se.seq[i];
	se.init(1, 1, N);
	while (Q--) {
		cin >> a >> p >> x;
		if (a == 1) {
			se.update(1, 1, N, p, x);
		}
		else {
			cout << se.query(1, 1, N, p, x) << "\n";
		}
	}
}
