#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using vi = vector<int>;

vi getPartialMatch(const string& N) {
	int m = N.size();
	vi pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vi kmpSearch(const string& H, const string& N) {
	int n = H.size(), m = N.size();
	vi ret;
	vi pi = getPartialMatch(N);
	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && H[begin + matched] == N[matched]) {
			++matched;
			if (matched == m) ret.push_back(begin);
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	string S,p = "IOI";
	cin >> N >> M >> S;
	for (int i = 1; i < N; i++) p += "OI";
	vi result;
	result = kmpSearch(S, p);
	cout << result.size();
}
