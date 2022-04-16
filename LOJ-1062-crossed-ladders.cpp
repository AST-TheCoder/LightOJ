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
        double x,y,c;
        cin>>x>>y>>c;

        double l=0.00000001,r=min(x,y);
        while(r-l>0.00000000001){
            double b=(r+l)/2.0;
            double m1=tan(acos(b/y));
            double m2=tan(3.141592653589-acos(b/x));

            double v=-m1*m2*b/(m1-m2);
            //cout<<fixed<<setprecision(2)<<b<<" "<<m1<<" "<<m2<<" "<<l<<" "<<r<<" "<<v<<endl;
            if(v>=c) l=b;
            else r=b;
        }
        cout<<fixed<<setprecision(10)<<"Case "<<++ii<<": "<<l<<endl;
    }

    return 0;
}