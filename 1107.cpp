#include <iostream>
#include <algorithm>
using namespace std;

bool broken[11];

int poss(int num) {
	if (num == 0) {
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (num > 0) {
		if (broken[num % 10]) return 0;
		num /= 10;
		len++;
	}
	return len;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		broken[num] = true;
	}
	int result = abs(N - 100);
	for (int i = 0; i <= 1000000; i++) {
		int checknum = i, c = poss(checknum);
		if (c) result = min(result, c + abs(N - checknum));
	}
	cout << result;
}
