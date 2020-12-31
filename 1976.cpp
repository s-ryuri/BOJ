#include <iostream>
#define MAX 210
using namespace std;

int n, m, p[MAX + 1];
int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return find(p[n]);
}
void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cout.tie(NULL);
	int num, arr[1001], count = 0;;
	fill(p, p + MAX, -1);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (num == 1) {
				merge(i, j);
			}
		}
	}
	for (int i = 0; i < m; i++) cin >> arr[i];
	for (int i = 1; i < m; i++) {
		if (find(arr[0]) == find(arr[i])) count++;
	}
	if (count == m - 1) cout << "YES";
	else cout << "NO";

}
