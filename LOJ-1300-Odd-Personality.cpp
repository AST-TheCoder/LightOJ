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

vector<ll> g[10007];
vector<pair<ll,ll>> bridge_edge;
ll tim,low[10007],d[10007],dis[10007],ans;
bool vis[10007];

void find_bridge(ll u,ll par){
    vis[u]=1;
    low[u]=d[u]=++tim;

    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==par) continue;
        if(vis[v]){
            low[u]=min(d[v],low[u]);
        }
        else{
            find_bridge(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>d[u]){
                if(u<v) bridge_edge.pb({u,v});
                else bridge_edge.pb({v,u});
            }
        }
    }
    ++tim;
}

int main(){
    ll t,ii=0;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;

        bridge_edge.clear();
        ans=0;
        tim=0;

        for(ll i=0;i<n;i++){
            g[i].clear();
            dis[i]=-1;
            vis[i]=0;
        }

        set<pair<ll,ll>> edge;
        for(ll i=0;i<m;i++){
            ll u,v;
            cin>>u>>v;
            if(u>v) swap(u,v);
            edge.insert({u,v});
        }

        for(auto x : edge){
            g[x.first].pb(x.second);
            g[x.second].pb(x.first);
        }

        for(ll i=0;i<n;i++){
            if(!vis[i]){
                find_bridge(i,-1);
            }
        }

        sort(all(bridge_edge));

        // cout<<endl;
        // for(ll i=0;i<bridge_edge.size();i++)
        //     cout<<bridge_edge[i].first<<" "<<bridge_edge[i].second<<endl;

        for(ll i=0;i<n;i++) g[i].clear();
        ll c=0;

        //cout<<endl;
        for(auto x : edge){
            if(x.first==bridge_edge[c].first && x.second==bridge_edge[c].second) c++;
            else{
                //cout<<x.first<<" "<<x.second<<endl;
                g[x.first].pb(x.second);
                g[x.second].pb(x.first);
            }
        }

        for(ll i=0;i<n;i++){
            if(dis[i]!=-1) continue;
            dis[i]=0;
            queue<ll> q;
            q.push(i);
            ll cnt=0,chk=0;

            while(!q.empty()){
                cnt++;
                ll u=q.front();
                q.pop();
                for(ll j=0;j<g[u].size();j++){
                    ll v=g[u][j];
                    if(dis[v]!=-1){
                        if((dis[v]+dis[u]+1)%2) chk=1;
                    }
                    else{
                        dis[v]=dis[u]+1;
                        q.push(v);
                    }
                }
            }
            if(chk==1) ans+=cnt;
        }
        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}