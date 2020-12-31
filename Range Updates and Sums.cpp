#include<bits/stdc++.h>
using namespace std;

#define   fi(a,b) for(int i=a;i<b;i++)
#define   fj(a,b) for(int j=a;j<b;j++)
#define   ff first
#define   ss second
#define   ll long long
#define   ld long double
#define   ull unsigned long long
#define   bp(x) __builtin_popcount(x)
#define   pr(x) for(auto it: x) cout<<it<<" "; cout<<endl;
#define   getMax(x) max_element(x.begin(),x.end())
#define   getMin(x) min_element(x.begin(),x.end())
#define   endl "\n"
typedef   vector<int> vi;
typedef   vector< pair<int,int> > vii;
typedef   vector<long long> vl;
typedef   pair<int,int> pii;
typedef   pair<ll,ll> pll;
typedef   vector< pair<ll,ll> > vll;
//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1};
//int dx[]={-1,0,1,1,1,0,-1,-1};
//int dy[]={-1,-1,-1,0,1,1,1,0};

const ll mxN=2e5;
ll n,q;
ll x[mxN];
struct node{
    ll mn,s,lz;
    bool lz2 = 0;
} st[1<<19];
 
void app(int i,ll x,bool x2,int l2,int r2){
    if(x2){
        st[i].s = 0;
        st[i].lz = 0;
        st[i].lz2 = 1;
    }
    st[i].mn += x;
    st[i].s += (r2-l2+1)*x;
    st[i].lz += x;
}

void psh(int i,int l2,int m2,int r2){
    app(2*i,st[i].lz,st[i].lz2,l2,m2);
    app(2*i+1,st[i].lz,st[i].lz2,m2+1,r2);
    st[i].lz2 = 0;
    st[i].lz = 0;
}

void upd(int l1,ll x,int i=1,int l2=0,int r2=n-1){
    if(l2==r2){
        st[i].mn = x;
        st[i].s = x;
        return;
    }
    
    int m2=(l2+r2)/2;
    psh(i,l2,m2,r2);
    
    if(l1<=m2)
        upd(l1,x,2*i,l2,m2);
    else
        upd(l1,x,2*i+1,m2+1,r2);

    st[i].mn = min(st[2*i].mn,st[2*i+1].mn);
    st[i].s = st[2*i].s+st[2*i+1].s;
}

void upd2(int l1,int r1,ll x,bool x2,int i=1,int l2=0,int r2=n-1){
    if(l1<=l2 and r2<=r1){
        app(i,x,x2,l2,r2);
        return;
    }
    
    int m2=(l2+r2)/2;
    psh(i,l2,m2,r2);
    
    if(l1<=m2)
        upd2(l1,r1,x,x2,2*i,l2,m2);
    if(m2<r1)
        upd2(l1,r1,x,x2,2*i+1,m2+1,r2);

    st[i].mn = min(st[2*i].mn,st[2*i+1].mn);
    st[i].s = st[2*i].s + st[2*i+1].s;
}

ll qry(int l1,int r1,int i=1,int l2=0,int r2=n-1){
    if(l1<=l2 and r2<=r1)
        return st[i].s;
    
    int m2 = (l2+r2)/2;
    psh(i,l2,m2,r2);

    return (l1<=m2?qry(l1,r1,2*i,l2,m2):0)+(m2<r1?qry(l1,r1,2*i+1,m2+1,r2):0);
}

void nikal_pehli_fursat_mai(){
    cin>>n>>q;
    fi(0, n) {
        cin>>x[i];
        upd(i,x[i]);
    }

    while(q--){
        int qt;cin>>qt;
        if(qt==1){
            int a,b,u;
            cin>>a>>b>>u;
            --a,--b;
            upd2(a,b,u,0);
        }
        else if(qt==2){
            int a,b,u;
            cin>>a>>b>>u;
            --a,--b;
            upd2(a,b,u,1);
        }
        else{
            int a,b;
            cin>>a>>b;
            --a,--b;
            cout<<qry(a,b)<<endl;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc=1; 
    cin>>tc;
    while(tc--){
    nikal_pehli_fursat_mai();
    }
}
