#include<bits/stdc++.h>
using namespace std;
int x[169000][4],y[169000][4],T,X[4],Y[4],s[14][2];
const int E=1e9;
mt19937_64 gen(19260817);
int work(int l,int r,int o){
    if (o==0) return gen()%l;
    else if (o==1) return l;
    else if (o==2) return l+1+gen()%(r-l-1);
    else if (o==3) return r;
    else return r+1+gen()%(E-r);
}

int main(){
    T=10000;
    int cc=0;
    for (int i=0;i<5;i++)
    for (int j=i+1;j<5;j++){
        s[cc][0]=i; s[cc][1]=j;
        ++cc;
    }
    for (int i=0;i<=4;i+=2){
        s[cc][0]=i; s[cc][1]=i;
        ++cc;
    }
    for (int o=0;o<1000;o++){
        for (int i=0;i<169;i++){
            while (true){
                X[0]=gen()%(E+1);
                X[1]=gen()%(E+1);
                if (min(X[0],X[1])>=3&&max(X[0],X[1])<=E-3&&abs(X[0]-X[1])>=3) break;
            }
            Y[0]=X[0]; Y[1]=X[1];
            while (true){
                X[0]=gen()%(E+1);
                X[1]=gen()%(E+1);
                if (min(X[0],X[1])>=3&&max(X[0],X[1])<=E-3&&abs(X[0]-X[1])>=3) break;
            }
            if (X[0]>X[1]) swap(X[0],X[1]);
            if (Y[0]>Y[1]) swap(Y[0],Y[1]);
            while (true){
                X[2]=work(X[0],X[1],s[i/13][0]);
                X[3]=work(X[0],X[1],s[i/13][1]);
                if (X[2]<X[3]) break;
            }
            while (true){
                Y[2]=work(Y[0],Y[1],s[i%13][0]);
                Y[3]=work(Y[0],Y[1],s[i%13][1]);
                if (Y[2]<Y[3]) break;
            }
            for (int j=0;j<4;j++) x[o*169+i][j]=X[j],y[o*169+i][j]=Y[j];
        }
    }
    cout<<T<<endl;
    for (int i=0;i<T;i++){
        cout<<x[i][0]<<' '<<y[i][0]<<' '<<x[i][1]<<' '<<y[i][1]<<endl;
        cout<<x[i][2]<<' '<<y[i][2]<<' '<<x[i][3]<<' '<<y[i][3]<<endl;
    }
}

