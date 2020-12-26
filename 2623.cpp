#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
int in[1001] = { 0, };
int N;
void we_sort();
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(nullptr);
	int M,num,p;
	cin >> N >> M;
	while (M--) {
		vector<int> pep;
		cin >> num;
		while (num--) {
			cin >> p;
			pep.push_back(p);
		}
		for (int i = 0; i < pep.size() - 1; i++) {
			adj[pep[i]].push_back(pep[i + 1]);
			in[pep[i + 1]]++;
		}
		
	}
	we_sort();
}
void we_sort() {
	queue<int> q;
	vector<int> result;
	for (int i = 1; i <= N; i++)
		if (in[i] == 0) q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			in[nxt]--;
			if (in[nxt] == 0) q.push(nxt);
		}
	}
	if (result.size() != N) {
		cout << "0";
		return;
	}
	for (int i = 0; i < N; i++) cout << result[i] << '\n';
}
