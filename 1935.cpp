#include <iostream>
#include <stack>
using namespace std;
double a, b;
stack<double> s;
void TopPop() {
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
}
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N;
	int num;
	string str;
	int arr[100] = { 0, };
	bool arr2[100] = { 0, };
	cin >> N;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '*') {
			TopPop();
			s.push(a * b);
		}
		else if (str[i] == '+') {
			TopPop();
			s.push(a + b);
		}
		else if (str[i] == '/') {
			TopPop();
			s.push(b / a);
		}
		else if (str[i] == '-') {
			TopPop();
			s.push(b - a);
		}
		else {
			if (arr2['Z' - str[i]] == false) {
				cin >> num;
				arr['Z' - str[i]] = num;
				arr2['Z' - str[i]] = true;
				s.push(num);
			}
			else s.push(arr['Z' - str[i]]);
		}
	}
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << s.top() << '\n';
}
