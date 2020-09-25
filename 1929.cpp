#include <iostream>
using namespace std;
const int MAX = 1000000;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	bool check[MAX+1] = { 0, }; //지워졌으면 true
	check[0] = check[1] = true;
	for (int i = 2; i*i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i * 2; j <= MAX; j += i) check[j] = true;
		}
	}
	int N, M; // 100까지의 소수
	cin >> N >> M;
	for (int i = N; i <= M; i++)
		if (check[i] == false) cout << i << '\n';
}
