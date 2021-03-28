//Problem link: https://lightoj.com/problem/problem-makes-problem

// Solution:

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

ll fact[2000007];
ll mod=1000000007;

ll modinverse(ll n,ll p){
	if(p==1) return n;
	if(p%2) return (modinverse(n,p-1)*n)%mod;
	ll x=modinverse(n,p/2);
	return (x*x)%mod;
}

int main()
{	
	fact[0]=1;
	for(ll i=1;i<2000007;i++) fact[i]=(fact[i-1]*i)%mod;
	ll t,ii=0;
	cin>>t;

	while(t--){
		ll n,k;
		cin>>n>>k;
		cout<<"Case "<<++ii<<": "<<(fact[n+k-1]*modinverse((fact[n]*fact[k-1])%mod,mod-2))%mod<<endl;
	}

	return 0;
}
