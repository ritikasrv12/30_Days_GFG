class Solution
{
    public:
    int help(int n,int x,int y,int z,vector<int> &dp){
        if(n<0)return INT_MIN;
        if(n==0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n] = 1+max({help(n-x,x,y,z,dp),help(n-y,x,y,z,dp),help(n-z,x,y,z,dp)});
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int ans = help(n,x,y,z,dp);
        return ans<0?0:ans;
        //Your code here
    }
};
