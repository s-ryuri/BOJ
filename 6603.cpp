#include <iostream>

using namespace std;

int K;
int num2[14];
int num1[14];
int check[14];
void func(int p);

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	while (1) {
		cin >> K;
		if (K == 0) break;
		for (int i = 0; i < K; i++) cin >> num2[i];
		func(0);
		cout << '\n';
	}
	return 0;
}

void func(int p) {
	if (p == 6) {
		for (int i = 0; i < 6; i++) cout << num1[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < K; i++) {
		if (!check[i]) {
			num1[p] = num2[i];
			if (p >= 1 && num1[p - 1] > num1[p]) continue;
			check[i] = 1;
			func(p + 1);
			check[i] = 0;
		}
	}
}
