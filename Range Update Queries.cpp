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

struct SegTree{
    int n;
    vl tree, lazy;  
    SegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }
 
    void updateRangeUtil(int si, int ss, int se, int us, int ue, ll diff) { 
        if (lazy[si] != 0) {
            tree[si] += (se-ss+1)*lazy[si]; 
            if (ss != se) { 
                lazy[si*2 + 1]   += lazy[si]; 
                lazy[si*2 + 2]   += lazy[si]; 
            } 
            lazy[si] = 0; 
        } 
        if (ss>se || ss>ue || se<us) return; 
        if (ss>=us && se<=ue) {  
            tree[si] += (se-ss+1)*diff; 
            if (ss != se) { 
                lazy[si*2 + 1]   += diff; 
                lazy[si*2 + 2]   += diff; 
            } 
            return; 
        } 
        int mid = (ss+se)/2; 
        updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
        updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);  
        tree[si] = tree[si*2+1] + tree[si*2+2]; 
    } 
      
    void updateRange(int us, int ue, ll diff) { 
       updateRangeUtil(0, 0, n-1, us, ue, diff); 
    } 
      
      
    ll getSumUtil(int ss, int se, int qs, int qe, int si) {
        if (lazy[si] != 0) {  
            tree[si] += (se-ss+1)*lazy[si]; 
            if (ss != se) {
                lazy[si*2+1] += lazy[si]; 
                lazy[si*2+2] += lazy[si]; 
            }  
            lazy[si] = 0; 
        } 
      
        if (ss>se || ss>qe || se<qs) return 0; 
        if (ss>=qs && se<=qe) return tree[si]; 
 
        int mid = (ss + se)/2; 
        return getSumUtil(ss, mid, qs, qe, 2*si+1) + getSumUtil(mid+1, se, qs, qe, 2*si+2); 
    } 
      
    ll getSum(int qs, int qe) {
        return getSumUtil(0, n-1, qs, qe, 0); 
    } 
};

void nikal_pehli_fursat_mai(){
    int n, q;
    cin>>n>>q;
    vl v(n);
    fi(0, n) cin>>v[i];
    SegTree st(n);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int a, b, c;
            cin>>a>>b>>c;
            a--; b--;
            st.updateRange(a, b, c);
        }
        else{
            int a;
            cin>>a;
            a--;
            cout<<v[a]+st.getSum(a, a)<<endl;
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
