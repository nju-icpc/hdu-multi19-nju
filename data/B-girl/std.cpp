#include <bits/stdc++.h>
using namespace std;
  
struct hasher {
    size_t operator ()(const pair<int, int>& pr) const {
#if SIZE_MAX == UINT64_MAX
        return size_t(pr.first) << 32 | size_t(pr.second);
#else
        return (size_t)pr.first * pr.second;
#endif
    }
};
  
const int MAXN = 100005;
int n, m, q;
unordered_set<int> adj[MAXN], qs[MAXN];
unordered_map<pair<int, int>, list<int>, hasher> qmp;
int w1[MAXN], w2[MAXN];
int ans[MAXN];
int fa[MAXN];
   
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

#ifndef POLICY 
#   define POLICY 0
#endif
void unite(int& u, int& v) {
    u = find(u); v = find(v); if (u == v) return;
#if POLICY == 0
    if (w1[u] + w2[u] > w1[v] + w2[v]) swap(u, v);
#elif POLICY == 1
    if (w1[u] > w1[v]) swap(u, v);
#elif POLICY == 2
    if (w2[u] > w2[v]) swap(u, v);
#elif POLICY == 3
    if (rand() & 1) swap(u, v);
#endif
    w1[v] += w1[u]; w2[v] += w2[u];
    fa[u] = v;
}
  
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
    if (u == v) return;
    for (int x : adj[u]) if (qs[v].count(x)) commit(x, v, w);
    for (int x : qs[u]) if (adj[v].count(x)) commit(x, u, w);
    merge_queries(u, v);
    for (int x : adj[u]) adj[x].erase(u), adj[x].insert(v), adj[v].insert(x);
    for (int x : qs[u]) qs[x].erase(u), qs[x].insert(v), qs[v].insert(x);
    adj[v].erase(v); qs[v].erase(v);
}
   
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &q);
        qmp.clear(); fill(ans, ans + q, -1);
        for (int i = 1; i <= n; i++) adj[i].clear(), qs[i].clear();
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            if (u == v) continue;
            adj[u].insert(v); adj[v].insert(u);
            edges.emplace_back(w, u, v);
        }
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
        for (int i = 1; i <= n; i++) {
            w1[i] = adj[i].size();
            w2[i] = qs[i].size();
        }
        sort(edges.begin(), edges.end());
        iota(fa + 1, fa + n + 1, 1);
        for (auto &e : edges) unite(get<1>(e), get<2>(e)); // dry run
        for (int i = 1; i <= n; i++) {
            adj[i].reserve(w1[i] * 2);
            qs[i].reserve(w2[i] * 2);
        }
        for (auto e : edges) unite(get<1>(e), get<2>(e), get<0>(e));
        for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
    }
    return 0;
}
