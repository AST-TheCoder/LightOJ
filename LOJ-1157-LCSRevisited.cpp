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

ll dp[1001][1001],cnt[1001][1001],mod=1000007;
string s,t;
ll solve(ll i, ll j){
    if(!i || !j) return 1;
    if(cnt[i][j]!=-1) return cnt[i][j];
    cnt[i][j]=0;
    if(s[i]==t[j]) return cnt[i][j]=solve(i-1,j-1);
    if(dp[i][j]==dp[i-1][j-1]) cnt[i][j]=(cnt[i][j]-solve(i-1,j-1)+mod)%mod;
    if(dp[i][j]==dp[i-1][j]) cnt[i][j]=(cnt[i][j]+solve(i-1,j))%mod;
    if(dp[i][j]==dp[i][j-1]) cnt[i][j]=(cnt[i][j]+solve(i,j-1))%mod;

    return cnt[i][j];
}

int main()
{   

    ll tc,ii=0;
    cin>>tc;

    vector<ll> str;

    while(tc--){
        cin>>s>>t;
        s='#'+s;
        t='#'+t;

        for(ll i=1;i<s.size();i++){
            for(ll j=1;j<t.size();j++){
                cnt[i][j]=-1;
                if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        ll ans=solve(s.size()-1,t.size()-1);
        str.pb(ans);
    }

    for(ll i=1;i<=str.size();i++){
        ll ans=str[i-1];
        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}