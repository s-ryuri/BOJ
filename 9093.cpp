#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int T;
	cin >> T;
	cin.ignore();
	for (int i = 0; i < T; i++) {
		stack<char> s;
		string sentence;
		getline(cin,sentence);
		sentence += '\n';
		for (int j = 0; j < sentence.length(); j++) {
			if (sentence[j] == ' ' || sentence[j] == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << sentence[j];
			}
			else s.push(sentence[j]);	
		}
	}
}
