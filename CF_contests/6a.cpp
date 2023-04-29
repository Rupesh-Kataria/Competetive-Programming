#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    int n,k; cin>>n>>k;

    int arr[n];
    int x=n*(n-1)/2-k;
    //itne -1 wale chahiye
    int sum=0; int s=n-1;
    loop(i,0,n){
       if(sum==x) {
         s=i; break;
       }
       else{
             sum+=n-1-i;
             sum-=i;
             arr[i]=-1;
       }
    }
    if(sum!=x){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=s; i<n; i++){
        arr[i]=1;
    }
    cout<<"YES"<<endl;
    loop(i,0,n) cout<<arr[i]<<" ";
    cout<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}