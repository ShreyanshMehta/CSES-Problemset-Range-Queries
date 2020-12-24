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
  struct node{
    ll sum, l, r, mx;
  };

  int n;
  vector<node>tree;

  SegTree(int n) {
      this->n = n;
      tree.resize(4*n);
  }

  SegTree(vector<ll> a) : SegTree(a.size()) {
      buildSeg(a,0,n-1,0);
  }

  void buildSeg(vector<ll> &arr,int start,int end,int node){
    if(start==end){
      tree[node].sum = arr[start];
      tree[node].l = arr[start];
      tree[node].r = arr[start];
      tree[node].mx = arr[start];
      return;
    }
    int mid=(start+end)/2;
    buildSeg(arr, start, mid, 2*node+1);
    buildSeg(arr, mid+1, end, 2*node+2);

    tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
    tree[node].l = max({tree[2*node+1].sum + tree[2*node+2].l, tree[2*node+1].l});
    tree[node].r = max({tree[2*node+2].r, tree[2*node+1].r + tree[2*node+2].sum});
    tree[node].mx = max({tree[node].sum, tree[node].r, tree[node].l, tree[2*node+1].r + tree[2*node+2].l, tree[2*node+1].mx, tree[2*node+2].mx});
  }

  void update(int i, ll new_val, int node, int start, int end){
    if(start==end){
      tree[node].sum = new_val;
      tree[node].l = new_val;
      tree[node].r = new_val;
      tree[node].mx = new_val;
      return;
    }

    int mid=(start+end)/2;
    if(start<=i and mid>=i) 
        update(i, new_val, 2*node+1, start, mid);
    if(mid+1<=i and end>=i)
        update(i, new_val, 2*node+2, mid+1, end);

    tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
    tree[node].l = max({tree[2*node+1].sum + tree[2*node+2].l, tree[2*node+1].l});
    tree[node].r = max({tree[2*node+2].r, tree[2*node+1].r + tree[2*node+2].sum});
    tree[node].mx = max({tree[node].sum, tree[node].r, tree[node].l, tree[2*node+1].r + tree[2*node+2].l, tree[2*node+1].mx, tree[2*node+2].mx});
  }

  void upd(vl &arr, int i, ll new_val){
    arr[i] = new_val;
    update(i, new_val, 0, 0, n-1);
  }

  void get(int start, int end, int node, int ind){
    if(start==end) {
        cout<<tree[node].sum<<" "<<tree[node].mx<<" "<<tree[node].l<<" "<<tree[node].r<<endl;
        return;
    }
    int mid = (start+end)/2;
    if(start<=ind and mid>=ind)
        get(start, mid, node*2+1, ind);
    else
        get(mid+1, end, node*2+2, ind);
  }
};

void nikal_pehli_fursat_mai(){
    int n, q;
    cin>>n>>q;
    vl v(n);
    fi(0, n) cin>>v[i];
    SegTree st(v);

    while(q--){
        ll k, u;
        cin>>k>>u;
        k--;
        st.upd(v, k, u);
        cout<<max(0LL, st.tree[0].mx)<<endl;
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
