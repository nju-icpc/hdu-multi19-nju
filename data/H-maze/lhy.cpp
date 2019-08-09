#include<bits/stdc++.h>
#define maxn 100005
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
vector <pi> h[maxn];
mt19937 gen(152349568);
const int inf=1e9;
int a[maxn],dp[maxn][64],color[maxn],T,n,m,k,temp,ans;
const int temp1=250;
const int temp2=500;
void Max(int &x,int y){if (x<y) x=y;}
int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&n,&m,&k); ans=0;
        for (int i=1;i<=n;i++) h[i].clear();
        while (m--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            h[u].pb((pi){v,w});
            h[v].pb((pi){u,w});
        }
        if (n<=50) temp=temp2; else temp=temp1;
        while (temp--){
            for (int i=1;i<=n;i++)
                for (int j=0;j<(1<<k);j++)
                    dp[i][j]=-inf;
            for (int i=1;i<=n;i++) color[i]=gen()%k,dp[i][1<<color[i]]=0;
            for (int j=1;j<(1<<k)-1;j++)
            for (int i=1;i<=n;i++) if (dp[i][j]>=0){
                for (auto e:h[i]) {
                    if (j&(1<<color[e.F])) continue;
                    Max(dp[e.F][j|(1<<color[e.F])],dp[i][j]+e.S);
                }
            }
            for (int i=1;i<=n;i++) Max(ans,dp[i][(1<<k)-1]);
        }
        if (ans==0) puts("impossible"); else cout << ans << endl;
    }
    return 0;
}