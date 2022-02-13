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

ll mod=10007;
vector<vector<ll>> v;
vector<ll> m;

void make_matrix(){
    vector<ll>temp; temp.pb(1); temp.pb(1); temp.pb(2); v.pb(temp);
    temp.clear(); temp.pb(1); temp.pb(0); temp.pb(0); v.pb(temp);
    temp.clear(); temp.pb(0); temp.pb(1); temp.pb(1); v.pb(temp);
    m.pb(2); m.pb(1); m.pb(1);
}

vector<vector<ll>> mat_mul(vector<vector<ll>> x, vector<vector<ll>> y){
    vector<vector<ll>> mul;

    for(ll i=0;i<m.size();i++){
        vector<ll> temp;
        for(ll j=0;j<m.size();j++){
            ll val=0;
            for(ll k=0;k<m.size();k++){
                val=(val+x[i][k]*y[k][j])%mod;
            }
            temp.pb(val%mod);
        }
        mul.pb(temp);
    }

    return mul;
}

vector<vector<ll>> solve(ll p){
    if(p==1) return v;
    if(p%2){
        vector<vector<ll>> temp=solve(p-1);
        return mat_mul(temp,v);
    }

    vector<vector<ll>> temp=solve(p/2);
    return mat_mul(temp,temp);
}

int main(){

    make_matrix();

    ll t,ii=0;
    cin>>t;
    while(t--){
        ll n,ans=0;
        cin>>n;
        cout<<"Case "<<++ii<<": ";
        if(n<m.size()){
            cout<<m[m.size()-n-1]<<endl;
            continue;
        }

        vector<vector<ll>> mat=solve(n-2);
        for(ll i=0;i<m.size();i++)
            ans+=(mat[0][i]*m[i])%mod;
        cout<<ans%mod<<endl;
    }

    return 0;
}