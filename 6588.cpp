#include <iostream>
using namespace std;
const int MAX = 1000000;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	bool check[MAX+1] = { 0, };
	check[0] = check[1] = true;
	for (int i = 2; i*i <= MAX; i++) {
		if (check[i] == false)
			for (int j = i * 2; j <= MAX; j += i) check[j] = true;
	}
	int num, a, b,c;
	int temp;
	while (1) {
		cin >> num;
		bool tre = false;
		if (num == 0) return 0;
		for (int i = 2; i <= MAX; i++) {
			if (!check[i]) {
				a = i;
				if (num - a >= 0&& num -a >= a&&!check[num - a]) {
					b = num - a;
					cout << num << " = " << a << " + " << b << "\n";
					tre = true;
					break;
				}
			}
		}
		if(!tre) cout << "Goldbach's conjecture is wrong." << "\n";
	}
}
