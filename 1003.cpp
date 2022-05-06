    #include<bits/stdc++.h>
    using namespace std;
     
    typedef unsigned long long ll;
    vector<vector<int> > a(10001);
    vector<int> v(10001);
    vector<int> ans;
    bool X=false;
    void dfs(int n)
    {
        if(v[n]==1)
        {
            X=true;
            return;
        }
        if(v[n]==2)
        {
            return;
        }
        v[n]=1;
        for(auto e:a[n])
        {
            dfs(e);
        }
        v[n]=2;
        ans.push_back(n);
        return;
    }
     
    int main()
    {
        int n,m;
        int t;
        cin>>t;
        int I=1;
        while(t--)
        {
            cin>>m;
            for(int i=0;i<a.size();i++)
            {
                a[i].clear();
            }
            fill(v.begin(),v.end(),0);
            int i=1;
            map<string,int> mp;
            string x,z;
            while(m--)
            {
                cin>>x>>z;
                if(!mp[x])mp[x]=i++;
                if(!mp[z])mp[z]=i++;
                a[mp[x]].push_back(mp[z]);
            }
            for(int ii=1;ii<i;ii++){
            if(!v[ii])
                dfs(ii);
            }
            if(X)
            {
                cout<<"Case "<<I++<<": No\n";
            }
            else{
                cout<<"Case "<<I++<<": Yes\n";
     
            }
            ans.clear();
            X=false;
        }
     
    }
     