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

vector<ll> fib;
ll mod=1000000007;

vector<ll> mat_exp(ll p){
    vector<ll> temp;
    if(p==1){
        temp.pb(1);
        temp.pb(1);
        temp.pb(1);
        temp.pb(0);
        return temp;
    }
    if(p%2){
        vector<ll> ans=mat_exp(p-1);
        temp.pb((ans[0]+ans[1])%mod);
        temp.pb(ans[0]);
        temp.pb((ans[2]+ans[3])%mod);
        temp.pb(ans[2]);
        return temp;
    }
    vector<ll> ans=mat_exp(p/2);
    temp.pb((ans[0]*ans[0]+ans[1]*ans[2])%mod);
    temp.pb((ans[0]*ans[1]+ans[1]*ans[3])%mod);
    temp.pb((ans[2]*ans[0]+ans[3]*ans[2])%mod);
    temp.pb((ans[2]*ans[1]+ans[3]*ans[3])%mod);
    return temp;
}

int main()
{   
    fib.pb(0);
    fib.pb(1);
    for(ll i=2;;i++){
        ll temp=fib[i-1]+fib[i-2];
        if(temp>2000000000) break;
        fib.pb(temp);
    }
    
    ll tc,ii=0;
    cin>>tc;

    vector<ll> prt;
    while(tc--){
        ll n,x,m,y,k;
        cin>>n>>x>>m>>y>>k;
        
        if(n>45 || m>45){
            prt.pb(-1);
            continue;
        }

        ll u=fib[n],v=fib[n+1],p=fib[m],q=fib[m+1];
        if(u*q==v*p || (q*x-v*y)/abs(q*x-v*y)!=(u*q-v*p)/abs(u*q-v*p) || (q*x-v*y)%(u*q-v*p)){
            prt.pb(-1);
            continue;
        }
        ll a=(q*x-v*y)/(u*q-v*p);
        if(y-p*a<0 || (y-p*a)%q){
            prt.pb(-1);
            continue;
        }
        ll b=(y-p*a)/q;
        vector<ll> ans=mat_exp(k);
        ll c1=ans[0],c2=ans[2];
        prt.pb(((c2*a)%mod+(c1*b)%mod)%mod);
    }

    for(ll i=0;i<prt.size();i++){
        cout<<"Case "<<++ii<<": ";
        if(prt[i]==-1) cout<<"Impossible"<<endl;
        else cout<<prt[i]<<endl;
    }

    return 0;
}