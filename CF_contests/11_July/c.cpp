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

const int nax= 2e5+5;


int dp[nax][2];
int arr[nax];

int n;

void rec2(int i){

    if(i==n) return;

    if(dp[i][0]==-1){
        dp[i][0]= (i-1 >=0) ? max(dp[i-1][0], dp[i-1][1]) : 0;
    }

    if(dp[i][1]==-1){
        dp[i][1]=arr[i]+(i-1>=0 ? dp[i-1][0]: 0);
    }

    rec2(i+1);
}

int rec(int i, int prev){

    if(i==n) return 0;

    if(dp[i][prev]!=-1) return dp[i][prev];

    if(prev){
       return dp[i][prev] = rec(i+1, 1-prev);
    }

    else{
        return dp[i][prev] = max(arr[i]+rec(i+1, 1), rec(i+1, 0));
    }
}
 
 
void solve(){
    cin>>n;

    for(int i=0; i<n; i++) cin>>arr[i];
  memset(dp, -1, sizeof(dp));
  bool flag= true;

  for(int i=0; i<n; i++){
    if(arr[i]>0){
        flag=false;
    break;
    }
  }

  if(flag){
    int maxi= -inf;
     for(int i=0; i<n; i++){
    maxi=max(maxi, arr[i]);
  }

  cout<<maxi<<endl;
  return;
  }

    rec2(0);



    cout<<max(dp[n-1][0], dp[n-1][1])<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}