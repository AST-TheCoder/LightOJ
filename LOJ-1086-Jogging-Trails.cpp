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

ll dp[16][16500],dis[16][16];
vector<ll> g;

ll solve(ll p,ll mask){
    ll n=g.size();
    ll cnt=0;
    for(ll i=0;i<n;i++){
        if(mask&(1<<i)) cnt++;
    }

    if(cnt==n) return 0;
    if(dp[p][mask]!=-1) return dp[p][mask];

    dp[p][mask]=Max;
    for(ll i=0;i<n;i++){
        if(!(mask&(1<<i))){
            if(cnt%2) dp[p][mask]=min(dp[p][mask],solve(0,mask|(1<<i))+dis[g[p]][g[i]]);
            else{
                dp[p][mask]=solve(i,mask|(1<<i));
                break;
            }
        }
    }
    return dp[p][mask];
}

int main()
{   
    ll t,ii=0;
    scanf("%lli",&t);

    while(t--){
        memset(dp,-1,sizeof(dp));
        ll n,m;
        scanf("%lli %lli",&n,&m);
        ll cnt[n+1],ans=0;
        for(ll i=1;i<=n;i++){
            cnt[i]=0;
            for(ll j=1;j<=n;j++){
                dis[i][j]=Max;
            }
        }

        for(ll i=0;i<m;i++){
            ll u,v,p;
            cin>>u>>v>>p;
            ans+=p;
            cnt[u]++;
            cnt[v]++;
            dis[u][v]=min(dis[u][v],p);
            dis[v][u]=min(dis[v][u],p);
        }

        for(ll k=1;k<=n;k++){
            for(ll i=1;i<=n;i++){
                for(ll j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
                }
            }
        }

        g.clear();
        for(ll i=1;i<=n;i++){
            if(cnt[i]%2) g.pb(i);
        }

        ans+=solve(0,1);
        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}