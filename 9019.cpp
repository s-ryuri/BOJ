#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
using namespace std;




void solve() {

	bool check[10000] = { 0, };
	int a, b;
	queue<pair<int, string>> q;
	vector<string> result;
	cin >> a >> b;
	check[a] = true;
	q.push({ a,"" });
	while (!q.empty()) {
		auto cur = q.front();
		
		if (cur.first == b) {
			cout << cur.second << "\n";
			
			break;
		}
		q.pop();
		int Dnum = cur.first * 2;
		if (Dnum > 9999) Dnum %= 10000;
		if (!check[Dnum]) {
			check[Dnum] = true;
			q.push({ Dnum, cur.second + "D" });
		}
		if (cur.first == 0) {
			cur.first = 9999;
			check[cur.first] = 1;
			q.push({ cur.first,cur.second + "S" });
		}
		else {
			int Snum = cur.first - 1;
			if (!check[Snum]) {
				check[Snum] = true;
				q.push({ Snum, cur.second + "S" });
			}
		}
		
		
		int Lnum = ((cur.first % 1000) * 10) + (cur.first / 1000);
		if (!check[Lnum]) {
			check[Lnum] = true;
			q.push({ Lnum,cur.second + "L" });
		}
		int Rnum = ((cur.first % 10) * 1000) + (cur.first / 10);
		if (!check[Rnum]) {
			check[Rnum] = true;
			q.push({ Rnum,cur.second + "R" });
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
}
