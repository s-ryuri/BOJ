#include<cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;
#define MAX 200005

int m, n,sum2 = 0;
vector<pair<int, int>> adj[MAX];
bool check[MAX] = { 0, };
using ti3 = tuple<int, int, int>;

void prim() {
    int cnt = 0, sum = 0;
    priority_queue<ti3, vector<ti3>, greater<ti3>> pq;
    for (auto& nxt : adj[0])
        pq.push({ nxt.first,0,nxt.second });
    check[0] = 1;
    while (1) {
        int cost, v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();
        if (check[v2]) continue;
        cnt++;
        check[v2] = 1;
        sum += cost;
        if (cnt == m - 1) break;
        for (auto& nxt : adj[v2]) {
            if (!check[nxt.second])
                pq.push({ nxt.first,v2,nxt.second });
        }
    }
    printf("%d\n", sum2- sum);
    for (int i = 0; i < MAX; i++) {
        adj[i].clear();
        check[i] = 0;
    }
    sum2 = 0;
}
int main(void){
    int x, y, z;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        while (n--) {
            scanf("%d %d %d", &x, &y, &z);
            adj[x].push_back({ z,y });
            adj[y].push_back({ z,x });
            sum2 += z;
        }
        prim();
    }
}
