#include <iostream>

using namespace std;
const int MAX = 1000000;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	bool check[MAX + 1] = { 0, };
	check[0] = check[1] = true;
	for (int i = 2; i * i <= MAX; i++)
		if (!check[i])
			for (int j = i * 2; j <= MAX; j += i) check[j] = true;
	int T, N,a,b,count = 0;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 2; i < N; i++) {
			if (!check[i]) {
				a = i;
				if (check[N-a] == false && N - a >= a && N - a >= 0) {
					b = N - a;
					count++;
				}
			}
		}
		cout << count << "\n";
		count = 0;
	}
}
