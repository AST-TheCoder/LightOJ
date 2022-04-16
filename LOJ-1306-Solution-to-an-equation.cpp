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
    cin>>t;
    while(t--){
        ll a,b,c,x1,x2,y1,y2;
        cin>>a>>b>>c>>x1>>x2>>y1>>y2;

        if(abs(a)<abs(b)){
            swap(a,b);
            swap(x1,y1);
            swap(x2,y2);
        }

        ll g=__gcd(abs(a),abs(b));
        if(abs(c)%g){
            cout<<0<<endl;
            continue;
        }
        ll p=abs(a)*((abs(b)+abs(c))/abs(a)+((abs(b)+abs(c))%abs(a)!=0));
        ll q=((p-abs(c))/abs(b))*abs(b);
        ll d=abs(a)%abs(b);
    }

    return 0;
}