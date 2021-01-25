#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 100002
using namespace std;

int cnt = 0, dfsn[MAX], SN = 0, sn[MAX];
//SN : SCC개수, sn[i] : i가 속한 SCC의 번호
vector<int> adj[MAX]; //유향그래프 담는 벡터
bool finished[MAX]; // 사이클 판별, scc 분리가 끝난 정정만 true
stack<int> s;

void clearr(int n) {
	memset(dfsn, 0, sizeof(dfsn));
	memset(sn, 0, sizeof(sn));
	memset(finished, 0, sizeof(finished));
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
	}
	cnt = 0;
	SN = 0;
}
int dfs(int cur) {
	dfsn[cur] = ++cnt;
	s.push(cur);
	//자신의 dfsn, 자식들의 결과나 dfsn중 가장 작은 번호를 result에 저장
	int result = dfsn[cur];
	for (int nxt : adj[cur]) {
		//아직 방문하지 않은 이웃 dfs 돌림
		if (dfsn[nxt] == 0) result = min(result, dfs(nxt));
		//방문은 했으나 아직 SCC로 추출되지 않은 이웃
		else if (!finished[nxt]) result = min(result, dfsn[nxt]);
	}

	if (result == dfsn[cur]) {
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			sn[t] = SN;
			if (t == cur) break;
		}
		SN++;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,N,M,x,y;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		int SccIndegree[MAX] = { 0, };
		int cresult = 0;
		while (M--) {
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= N; i++) {
			if (dfsn[i] == 0) dfs(i);
		}
		for (int i = 1; i <= N; i++) {
			for (int j : adj[i]) {
				if (sn[i] != sn[j]) SccIndegree[sn[j]]++;
			}
		}
		for (int i = 0; i < SN; i++) {
			if (SccIndegree[i] == 0) cresult++;
		}
		cout << cresult << "\n";
		clearr(N);
	}

}
