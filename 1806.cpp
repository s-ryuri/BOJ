#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, S, length = 1e6;
	cin >> N >> S;
	vector<int> v(N + 1);
	for (int i = 0; i < N; i++) cin >> v[i];
	int s = 0, e = 0,sum = 0;
	while (1) {
		if (e == N + 1) break;
		else if (sum >= S) {
			sum -= v[s++];
			length = min(length, e - s + 1);
		}
		else sum += v[e++];
		/*cout << "s : " << s << " e : " << e << "\n";
		cout << "sum : " << sum << "\n";*/
	}
	if (length == 1e6) cout << 0;
	else cout << length;
}
