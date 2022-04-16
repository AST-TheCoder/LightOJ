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
        double a,b;
        char c;
        cin>>b>>c>>a;
        double x=400.0/(2.0*b+sqrt(a*a+b*b)*(3.141592653589-2.0*atan(b/a)));
        cout<<fixed<<setprecision(10)<<"Case "<<++ii<<": "<<b*x<<" "<<a*x<<endl;
    }

    return 0;
}