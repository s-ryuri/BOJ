#include <iostream>
#include <string>
#include<stack>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	string str="";
	stack<char> s;
	int k = 0;
	int count = 0;
	getline(cin, str);
	str += "\n";
	while(k<str.length()) {
		if (str[k] == ' ' || str[k] == '\n') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << str[k++];
		}
		else if (str[k] == '<') {
			if (!s.empty()) {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << str[k++];
			}
			while (str[k] != '>') cout << str[k++];
			cout << str[k++];
		}
		else {
			s.push(str[k++]);
		}
	}
}
