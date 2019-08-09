/*
    This std code doesn't compile on HDUOJ. If you need a code that compiles
  on HDUOJ, please see lhy.cpp.
*/
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define Rep(i, n) for (int i = 1; i <=int(n); i++)
#define range(x) begin(x), end(x)
#ifdef __LOCAL_DEBUG__
#define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", __func__, ##__VA_ARGS__)
#else
#define _debug(...) ((void) 0)
#endif
typedef long long LL;
typedef unsigned long long ULL;

enum { U, R, D, L };
const int MAXN = 6 * 64 * 64;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const tuple<int, int, int> adj_info[6][4] = {
    // ------------------------------------------------------
    // |    UP      |    RIGHT    |    DOWN     |    LEFT   |
    // ------------------------------------------------------
    {  { 4, L, +1 }, { 1, L, +1 }, { 5, L, -1 }, { 3, R, +1 } },    // 0
    {  { 4, D, +1 }, { 2, L, +1 }, { 5, U, +1 }, { 0, R, +1 } },    // 1
    {  { 4, R, -1 }, { 3, L, +1 }, { 5, R, +1 }, { 1, R, +1 } },    // 2 
    {  { 4, U, -1 }, { 0, L, +1 }, { 5, D, -1 }, { 2, R, +1 } },    // 3 
    {  { 3, U, -1 }, { 2, U, -1 }, { 1, U, +1 }, { 0, U, +1 } },    // 4
    {  { 1, D, +1 }, { 2, D, +1 }, { 3, D, -1 }, { 0, D, -1 } },    // 5
};

int n;
int adj[MAXN][4], adj_dir[MAXN][4], tag[MAXN], deg[MAXN];

inline int getid(int f, int x, int y) { return f * n * n + x * n + y; }

int compute_id(int x, int y, int ff, int fd) {
    int tf, td, sgn; tie(tf, td, sgn) = adj_info[ff][fd];
    int c = (fd == U || fd == D ? y : x);
    if (sgn < 0) c = n - 1 - c; 
                        //  U    R    D    L
    int xx = array<int, 4>{ 0,   c,   n-1, c }[td], 
        yy = array<int, 4>{ c,   n-1, c,   0 }[td];
    return getid(tf, xx, yy);
}

void init() {
    for (int f = 0; f < 6; f++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int id = getid(f, x, y); tag[id] = 0;
                for (int i = 0; i < 4; i++) {
                    int xx = x + dx[i], yy = y + dy[i];
                    int cr = -1;
                    if (xx < 0) cr = U; if (xx >= n) cr = D;
                    if (yy < 0) cr = L; if (yy >= n) cr = R;
                    if (cr == -1) {
                        adj[id][i] = getid(f, xx, yy);
                        adj_dir[id][i] = i;
                    } else {
                        adj[id][i] = compute_id(x, y, f, cr);
                        adj_dir[id][i] = (get<1>(adj_info[f][cr]) + 2) & 3;
                    }
                    deg[adj[id][i]]++;
                }
            }
        }
    }
    for (int i = 0; i < 6 * n * n; i++) 
        if (deg[i] != 4) _debug("deg[%d]=%d", i, deg[i]);
}

int nx, ny;
char g[512][512];
int vis[512][512];

void dfs(int x, int y, int id, int dir) {
    if (x < 0 || y < 0 || x >= nx || y >= ny) return;
    if (g[x][y] != '#' || vis[x][y]) return;
    if (tag[id]) throw 0;
    vis[x][y] = id / (n * n) + 1; tag[id] = 1;
    for (int i = 0; i < 4; i++) { 
        int adir = (i + dir) & 3;
        dfs(x + dx[i], y + dy[i], adj[id][adir], (adj_dir[id][adir] - i) & 3);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        memset(adj, 0, sizeof adj);
        memset(adj_dir, 0, sizeof adj_dir);
        memset(deg, 0, sizeof deg);
        memset(g, 0, sizeof g);
        scanf("%d%d", &nx, &ny);
        rep (i, nx) scanf("%s", g[i]);
        int tot = 0;
        int x, y;
        for (int i = nx - 1; i >= 0; i--)
            for (int j = ny - 1; j >= 0; j--) if (g[i][j] == '#') {
                x = i; y = j; tot++;
            }
        n = sqrt(tot / 6);
        if (n * n * 6 != tot) {
            puts("no");
            continue;
        }
        init();
        rep (id, n * n) {
            try {
                memset(vis, 0, sizeof vis);
                memset(tag, 0, sizeof tag);
                dfs(x, y, id, 0);
                puts("yes");
                goto cont;
            } catch (...) {
            }
        }
        puts("no");
        cont:;
    }
    return 0;
}
