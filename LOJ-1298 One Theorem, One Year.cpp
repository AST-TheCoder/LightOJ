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

ll pre[501][501],ph[501];
bool c[5001];
int main()
{   
    ll t,ii=0,mod=1000000007;
    vector<ll> pr;
    pr.pb(1);
    for(ll i=2;i<=5000;i++){
        if(!c[i]){
            for(ll j=i;j<=5000;j+=i){
                c[j]=1;
            }
            pr.pb(i);
        }
    }

    for(ll k=1;k<=500;k++){
        for(ll p=1;p<=500;p++){
            ll v=pr[p];
            if(k!=1) pre[k][p]=((pre[k-1][p]*v)%mod+pre[k][p-1])%mod;
            else pre[k][p]=(v+pre[k][p-1])%mod;
        }
    }

    ph[0]=1;
    for(ll i=1;i<=500;i++){
        ph[i]=(ph[i-1]*(pr[i]-1))%mod;
    }

    cin>>t;
    read:
    while(t--){
        ll k,p;
        cin>>k>>p;
        k-=p;
        ll ans=ph[p];
        if(k) ans=(ans*pre[k][p])%mod;
        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}
