#include<bits/stdc++.h>
#define fi(n, m) for(int i=n; i<=m; i++)
#define fd(n, m) for(int i=n; i>=m; i--)
using namespace std;
int x, pr[105], n;

struct edge{
    int u, v, w;
}one[12005];

bool comp(edge f, edge s){
    return f.w<s.w;
}

int find(int p){
    if(pr[p]==p) return p;
    else return find(pr[p]);
}

int mst(int st){
    int cnt=0, sm=0, xx, yy;
    fi(0, n)pr[i]=i;
    fi(0, x-1){
        xx=find(one[i].u);
        yy=find(one[i].v);
        if(xx!=yy){
            cnt++;
            sm+=one[i].w;
            pr[yy]=xx;
        }
        if(cnt==n) break;
    }
    return sm;
}

int mxst(int st){
    int cnt=0, sm=0, xx, yy;
    fi(0, n)pr[i]=i;
    fd(x-1, 0){
        xx=find(one[i].u);
        yy=find(one[i].v);
        if(xx!=yy){
            cnt++;
            pr[yy]=xx;
            sm+=one[i].w;
        }
        if(cnt==n) break;
    }
    return sm;
}

int main(){
    int t, cs=1, u, v, w, up, dwn;
    cin>>t;
    while(t--){
        cin>>n;
        x=0;
        while(1){
            cin>>u>>v>>w;
            if(u==0&&v==0&&w==0) break;
            one[x].u=u;
            one[x].v=v;
            one[x].w=w;
            x++;
        }
        sort(one, one+x, comp);
        up=mxst(0);
        dwn=mst(0);
        cout<<"Case "<<cs++<<": ";
        if((up+dwn)%2==0) cout<<(up+dwn)/2<<endl;
        else cout<<up+dwn<<"/"<<2<<endl;
    }
    return 0;
}