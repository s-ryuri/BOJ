#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 4000000
bool check[MAX + 2] = { 0, };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	check[0] = true;
	check[1] = true;
	int N,num = 0;
	cin >> N;
	vector<int> v(N);
	for (int i = 2; i <= N; i++) {
		if (!check[i]) {
			for (int j = i * 2; j <= N; j += i) {
				check[j] = true;
			}
			v[num++] = i;
		}
	}
	int s = 0, e = 0,sum = 0,cnt = 0;
	while (1) {
		if (sum >= N) sum -= v[s++];
		else if (v[e] == 0) break;
		else sum += v[e++];
		if (sum == N) cnt++;
	}
	cout << cnt;
	
}
