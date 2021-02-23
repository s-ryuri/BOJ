#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	string s;
	cin >> s;
	istringstream ss(s);
	istringstream ss2(s);
	string result,result2;
	vector<string> vp;
	bool check[100] = { 0, };
	int ssize = s.size();
	int cnt = 0,can = 1;
	for (int i = 0; i < ssize; i++) {
		if (s[i] == '-') {
			cnt++;
			check[i] = true;
		}
			
	}

	while (getline(ss, result, '-')) {
		vp.push_back(result);
	}

	if (cnt == 0) {
		int sum = 0;
		while (getline(ss2, result2, '+')) {
			sum += stoi(result2);
		}
		cout << sum;
	}
	else {
		int sum = 0;
		if (check[0] == true) { //마이너스로 시작할 때
			string sss;
			for (int i = 0; i < vp.size(); i++) {
				istringstream ss1(vp[i]);
				while (getline(ss1, sss, '+')) {
					sum += stoi(sss);
				}
			}
			cout << -sum;
			
		}
		else { //플러스로 시작할 때
			string sss;
			for (int i = 0; i < vp.size(); i++) {
				if (i == 0) {
					istringstream ss1(vp[i]);
					while (getline(ss1, sss, '+')) {
						sum += stoi(sss);
					}
				}
				else {
					istringstream ss1(vp[i]);
					while (getline(ss1, sss, '+')) {
						sum -= stoi(sss);
					}
				}

			}
			cout << sum;
		}
	}
}

