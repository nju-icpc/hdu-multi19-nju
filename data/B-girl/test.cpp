#include <bits/stdc++.h>
#define maxn 100009
using namespace std;
long long MOD = 1e9 + 7;
int n ,m ,Q;
int p[maxn];
vector<pair<int,int> > G[20];
unordered_map<long long, bool > mp;
int ans[maxn];
bool vis[maxn];
struct Node{
    int u, v;
}a[maxn];
 
int findset(int x){
    return p[x] == x ? x : p[x] = findset(p[x]);
}
 
void unionset(int x, int y){
    p[findset(x)] = findset(y);
}
 
 
void init(){
   for(int i = 1; i <= n; i++){
        p[i]= i ;
    }
    for(int i = 1; i <= Q; i++){ans[i] = -1; vis[i] = 0;}
    for(int i = 0; i <= 10; i++)
        G[i].clear();
    mp.clear();
}
 
 
int main(){
        int tt;
        scanf("%d", &tt);
        while(tt--){
            scanf("%d%d%d", &n, &m ,&Q);
            init();
            for(int i = 1; i <= m; i++){
                int x, y, w;
                scanf("%d%d%d", &x, &y, &w);
                G[w].push_back(make_pair(x, y));
            }
            for(int i = 1; i <= Q; i++){
                scanf("%d%d", &a[i].u, &a[i].v);
            }
            for(int i = 0; i <= 10; i++){
                for(int j = 0; j < (int)G[i].size(); j++){
                    int u = G[i][j].first;
                    int v = G[i][j].second;
                    unionset(u, v);
                }
                mp.clear();
                for(int j = i + 1; j <= 10; j++){
                    for(int k = 0; k < (int)G[j].size(); k++){
                        int u = G[j][k].first;
                        int v = G[j][k].second;
                        int fu = findset(u);
                        int fv = findset(v);
                        if(fu == fv) continue;
                        if(fu > fv) swap(fu, fv);
                        mp[fu * MOD + fv] = 1;
                    }
                }
                for(int j = 1; j <= Q; j++){
                    if(vis[j]) continue;
                     int fu = findset(a[j].u);
                     int fv = findset(a[j].v);
                     if(fu == fv) {ans[j] = i; vis[j] = 1;}
                     if(fu > fv) swap(fu, fv);
                     if(mp[fu * MOD + fv]){ans[j] = i; vis[j] = 1;}
                }
            }
            for(int i = 1; i <= Q; i++)
                printf("%d\n", ans[i]);
        }
        return 0;
}
 