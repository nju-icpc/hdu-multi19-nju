#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 30, "T"); inf.readEoln();
    int bigcase = 0;
    for (int t = 1; t <= T; t++) {
        int n = inf.readInt(1, 10000, "n"); inf.readSpace();
        int m = inf.readInt(1, 10000, "m"); inf.readSpace();
        if (max(n, m) > 100) bigcase++;
        inf.readInt(2, 6, "k"); inf.readEoln();
        set<pair<int, int>> edges;
        for (int i = 0; i < m; i++) {
            int a = inf.readInt(1, n, "a"); inf.readSpace();
            int b = inf.readInt(1, n, "b"); inf.readSpace();
            inf.readInt(1, 100000000, "w"); inf.readEoln();
            ensure(a != b);
            ensure(edges.count({a, b}) == 0);
            edges.emplace(a, b);
        }
    }
    ensure(bigcase <= 5);
    inf.readEof();
    return 0;
}
