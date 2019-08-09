#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 100, "T"); inf.readEoln();
    int totn = 0, totm = 0, totq = 0;
    for (int t = 1; t <= T; t++) {
        int n = inf.readInt(1, 100000, "n"); inf.readSpace();
        int m = inf.readInt(1, 200000, "m"); inf.readSpace();
        int q = inf.readInt(1, 100000, "q"); inf.readEoln();
        
        totn += n; totm += m; totq += q;

        for (int i = 0; i < m; i++) {
            int u = inf.readInt(1, n, "u"); inf.readSpace();
            int v = inf.readInt(1, n, "v"); inf.readSpace();
            ensuref(u != v, "u == v, edge (%d, %d) [%d:%d]", u, v, t, i);
            int w = inf.readInt(1, 1000000000, "w"); inf.readEoln();
        }
        for (int i = 0; i < q; i++) {
            int u = inf.readInt(1, n, "u"); inf.readSpace();
            int v = inf.readInt(1, n, "v"); inf.readEoln();
            ensuref(u != v, "u == v, query (%d, %d) [%d:%d]", u, v, t, i);
        }
    }
    inf.readEof();
    fprintf(stderr, "Total n: %d\n", totn);
    fprintf(stderr, "Total m: %d\n", totm);
    fprintf(stderr, "Total q: %d\n", totq);
    return 0;
}
