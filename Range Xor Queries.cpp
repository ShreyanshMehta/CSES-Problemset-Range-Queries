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
  vector<ll>tree;

  SegTree(int n) {
      this->n = n;
      tree.assign(4*n, 0);
  }

  SegTree(vector<ll> a) : SegTree(a.size()) {
      buildSeg(a,0,n-1,0);
  }

  int getMid(int s, int e) { return s + (e - s)/2; }
  void buildSeg(vector<ll> &arr,int start,int end,int treeNode){
    if(start==end){
      tree[treeNode]=arr[start];
      return;
    }
    int mid=(start+end)/2;
    buildSeg(arr, start, mid, 2*treeNode+1);
    buildSeg(arr, mid+1, end, 2*treeNode+2);

    tree[treeNode]=tree[2*treeNode+1]^tree[2*treeNode+2];
  }

  void updateValueUtil(int ss, int se, int i, ll diff, int si)  {
      if (i < ss || i > se)  return;  
      tree[si] = tree[si] ^ diff;  
      if (se != ss)  {  
          int mid = getMid(ss, se);  
          updateValueUtil(ss, mid, i, diff, 2*si + 1);  
          updateValueUtil(mid+1, se, i, diff, 2*si + 2);  
      }  
  } 

  void update(vector<ll> &arr,int i,ll new_val)  {  
      ll diff = new_val ^ arr[i];  
      arr[i] = new_val;  
      updateValueUtil(0, n-1, i, diff, 0);  
  }

  ll findSumUtil(int ss, int se, int qs, int qe, int si)  {
      if (qs <= ss && qe >= se)  return tree[si];  
      if (se < qs || ss > qe)  return 0;  
      int mid = getMid(ss, se);  
      return findSumUtil(ss, mid, qs, qe, 2*si+1) ^  findSumUtil(mid+1, se, qs, qe, 2*si+2);  
  }  
   
  ll get(int qs, int qe)  {
      return findSumUtil(0, n-1, qs, qe, 0);  
  } 
};
 
void nikal_pehli_fursat_mai(){
    int n, q;
    cin>>n>>q;
    vl v(n);
    fi(0, n) cin>>v[i];
    SegTree st(v);
    // pr(st.tree);
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<st.get(a-1, b-1)<<endl;
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
