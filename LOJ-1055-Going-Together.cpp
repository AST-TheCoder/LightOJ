#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end() 
#define Max 10000000000000000
#define min_heap priority_queue <ll, vector<ll>, greater<ll> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll dis[101][101][101];

int main()
{   
    ll t,ii=0;
    scanf("%lli",&t);

    while(t--){
        ll n;
        scanf("%lli",&n);

        string s[n];
        ll g[n*n+1][4];
        set<ll> b,d;
        for(ll i=0;i<n;i++) cin>>s[i];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(s[i][j]!='#'){
                    ll u=i*n+j+1;
                    if(i-1>=0 && s[i-1][j]!='#') g[u][0]=((i-1)*n+j+1);
                    else g[u][0]=u;
                    if(i+1<n && s[i+1][j]!='#') g[u][2]=((i+1)*n+j+1);
                    else g[u][2]=u;
                    if(j-1>=0 && s[i][j-1]!='#') g[u][1]=(i*n+j);
                    else g[u][1]=u;
                    if(j+1<n && s[i][j+1]!='#') g[u][3]=(i*n+j+2);
                    else g[u][3]=u;
                }
                if(s[i][j]=='A' || s[i][j]=='B' || s[i][j]=='C') b.insert(i*n+j+1);
                if(s[i][j]=='X') d.insert(i*n+j+1);
            }
        }
        for(ll i=1;i<=n*n;i++){
            for(ll j=1;j<=n*n;j++){
                for(ll k=1;k<=n*n;k++){
                    dis[i][j][k]=-1;
                }
            }
        }
        queue<set<ll>> q;
        q.push(b);
        vector<ll> u;
        for(auto val:b) u.pb(val);
        dis[u[0]][u[1]][u[2]]=0;


        while(!q.empty()){
            u.clear();
            set<ll> temp=q.front();
            q.pop();
            for(auto val:temp) u.pb(val);
            //cout<<u[0]<<" "<<u[1]<<" "<<u[2]<<" "<<dis[u[0]][u[1]][u[2]]<<endl;
            for(ll i=0;i<4;i++){
                set<ll> p;
                ll a,b,c;
                if(i<=1){
                    a=g[u[0]][i];
                    if(g[u[1]][i]!=a) b=g[u[1]][i];
                    else b=u[1];
                    if(g[u[2]][i]!=a && g[u[2]][i]!=b) c=g[u[2]][i];
                    else c=u[2];
                }
                else{
                    a=g[u[2]][i];
                    if(g[u[1]][i]!=a) b=g[u[1]][i];
                    else b=u[1];
                    if(g[u[0]][i]!=a && g[u[0]][i]!=b) c=g[u[0]][i];
                    else c=u[0];
                }
                //cout<<a<<" "<<b<<" "<<c<<endl;
                p.insert(a);
                p.insert(b);
                p.insert(c);
                vector<ll> v;
                for(auto val:p) v.pb(val);
                if(dis[v[0]][v[1]][v[2]]==-1){
                    dis[v[0]][v[1]][v[2]]=dis[u[0]][u[1]][u[2]]+1;
                    q.push(p);
                }
            }
        }
        u.clear();
        for(auto val:d) u.pb(val);
        cout<<"Case "<<++ii<<": ";
        if(dis[u[0]][u[1]][u[2]]==-1) cout<<"trapped"<<endl;
        else cout<<dis[u[0]][u[1]][u[2]]<<endl;
    }

    return 0;
}