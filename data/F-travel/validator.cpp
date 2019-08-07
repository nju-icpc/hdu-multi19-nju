#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int fa[1 << 20];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
bool unite(int u, int v) {
    u = find(u); v = find(v);
    fa[u] = v;
    return u != v;
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 30, "T"); inf.readEoln();
    int totn = 0;
    for (int t = 1; t <= T; t++) {
        int n = inf.readInt(1, 100000, "n"); inf.readEoln(); totn += n;
        iota(fa + 1, fa + n + 1, 1);
        for (int i = 0; i < n; i++) {
            inf.readInt(0, 1000000000, "a");
            if (i == n - 1) inf.readEoln(); else inf.readSpace();
        }
        for (int i = 0; i < n; i++) {
            inf.readInt(0, 1000000000, "b");
            if (i == n - 1) inf.readEoln(); else inf.readSpace();
        }
        for (int i = 1; i < n; i++) {
            int x = inf.readInt(1, n, "x"); inf.readSpace();
            int y = inf.readInt(1, n, "y"); inf.readEoln();
            ensure(unite(x, y));
        }
    }
    inf.readEof();
    fprintf(stderr, "Total n: %d\n", totn);
    ensure(totn <= 501000);
    return 0;
}
