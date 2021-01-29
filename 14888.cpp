#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
vector<char> yun2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int minresult = 1e9 + 1;
	int maxresult = -(1e9 + 1);
	int ga[4] = { 0, };
	int N,num;
	char a[4] = { '+','-','*','%' };
	cin >> N;
	deque<int> v(N);
	deque<int> v2(N);
	vector<char> yun;
	
	for (auto& x : v) cin >> x;
	for (int i = 0; i < 4; i++){
		cin >> num;
		for (int j = 0; j < num; j++) {
			yun.push_back(a[i]);
		}
	}
	int cnt = 0;
	sort(yun.begin(), yun.end());
	v2 = v;
	do {
		int ysize = yun.size();
		for (int i = 0; i < ysize; i++) {
			if (yun[i] == '+') {
				int temp = v.front();
				v.pop_front();
				int temp2 = v.front();
				v.pop_front();
				v.push_front(temp + temp2);
			}
			else if (yun[i] == '-') {
				int temp = v.front();
				v.pop_front();
				int temp2 = v.front();
				v.pop_front();
				v.push_front(temp - temp2);
			}
			else if (yun[i] == '*') {
				int temp = v.front();
				v.pop_front();
				int temp2 = v.front();
				v.pop_front();
				v.push_front(temp * temp2);
			}
			else{
				int temp = v.front();
				v.pop_front();
				int temp2 = v.front();
				v.pop_front();
				if (temp < 0) {
					temp = -temp;
					int k = (temp / temp2);
					v.push_front(-k);
				}
				else v.push_front(temp / temp2);
			}
		}
		minresult = min(minresult, v[0]);
		maxresult = max(maxresult, v[0]);
		v = v2;	
	} while (next_permutation(yun.begin(),yun.end()));

	cout << maxresult << '\n';
	cout << minresult;
}
