#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> g;

template <char ch>
void dfs(int x, int y) {
    if (x < 0 || y < 0 || x > n + 1 || y > m + 1) return;
    if (g[x][y] == ' ') return;
    if (g[x][y] == ch) {
        g[x][y] = ' ';
        dfs<ch>(x-1, y);
        dfs<ch>(x+1, y);
        dfs<ch>(x, y-1);
        dfs<ch>(x, y+1);
    }
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int T = inf.readInt(1, 30, "T"); inf.readEoln();
    int totsz = 0;
    for (int t = 1; t <= T; t++) {
        n = inf.readInt(1, 100, "n"); inf.readSpace();
        m = inf.readInt(1, 100, "m"); inf.readEoln();
        totsz += n * m;
        g.resize(n + 2);
        g.front() = g.back() = string(m + 2, '.');
        for (int i = 1; i <= n; i++) {
            g[i] = inf.readToken(); inf.readEoln();
            ensuref(g[i].size() == m, "size error: row=%d, T=%d", i, t);
            for (char ch : g[i]) 
                ensuref(ch == '#' || ch == '.', 
                    "mysterious character: row=%d, T=%d", i, t);
            g[i] = "." + g[i] + ".";
        }
        int x = -1, y = -1;
        for (x = 1; x <= n; x++) for (y = 1; y <= m; y++)
            if (g[x][y] == '#') goto cont;
        ensuref(x != -1, "input is empty (T=%d)", t);
    cont:
        dfs<'#'>(x, y);
        dfs<'.'>(0, 0);
        for (auto& s : g) for (char ch : s) 
            ensuref(ch == ' ', "not connected (T=%d)", t);
    }
    inf.readEof();
    fprintf(stderr, "total size = %d\n", totsz);
    return 0;
}
