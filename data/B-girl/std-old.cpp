#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 100005;
int n, m, q;
unordered_set<int> adj[MAXN], qs[MAXN];
map<pair<int, int>, list<int>> qmp;
int ans[MAXN];
int fa[MAXN];
 
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
 
void merge_queries(int u, int v) {
    for (int x : qs[u]) {
        auto it1 = qmp.find(minmax(x, u));
        if (it1 == qmp.end()) continue;
        auto it2 = qmp.find(minmax(x, v));
        if (it2 == qmp.end()) {
            qmp[minmax(x, v)] = move(it1->second);
        } else {
            it2->second.splice(it2->second.end(), it1->second);
        }
        qmp.erase(it1);
    }
}
 
void commit(int u, int v, int w) {
    auto it = qmp.find(minmax(u, v));
    if (it == qmp.end()) return;
    for (int id : it->second) if (ans[id] < 0) ans[id] = w;
    qmp.erase(it);
}
 
void unite(int u, int v, int w) {
    u = find(u); v = find(v); if (u == v) return;
    if (adj[u].size()+qs[u].size()>adj[v].size()+qs[v].size()) swap(u, v);
    for (int x : adj[u]) if (qs[v].count(x)) commit(x, v, w);
    for (int x : qs[u]) if (adj[v].count(x)) commit(x, u, w);
    merge_queries(u, v);
    for (int x : adj[u]) adj[x].erase(u), adj[x].insert(v), adj[v].insert(x);
    for (int x : qs[u]) qs[x].erase(u), qs[x].insert(v), qs[v].insert(x);
    adj[v].erase(v); qs[v].erase(v);
    fa[u] = v;
}
 
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &q);
        qmp.clear(); fill(ans, ans + q, -1);
        for (int i = 1; i <= n; i++) adj[i].clear(), qs[i].clear();
        iota(fa + 1, fa + n + 1, 1);
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            if (u == v) continue;
            adj[u].insert(v); adj[v].insert(u);
            edges.emplace_back(w, u, v);
        }
        sort(edges.begin(), edges.end());
        for (int i = 0; i < q; i++) {
            int u, v; scanf("%d%d", &u, &v);
            if (u > v) swap(u, v);
            if (adj[u].count(v)) {
                ans[i] = 0;
            } else {
                qmp[{u, v}].push_back(i);
                qs[u].insert(v); qs[v].insert(u);
            }
        }
        for (auto e : edges) unite(get<1>(e), get<2>(e), get<0>(e));
        for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
    }
    return 0;
}