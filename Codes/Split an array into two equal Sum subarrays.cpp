class Solution {
  public:
    bool canSplit(vector<int>& arr) {
         int sum = 0, firstSum = 0;
        for(auto x:arr)sum+=x;
        for(auto x:arr){
            sum-=x;
            firstSum+=x;
            if(sum==firstSum)return true;
        }
        return false;
        // code here
    }
};
