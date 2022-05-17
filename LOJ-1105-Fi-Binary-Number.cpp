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
    ll cnt[45];
    cnt[0]=0;
    cnt[1]=1;
    for(ll i=2;i<45;i++) cnt[i]=cnt[i-1]+cnt[i-2];
    for(ll i=2;i<45;i++) cnt[i]+=cnt[i-1];
    
    cin>>t;

    while(t--){
        ll n,ok=0;
        cin>>n;
        string ans;
        for(ll i=44;i>=0;i--){
            if(cnt[i]<n){
                ok=1;
                ans+='1';
                n-=(cnt[i]+1);
            }
            else if(ok) ans+='0';
        }
        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}