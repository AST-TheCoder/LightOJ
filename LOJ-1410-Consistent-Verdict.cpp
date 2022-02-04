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

int main(){
    ll t,ii=0;
    scanf("%lli",&t);
    while(t--){
        vector<ll> s;
        ll n,ans=1;
        scanf("%lli",&n);

        ll x[n],y[n];
        for(ll i=0;i<n;i++) scanf("%lli %lli",&x[i],&y[i]);

        for(ll i=0;i<n;i++){
            for(ll j=i;j<n;j++){
                ll temp=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                s.pb(temp);
            }
        }

        sort(all(s));
        for(ll i=1;i<s.size();i++)
            if(s[i]!=s[i-1])
                ans++;

        printf("Case %lli: %lli\n",++ii,ans);
    }

    return 0;
}