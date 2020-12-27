#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <cmath>
using namespace std;

using ti3 = tuple<double, int, int>;
vector<pair<double, int>> adj[105]; // cost,index
int n;
bool check[105] = { 0, };

void prim() {
    cout.setf(ios::fixed);
    cout.precision(2);
    int cnt = 0;
    double sum = 0.0;
    priority_queue<ti3, vector<ti3>, greater<ti3>> pq;
    for(auto& nxt : adj[1]){
        pq.push({ nxt.first,1,nxt.second });
    }
    check[1] = true;
    while (1) {
        double cost;
        int v1, v2;
        tie(cost, v1, v2) = pq.top();
        pq.pop();
        if (check[v2]) continue;
        check[v2] = true;
        cnt++;
        sum += cost;
        if (cnt == n - 1) break;
        for (auto& nxt : adj[v2]) {
            if (!check[nxt.second])
                pq.push({ nxt.first,v2,nxt.second });
        }
    }
    cout << sum;
}

int main(void){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    double x, y,distance = 0;
    vector<pair<double, double>> pxy;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pxy.push_back({ x,y });
    }
    for (int i = 0; i < pxy.size(); i++) {
        for (int j = i + 1; j < pxy.size(); j++) {
            distance = sqrt(((pxy[i].first - pxy[j].first) * (pxy[i].first - pxy[j].first)) + ((pxy[i].second - pxy[j].second) * (pxy[i].second - pxy[j].second)));
            adj[i + 1].push_back({ distance,j + 1 });
            adj[j + 1].push_back({ distance,i + 1 });
        }
    }
    prim();
}
