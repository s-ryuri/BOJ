#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<long long> h;

long long solve() {
	stack<long long> rem;
	h.push_back(0);
	long long ret = 0;
	for (int i = 0; i < h.size(); i++) {
		while (!rem.empty() && h[rem.top()] >= h[i]) {
			long long j = rem.top();
			//cout << "rem.top() : " <<j << "\n";
			rem.pop();
			long long width = -1;
			if (rem.empty()) width = i;
			else width = (i - rem.top() - 1);
			//cout << "i : " << i<<" width : " << width << "\n";
			ret = max(ret, h[j] * width);
		}
		rem.push(i);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	while (1) {
		cin >> N;
		if (N == 0) return 0;
		while (N--) {
			long long num;
			cin >> num;
			h.push_back(num);
		}
		cout << solve() << "\n";
		h.clear();
	}
}
