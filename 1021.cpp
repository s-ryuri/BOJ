#include <iostream>
#include <deque>
#include <utility>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	deque<pair<int,int>> deq(N);
	for (int i = 0; i < N; i++) {
		deq[i].first = i + 1; //순서
		deq[i].second = i; //들어 있는 거
	}
	vector<int> v(M);
	for (auto& x : v) cin >> x;
	int vsize = v.size(),cnt = 0;
	for (int i = 0; i < vsize; i++) {
		for (int j = 0; j < deq.size(); j++) {
			if (v[i] == deq[j].first) {
				if (j <= deq.size() - 1 - j) {
					int num = j;
					cnt += num;
					while (num--) {
						pair<int,int> temp = deq.front();
						deq.pop_front();
						deq.push_back(temp);
					}					
					deq.pop_front();
				}
				else if (j > deq.size() - 1 - j) {
					int num = deq.size() - j;
					cnt += num;
					while (num--) {
						pair<int,int> temp = deq.back();
						deq.pop_back();
						deq.push_front(temp);
					}
					deq.pop_front();
				}
			}
		}
	}
	cout << cnt;
}
