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

ll n,k;
ll dp[100007],a[100007],des[100007];

ll solve(ll pos){
    if(pos>=n) return 0;
    if(dp[pos]!=-1) return dp[pos];
    dp[pos]=Max;

    for(ll i=des[pos];i>=des[pos]-2;i--){
        if(i-pos+1>=3) dp[pos]=min(dp[pos],solve(i+1)+1);
    }
    return dp[pos];
}

int main()
{   
    ll t,ii=0;
    scanf("%lli",&t);

    while(t--){
        memset(dp,-1,sizeof(dp));
        scanf("%lli %lli",&n,&k);
        for(ll i=0;i<n;i++) scanf("%lli",&a[i]);
        sort(a,a+n);

        for(ll i=0,j=0;i<n;){
            if(j<n && a[j]<=a[i]+2*k) j++;
            else{
                des[i]=j-1;
                i++;
            }
        }

        ll ans=solve(0);
        if(ans>=Max) ans=-1;
        printf("Case %lli: %lli\n",++ii,ans);
    }

    return 0;
}