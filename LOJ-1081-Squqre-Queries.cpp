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

ll n; 
ll a[505][505];
ll Block[505][505][10];

void init(ll k){
    for(ll i=n;i>=1;i--){
        for(ll j=1;i+j-1<=n;j*=2){
            ll temp=log2(j);
            if(j==1) Block[k][i][temp]=a[k][i];
            else Block[k][i][temp]=max(Block[k][i][temp-1],Block[k][i+j/2][temp-1]);
        }
    }
}

int main(){
    ll t,ii=0;
    cin>>t;
    while(t--){
        ll i,j,k,q;
        cin>>n>>q;
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                cin>>a[i][j];
            }
            init(i);
        }
        printf("Case %lli:\n",++ii);
        while(q--){
            ll x,y,s;
            cin>>x>>y>>s;
            ll ans=0;
            ll temp=log2(s);
            for(i=x; i<x+s; i++){
                ans=max(ans,max(Block[i][y][temp],Block[i][y+s-(1<<temp)][temp]));
            }
            printf("%lli\n",ans);
        }
 
    }
}