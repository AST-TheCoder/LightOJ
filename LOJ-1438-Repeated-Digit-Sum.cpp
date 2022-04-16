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
        string a,b;
        cin>>a>>b;
        cout<<"Case "<<++ii<<": ";

        if(a=="0"){
            cout<<0<<endl;
            continue;
        }
        if(b=="0"){
            cout<<1<<endl;
            continue;
        }

        ll s=0;
        for(ll i=0;i<a.size();i++){
            s+=(ll)(a[i]-'0');
        }
        while(s>=10){
            ll temp=s;
            s=0;
            while(temp){
                s+=temp%10;
                temp/=10;
            }
        }

        vector<ll> c;
        c.pb(s);

        ll mark[10],start;
        memset(mark,0,sizeof(mark));
        mark[s]=1;

        while(1){
            ll x=0,r=0;
            for(ll i=a.size()-1;i>=0;i--){
                ll d=(ll)(a[i]-'0');
                d*=s;
                d+=r;

                x+=(d%10);
                r=(d/10);
            }
            x+=r;
            while(x>=10){
                ll temp=x;
                x=0;
                while(temp){
                    x+=temp%10;
                    temp/=10;
                }
            }
            if(mark[x]){
                start=mark[x];
                break;
            }
            c.pb(x);
            mark[x]=c.size();
            s=x;
        }

        ll id=0;
        for(ll i=0;i<b.size() && id<start;i++){
            id=(id*10+(ll)(b[i]-'0'));
        }

        if(id<start){
            cout<<c[id-1]<<endl;
            continue;
        }

        vector<ll> temp;
        start--;
        ll x=start;
        while(x){
            temp.pb(x%10);
            x/=10;
        }

        while(temp.size()!=b.size()){
            temp.pb(0);
        }
        reverse(all(temp));
        for(ll i=b.size()-1;i>=0;i--){
            ll d=(ll)(b[i]-'0');
            if(d>=temp[i]) d-=temp[i];
            else{
                d+=10;
                temp[i-1]++;
                d-=temp[i];
            }
            b[i]=(char)(d+'0');
        }
        //for(ll i=0;i<c.size();i++) cout<<c[i]<<" ";cout<<endl;cout<<start<<endl;cout<<b<<endl;for(ll i=0;i<temp.size();i++) cout<<temp[i]<<" ";cout<<endl;

        ll len=c.size()-start;
        x=0;
        for(ll i=0;i<b.size();i++){
            x=(x*10+(b[i]-'0'));
            x%=len;
        }
        if(!x) start=c.size()-1;
        else start+=(x-1);
        cout<<c[start]<<endl;

    }

    return 0;
}