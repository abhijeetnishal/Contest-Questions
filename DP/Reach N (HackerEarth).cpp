/*
Asked in HackerEarth Data Strucures and Algorithm Contest (Oct-2022)

Problem:
You are given an array  consisting of  integers. In one move, you can jump from your current index  to some index  if,
1. i<j
2. j<=n
3. (j-i)=(2^k) where (k>=0) (i.e difference between the current index and next index should be equal to some power of 2).

You will start from index 1 and your task is to reach index n maximizing the sum of the path.

Sum of the path:
Let the indices that you go through while going from index  to index  are . So, sum of the path here is equal to 
a[1]+a[i2]...+a[n].
*/


//Recursion code: O(exponential)

#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
using namespace std;
 
void rec(int idx,int sum,int &mxm,int n,int a[]){
    sum+=a[idx];
    if(idx==n-1){
        mxm=max(mxm,sum);
        return;
    }
    for(int i=0;i<31;i++){
        int new_idx=idx+(1<<i);
        if(new_idx<n){
            rec(new_idx,sum,mxm,n,a);
        }
        else
            return;
    }
}
 
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int sum=0,mxm=INT_MIN;
    rec(0,sum,mxm,n,a);
    cout<<mxm<<"\n";
}
 
int32_t main(){
    fastio;
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        solve();
    }
}



//DP code: O(n)

#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long int
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int sum=0,mxm=INT_MIN;
    vector<int> dp(n,INT_MIN);
    dp[n-1]=a[n-1];

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<31;j++){
            int new_idx=i+(1<<j);
            if(new_idx<n){
                dp[i]=max(dp[i],a[i]+dp[new_idx]);
            }
        }
    }

    cout<<dp[0]<<"\n";
}

int32_t main(){
    fastio;
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        solve();
    }
}
