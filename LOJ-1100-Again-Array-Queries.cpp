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
    ll t,ii=0;
    scanf("%lli",&t);

    while(t--){
        ll n,q;
        cin>>n>>q;

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];

        cout<<"Case "<<++ii<<":"<<endl;
        while(q--){
            ll l,r;
            cin>>l>>r;

            if(r-l+1>1000){
                cout<<0<<endl;
                continue;
            }

            vector<ll> v;
            for(ll i=l;i<=r;i++) v.pb(a[i]);
            sort(all(v));
            ll ans=Max;
            for(ll i=1;i<v.size();i++) ans=min(ans,v[i]-v[i-1]);
            cout<<ans<<endl;
        }
    }

    return 0;
}