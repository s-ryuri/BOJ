#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int updp[502];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<int, int>> vp(N + 1);
	for (int i = 1; i <= N; i++) cin >> vp[i].X >> vp[i].Y;
	sort(vp.begin(), vp.end());
	for (int i = 1; i <= N; i++) {
		updp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (vp[i].Y > vp[j].Y && updp[j] + 1 > updp[i])
				updp[i] = updp[j] + 1;
		}
	}
	int ans = *max_element(updp, updp + N + 1);
	cout << N - ans;
}
