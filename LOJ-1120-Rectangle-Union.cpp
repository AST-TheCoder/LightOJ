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
#define min_heap priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> >

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{   
    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        vector<pair<pair<ll,ll>,pair<ll,ll>>> v;
        ll mark[n];

        for(ll i=0;i<n;i++){
            ll x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            v.pb({{x1,i},{y1,y2}});
            v.pb({{x2,i},{y1,y2}});
            mark[i]=-1;
        }

        min_heap p;
        priority_queue<pair<ll,ll>> q;

        sort(all(v));
        p.push({v[0].second.first,v[0].first.second});
        q.push({v[0].second.second,v[0].first.second});
        ll x1=v[0].first.first,x2=v[0].first.first,y1=v[0].second.first,y2=v[0].second.second;
        ll ans=0;
        mark[v[0].first.second]++;

        for(ll i=1;i<v.size();i++){
            x2=v[i].first.first;
            if(!p.empty() && !q.empty()){
                y1=p.top().first;
                y2=q.top().first;
                ans+=(x2-x1)*(y2-y1);
                //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
            }
            p.push({v[i].second.first,v[i].first.second});
            q.push({v[i].second.second,v[i].first.second});
            x1=x2;
            mark[v[i].first.second]++;
            while(!p.empty() && mark[p.top().second]>0) p.pop();
            while(!q.empty() && mark[q.top().second]>0) q.pop();
        }

        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}