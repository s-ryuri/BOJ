#include<iostream>
#include<vector>
using namespace std;

vector<int> subset;
vector<int> subset2;
int n,num, k,sum = 0,cnt = 0,S;
void search(int k);

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	cin >> n >> S;
	for (int i = 0; i < n; i++) {
		cin >> num;
		subset.push_back(num);
	}
	search(0);
	if (S == 0) cnt--;
	cout << cnt;
}

void search(int k) {
	if (k == n) {
		for (int i = 0; i < subset2.size(); i++) {
			sum += subset2[i];
		}
		if (sum == S) cnt++;
		sum = 0;
		return;
	}
	else {
		subset2.push_back(subset[k]);
		search(k + 1);
		subset2.pop_back();
		search(k + 1);
	}
}
