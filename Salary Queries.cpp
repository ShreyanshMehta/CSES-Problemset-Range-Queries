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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
//find_by_order(k) - returns an iterator to k-th element(starting from 0)
//order_of_key(k) - Number of items strictly smaller than k 

void nikal_pehli_fursat_mai(){
    ll n, q;
    cin>>n>>q;

    ordered_multiset st;

    vl v(n);
    fi(0, n) {
        cin>>v[i];
        st.insert(v[i]);
    }

    while(q--){
        char ch;
        int a, b;
        cin>>ch>>a>>b;
        if(ch=='?'){
            int r = st.order_of_key(b+1);
            int l = st.order_of_key(a);
            cout<<(r-l)<<endl;
        }
        else{
            a--;
            st.erase(st.find_by_order(st.order_of_key(v[a])));
            v[a] = b;
            st.insert(b);
            // pr(st);
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
