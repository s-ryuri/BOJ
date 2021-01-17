#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, M;
	cin >> T;
	while (T--) {
		long long cnt = 0;
		cin >> N >> M;
		vector<int> A(N);
		vector<int> B(M);
		vector<int>::iterator vi;
		for (auto& x : A) cin >> x;
		for (auto& x : B) cin >> x;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for (auto& x : A) {
			vi = lower_bound(B.begin(),B.end(),x);
			cnt += vi - B.begin();
		}
		cout << cnt << "\n";
	}
}
