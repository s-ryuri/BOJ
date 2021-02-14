#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define MAX 1003333
using namespace std;

bool check[MAX];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	check[0] = check[1] = true;
	for (int i = 2; i * i <= MAX; i++) {
		if (!check[i])
			for (int j = i * i; j <= MAX; j += i) check[j] = true;
	}
	int N;
	cin >> N;
	for (int i = N;; i++) {
		string s1 = to_string(i);
		string s = to_string(i);
		reverse(s.begin(),s.end());
		if (s == s1 && !check[i]) {
			cout << s1;
			return 0;
		}
			
	}
}
