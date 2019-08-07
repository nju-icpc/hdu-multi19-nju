#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL mod = 1006658951440146419, g = 967;
const int MAXN = 300005;
LL pg[MAXN];

inline LL mul(LL x, LL y) {
    return __int128_t(x) * y % mod;
}

void init_hash() {
    pg[0] = 1;
    for (int i = 1; i < MAXN; i++) 
        pg[i] = mul(pg[i-1], g);
}

struct hasher {
    LL val[MAXN];

    void build(const char *str) {
        val[0] = 0;
        for (int i = 0; str[i]; i++) 
            val[i+1] = (mul(val[i], g) + str[i]) % mod;
    }

    LL operator() (int l, int r) {
        return (val[r] - mul(val[l], pg[r-l]) + mod) % mod;
    }
} ha;

int n, k;
char str[MAXN];

int work(int len) {
    int cnt = 0;
    int seg = len / k;
    for (int i = 0; i + len <= n; i++)
        if (ha(i, i + len - seg) == ha(i + seg, i + len)) 
            cnt++;
    return cnt;
}

int main() {
    init_hash();
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &k);
        scanf("%s", str);
        n = strlen(str);
        ha.build(str);
        atomic<LL> cnt;
        atomic<int> ticket;
        cnt = 0; ticket = 0;

        vector<thread> thrd;
        for (int i = 0; i < thread::hardware_concurrency(); i++) {
            thrd.emplace_back([&]() {
                do {
                    int cur = ++ticket;
                    if (cur * k > n) break;
                    cnt += work(cur * k);
                } while (true);
            });
        }
        for (auto& th : thrd) th.join();
        cout << cnt << endl;
    }
    return 0;
}
