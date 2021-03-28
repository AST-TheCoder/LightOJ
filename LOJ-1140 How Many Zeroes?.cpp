//Problem link: https://lightoj.com/problem/how-many-zeroes

//Solution:

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
	cin>>t;

	while(t--){
		ll n,m;
		cin>>n>>m;
		cout<<"Case "<<++ii<<": ";

		if(!m){
			cout<<1<<endl;
			continue;
		}

		ll ten=10,x=0,y=0;
		while(m/ten>0){
			ll p=m/ten;
			ll c=p*ten+ten/10-1;
			p*=ten/10;
			if(m<c){
				p-=(c-m);
			}
			x+=p;
			ten*=10;
		}
		x++;
		if(!n){
			cout<<x<<endl;
			continue;
		}
		ten=10;
		n--;
		while(n/ten>0){
			ll p=n/ten;
			ll c=p*ten+ten/10-1;
			p*=ten/10;
			if(n<c){
				p-=(c-n);
			}
			y+=p;
			ten*=10;
		}
		y++;
		cout<<x-y<<endl;
	}

	return 0;
}
