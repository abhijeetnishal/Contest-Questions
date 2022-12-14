/*
LeetCode weekly contest 314 (Hard)

You are given a 0-indexed m x n integer matrix grid and an integer k. 
You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. 
Since the answer may be very large, return it modulo 109 + 7.

Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
Output: 2

*/

//Code (Recursion)-> O(exponential):

    int rec(int i,int j,int m,int n,int k,vector<vector<int>> &grid,int sum,int mod){
        if(i>=m || j>=n)
            return 0;
        if(i==m-1 && j==n-1){
            sum+=grid[i][j];
            if(sum%k==0)
                return 1;
            else
                return 0;
        }
        return (rec(i+1,j,m,n,k,grid,sum+grid[i][j],mod)%mod 
             + rec(i,j+1,m,n,k,grid,sum+grid[i][j],mod)%mod)%mod; 
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod=1e9+7;
        int sum=0;
        int m=grid.size(),n=grid[0].size();
        return rec(0,0,m,n,k,grid,sum,mod);
    }


//Code (Memoization)-> O(n*m*k):

    int rec(int i,int j,int m,int n,int k,vector<vector<int>> &grid,int sum,int mod,vector<vector<vector<int>>> &dp){
        if(i>=m || j>=n)
            return 0;
        if(i==m-1 && j==n-1){
            sum+=grid[i][j];
            if(sum%k==0)
                return 1;
            else
                return 0;
        }
        if(dp[i][j][sum]!=-1)
            return dp[i][j][sum];
        return dp[i][j][sum]=(rec(i+1,j,m,n,k,grid,(sum+grid[i][j])%k,mod,dp)%mod 
             + rec(i,j+1,m,n,k,grid,(sum+grid[i][j])%k,mod,dp)%mod)%mod; 
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod=1e9+7;
        int sum=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return rec(0,0,m,n,k,grid,sum,mod,dp);
    }
