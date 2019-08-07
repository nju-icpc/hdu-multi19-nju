#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    int tt = 0;
    while (T--) {
        int n, m, q; scanf("%d%d%d", &n, &m, &q);
        vector<tuple<int, int, int>> edges;
        vector<pair<int, int>> queries;
        while (m--) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            if (u == v) continue;
            edges.emplace_back(u, v, w);
        }
        while (q--) {
            int u, v; scanf("%d%d", &u, &v);
            queries.emplace_back(u, v);
        }
        m = edges.size(); q = queries.size();
        if (n == 0 || m == 0 || q == 0 || max({n, m, q}) >= 10000) continue;
        tt++;
        printf("%d %d %d\n", n, m, q);
        for (auto [u, v, w] : edges) printf("%d %d %d\n", u, v, w);
        for (auto [u, v] : queries) printf("%d %d\n", u, v); 
    }
    fprintf(stderr, "T=%d\n", tt);
    return 0;
}
