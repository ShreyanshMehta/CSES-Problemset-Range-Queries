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

    tree[treeNode]=max(tree[2*treeNode+1],tree[2*treeNode+2]);
  }

  void updateValue(vl &arr, int ss, int se, int index, int value, int node) { 
    if (index < ss || index > se) return; 
    if (ss == se) { 
        arr[index] = value; 
        tree[node] = value; 
    } 
    else { 
        int mid = getMid(ss,se); 
        if(index>=ss && index<=mid) 
            updateValue(arr, ss, mid, index,value, 2*node+1); 
        else
            updateValue(arr, mid+1, se, index, value, 2*node+2); 
        tree[node] = max( tree[2*node+1], tree[2*node+2]); 
    } 
    return; 
  }

  void update(vl &arr, int index, int new_value){
    updateValue(arr, 0, n-1, index, new_value, 0);
  } 

  ll findMaxUtil(int ss, int se, int qs, int qe, int si)  {
      if (qs <= ss && qe >= se)  return tree[si];  
      if (se < qs || ss > qe)  return 0;  
      int mid = getMid(ss, se);  
      return max(findMaxUtil(ss, mid, qs, qe, 2*si+1),findMaxUtil(mid+1, se, qs, qe, 2*si+2));  
  }  
   
  ll get(int qs, int qe)  {
      return findMaxUtil(0, n-1, qs, qe, 0);  
  } 
};

void nikal_pehli_fursat_mai(){
    ll n, m;
    cin>>n>>m;

    vl v(n);
    fi(0, n) cin>>v[i];
    
    SegTree st(v);

    while(m--){
        ll temp;
        cin>>temp;
        if(st.get(0, n-1)<temp){
            cout<<0<<" ";
            continue;;
        }
        ll low = 0, high = n-1;
        fi(0, 22){
            ll mid = (low+high)/2;
            if(st.get(low, mid)>=temp){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        cout<<low+1<<" ";
        st.update(v, low, v[low]-temp);
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
