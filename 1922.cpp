#include<cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;

bool check[1005];
vector<pair<int, int>> adj[1005];
using ti3 = tuple<int, int, int>;
int N, M;

void prim() {
    int cnt = 0, sum = 0;
    priority_queue<ti3, vector<ti3>, greater<ti3>> pq;
    for (auto& nxt : adj[1]) {
        pq.push({ nxt.first,1,nxt.second });
    }
    check[1] = true;
    while (1) {
        int cost, v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();
        if (check[v2]) continue;
        check[v2] = true;
        cnt++;
        sum += cost;
        if (cnt == N - 1) break;
        for (auto& nxt : adj[v2]) {
            if (!check[nxt.second])
                pq.push({ nxt.first,v2,nxt.second });
        }
    }
    printf("%d", sum);
}

int main(void){
    int a, b, c;
    scanf("%d %d", &N, &M);
    while (M--) {
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }
    prim();
}
