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

/***********Time Complexity**********/
//Updation & Submatrix Sum - O(log(n)log(m))
//Preprocessing -O( mnlog(n)log(m) )

struct BIT2D{
    int n, m;
    vector<vector<ll>> bit;
    
    BIT2D(int n, int m){
        this->n = n;
        this->m = m;
        bit.assign(n+5, vector<ll>(m+5));
    }

    BIT2D(vector<vector<ll>>mat): BIT2D(mat.size(), mat[0].size()){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                add(i, j, mat[i][j]);
            }
        }
    } 
      
    ll sum(int x, int y) {
        ll ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
       
    ll getAns(ll x1, ll y1, ll x2, ll y2) { 
        ll ans = sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1); 
        return ans; 
    } 
};


void nikal_pehli_fursat_mai(){
    ll n, q;
    cin>>n>>q;
    vector<vl>v(n, vl(n));
    fi(0, n){
        fj(0, n) {
            char ch;
            cin>>ch;
            if(ch=='*') v[i][j] = 1;
        }
    }

    BIT2D f(v);

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            ll x, y;
            cin>>x>>y;
            x--, y--;
            f.add(x, y, (-2)*v[x][y]+1);
            v[x][y] = !v[x][y];
        }
        else{
            ll x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            x1--, y1--, x2--, y2--;
            cout<<f.getAns(x1, y1, x2, y2)<<endl;
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
    // cin>>tc;
    while(tc--){
    nikal_pehli_fursat_mai();
    }
}
