#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	stack<int> sta;
	int count = 0;
	string iron;
	cin >> iron;
	for (int i = 0; i < iron.length(); i++) {
		if(iron[i] == '(') sta.push(i);
		else {
			if (sta.top() + 1 == i) {
				sta.pop();
				count += sta.size();
			}
			else {
				sta.pop();
				count++;
			}
		}
	}
	cout << count;
}
