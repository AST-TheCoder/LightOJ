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

int main()
{   

    ll tc,ii=0;
    cin>>tc;

    vector<ll> str;

    while(tc--){
        ll n,m;
        cin>>n>>m;

        ll a[n+2][m+2],b[n+2][m+2];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
                cin>>b[i][j];
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=m;j++)
                cin>>a[i][j];

        ll dp[n+2][m+2];
        memset(dp,0,sizeof(dp));

        for(ll i=1;i<=n+1;i++){
            for(ll j=0;j<=m+1;j++){
                a[i][j]+=a[i-1][j];
            }
        }

        for(ll i=0;i<=n+1;i++){
            for(ll j=m;j>=0;j--){
                a[i][j]+=a[i][j+1];
            }
        }

        for(ll i=0;i<=n+1;i++){
            for(ll j=1;j<=m+1;j++){
                b[i][j]+=b[i][j-1];
            }
        }

        ll ans=0;
        for(ll i=n;i>0;i--){
            for(ll j=m;j>=0;j--){
                for(ll k=j;k<=m;k++){
                    dp[i][j]=max(dp[i][j],b[i][j]+a[i][j+1]-a[i][k+1]+dp[i+1][k]);
                }
                ans=max(ans,dp[i][j]);
            }
        }

        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}