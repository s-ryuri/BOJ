#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10020
using namespace std;

int p[MAX],a;
int ran[MAX], arr[MAX];
bool check[MAX] = { 0, };
int find(int n) {
	if (p[n] == n) return n;
	return p[n] = find(p[n]);
}
void merge(int a, int b) {
	a = find(a); 
	b = find(b);
	if (a == b) return;
	if (ran[a] > ran[b]) swap(a, b);
	p[a] = b;
	if (ran[a] == ran[b]) ran[b]++;
}
int n, m, k,v,w;
int main() {
	for (int i = 0; i < MAX; i++) {
		p[i] = i;
		ran[i] = i;
	}
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	vector<int> vec[MAX];
	int sum = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	while (m--) {
		cin >> v >> w;
		check[v] = check[w] = 1;
		merge(v, w);
	}
	for (int i = 1; i <= n; i++) {
		if (check[i]) vec[find(i)].push_back(i);
		else sum += arr[i];
	}
	for (int i = 0; i <= n; i++) {
		if (vec[i].size()) {
			a = arr[vec[i][0]];
			for (int j = 1; j < vec[i].size(); j++)a = min(a, arr[vec[i][j]]);
			sum += a;
		}
	}
	if (sum > k) cout << "Oh no";
	else cout << sum;
}
