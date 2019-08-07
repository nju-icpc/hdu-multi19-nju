#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
const int MAXN = 200005;
int n;
int a[MAXN];
vector<int> adj[MAXN];
vector<LL> mem[2][MAXN];
 
template <bool f>
LL dp(int u, int p, LL &mr) {
    typedef typename conditional<f, greater<LL>, less<LL>>::type cmp;
    if (mr != LLONG_MAX) return mr;
    if (adj[u].size() == bool(p)) return mr = a[u];
    LL ret = f ? LLONG_MIN : LLONG_MAX;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i]; if (v == p) continue; 
        ret = min(ret, dp<!f>(v, u, mem[!f][u][i]), cmp());
    }
    return mr = a[u] + ret;
}
 
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        for (int i = 1, x; i <= n; i++)
            scanf("%d", &x), a[i] -= x;
        for (int i = 1; i < n; i++) {
            int u, v; scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int f = 0; f < 2; f++) {
            mem[f][0].assign(n, LLONG_MAX);
            for (int i = 1; i <= n; i++)
                mem[f][i].assign(adj[i].size(), LLONG_MAX);
        }
        LL ret = LLONG_MIN;
        for (int i = 1; i <= n; i++)
            ret = max(ret, dp<false>(i, 0, mem[0][0][i - 1])); 
        printf("%lld\n", ret);
    }
    return 0;
}
