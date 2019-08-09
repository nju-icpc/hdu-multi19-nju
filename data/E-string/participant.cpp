#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
 
const int maxn=300005;
const int maxs=27;
struct suffix_array  //each character should between 0~maxs-1,modify "read()" if nessisary
{
    char s[maxn];
    int sa[maxn],t[maxn],t2[maxn],c[maxn],n;
    int rank[maxn],height[maxn];
    void read()
    {
        scanf("%s",s);
        n=strlen(s);
        for(int i=0;i<n;i++) //*note or change it if not use
            s[i]-='a'-1;
    }
    void get_sa()
    {
        memset(t,-1,sizeof(t));
        memset(t2,-1,sizeof(t2));
        int m=maxs;
        int *x=t,*y=t2;
        for(int i=0;i<m;i++)
            c[i]=0;
        for(int i=0;i<n;i++)
            c[x[i]=s[i]]++;
        for(int i=1;i<m;i++)
            c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--)
            sa[--c[x[i]]]=i;
        for(int k=1;k<=n;k<<=1)
        {
            int p=0;
            for(int i=n-k;i<n;i++)
                y[p++]=i;
            for(int i=0;i<n;i++)
                if(sa[i]>=k)
                    y[p++]=sa[i]-k;
            for(int i=0;i<m;i++)
                c[i]=0;
            for(int i=0;i<n;i++)
                c[x[y[i]]]++;
            for(int i=1;i<m;i++)
                c[i]+=c[i-1];
            for(int i=n-1;i>=0;i--)
                sa[--c[x[y[i]]]]=y[i];
            swap(x,y);
            p=1;
            x[sa[0]]=0;
            for(int i=1;i<n;i++)
                x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
            if(p>=n)
                break;
            m=p;
        }
    }
    void get_height()
    {
        int k=0;
        for(int i=0;i<n;i++)
            rank[sa[i]]=i;
        for(int i=0;i<n;i++)
        {
            if(k)
                k--;
            if(rank[i]==0)
            {
                k=0;
                continue;
            }
            int j=sa[rank[i]-1];
            while(s[i+k]==s[j+k])
            {
                k++;
            }
            height[rank[i]]=k;
        }
    }
    int d[maxn][20];
    void rmq()
    {
        for(int i=1;i<n;i++)
            d[i][0]=height[i];
        for(int j=1;(1<<j)<=n;j++)
            for(int i=1;i+(1<<j)-1<n;i++)
                d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
    }
    int get_pre(int l,int r)
    {
        if(l==r)
            return n-l;
        l=rank[l];
        r=rank[r];
        if(r<l)
            swap(r,l);
        l++;
        int k=0;
        while((1<<(k+1))<=r-l+1)
            k++;
        return min(d[l][k],d[r-(1<<k)+1][k]);
    }
    void init()
    {
        get_sa();
        get_height();
        rmq();
    }
}data[2];
int n,k;
void readin()
{
    scanf("%d",&k);
    data[0].read();
    n=data[0].n;
    data[0].s[n]='\0';
    data[1].n=n;
    for(int i=0;i<n;i++)
        data[1].s[i]=data[0].s[n-i-1];
    data[1].s[n]='\0';
    for(int i=0;i<2;i++)
        data[i].init();
}
void solve()
{
    if(k==1)
    {
        printf("%lld\n",(long long)n*(n+1)/2);
        return ;
    }
    long long ans=0;
    for(int p=1;p<=n/k;p++)
    {
        for(int i=0;i<n;i+=p)
        {
            int a=0,b=0;
            if(i+p<n)
                a=data[0].get_pre(i,i+p);
            if(i&&i+p-1<n)
                b=data[1].get_pre(n-i,n-i-p);
            if(a+b+p>=p*k&&b<p)
            {
                ans+=a+b+p-p*k+1;
            }
        }
    }
    printf("%lld\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        readin();
        solve();
    }
    return 0;
}
 