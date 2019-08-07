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
}

const int MAXSZ = 2048;
int xl, xr, yl, yr;
char g[MAXSZ][MAXSZ];

function<array<int, 4>()> func;

void dfs(int x, int y, int id, int dir) {
    if (tag[id]) return;
    _debug("id=%d", id);
    g[x][y] = '#'; tag[id] = true;
    for (int i : func()) {
        int adir = (i + dir) & 3;
        dfs(x + dx[i], y + dy[i], adj[id][adir], (adj_dir[id][adir] - i) & 3); 
    }
}

mt19937 gen(998244353);

bool col_empty(int x) {
    rep (i, MAXSZ) if (g[x][i] == '#') return false;
    return true;
}

bool row_empty(int x) {
    rep (i, MAXSZ) if (g[i][x] == '#') return false;
    return true;
}

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);
    int tp = atoi(argv[2]);
    if (argc > 3) gen.seed(atoi(argv[3]));
    switch (tp) {
    case 0:
        func = [] { return array<int, 4>{{0, 1, 2, 3}}; };
        break;
    case 1:
        func = [] { return array<int, 4>{{3, 2, 1, 0}}; };
        break;
    case 2:
        func = [] { return array<int, 4>{{1, 3, 0, 2}}; };
        break;
    case 3:
        func = [] { return array<int, 4>{{3, 1, 2, 0}}; };
        break;
    case 4:
        func = [] { 
            array<int, 4> x = {{0, 1, 2, 3}};
            shuffle(x.begin(), x.end(), gen);
            return x;
        };
        break;
    default: assert(0);
    }
    init();
    dfs(MAXSZ / 2, MAXSZ / 2, gen() % (n * n * 6), gen() & 3);
    while (col_empty(xl)) xl++;
    xr = MAXSZ - 1; while (col_empty(xr)) xr--;
    while (row_empty(yl)) yl++;
    yr = MAXSZ - 1; while (row_empty(yr)) yr--;
    printf("%d %d\n", xr - xl + 1, yr - yl + 1);
    int cnt = 0;
    for (int i = xl; i <= xr; i++) {
        for (int j = yl; j <= yr; j++) 
            if (g[i][j] == '#') putchar('#'), cnt++; else putchar('.');
        putchar('\n');
    }
    cerr << cnt << endl;
    return 0;
}
