#include <iostream>
#include <algorithm>
#define IF if (alpha[k] == 'a' || alpha[k] == 'e' || alpha[k] == 'i' || alpha[k] == 'o' || alpha[k] == 'u') num++;
#define IF2 if (alpha[k] == 'a' || alpha[k] == 'e' || alpha[k] == 'i' || alpha[k] == 'o' || alpha[k] == 'u') num--;
#define Else else num2++;
#define Else2 else num2--;
using namespace std;
int L, C;
char alpha[16];
char alpha2[16];
int check[16];
int num = 0;
int num2 = 0;
void func(int k);
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> L >> C;
	for (int i = 0; i < C; i++) cin >> alpha2[i];
	sort(alpha2, alpha2 + C);
	func(0);
}
void func(int k) {
	if (k == L) {
		if (num >= 1 && num2 >= 2) {
			for (int i = 0; i < L; i++) cout << alpha[i];
			cout << '\n';
			return;
		}
	}
	for (int i = 0; i < C; i++) {
		if (!check[i]) {
			alpha[k] = alpha2[i];
			IF
			Else
			if (k >= 1 && alpha[k - 1] > alpha[k]) {
				IF2
				Else2
				continue;
			}
			check[i] = 1;
			func(k + 1);
			check[i] = 0;
			IF2
			Else2
		}
	}
}
