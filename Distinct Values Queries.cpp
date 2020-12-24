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

int block_size;

struct Query {
    int L, R, id;
    bool operator<(Query other) const{
        return make_pair(L / block_size, R) < make_pair(other.L / block_size, other.R);
    }
};

void nikal_pehli_fursat_mai(){
    int n, q;
    cin>>n>>q;
    vl v(n), a(q);
    map<int, int>compress;
    set<int>st;
    fi(0, n) { 
        cin>>v[i];
        st.insert(v[i]);
    }

    int pt = 0;
    while(!st.empty()){
        compress[*st.begin()] = pt++;
        st.erase(st.begin());
    }

    fi(0, n) v[i] = compress[v[i]];
    
    block_size = sqrt(n);
    vector<Query>query(q);
    
    fi(0, q){
        cin>>query[i].L>>query[i].R;
        query[i].L--; query[i].R--;
        query[i].id = i;
    }

    sort(query.begin(), query.end());

    int l=0, r=-1, ans = 0;
    vi mp(pt+1, 0);

    fi(0, q){
        while(l>query[i].L){
            l--;
            mp[v[l]]++;
            if(mp[v[l]]==1) ans++;
        }
        while(r<query[i].R){
            r++;
            mp[v[r]]++;
            if(mp[v[r]]==1) ans++;
        }
        while(l<query[i].L){
            mp[v[l]]--;
            if(mp[v[l]]==0) ans--;
            l++;
        }
        while(r>query[i].R){
            mp[v[r]]--;
            if(mp[v[r]]==0) ans--;
            r--;
        }
        a[query[i].id] = ans;
    }
    for(auto it: a) cout<<it<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc=1; 
    // cin>>tc;
    while(tc--){
    nikal_pehli_fursat_mai();
    }
}
